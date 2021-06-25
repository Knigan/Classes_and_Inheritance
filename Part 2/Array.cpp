#include "Array.h"

int Array::Arraycount = 0;

Array::Array() noexcept : size(0) {
	arr = new uchar[maxsize];
	for (int i = 0; i < maxsize; ++i)
		arr[i] = '\0';
	++Arraycount;
}

Array::Array(int n, uchar* arr): Array() {
	if (n < 0)
		throw ArrayError("The size of the array must be a positive integer number");
	if (n > maxsize)
		throw ArrayError("The size of the array is too large");
	size = n;
	for (int i = 0; i < size; ++i)
		this->arr[i] = arr[i];
}

Array::Array(const Array& x) noexcept {
	size = x.size;
	arr = new uchar[size];
	for (int i = 0; i < size; ++i)
		arr[i] = x.arr[i];
	++Arraycount;
}

Array::~Array() noexcept {
	delete[] arr;
}

Array& Array::operator = (const Array& x) noexcept {
	if (this == &x)
		return *this;
	size = x.size;
	for (int i = 0; i < size; ++i)
		arr[i] = x.arr[i];
	return *this;
}


uchar& Array::operator [] (int i) {
	if (i < 0 || i >= size) throw ArrayError("The index of the array is incorrect");
	return arr[i];
}

const uchar& Array::operator [] (int i) const {
	if (i < 0 || i >= size) throw ArrayError("The index of the array is incorrect");
	return arr[i];
}

void Array::sum(const Array& x, Array& res) {
	res.size = max(size, x.size);
	for (int i = 0; i < max(size, x.size); ++i)
		res[i] = arr[i] + x[i];
}

int Array::getsize() const noexcept {
	return size;
}

void Array::setsize(int n) {
	if (n < 0)
		throw ArrayError("The size of the array must be a positive integer number");
	if (n > maxsize)
		throw ArrayError("The size of the array is too large");
	size = n;
}

int Array::getcount() {
	return Arraycount;
}