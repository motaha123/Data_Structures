/*
Author : Mhd Taha Daboul
Date : 23/6/2023
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char oper)//Checking if the chara is operator
{
    return (oper == '+' || oper == '*' || oper == '/' || oper == '-');
}

bool isAlphaOrNumber(char chara)//Checking if the char is number or varible
{
	if (chara>='a'&&chara<='z'|| chara >= 'A' && chara <= 'Z' || chara >= '0' && chara <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int powerOfOperator(char oper)//operator powering
{
	int power=4;
	if (oper=='+'||oper=='-')
	{
		power = 1;
	}
	else if (oper=='*'||oper=='/')
	{
		power = 2;
	}
	return power;
}

bool hightestPower(int oper1, int oper2)//comparing between two operator
{
	if (powerOfOperator(oper1)>powerOfOperator(oper2))
	{
		return true;
	}
	else if (powerOfOperator(oper1) > powerOfOperator(oper2))
	{
		return false;
	}
	else if(powerOfOperator(oper1)==powerOfOperator(oper2))
	{
		return false;
	}
}

string infixToPostfix(string operation)//main function
{
	stack<char> s;
	string postfix;
	for (size_t i = 0; i < size(operation); i++)
	{
		if (isAlphaOrNumber(operation[i]))//if the chara is number or varible but it in our string
		{
			postfix += operation[i];
		}
		else if (isOperator(operation[i]))
		{
			if (s.empty()) {//if there is no element in our stack put the operator in it
				s.push(operation[i]);
			}
			else if (!s.empty()&&s.top()!='(')//if there and not equel '(' compare it with our operator
			{
				if (hightestPower(powerOfOperator(operation[i]),powerOfOperator(s.top())))
				{
					s.push(operation[i]);
				}
				else
				{
					postfix += s.top();
					s.pop();
					s.push(operation[i]);
				}
			}
			else if (s.top()=='(')
			{
				s.push(operation[i]);
			}
		}
		else if (operation[i]=='(')
		{
			s.push(operation[i]);
		}
		else if (operation[i]==')')
		{
			while (s.top() != '(') {//adding all element to our string until you see '('
				postfix += s.top();
				s.pop();
			}
			s.pop();//remove '(' from stack
		}

	}
	while (!s.empty())//Add all stack element to our element
	{
		postfix += s.top();
		s.pop();
	}
	return postfix;
}

int main()
{
    std::cout << "Hello World!\n";
	string infix,postfix;
	cout << "Enter your operation please: ";
	getline(cin, infix);
	postfix = infixToPostfix(infix);
	cout << postfix;
}

