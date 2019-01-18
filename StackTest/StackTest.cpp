
#include "pch.h"
#include <iostream>
#include <string>
#include "Stack.h"
#include <stack>

int main()
{
	Stack<std::string> s;
	Stack<int> i;
	std::cout << i.Top() << " ";

	std::stack<int> ii;
	std::cout << ii.top() << " ";
	//int size = 20;
	//for (int i = 0; i < size; ++i)
	//{
	//	s.Push("hb");
	//}
	//std::cout << s.GetSize() << std::endl;
	//for (int i = 0; i < size; ++i)
	//{				
	//	std::cout << s.Top() << " ";
	//	s.Pop();
	//}
	
	return 0;
}
