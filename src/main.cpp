#include "stdafx.h"
#include "main.h"
#include "resource.h"
#include "util.h"
#include "document.h"

#include "dialogs.h"
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[] = _T("Path Manager Main Frame");

g_inst g;
void InitCommonControl() {
	INITCOMMONCONTROLSEX InitCtrlEx;
	InitCtrlEx.dwSize = sizeof(INITCOMMONCONTROLSEX);
	InitCtrlEx.dwICC = ICC_STANDARD_CLASSES | ICC_LISTVIEW_CLASSES;
	InitCommonControlsEx(&InitCtrlEx);
}

void ShowTab(int index, HWND hwnd);
void ShowTab0(HWND hwnd);
void ShowTab1(HWND hwnd);

void ClearTab(int index);
void ClearTab0();
void ClearTab1();

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{

    MSG messages;     /* Here messages to the application are saved */
    WNDCLASSEX wincl; /* Data structure for the windowclass */
    
    g.hInst = hThisInstance;
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure; /* This function is called by windows */
    wincl.style = CS_DBLCLKS;            /* Catch double-clicks */
    wincl.cbSize = sizeof(WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU); /*  menu */
    wincl.cbClsExtra = 0;                               /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                               /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);

    /* Register the window class, and if it fails quit the program */
    if(!RegisterClassEx(&wincl))
	return 0;
	
	InitCommonControl();
    /* The class is registered, let's create the program*/
    g.hwnd = CreateWindowEx(0, /* Extended possibilites for variation */
                            szClassName,
                            /* Classname */ _T("Path Manager Windows App"), /* Title Text */
                            WS_OVERLAPPEDWINDOW,                            /* default window */
                            CW_USEDEFAULT,                                  /* Windows decides the position */
                            CW_USEDEFAULT,                                  /* where the window ends up on the screen */
                            544,                                            /* The programs width */
                            460,                                            /* and height in pixels */
                            HWND_DESKTOP,  /* The window is a child-window to desktop */
                            NULL,          /* No menu */
                            hThisInstance, /* Program Instance handler */
                            NULL           /* No Window Creation data */
                            );

    /* Make the window visible on the screen */
    ShowWindow(g.hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while(GetMessage(&messages, NULL, 0, 0)) {
	/* Translate virtual-key messages into character messages */
	TranslateMessage(&messages);
	/* Send message to WindowProcedure */
	DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

void ReadPath()
{

    HKEY hk;

    int result = RegOpenKeyEx(
        HKEY_LOCAL_MACHINE, _T("SYSTEM\\ControlSet001\\Control\\Session Manager\\Environment"), NULL, KEY_READ, &hk);

    if(result != ERROR_SUCCESS) {
	if(result == ERROR_FILE_NOT_FOUND) {

	    MessageBox(g.hwnd, _T("no such key in RegOpenKeyEx"), _T("title"), MB_ICONWARNING);
	}

	else {
	    Error2Msgbox(result, g.hwnd);
	}
	return;
    }

    DWORD lsize;

    result = RegQueryValueEx(hk, _T("Path"), NULL, NULL, NULL, &lsize);//this size do not include \000 at the end

    if(result != ERROR_SUCCESS) {
	if(result == ERROR_FILE_NOT_FOUND) {

	    MessageBox(g.hwnd, _T("no such key in RegQueryValue"), _T("title"), MB_ICONWARNING);
	} else if(result == ERROR_MORE_DATA) {
	    MessageBox(g.hwnd, _T("need more buffer"), _T("title"), MB_ICONWARNING);
	} else {
	    Error2Msgbox(result, g.hwnd);
	}
	return;
    }
	g.dwEditSize = (lsize + 1) * sizeof(TCHAR);
    g.editBuf = (TCHAR*)malloc(g.dwEditSize);//need to pass the str length and a null at the end
    result = RegQueryValueEx(hk, _T("Path"), NULL, NULL, (LPBYTE)g.editBuf, &g.dwEditSize);
    if(result != ERROR_SUCCESS) {
	if(result == ERROR_FILE_NOT_FOUND) {

	    MessageBox(g.hwnd, _T("no such key in RegQueryValue"), _T("title"), MB_ICONWARNING);
	} else if(result == ERROR_MORE_DATA) {
	    MessageBox(g.hwnd, _T("need more buffer"), _T("title"), MB_ICONWARNING);
	} else {
	    Error2Msgbox(result, g.hwnd);
	}
	return;
    }
    SetWindowText(g.hwndEdit, g.editBuf);

    RegCloseKey(hk);
	parse(g.editBuf, &g.root);
	updateListview(&g.root);
}

INT_PTR CALLBACK AboutDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg) {
    case WM_COMMAND: {
	switch(LOWORD(wParam)) {
	case IDOK:
	case IDCANCEL: {
	    EndDialog(hwndDlg, (INT_PTR)LOWORD(wParam));
	    return (INT_PTR)TRUE;
	}
	}
	break;
    }

    case WM_INITDIALOG:
	return (INT_PTR)TRUE;
    }

    return (INT_PTR)FALSE;
}

BOOL OnNotify(HWND hwndTab, LPARAM lParam)
{
	TCHAR achTemp[256]; // temporary buffer for strings
	static int prevTabIndex = 0;

	switch (((LPNMHDR)lParam)->code)
	{
	case TCN_SELCHANGING:
	{
		// Return FALSE to allow the selection to change.
		return FALSE;
	}
	break;
	case TCN_SELCHANGE:
	{
		int iPage = TabCtrl_GetCurSel(hwndTab);
		
		// Note that g_hInst is the global instance handle.
		WCHAR buf[128];
		wsprintf(buf, L"tab %i\n", iPage);
		OutputDebugStringW(buf);

		if (prevTabIndex == iPage) {
			return TRUE;
		}
		ClearTab(prevTabIndex);
		ShowTab(iPage, g.hwnd);
		prevTabIndex = iPage;
		
	}
	break;
	}
	return TRUE;
}

HWND CreateMainEditCtrl(HWND hWnd)
{
	return CreateWindow(_T("Edit"),
		NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | ES_MULTILINE,
		20,
		22,
		500,
		100,
		hWnd,
		(HMENU)ID_EDIT,
		NULL,
		NULL);
}

void ShowTab0(HWND hwnd)
{
	g.hwndEdit = CreateMainEditCtrl(hwnd);
	createListView(hwnd);
	ReadPath();
}

void ShowTab1(HWND hwnd)
{

}

void ShowTab(int index, HWND hwnd)
{
	switch (index) {
	case 0:
		ShowTab0(hwnd);
		break;
	case 1:
		ShowTab1(hwnd);
		break;
	}
}
void ClearTab0()
{
	DestroyWindow(g.hwndEdit);
	DestroyWindow(g.hwndListView);
}

void ClearTab1()
{

}

void ClearTab(int index)
{
	switch (index) {
	case 0:
		ClearTab0();
		break;
	case 1:
		ClearTab1();
		break;

	}
}
HWND CreateMainTab(HWND hWnd)
{
	HWND hwndTab = CreateWindow(WC_TABCONTROL, L"",
		WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE,
		0, 0, 530, 20, 
		hWnd, NULL, g.hInst, NULL);
	if (hwndTab == NULL)
	{
		return NULL;
	}
	TCITEM item;
	item.mask = TCIF_TEXT | TCIF_IMAGE;
	item.iImage = -1;
	item.pszText = L"Path";
	int iRet = TabCtrl_InsertItem(hwndTab, 0, &item);
	assert(iRet != -1);
	item.pszText = L"Other Path";
	iRet = TabCtrl_InsertItem(hwndTab, 1, &item);
	assert(iRet != -1);
	return hwndTab;
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	

    switch(message) /* handle the messages */
    {
    case WM_CREATE:
		g.hwndTab = CreateMainTab(hwnd);
		ShowTab0(hwnd);
		break;
	case WM_DESTROY:
		free(g.editBuf);
		PostQuitMessage(0); /* send a WM_QUIT to the message queue */
		break;
	case WM_NOTIFY:
		return OnNotify(g.hwndTab, lParam);
	case WM_COMMAND: {
		switch(LOWORD(wParam)) {
		case ID_HELP_ABOUT: {
			DialogBox(g.hInst, MAKEINTRESOURCE(IDD_ABOUTDIALOG), hwnd, &AboutDialogProc);
			return 0;
		}

	case ID_FILE_EXIT: {
	    DestroyWindow(hwnd);
	    return 0;
	}
	case ID_FILE_SAVE: {
	    dialog_save();
	    return 0;
	}
	case ID_FILE_SAVEAS: {
	    dialog_saveas();
	    return 0;
	}
	}
	break;
    }
    default: /* for messages that we don't deal with */
	return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}
