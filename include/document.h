#include "stdafx.h"

#ifndef __DOCUMENT_H__
#define __DOCUMENT_H__
#pragma once
struct _path_item;
struct _path_tag;
typedef struct _path_item path_item;
typedef struct _path_tag path_tag;
 struct _path_tag{
	TCHAR *name;
	 path_tag *next;
};
struct _path_item{
	TCHAR *path;
	path_tag *tags;
	long index;
	path_item*next;
};
VOID createListView(HWND hwnd);
BOOL parse(TCHAR* in, path_item* out);
BOOL updateListview(path_item* root);
#endif