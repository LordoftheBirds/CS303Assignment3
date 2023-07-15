#ifndef POSTFIXCONVERT_H_
#define POSTFIXCONVERT_H_
#include <stack>
#include <string>

using namespace std;

class PostfixConvert {
private:
	stack<char> expressionChars;
	int priority(char a);
public:
	bool balancedBracketsCheck(string infix);
	string infixToPostfix(string infix);
};

#endif // !POSTFIXCONVERT_H_

