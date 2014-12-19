#include "document.h"
#include <UnitTest++.h>
TEST(document){
	path_item root;
	TCHAR *ex1 = _T("a;b;c;d;ee;fff;");
	CHECK(parse(ex1, &root));
}