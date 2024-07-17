#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*
 * This is a header-only utility function file as many of these tasks require creating a
 * template function. Template functions require both declaration and implementation
 * details. Using forward declarations means that the function implementation is hidden
 * and will result in a linker error as template functions are not able to be compiled.
 */

/**
 * @brief Determines if the given value in contained inside the array.
 * @param val the value to look for in the array.
 * @param arr the search array.
 * @return A boolean determining if the val is found in arr.
 */
template <typename T, size_t N>
inline bool contains(const T& val, const T(&arr)[N]) {
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
inline void writeToFile(const std::vector<T>& v, const std::string& dir) {
	std::ofstream file(dir.c_str());

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