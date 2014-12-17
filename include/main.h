#pragma once
#ifndef __MAIN_H__
#define __MAIN_H__
#define UNICODE
#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#define _WIN32_WINNT 0x0600
#define _WIN32_IE 0x0900

#include <windows.h>
#include <tchar.h>
#include <commdlg.h>
#include <shlwapi.h>
#include <commctrl.h>
typedef struct _g_inst {
    HWND hwnd;
    HWND hwndEdit;
    HINSTANCE hInst;
} g_inst;

extern g_inst g;
#endif // __MAIN_H__
