#include "stdafx.h"
#include "document.h"

BOOL parse(TCHAR* in, path_item* out){
	long start=0;
	long lsize = lstrlen(in);
	memset(out, 0, sizeof(path_item));
	out->index = 0;
	long index = 0;
	BOOL onError=false;
	for(int i=1;i < lsize;i++){
		if(*(in+i) == _T(';')){
			if(i-start > 0){
				out->index = index++;
				out->path = (TCHAR *)malloc((i-start)*sizeof(TCHAR));
				memcpy(out->path,(void *)(start+1),i-start-1);
				*(out->path+i-start)=_T('\0');
				out->next = (path_item *)malloc(sizeof(path_item));
				memset(out->next, 0, sizeof(path_item));
				
				out = out->next;
				start = i;
			}
		}
	}
		
	return(!onError) ;

}