#pragma once
#include "Bubble.h"
#include "Choise.h"

class Application {
private:
	Container* A;
	void BubbleTest();
	void ChoiseTest();

public:
	~Application() noexcept {};
	void Run();
};