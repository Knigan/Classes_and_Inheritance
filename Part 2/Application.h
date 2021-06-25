#pragma once
#include "Octal.h"
#include "String.h"

class Application {
private:
	Array* A;
	Array* B;
	Array* res;
	void OctalTest();
	void StringTest();
public:
	~Application() noexcept {};
	void Run();
};