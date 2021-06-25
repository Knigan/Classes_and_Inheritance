#include "Choise.h"

int Choise::count = 0; 

//!!! Замечания аналогичны Bubble 


Choise::Choise() noexcept {
	++count;
}

Choise::Choise(int n, double* arr): Container(n, arr) {
	++count;
}

void Choise::sort() noexcept {
	for (int i = 0; i < size; ++i) {
		int imin = i;
		for (int j = i + 1; j < size; ++j) {
			if (arr[j] < arr[imin])
				imin = j;
		}
		std::swap(arr[i], arr[imin]);
	}
}

void Choise::foreach() {
	for (int i = 0; i < size; ++i) {
		if (arr[i] <= 0)
			throw ChoiseError("The array contains non-positive numbers");
		else arr[i] = log(arr[i]);
	}
}

int Choise::getcount() noexcept {
	return count;
}

void Choise::print () const noexcept {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void Choise::input () {
	int n;
	std::cout << "\nInput the size of the array\n";
	std::cin >> n;
	if (n <= 0)
		throw ChoiseError("The size of the array must be a positive integer number");
	std::cout << "\nInput the array\n";
	double* array = new double[n];
	for (int i = 0; i < n; ++i)
		std::cin >> array[i];
	Choise num(n, array);
	*this = num;
}