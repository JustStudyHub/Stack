#include "stdafx.h"
#include "CppUnitTest.h"
#include "Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackUnitTest
{		
	TEST_CLASS(TestPush)
	{
	public:
		
		TEST_METHOD(TestPushInt)
		{
			Stack<int> testStack;
			int size = 10000;
			try
			{
				for (int i = 0; i < size; ++i)
				{
					testStack.Push(i);
				}
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(TestPushChar)
		{
			Stack<char> testStack;
			int size = 10000;
			try
			{
				for (int i = 0; i < size; ++i)
				{
					testStack.Push(i);
				}
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(TestPushString)
		{
			Stack<std::string> testStack;
			std::string tempStr = "";
			int size = 100;
			try
			{
				for (int i = 1; i < size; ++i)
				{
					for (int j = 0; j < i; ++j)
					{
						tempStr += i * j;
					}
					testStack.Push(tempStr);
				}
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};

	TEST_CLASS(TestPop)
	{
	public:

		TEST_METHOD(TestPopInt)
		{
			Stack<int> testStack;
			int size = 10000;
			for (int i = 0; i < size; ++i)
			{
				testStack.Push(i);
			}
			try
			{
				for (int i = 0; i < size; ++i)
				{
					testStack.Pop();
				}
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(TestPopChar)
		{
			Stack<char> testStack;
			int size = 10000;
			for (int i = 0; i < size; ++i)
			{
				testStack.Push(i);
			}
			try
			{
				for (int i = 0; i < size; ++i)
				{
					testStack.Pop();
				}
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(TestPopString)
		{
			Stack<std::string> testStack;
			std::string tempStr = "";
			int size = 100;
			for (int i = 1; i < size; ++i)
			{
				for (int j = 0; j < i; ++j)
				{
					tempStr += i * j;
				}
				testStack.Push(tempStr);
			}
			try
			{
				for (int i = 1; i < size; ++i)
				{
					testStack.Pop();
				}
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};

	TEST_CLASS(TestEmpty)
	{
	public:
		TEST_METHOD(TestEmptyIntTrue)
		{
			Stack<int> testStack;
			try
			{
				Assert::IsTrue(testStack.Empty());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(TestEmptyIntFalse)
		{
			Stack<int> testStack;
			int size = 10000;
			for (int i = 0; i < size; ++i)
			{
				testStack.Push(i);
			}
			try
			{
				Assert::IsFalse(testStack.Empty());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		
		TEST_METHOD(TestEmptyStringTrue)
		{
			Stack<std::string> testStack;
			try
			{
				Assert::IsTrue(testStack.Empty());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(TestEmptyStringFalse)
		{
			Stack<std::string> testStack;
			std::string tempStr = "";
			int size = 100;
			for (int i = 1; i < size; ++i)
			{
				for (int j = 0; j < i; ++j)
				{
					tempStr += i * j;
				}
				testStack.Push(tempStr);
			}
			try
			{
				Assert::IsFalse(testStack.Empty());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};

	TEST_CLASS(TestGetSize)
	{
	public:

		TEST_METHOD(TestGetSizeInt)
		{
			Stack<int> testStack;
			int size = 10000;
			for (int i = 0; i < size; ++i)
			{
				testStack.Push(i);
			}
			try
			{
				Assert::AreEqual(size, testStack.GetSize());
				for (int i = 0; i < size; ++i)
				{
					testStack.Pop();
				}
				Assert::AreEqual(0, testStack.GetSize());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		
		TEST_METHOD(TestGetSizeString)
		{
			Stack<std::string> testStack;
			std::string tempStr = "";
			int size = 100;
			for (int i = 0; i < size; ++i)
			{
				for (int j = 0; j < i; ++j)
				{
					tempStr += i * j;
				}
				testStack.Push(tempStr);
			}
			try
			{
				Assert::AreEqual(size, testStack.GetSize());

				for (int i = 0; i < size; ++i)
				{
					testStack.Pop();
				}
				Assert::AreEqual(0, testStack.GetSize());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};

	TEST_CLASS(TestTop)
	{
	public:

		TEST_METHOD(TestTopInt)
		{
			Stack<int> testStack;
			int size = 10000;
			try
			{
				Assert::IsNull(testStack.Top());
				for (int i = 0; i < size; ++i)
				{
					testStack.Push(i);
					Assert::AreEqual(i, *testStack.Top());
				}
			}			
			catch (...)
			{
				Assert::Fail();
			}
		}


		TEST_METHOD(TestTopString)
		{
			Stack<std::string> testStack;
			std::string tempStr = "";
			int size = 100;
			try
			{
				Assert::IsNull(testStack.Top());
				for (int i = 1; i < size; ++i)
				{
					for (int j = 0; j < i; ++j)
					{
						tempStr += i * j;
					}
					testStack.Push(tempStr);
					Assert::AreEqual(tempStr, *testStack.Top());
				}
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}