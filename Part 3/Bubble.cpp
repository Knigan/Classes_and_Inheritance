#include "Bubble.h"

int Bubble::count = 0;

Bubble::Bubble() noexcept {
	++count;
}

Bubble::Bubble (int n, double* arr): Container(n, arr) {
	++count;
}

void Bubble::sort() noexcept {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}
}

void Bubble::foreach() {
	for (int i = 0; i < size; ++i) {
		if (arr[i] < 0)
			throw BubbleError("The array contains negative numbers");
		else arr[i] = sqrt(arr[i]);
	}
}

int Bubble::getcount() noexcept {
	return count;
}

void Bubble::print () const noexcept {
	for (int i = 0; i < size; ++i) 
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void Bubble::input () {
	int n;
	std::cout << "\nInput the size of the array\n";
	std::cin >> n;
	if (n <= 0)
		throw BubbleError("The size of the array must be a positive integer number");
	std::cout << "\nInput the array\n";
	double* array = new double[n];
	for (int i = 0; i < n; ++i)
		std::cin >> array[i];
	Bubble num(n, array);
	*this = num;
}