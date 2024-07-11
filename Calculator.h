#pragma once
#include <iostream>

// Performs the passed operation from the two given numbers
double calculate(double n1, double n2, char operation)
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
			throw "Invalid operation";
			break;
	}
}