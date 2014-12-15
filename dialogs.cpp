#include "main.h"
#include "util.h"
#include "dialogs.h"
#include "actions.h"
void dialog_saveas(){
    TCHAR szFileName[MAX_PATH];
    lstrcpy(szFileName, _T("path_exported.txt"));
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lpstrFilter = _T("Plain Text(*.txt)\0*.txt\0All\0*.*\0");
    ofn.lpstrFile = (LPTSTR) szFileName;
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = (LPCTSTR)_T("txt");
    GetSaveFileName(&ofn);
    file_saveas( szFileName);

}
void dialog_save(){
    TCHAR *buf;
    DWORD lsize = GetWindowTextLength(g.hwndEdit);
    buf = (TCHAR*) malloc((lsize+1) * sizeof(TCHAR));
    GetWindowText(g.hwndEdit, buf, lsize+sizeof(TCHAR));
        HKEY hk;

    int result = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
                              _T("SYSTEM\\ControlSet001\\Control\\Session Manager\\Environment"),
                              NULL,
                              KEY_ALL_ACCESS,  &hk );

    if(result != ERROR_SUCCESS)
    {
        if(result == ERROR_FILE_NOT_FOUND)
        {

            MessageBox(g.hwnd,_T("no such key in RegOpenKeyEx"),_T("title"),MB_ICONWARNING);
        }

        else
        {
            Error2Msgbox(result, g.hwnd);
        }
        return;
    }
    result = RegSetValueEx(hk,_T("Path"), NULL, REG_EXPAND_SZ,(BYTE*) buf, lsize+sizeof(TCHAR));
    if(result != ERROR_SUCCESS){
        Error2Msgbox(result,g.hwnd);
    }else{
         MessageBox(g.hwnd, _T("Saved"), _T("congratulations"), MB_ICONINFORMATION);
    }


}
