#include "stdafx.h"
#include "main.h"
#include "actions.h"
#include <stdio.h>
void action_file_saveas(TCHAR* filename)
{
    FILE* fp;

    fp = _tfopen(filename, _T("w"));

    if(fp == NULL) {
	MessageBox(g.hwnd, _T("can`t open file"), _T("opps"), MB_ICONWARNING);
	return;
    }
    int isize = GetWindowTextLength(g.hwndEdit);
    TCHAR* buf = (TCHAR*)malloc((isize + 1) * sizeof(TCHAR));
    if(buf == NULL) {
	MessageBox(g.hwnd, _T("no enough memery"), _T("opps"), MB_ICONWARNING);
	return;
    }

    GetWindowText(g.hwndEdit, buf, isize);
    _ftprintf(fp, _T("%s"), buf);
    fclose(fp);
    free(buf);
    MessageBox(g.hwnd, _T("file saved!"), _T("congratulations"), MB_ICONINFORMATION);
}
