// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//


#ifdef _MSC_VER
#pragma once
#include "targetver.h"
#define _CRT_SECURE_NO_WARNINGS
#else
	#ifndef __STDAFX__
	#define __STDAFX__

#define _WIN32_WINNT 0x0600
#define _WIN32_IE 0x0900
#endif

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息 this will assume smaller exe
//强制声明UNICODE
#ifndef UNICODE
#define UNICODE
#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif
#endif
// Windows 头文件:
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <commdlg.h>
#include <shlwapi.h>
#include <commctrl.h>


#ifndef _MSC_VER
	#endif
#endif
