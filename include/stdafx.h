// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once
#if _MSC_VER
#include "targetver.h"
#define _CRT_SECURE_NO_WARNINGS
#else
#define _WIN32_WINNT 0x0600
#define _WIN32_IE 0x0900
#endif

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
//ǿ������UNICODE
#ifndef UNICODE
#define UNICODE
#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif
#endif
// Windows ͷ�ļ�: 
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
 
#include <commdlg.h>
#include <shlwapi.h>
#include <commctrl.h>

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
