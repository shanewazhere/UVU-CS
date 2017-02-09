

//Stack - infix to postfix - 02/2/2017
//Max Nelson
//Section 002
//calc.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

#include <iostream>
#include <strstream>
#include <fstream>
#include <string>
#include "stack.h"

using namespace std;
using namespace custom_stack;

int hasHighPrecedence(char op1, char op2);
void infixToPostfix(string expr);

int main()
{	
	//get the file contents
	ifstream infixFile;
	infixFile.open("tests.txt");

	//check if file was opened 
	if (infixFile.fail()) {
		std::cout << "Error opening file..." << std::endl;
	}
	//check if end of file
	while (infixFile.good())
	{
		//if not, get the next test case
		string exp;
		getline(infixFile, exp);
		cout << "Infix: " << exp << endl;
		//cout << "Postfix: "<< infixToPostfix(exp) << endl << endl;
		infixToPostfix(exp);
	}
	system("PAUSE");
}



//convert infix to postfix
//params: string expression; the expression read from a line in the file
void infixToPostfix(string expr)
{
	stack<char> s;
	string result = "";
	cout << "Postfix: ";
	for (unsigned i = 0; i < expr.size(); i++)
	{
		//grab first char
		const char NEXT = expr[i];

		if (NEXT == '(')
		{
			//read left parenthesis and push it onto the stack
			//cout << NEXT;
			s.push(NEXT);
		}
		else if ((NEXT >= '0' && NEXT <= '9') || (NEXT >= 'A' && NEXT <= 'Z') || (NEXT >= 'a' && NEXT <= 'z'))
		{
			//if its a number
			//read the operand and write it to the output
			cout << NEXT;
			
		}
		else if ((NEXT == '+' || NEXT == '-' || NEXT == '*' || NEXT == '/'))
		{
			//if it is an operator
			//read the operand and write it to the output
			if (!s.empty() && hasHighPrecedence(s.top(), NEXT && s.top() != '('))
			{
				//stack not empty, next has higher precedence, next symbol aint (
				cout << s.top();
				s.pop();
				//get rid of the operator it has been printed

			}
			//push operator on stack
			s.push(NEXT);
		}
		else {
			//read and sicared the next input symbol. should be a parenthases
			//print the top operation and pop it; keep printing and poping 
			//until the next symbol on the stack is a left parenthesis
			while (s.top() != '(' && !s.empty()) {
				cout << s.top();
				s.pop();
			} 
			//remove
			s.pop();
		}
	}
	while (!s.empty())
	{
		//print the rest
		cout << s.top();
		s.pop();
	}
	//mm some line spacing would b nice
	cout << endl << endl;
}



//weight
//params: char op. operator 
int opWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
		weight = 1;
	case '-':
		weight = 1;
	case '*':
		weight = 2;
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

//check precedence
//params: char op1, char op2
int hasHighPrecedence(char op1, char op2)
{
	int one = opWeight(op1);
	int two = opWeight(op2);
	return one > two ? true : false;
}





