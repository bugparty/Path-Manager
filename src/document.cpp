#include "stdafx.h"
#include "resource.h"
#include "document.h"
#include "main.h"
#include "util.h"
BOOL parse(TCHAR* in, path_item* out){
	long start=0;
	long lsize = lstrlen(in);
	
	long index = 0;
	BOOL onError=false;
	for (int i = 0; i < lsize;i++){
		if(*(in+i) == _T(';')){
			//process when i pointing to a ';'
			if(i-start > 1){
				memset(out, 0, sizeof(path_item));
				out->index = index++;
				out->path = (TCHAR *)malloc((i-start+1)*sizeof(TCHAR));
				
				memcpy(out->path,(void *)(in+start),(i-start+1)*sizeof(TCHAR));
				*(out->path+i-start+1)=_T('\0');
				//when processing the end of a line
				if (i == lsize - 1){
					out->next = NULL;
				}
				else{//get ready for the next semicolon
					out->next = (path_item *)malloc(sizeof(path_item));
					memset(out->next, 0, sizeof(path_item));

					out = out->next;
					start = i + 1;
				}
				
				
			}
			else
			{
				start = i + 1;
			}
			

		}
		//process the last line without an semicolon
		else if (i == lsize - 1){
			if (i - start > 0){
				memset(out, 0, sizeof(path_item));
				out->index = index++;
				out->path = (TCHAR *)malloc((i - start+2)*sizeof(TCHAR));

				memcpy(out->path, (void *)(in+start ), (i - start + 1)*sizeof(TCHAR));
				*(out->path + i - start+1) = _T('\0');
			}

		}
		
		
	}
		
	return(!onError) ;

}
VOID createListView(HWND hwnd){
	// Create the list-view window in report view with label editing enabled.
	g.hwndListView = CreateWindow(WC_LISTVIEW,
		_T("List"),
		WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_EDITLABELS,
		20, 130,
		500,
		300,
		hwnd,
		(HMENU)ID_LISTVIEW,
		g.hInst,
		NULL);
	SendMessage(g.hwndListView, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT); // Set style
	// Here we put the info on the Coulom headers
	// this is not data, only name of each header we like
	memset(&g.LvCol, 0, sizeof(g.LvCol)); // Reset Coluom
	g.LvCol.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM; // Type of mask
	g.LvCol.cx = 80;  // width between each coloum
	g.LvCol.pszText = _T("Type");// First Header
	// Inserting Couloms as much as we want
	SendMessage(g.hwndListView, LVM_INSERTCOLUMN, 0, (LPARAM)&g.LvCol); // Insert/Show the coloum
	g.LvCol.pszText = _T("Value");
	g.LvCol.cx = 420;                         // Next coloum
	SendMessage(g.hwndListView, LVM_INSERTCOLUMN, 1, (LPARAM)&g.LvCol); // ...
}
BOOL updateListview(path_item* root){
	LVITEM *pitem = (LVITEM*)malloc(sizeof(LVITEM));
	memset(pitem, 0, sizeof(LVITEM));
	pitem->mask = LVIF_TEXT;
	pitem->iItem = 0;
	pitem->iSubItem = 0;
	DWORD status;
	while (root){
		pitem->iItem = root->index;
		pitem->iSubItem = 0;
		pitem->pszText = _T("unknown");
		ListView_InsertItem(g.hwndListView, pitem);

		pitem->iSubItem = 1;
		pitem->pszText = root->path;
		status = ListView_SetItem(g.hwndListView, pitem);
		assert(status != FALSE);
		if (status == FALSE){
			DWORD dwError = GetLastError();
			Error2Msgbox(dwError, g.hwnd);
		}
		root = root->next;
	}

	return true;
}