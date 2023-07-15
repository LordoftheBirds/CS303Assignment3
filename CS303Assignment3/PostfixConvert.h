#ifndef POSTFIXCONVERT_H_
#define POSTFIXCONVERT_H_
#include <stack>
#include <string>

using namespace std;

class PostfixConvert {
private:
	stack<char> expressionChars;
	
	/*
	* Helper function used in determining operator priority for use in postfix conversion.
	* Returns value 1 for + and -, 2 for *, /, %, and 0 for brackets.
	*/
	int priority(char a);

	/*
	* Helper function to see if current char is a leading bracket.
	* Helps with code legibility.
	*/
	bool isLeadingBracket(char a) const;
public:
	/*
	* A function which determines whether a not a user expression has balanced brackets.
	* 
	* @param infix - An expression entered by the user in infix notation.
	* @return True if brackets are balanced, false otherwise.
	*/
	//Possilbly could put in private section, only called indirectly.
	bool balancedBracketsCheck(string infix);

	/*
	* Converts an infix expression with balanced brackets to postfix notation.
	* 
	* @param infix an expression in infix notation
	* @return a string that shows the original function in postfix notation.
	*/
	string infixToPostfix(string infix);
};

#endif // !POSTFIXCONVERT_H_

