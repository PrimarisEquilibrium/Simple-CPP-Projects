#pragma once
#include <iostream>
#include <string>
#include <vector>

// Holds all the user entries on their todo list
// A vector is used for its dynamic size (users may add an arbitrary amount of values)
std::vector<std::string> todoEntries;

static void displayEntries(std::vector<std::string> entries) {
	for (int i = 0; i < entries.size(); i++) {
		std::cout << i + 1 << ". " << entries[i];
	}
	std::cout << "\n";
}

void todoLoop(bool& running) {
	todoEntries.push_back("Wash the dishes \n");
	todoEntries.push_back("Brush my teeth \n");

	int userInput;
	std::cout << "Enter: \n 1. View TODO list \n 2. Add TODO list entry \n 3. Delete TODO list entry \n 4. Save to .txt file \n 9. Exit program \n";
	std::cout << "Select an option: ";
	std::cin >> userInput;
	std::cout << "\n";
	switch (userInput) {
	case 1:
		// Display all entries in the todo list
		displayEntries(todoEntries);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 9:
		running = false;
	}
}