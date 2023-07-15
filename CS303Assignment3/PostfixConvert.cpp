#include "PostfixConvert.h"
#include <iostream>

bool PostfixConvert::balancedBracketsCheck(string infix) {
	bool isBalanced = true;
	
	for (int i = 0; i < infix.length(); i++) {
		char curChar = infix.at(i);
		if ((curChar == '{') ||
			(curChar == '(') ||
			(curChar == '['))
		{
			expressionChars.push(curChar);
		}
		
		//Switch might be better here
		//Check if empty before these checks
		if (infix.at(i) == '}')
		{
			if (!expressionChars.empty() && expressionChars.top() == '{') {
				expressionChars.pop();
			}
			else {
				isBalanced = false;
			}
		}
		if (infix.at(i) == ')')
		{
			if (!expressionChars.empty() && expressionChars.top() == '(') {
				expressionChars.pop();
			}
			else {
				isBalanced = false;
			}
		}
		if (infix.at(i) == ']')
		{
			if (!expressionChars.empty() && expressionChars.top() == '[') {
				expressionChars.pop();
			}
			else {
				isBalanced = false;
			}
		}

		if (!isBalanced) {
			break;
		}
	}

	//Cout statements used for debugging for debugging
	if (isBalanced && expressionChars.empty()) {
		cout << "The brackets in your expression are balanced!" << endl;
		return true;
	}
	else {
		//cout << "The brackets in your expression are not balanced." << endl;
		//cout << "isBalanced Check: " << isBalanced << " (0 is not balanced, 1 is)" << endl;
		//cout << "Empty Stack Check: " << brackets.empty() << "(1 is empty, 0 is not empty.)" << endl;
		
		return false;
	}
}

string PostfixConvert::infixToPostfix(string infix) {
	if (balancedBracketsCheck(infix)) {
		string postfixResult;

		//Empty stack after bracket check
		while (!expressionChars.empty()) {
			expressionChars.pop();
		}

		for (int i = 0; i < infix.length(); i++) {
			
			char currentChar = infix[i];

			// If the scanned character is an operand, add it to output string.
			if ((currentChar >= 'a' && currentChar <= 'z')
				|| (currentChar >= 'A' && currentChar <= 'Z')
				|| (currentChar >= '0' && currentChar <= '9')) {
				postfixResult += currentChar;
			}

			// If the scanned character is a bracket, push it to the stack.
			else if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
				expressionChars.push(currentChar);
			}

			// If the scanned character is a bracket, pop and add to output string from the stack
			// until a bracket is encountered.
			else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
				while (!expressionChars.empty() 
					&& (expressionChars.top() != '(' || expressionChars.top() != '[' || expressionChars.top() != '{')) {
					postfixResult += expressionChars.top();
					expressionChars.pop();
				}
				expressionChars.pop();
			}

			// If an operator is scanned
			else if ((currentChar == '+') 
				|| (currentChar == '-')
				|| (currentChar == '*')
				|| (currentChar == '/')
				|| (currentChar == '%')){


				while (!expressionChars.empty()
					&& (priority(infix.at(i)) <= priority(expressionChars.top()))) {
					postfixResult += expressionChars.top();
					expressionChars.pop();
				}
				expressionChars.push(currentChar);
			}
		}

		// Pop all the remaining elements from the stack
		while (!expressionChars.empty()) {
			postfixResult += expressionChars.top();
			expressionChars.pop();
		}
		return postfixResult;
	}

	return "Brackets not balanced. Cannot convert to postfix.";
}

int PostfixConvert::priority(char a) {
	if (a == '+' || a == '-') {
		return 1;
	}
	else {
		return 2;
	}
}