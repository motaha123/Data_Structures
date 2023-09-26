/*
Author : Mhd Taha Daboul
Date : 22/6/2023
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPair(char open, char close) //Function Check if the open perantheses and the close perantheses are equel
{
	if (open=='('&&close==')')
	{
		return true;
	}
	else if (open=='{'&&close=='}')
	{
		return true;
	}
	else if (open=='['&&close==']')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isBalanced(string oper)
{
	stack<char> ob;
	for (size_t i = 0; i < size(oper); i++)
	{
		if (oper[i] == '[' || oper[i] == '{' || oper[i] == '(') {//Passing the open perantheses to our stack
			ob.push(oper[i]);
		}
		else if(oper[i] == ']' || oper[i] == '}' || oper[i] == ')')//if the open peranth has a close one remove it from stack
		{
			if (!ob.empty()&&isPair(ob.top(),oper[i]))
			{
				ob.pop();
			}
			else
			{
				return false;
			}
		}
	
	}
	return ob.empty();//return true if the stack is empty
}


int main()
{
    std::cout << "Hello World!\n";
	cout << "Enter your operation ya habibi: ";
	string str;
	getline(cin, str);
	if (isBalanced(str))
	{
		cout << "Balanced";
	}
	else
	{
		cout <<"Not balaced";
	}
}

