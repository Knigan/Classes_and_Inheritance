#pragma once
#include <iostream>
#include "Array.h"

class String: public Array {
private:
	static int count;
public:
	String () noexcept;
	String (int n, uchar* arr);

	int length ();
	void sum (const Array& x, Array& res) override;
	int search (const String& str) const noexcept;
	String insert (const String& str, int pos) const;
	String del (const String& str) const;

	static int getcount();

	friend std::ostream& operator << (std::ostream& out, const String& str) noexcept;
	friend std::istream& operator >> (std::istream& in, String& str);
};