#include <iostream>

// Determines if the given value in contained inside the array
template <typename T, size_t N>
bool contains(const T& val, const T(&arr)[N])
{
	// std::find attempts to get the first iterator pointing to val; otherwise it stops at the end of the array
	// If it stops at the end of the array val is not part of the array; otherwise it is
	return std::find(std::begin(arr), std::end(arr), val) != std::end(arr);
}