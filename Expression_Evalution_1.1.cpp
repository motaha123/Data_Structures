/*
Author : Mhd Taha Daboul
Date : 22/6/2023
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_operator(char operation)//Checking the operator
{
	return (operation == '*' || operation == '/' || operation == '+' || operation == '-');
}

template <class T>
T operation(T num1, T num2, char oper)//Doing the operation
{
	T ans;
	switch (oper) {
	case '+':
		ans = num1 + num2;
		break;
	case '-':
		ans = num1 - num2;
		break;
	case '*':
		ans = num1* num2;
		break;
	case '/':
		ans = num1 / num2;
		break;
	}
	return ans;
}


int getResult(string exp)
{
	int number1, number2,result;
	stack<int> s;
	for (size_t i = 0; i < size(exp); i++)
	{
		number1 = 0;
		number2 = 0;
		result = 0;
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			number1 = int(exp[i])-48;//convert the number to intger 
			s.push(number1);//move it to the stack
			number1 = 0;
		}
		else if (is_operator(exp[i]))
		{
			number2 = s.top();//get the last number = in operation number2
			s.pop();//delete it
			number1 = s.top();//get the last number after we delete the last one
			s.pop();
			result=operation(number1, number2, exp[i]);
			s.push(result);//push the result to ehier enter in a new operation or to be the last result
		}
	}
	return result;
}

int main()
{
    std::cout << "Hello World!\n";
	string expression;
	cout << "Enter your expression: ";
	getline(cin, expression);
	cout << getResult(expression);
}
