#include <iostream>
#include "Calculator.h"

double n1, n2;
char operation;

int main()
{
    std::cout << "Type the first number: ";
    std::cin >> n1;
    std::cout << "Type the second number: ";
    std::cin >> n2;
    std::cout << "Select an operation (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "Result: " << calculator(n1, n2, operation);
    return 0;
}