#include "Container.h"

int Container::Contcount = 0;

Container::Container() noexcept: size(0), arr(nullptr) {
	++Contcount;
}

Container::Container(int n, double* arr): size(n) {
	if (n <= 0)
		throw ContainerError("The size of the array must be a positive integer number");
	this->arr = new double[n];
	for (int i = 0; i < n; ++i)
		this->arr[i] = arr[i];
	++Contcount;
}

Container::Container(const Container& x) noexcept: size(x.size) {
	arr = new double[size];
	for (int i = 0; i < size; ++i)
		arr[i] = x[i];
	++Contcount;
}

Container::~Container() noexcept {
	delete[] arr;
}

Container& Container::operator = (const Container& x) noexcept {
	if (this == &x)
		return *this;
	size = x.size;
	delete[] arr;
	arr = new double[size];
	for (int i = 0; i < size; ++i)
		arr[i] = x.arr[i];
	return *this;
}
double& Container::operator [] (int i) {
	if (i < 0 || i >= size)
		throw ContainerError("The index of the array is incorrect");
}

const double& Container::operator [] (int i) const {
	if (i < 0 || i >= size)
		throw ContainerError("The index of the array is incorrect");
}

int Container::getcount() noexcept {
	return Contcount;
}