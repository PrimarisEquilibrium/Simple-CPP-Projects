#include <iostream>
#include <string>
#include "Calculator.h"

bool running = true;

int main()
{	
	while (running) {
		calculatorLoop(running);
	}
}