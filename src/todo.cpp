#include "Utils.h"
#include "Todo.h"
#include <iostream>
#include <string>
#include <vector>
#include <format>

// Type alias of a string vector
typedef std::vector<std::string> strVector;

// Holds all the user entries on their todo list
// A vector is used for its dynamic size (users may add an arbitrary amount of values)
strVector todoEntries;

/**
 * @brief Outputs the current todo entries in an ordered list.
 * @param entries a string vector containing todo entries.
 */
static void displayEntries(strVector entries) {
	for (int i = 0; i < entries.size(); i++) {
		std::cout << i + 1 << ". " << entries[i] << "\n";
	}
}

/**
 * @brief Pushes a user obtained string to a todo entry string vector.
 * @param entries a string vector containing todo entries.
 */
void addEntry(strVector& entries) {
	std::string newEntry{};
	std::cout << "Enter TODO entry: ";

	// Ensures that the entire string is extracted and assigned to newEntry (doesn't stop extracting at whitespace)
	std::cin.ignore();
	std::getline(std::cin, newEntry);

	entries.push_back(newEntry);
}

/**
 * @brief Deletes a value in the todo entry at the (one-based) index the user provides.
 * @param entries a string vector containing todo entries.
 */
void deleteEntry(strVector& entries) {
	int position{};
	std::cout << "Enter the position of entry to delete: ";
	std::cin >> position;

	// Deletes the entry at index position - 1 (as entries are listed starting at 1, not 0)
	deleteAtPosition(entries, position - 1);
}

/* Main todo list logic loop */
void todoLoop(bool& running) {
	int userInput{};
	std::cout << "Enter:\n 1. View TODO list\n 2. Add TODO list entry\n 3. Delete TODO list entry\n 4. Save to .txt file\n 9. Exit program \n";
	std::cout << "Select an option: ";
	std::cin >> userInput;

	switch (userInput) {
	case 1:
		// Display all entries in the todo list
		displayEntries(todoEntries);
		break;
	case 2:
		// Adds an entry to the todo list
		addEntry(todoEntries);
		break;
	case 3:
		// Deletes an entry in the todo list
		deleteEntry(todoEntries);
		break;
	case 4:
		// Writes the current todo list contents to a .txt file
		writeToFile(todoEntries, "myfile.txt");
		break;
	case 9:
		running = false;
	}
}