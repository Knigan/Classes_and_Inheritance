#include "Octal.h"

int Octal::count = 0;

Octal::Octal() noexcept {
	++count;
}

Octal::Octal (int n, uchar* arr) : Array(n, arr) {
	++count;
}

bool Octal::operator == (const Octal& x) {
	if (size != x.size) return false;
	for (int i = 0; i < size; ++i)
		if (arr[i] != x[i]) return false;
	return true;
}

bool Octal::operator != (const Octal& x) {
	if (size != x.size) return true;
	for (int i = 0; i < size; ++i)
		if (arr[i] != x[i]) return true;
	return false;
}

bool Octal::operator < (const Octal& x) {
	if (size < x.size) return true;
	if (size > x.size) return false;
	for (int i = size - 1; i >= 0; --i) {
		if (arr[i] < x[i]) return true;
		if (arr[i] > x[i]) return false;
	}
	return false;
}

bool Octal::operator > (const Octal& x) {
	if (size > x.size) return true;
	if (size < x.size) return false;
	for (int i = size - 1; i >= 0; --i) {
		if (arr[i] > x[i]) return true;
		if (arr[i] < x[i]) return false;
	}
	return false;
}

int transform(const Array& x) noexcept {
	int res = 0, deg = 1;
	for (int i = 0; i < x.getsize(); ++i) {
		char k = x[i] - 48;
		res += static_cast <int> (k) * deg;
		deg *= 8;
	}
	return res;
}

void Octal::sum (const Array& x, Array& res) {
	int num = transform(*this) + transform(x);
	int n = 0, num2 = num;
	while (num2 > 0) {
		num2 /= 8;
		++n;
	}
	if (n > octalmaxsize)
		throw OctalError("The size of the sum is too large");
	res.setsize(n);
	for (int i = 0; i < n; ++i) {
		res[i] = num % 8 + 48;
		num /= 8;
	}
}

Octal Octal::sub(const Octal& x) const {
	if (transform(*this) < transform(x))
		throw OctalError("An attempt to subtract a larger number from a smaller number has been done");
	int num = transform(*this) - transform(x);
	int n = 0, num2 = num;
	while (num2 > 0) {
		num2 /= 8;
		++n;
	}
	Octal res;
	res.size = n;
	for (int i = 0; i < n; ++i) {
		res[i] = num % 8 + 48;
		num /= 8;
	}
	return res;
}

Octal Octal::mul(const Octal& x) const {
	int num = transform(*this) * transform(x);
	int n = 0, num2 = num;
	while (num2 > 0) {
		num2 /= 8;
		++n;
	}
	if (n > octalmaxsize)
		throw OctalError("The size of the product is too large");
	Octal res;
	res.size = n;
	for (int i = 0; i < n; ++i) {
		res[i] = num % 8 + 48;
		num /= 8;
	}
	return res;
}

Octal Octal::div(const Octal& x) const {
	if (transform(x) == 0)
		throw OctalError("An attempt to divide by zero has been done");
	int num = transform(*this) / transform(x);
	int n = 0, num2 = num;
	while (num2 > 0) {
		num2 /= 8;
		++n;
	}
	Octal res;
	res.size = n;
	for (int i = 0; i < n; ++i) {
		res[i] = num % 8 + 48;
		num /= 8;
	}
	return res;
}

int Octal::getcount() {
	return count;
}

std::ostream& operator << (std::ostream& out, const Octal& x) noexcept {
	for (int i = x.size - 1; i >= 0; --i) {
		out << x[i];
	}
	return out;
}

std::istream& operator >> (std::istream& in, Octal& x) {
	int n;
	std::cout << "\nInput the size of the octal number\n";
	in >> n;
	if (n > octalmaxsize)
		throw OctalError("The size of the number is too large");
	x.setsize(n);
	std::cout <<"\nInput the octal number\n";
	for (int i = 0; i < n; ++i) {
		x[i] = '\0';
	}
	for (int i = n - 1; i >= 0; --i) {
		in >> x[i];
	}
	return in;
}