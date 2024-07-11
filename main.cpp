#include <iostream>
#include <string>
#include "Calculator.h"
#include "Utils.h"

double n1, n2;
char operation;
char validOperations[4] = { '+', '-', '*', '/' };
std::string divider = "------------------------------- \n";

// Calculator state variables
bool running = true;
bool selectingOperation = true;

int main()
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