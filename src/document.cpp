#include "stdafx.h"
#include "document.h"

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
				else{
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
				out->index = ++index;
				out->path = (TCHAR *)malloc((i - start+2)*sizeof(TCHAR));

				memcpy(out->path, (void *)(in+start ), (i - start + 1)*sizeof(TCHAR));
				*(out->path + i - start+1) = _T('\0');
			}

		}
		
		
	}
		
	return(!onError) ;

}