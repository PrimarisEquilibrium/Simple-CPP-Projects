#include <iostream>
#include "Calculator.h"

double n1, n2;
char operation;
char validOperations[4] = { '+', '-', '*', '/' };

// Determines if the given value in contained inside the array
template <typename T, size_t N>
bool contains(const T &val, const T (&arr)[N])
{
	// std::find attempts to get the first iterator pointing to val; otherwise it stops at the end of the array
	// If it stops at the end of the array val is not part of the array; otherwise it is
	return std::find(std::begin(arr), std::end(arr), val) != std::end(arr);
}

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
				selectingOperation = false; // End the loop once the valid choice is made
			}
			else {
				std::cout << "Enter a valid operation \n";
			}
		}
	}

    return 0;
}