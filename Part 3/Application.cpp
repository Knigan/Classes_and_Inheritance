#include "Application.h"

void Application::BubbleTest() {
	A = new Bubble;
	A->input();
	std::cout << "A = ";
	A->print();

	static bool b = true;
	do {
		short key;
		std::cout << "\n---------------------------- Bubble Test menu ----------------------------\n";
		std::cout << " 1: generate a new array\n 2: sort\n 3: foreach\n 4: check Container's count\n 5: check Bubble's count\n 6: clear screen\n 7: exit\n";
		std::cin >> key;
		switch (key) {
			case 1: BubbleTest(); break;
			case 2: A->sort(); std::cout << "sort(A) = "; A->print(); break;
			case 3: A->foreach(); std::cout << "foreach(A) = "; A->print(); break;
			case 4: std::cout << "Container's count is equal to " << Container::getcount() << std::endl; break;
			case 5: std::cout << "Bubble's count is equal to " << Bubble::getcount() << std::endl; break;
			case 6: system("cls"); break;
			case 7: b = false; break;
			default: std::cout << "Error! Entered key doesn't exist!\n";
		}
	} while (b);
	delete A;
}

void Application::ChoiseTest() {
	A = new Choise;
	A->input();
	std::cout << "A = ";
	A->print();

	static bool b = true;
	do {
		short key;
		std::cout << "\n---------------------------- Choise Test menu ----------------------------\n";
		std::cout << " 1: generate a new array\n 2: sort\n 3: foreach\n 4: check Container's count\n 5: check Choise's count\n 6: clear screen\n 7: exit\n";
		std::cin >> key;
		switch (key) {
			case 1: ChoiseTest(); break;
			case 2: A->sort(); std::cout << "sort(A) = "; A->print(); break;
			case 3: A->foreach(); std::cout << "foreach(A) = "; A->print(); break;
			case 4: std::cout << "Container's count is equal to " << Container::getcount() << std::endl; break;
			case 5: std::cout << "Choise's count is equal to " << Choise::getcount() << std::endl; break;
			case 6: system("cls"); break;
			case 7: b = false; break;
			default: std::cout << "Error! Entered key doesn't exist!\n";
		}
	} while (b);
	delete A;
}

void Application::Run() {
	try {
		BubbleTest();
		system("pause");
		ChoiseTest();
	}
	catch (std::exception& error) {
		std::cout << error.what() << std::endl;
	}
	system("pause");
}