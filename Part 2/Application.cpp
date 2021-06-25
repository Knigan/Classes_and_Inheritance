#include "Application.h"

Application::~Application() {}

void Application::OctalTest() {
	res = new Octal;
	A = new Octal;
	B = new Octal;
	Octal* a = dynamic_cast <Octal*> (A);
	if (a == nullptr)
		throw CastError("Type Array cannot be cast to type Octal");
	std::cin >> *a;
	std::cout << "A = " << *a << std::endl;
	
	Octal* b = dynamic_cast <Octal*> (B);
	if (b == nullptr)
		throw CastError("Type Array cannot be cast to type Octal");
	std::cin >> *b;
	std::cout << "B = " << *b << std::endl;

	static bool check = true;
	do {
		short key;
		std::cout << "\n---------------------------- Octal Test menu ----------------------------\n";
		std::cout << " 1: generate new numbers\n 2: sum\n 3: subtract\n 4: multiple\n 5: divide\n 6: check equal\n 7: check not equal\n 8: check greater\n 9: check less\n 10: check Array's count\n 11: check Octal's count\n 12: clear screen\n 13: exit\n";
		std::cin >> key;
		switch (key) {
			case 1: OctalTest(); break;
			case 2: A->sum(*B,*res); std::cout << "A + B = " << *dynamic_cast <Octal*> (res) << std::endl; break;
			case 3: std::cout << "A - B = " << a->sub(*b) << std::endl; break;
			case 4: std::cout << "A * B = " << a->mul(*b) << std::endl; break;
			case 5: std::cout << "A / B = " << a->div(*b) << std::endl; break;
			case 6: std::cout << "A == B? Answer: " << static_cast <bool> (*a == *b) << std::endl; break;
			case 7: std::cout << "A != B? Answer: " << static_cast <bool> (*a != *b) << std::endl; break;
			case 8: std::cout << "A > B? Answer: " << static_cast <bool> (*a > *b) << std::endl; break;
			case 9:	std::cout << "A < B? Answer: " << static_cast <bool> (*a < *b) << std::endl; break;
			case 10: std::cout << "Array's count is equal to " << Array::getcount() << std::endl; break;
			case 11: std::cout << "Octal's count is equal to " << Octal::getcount() << std::endl; break;
			case 12: system("cls"); break;
			case 13: check = false; break;
			default: std::cout << "Error! Entered key doesn't exist!\n";
		}
	} while (check);
	delete res;
	delete A;
	delete B;
}

void Application::StringTest() {
	res = new String;
	A = new String;
	B = new String;
	String* a = dynamic_cast <String*> (A);
	if (a == nullptr)
		throw CastError("Type Array cannot be cast to type String");
	std::cin >> *a;
	std::cout << "A: " << *a << std::endl;

	String* b = dynamic_cast <String*> (B);
	if (b == nullptr)
		throw CastError("Type Array cannot be cast to type String");
	std::cin >> *b;
	std::cout << "B: " << *b << std::endl;

	static bool check = true;
	do {
		short key;
		std::cout << "\n---------------------------- String Test menu ----------------------------\n";
		std::cout << " 1: generate new strings\n 2: sum\n 3: length\n 4: search\n 5: insert\n 6: delete\n 7: check Array's count\n 8: check String's count\n 9: clear screen\n 10: exit\n";
		std::cin >> key;
		switch (key) {
			case 1: StringTest(); break;
			case 2: A->sum(*B, *res); std::cout << "A + B = " << *dynamic_cast <String*> (res) << std::endl; break;
			case 3: std::cout << "Length of A = " << a->length() << "\nLength of B = " << b->length() << std::endl; break;
			case 4: std::cout << "A.search(B) = " << a->search(*b) << std::endl; break;
			case 5: std::cout << "A.insert(B, A.search(B)) = " << a->insert(*b, a->search(*b)) << std::endl; break;
			case 6: std::cout << "A.insert(B, A.search(B)).del(B) = " << a->insert(*b, a->search(*b)).del(*b) << std::endl; break;
			case 7: std::cout << "Array's count is equal to " << Array::getcount() << std::endl; break;
			case 8: std::cout << "String's count is equal to " << String::getcount() << std::endl; break;
			case 9: system("cls"); break;
			case 10: check = false; break;
			default: std::cout << "Error! Entered key doesn't exist!\n"; break;
		}
	} while (check);
	delete res;
	delete A;
	delete B;
}

void Application::Run() {
	try {
		OctalTest();
		system("pause");
		StringTest();
	}
	catch (std::exception& error) {
		std::cout << error.what() << std::endl;
	}
	system("pause");
}