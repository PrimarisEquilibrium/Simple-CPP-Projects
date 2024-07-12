#include "Calculator.h"
#include "Todo.h"

bool running = true;

int main()
{	
	while (running) {
		todoLoop(running);
		// calculatorLoop(running);
	}
}