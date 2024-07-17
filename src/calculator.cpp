#include "Calculator.h"
#include "Utils.h"
#include <iostream>
#include <string>

// Performs the passed operation from the two given numbers
double calculator(double n1, double n2, char operation)
{
	switch (operation) {
	case '+':
		return n1 + n2;
		break;
	case '-':
		return n1 - n2;
		break;
	case '*':
		return n1 * n2;
		break;
	case '/':
		// If the denominator is zero throw an error (dividing by zero error)
		if (n2 <= 0) {
			throw "Division by zero error";
		}
		else {
			return n1 / n2;
		}
		break;
	default:
		throw "Invalid operation, the only valid operations are (+, -, *, /)";
		break;
	}
}

double n1, n2;
char operation;
char validOperations[4] = { '+', '-', '*', '/' };
std::string divider = "------------------------------- \n";

// Calculator loop state variable
bool selectingOperation = true;

int calculatorLoop(bool& running) // Get the reference to the running variable in memory
{
	while (running) {
		std::cout << "Type the first number: ";
		std::cin >> n1;
		std::cout << "Type the second number: ";
		std::cin >> n2;

		// Loop operation selection until a valid choice is made
		while (selectingOperation) {
			std::cout << "Select an operation (+, -, *, /): ";
			std::cin >> operation;

			if (contains(operation, validOperations)) {
				std::cout << "Result: " << calculator(n1, n2, operation) << "\n";
				std::cout << "\n" << divider << "\n";

				// After the result is shown give the user an option to continue using the calculator
				bool continueResult;
				std::cout << "Would you like to continue? (0 = false, 1 = true): ";
				std::cin >> continueResult;
				if (!continueResult) {
					running = false;
				}

				selectingOperation = false; // End the loop once the valid choice is made
			}
			else {
				std::cout << "Enter a valid operation \n";
			}
		}

		// Ensures that the operation selection state occurs on the next calculation
		selectingOperation = true;
	}

	return 0;
}