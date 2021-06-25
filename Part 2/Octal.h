#pragma once
#include <iostream>
#include "Array.h"
const int octalmaxsize = 100;

class Octal: public Array {
private:
	friend int transform(const Array& x) noexcept;
	static int count;
public:
	Octal () noexcept;
	Octal (int n, uchar* arr);

	bool operator == (const Octal& x);
	bool operator != (const Octal& x);
	bool operator < (const Octal& x);
	bool operator > (const Octal& x);

	void sum (const Array& x, Array& res) override;
	Octal sub(const Octal& x) const;
	Octal mul(const Octal& x) const;
	Octal div(const Octal& x) const;

	static int getcount();

	friend std::ostream& operator << (std::ostream& out, const Octal& x) noexcept;
	friend std::istream& operator >> (std::istream& in, Octal& x);
};