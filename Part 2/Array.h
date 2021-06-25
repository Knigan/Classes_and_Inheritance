#pragma once
#include "Exception.h"
#define max(a, b) ((a > b) ? a : b)
using uchar = unsigned char;
const int maxsize = 255;

class Array {
private:
	static int Arraycount;
protected:
	int size;
	uchar* arr;
public:
	Array () noexcept;
	Array (int n, uchar* arr);
	Array (const Array& x) noexcept;
	virtual ~Array () noexcept;
	uchar& operator [] (int i);
	const uchar& operator [] (int i) const;
	Array& operator = (const Array& x) noexcept;
	virtual void sum (const Array& x, Array& res);
	int getsize() const noexcept;
	void setsize(int n);
	static int getcount();
};  