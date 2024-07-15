#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Determines if the given value in contained inside the array
template <typename T, size_t N>
bool contains(const T& val, const T(&arr)[N]) {
	// std::find attempts to get the first iterator pointing to val; otherwise it stops at the end of the array
	// If it stops at the end of the array val is not part of the array; otherwise it is
	return std::find(std::begin(arr), std::end(arr), val) != std::end(arr);
}

/**
 * @brief Iterates over the vector and writes its contents to the given directory.
 * @param v   a vector.
 * @param dir a valid directory.
 */
template <typename T>
void writeToFile(const std::vector<T>& v, const std::string& dir) {
	std::ofstream file(dir);

	if (file.is_open()) {
		for (int i = 0; i < v.size(); i++) {
			file << i + 1 << ". " << v[i] << "\n";
		}
		file.close();
		std::cout << "Successfully wrote to the .txt file\n";
	}
	else {
		std::cerr << "Error opening file\n";
	}
}


/**
 * @brief Deletes a value in a vector based on the given index
 * @param v        a vector
 * @param position the position of the element to delete
 */
template <typename T> // Template to allow for any type of vector to be passed into the function
void deleteAtPosition(std::vector<T>& v, int position) {
	if (position < v.size()) {
		v.erase(v.begin() + position);
	}
	else {
		std::cerr << "Error: position out of range\n";
	}
}