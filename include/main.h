
#ifndef __MAIN_H__
#define __MAIN_H__
#ifdef _MSC_VER
#pragma once
#endif

#include "stdafx.h"
#include "document.h"

typedef struct _g_inst {
    HWND hwnd;
    HWND hwndEdit;
	HWND hwndTab;
    HWND hwndListView;
    LVCOLUMN LvCol; // Make Coluom struct for ListView
    LVITEM LvItem;  // ListView Item struct
    LV_DISPINFO lvd;
    HINSTANCE hInst;
	TCHAR *editBuf;
	DWORD dwEditSize;
	path_item root;

} g_inst;

extern g_inst g;


#endif // __MAIN_H__
 
