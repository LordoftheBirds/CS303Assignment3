//#include "Queue.hpp"
#include "PostfixConvert.h"
#include <iostream>
#include <string>

using namespace std;


int main() {
	/*Queue<string> theQueue;
	int userChoice;
	string userString;


	do {
		cout << endl << "Please select an option: " << endl
			<< "1. Add an item to the queue" << endl
			<< "2. Remove the front item from the queue." << endl
			<< "3. View the item at the front of the queue." << endl
			<< "4. See how many items are currently in the queue." << endl
			<< "5. Check if the queue is empty." << endl
			<< "6. Quit." << endl << endl;

		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			cout << "Type a string to add to the queue: " << endl;

			cin >> userString;

			theQueue.push(userString);

			break;

		case 2:
			cout << "The item you removed from the queue is: ";
			cout << theQueue.pop();
			cout << endl;
			break;

		case 3:
			cout << "The item at the front of the queue is: ";
			cout << theQueue.peek();
			cout << endl;
			break;

		case 4:
			cout << "There are currently " << theQueue.queueSize() << " items in the queue." << endl;
			break;

		case 5:
			cout << "Queue status (1 - Empty | 0 - Not empty): ";
			cout << theQueue.isEmpty();
			cout << endl;
			break;

		case 6: 
			cout << "Thank you for using! Goodbye." << endl;
			break;

		default:
			cout << "Please enter a valid number." << endl;
			break;
		}
	} while (userChoice != 6);*/

	//Start of Postfix Conversion and Balanced Brackets Check

	PostfixConvert expressionA;
	string userExpression;

	cout << endl << "Please enter a mathematical expression in infix notation:" << endl;
	getline(cin, userExpression);

	cout << expressionA.infixToPostfix(userExpression);
	
	
	return 0;
}

