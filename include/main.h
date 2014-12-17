#pragma once
#ifndef __MAIN_H__
#define __MAIN_H__

#include "stdafx.h"


typedef struct _g_inst {
    HWND hwnd;
    HWND hwndEdit;
    HINSTANCE hInst;
} g_inst;

extern g_inst g;
#endif // __MAIN_H__
