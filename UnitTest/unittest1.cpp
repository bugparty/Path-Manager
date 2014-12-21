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

	};
}