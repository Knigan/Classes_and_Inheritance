#include "Application.h"

void Application::Run() const {
	srand(time(nullptr));
	try {
		bool b = true;
		Rational number1;
		std::cout << "Number1 = " << number1 << std::endl;
		Rational number2;
		std::cout << "Number2 = " << number2 << std::endl;
		do {
			short key;
			std::cout << "\n---------------------------- Test menu ----------------------------\n";
			std::cout << " 1: generate new numbers\n 2: add\n 3: subtract\n 4: multiple\n 5: divide\n 6: check equal\n 7: check greater\n 8: check less\n 9: check LongLong's count\n 10: check Rational's count\n 11: clear screen\n 12: exit\n";
			std::cin >> key;
			switch (key) {
				case 1: number1.generate(); std::cout << "Number1 = " << number1 << std::endl; 
				number2.generate(); std::cout << "Number1 = " << number1 << std::endl; 
				break;
				case 2: std::cout << "\nNumber1 + Number2 = " << number1 + number2 << std::endl; break;
				case 3: std::cout << "\nNumber1 - Number2 = " << number1 - number2 << std::endl; break;
				case 4: std::cout << "\nNumber1 * Number2 = " << number1 * number2 << std::endl; break;
				case 5: std::cout << "\nNumber1 / Number2 = " << number1 / number2 << std::endl; break;
				case 6: std::cout << "\nNumber1 == Number2? Answer: " << (number1 == number2) << std::endl; break;
				case 7: std::cout << "\nNumber1 > Number2? Answer: " << (number1 > number2) << std::endl; break;
				case 8: std::cout << "\nNumber1 < Number2? Answer: " << (number1 < number2) << std::endl; break;
				case 9: std::cout << "\nLongLong's count is equal to " << LongLong::getcount() << std::endl; break;
				case 10: std::cout << "\nRational's count is equal to " << Rational::getcount() << std::endl; break;
				case 11: system("cls"); break;
				case 12: b = false; break;
				default: std::cout << "Error! Entered key doesn't exist!\n";
			}
		} while (b);
	}
	catch (std::exception& error) {
		std::cout << error.what() << std::endl;
	}
	system("pause");
}