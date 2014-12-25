#include "stdafx.h"
#include "CppUnitTest.h"
#include "document.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(Document)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			 
			path_item root;
			Assert::IsTrue(parse(_T("123"), &root));
			Assert::AreEqual(_T("123"), root.path);
			Assert::IsTrue(root.next == (path_item*)NULL);
		}
		TEST_METHOD(TestMethod2)
		{ 
			path_item root;
			 
			Assert::IsTrue(parse(_T(";;123"), &root));
			Assert::AreEqual(_T("123"), root.path);
			Assert::IsTrue(root.next == (path_item*)NULL);
		}
		TEST_METHOD(TestMethod3)
		{
			 
			path_item* root =(path_item*) malloc(sizeof(path_item));

			Assert::IsTrue(parse(_T(";;123;456;abcddd"), root));
			Assert::AreEqual(_T("123;"), root->path);
			Assert::IsTrue(root->next != (path_item*)NULL);
			root = root->next;
			Assert::AreEqual(_T("456;"), root->path);
			root = root->next;
			Assert::AreEqual(_T("abcddd"), root->path);
			Assert::IsTrue(root->next == (path_item*)NULL);

		}
		TEST_METHOD(TestMethod4)
		{
			 
			path_item* root = (path_item*)malloc(sizeof(path_item));

			Assert::IsTrue(parse(_T(";;123;456;abcddd;"), root));
			Assert::AreEqual(_T("123;"), root->path);
			Assert::IsTrue(root->next != (path_item*)NULL);
			root = root->next;
			Assert::AreEqual(_T("456;"), root->path);
			root = root->next;
			Assert::AreEqual(_T("abcddd;"), root->path);
			Assert::IsTrue(root->next == (path_item*)NULL);
		

		}
		TEST_METHOD(TestRealPath1)
		{

			path_item* root = (path_item*)malloc(sizeof(path_item));

			Assert::IsTrue(parse(_T("C:\\Python27\\;C:\Python27\\Scripts;C:\\Program Files (x86)\\AMD APP\\bin\\x86_64;C:\\Program Files (x86)\\AMD APP\\bin\\x86;D:\\Program Files\\MATLAB\\R2014b\\polyspace\\bin"), root));
			Assert::AreEqual(_T("C:\\Python27\\;"), root->path);
			Assert::IsTrue(root->next != (path_item*)NULL);
			root = root->next;
			Assert::AreEqual(_T("C:\Python27\\Scripts;"), root->path);
			root = root->next;
			Assert::AreEqual(_T("C:\\Program Files (x86)\\AMD APP\\bin\\x86_64;"), root->path);
			root = root->next;
			Assert::AreEqual(_T("C:\\Program Files (x86)\\AMD APP\\bin\\x86;"), root->path);
			root = root->next;
			Assert::AreEqual(_T("D:\\Program Files\\MATLAB\\R2014b\\polyspace\\bin"), root->path);
			Assert::IsTrue(root->next == (path_item*)NULL);


		}

	};
}