#pragma once
#include "Exception.h"

class Container {
private:
	static int Contcount;
protected:
	int size;
	double* arr;
public:
	Container() noexcept;
	Container (int n, double* arr);
	Container (const Container& x) noexcept;
	virtual ~Container() noexcept;

	Container& operator = (const Container& x) noexcept;
	double& operator [] (int i);
	const double& operator [] (int i) const;
	virtual void sort() noexcept = 0;
	virtual void foreach() = 0;
	static int getcount() noexcept;

	virtual void print() const noexcept = 0;
	virtual void input() = 0;
};