#pragma once
#include <iostream>
#include "Container.h"

class Bubble: public Container {
private:
	static int count;
public:
	Bubble () noexcept;
	Bubble (int n, double* arr);
	void sort() noexcept override;
	void foreach() override; 

	static int getcount() noexcept;

	void print() const noexcept override;
	void input() override;
};