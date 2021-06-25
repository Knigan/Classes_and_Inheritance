#pragma once
#include <iostream>
#include "Container.h"

class Choise: public Container {
private:
	static int count;
public:
	Choise() noexcept;
	Choise (int n, double* arr);

	void sort() noexcept override;
	void foreach() override;

	static int getcount() noexcept;

	void print() const noexcept override;
	void input() override;
};