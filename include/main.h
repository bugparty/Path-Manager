#if _MSC_VER
#pragma once
#else
	#ifndef __MAIN_H__
	#define __MAIN_H__
#endif
#include "stdafx.h"


typedef struct _g_inst {
    HWND hwnd;
    HWND hwndEdit;
    HWND hwndListView;
    LVCOLUMN LvCol; // Make Coluom struct for ListView
    LVITEM LvItem;  // ListView Item struct
    LV_DISPINFO lvd;
    HINSTANCE hInst;
	TCHAR *editBuf;
	DWORD dwEditSize;


} g_inst;

extern g_inst g;

#ifndef _MSC_VER
#endif // __MAIN_H__
#endif
