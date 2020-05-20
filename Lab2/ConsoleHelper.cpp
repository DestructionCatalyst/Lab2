#include "ConsoleHelper.h"

int ConsoleHelper::InputNumber() {
	std::string str{ "" };
	int a{ 0 };
	while (true) {
		std::cin >> str;
		try {
			a = std::stoi(str);
			return a;
		}
		catch (std::invalid_argument) {
			std::cout << "An argument should be an integer number, not " << str << std::endl;
		}
	}
	
}

double ConsoleHelper::InputDouble() {
	std::string str{ "" };
	double a{ 0 };
	while (true) {
		std::cin >> str;
		try {
			a = std::stod(str);
			return a;
		}
		catch (std::invalid_argument) {
			std::cout << "An argument should be a number, not " << str << std::endl;
		}
	}

}

Arithmetics::Complex ConsoleHelper::InputComplex() {
	std::string str{ };
	std::string str1{ };
	double a{ };
	double b{ };
	while (true) {
		std::cin >> str;
		std::cin >> str1;
		try {
			a = std::stod(str);
			b = std::stod(str1);
			return Arithmetics::Complex(a, b);
		}
		catch (std::invalid_argument) {
			std::cout << "An argument should be a pair of numbers!" << std::endl;
		}
	}

}

int ConsoleHelper::InputPositive() {
	int a;
	while (true) {
		a = InputNumber();

		if (a < 0)
			std::cout << "An argument should be a positive integer number!" << std::endl;
		else
			return a;
	}
}

int ConsoleHelper::InputIndex(bool zeroAllowed) {
	std::string str{ "" };
	int a;

	
	std::cin >> str;
	try {
		a = std::stoi(str);

		if ((a < 0) || (a > arr.size()) || ((!zeroAllowed) && (a == 0))) {
			std::cout << "An argument should be a polynom index!" << std::endl;
		}
		else {
			a--;
			return a;
		}
	}
	catch (std::invalid_argument) {
		std::cout << "An argument should be a polynom index!" << std::endl;
	}
		
	throw std::runtime_error("Incorrect input!");
	
}

void ConsoleHelper::Run() {
	std::string command{ "" };
	
	std::cout << "Welcome to Polynom console application! To see the list of commands, please type 'help'." << std::endl;

	while ((command != "exit") && (command != "quit")) {
		std::cin >> command;

		if (command == "create") {
			Create();
		}
		else if (command == "print") {
			Print();
		}
		else if (command == "add") {
			Add();
		}
		else if (command == "mult") {
			Multiply();
		}
		else if (command == "calc") {
			Calculate();
		}
		else if (command == "cmult") {
			CrossMultiply();
		}
		else if (command == "comp") {
			Composition();
		}
		else if (command == "del") {
			Delete();
		}
		else if (command == "help") {
			Help();
		}
		else if (command == "test") {
			Test();
		}
		else {
			std::cout << "Incorrect command! To see the list of commands, please type 'help'." << std::endl;
		}
	}
}

void ConsoleHelper::Create() {
	std::string postfix;
	std::cin >> postfix;

	int arg1 = InputPositive();
	arg1++;

	double arg2{};

	Polynom_t poly;

	if (postfix == "complex") {
		std::cout << "Enter " << arg1 << " complex numbers" << std::endl;
		std::cout << "(split real and imaginary part using space)" << std::endl;

		unique_ptr<Arithmetics::Complex[]> coef = make_unique<Arithmetics::Complex[]>(arg1);

		for (int i = 0; i < arg1; i++) {

			coef[i] = InputComplex();
		}
		poly = Polynom_t(coef.get(), arg1);
		arr.push_back(poly);
	}
	else {
		std::cout << "Enter " << arg1 << " real numbers" << std::endl;

		unique_ptr<Arithmetics::Complex[]> coef = make_unique<Arithmetics::Complex[]>(arg1);

		for (int i = 0; i < arg1; i++) {
			arg2 = InputDouble();

			coef[i] = Arithmetics::Complex(arg2);
		}
		poly = Polynom_t(coef.get(), arg1);
		arr.push_back(poly);
	}

	std::cout << "Created " << (string)poly << std::endl << std::endl;
}

void ConsoleHelper::Print() {
	int arg1;
	try {
		arg1 = InputIndex(true);
		if (arg1 < 0) {
			for (int i = 0; i < arr.size(); i++) {
				std::cout << i + 1 << ". " << (string)arr[i] << std::endl;
			}
			std::cout << std::endl;
		}
		else {
			std::cout << arg1 + 1 << ". " << (string)arr[arg1] << std::endl << std::endl;
		}
	}
	catch (std::runtime_error) {}
	
}

void ConsoleHelper::Add() {
	int arg1;
	int arg2;
	try {
		arg1 = InputIndex(false);
		arg2 = InputIndex(false);
		
		Polynom_t sum = arr[arg1] + arr[arg2];
		arr.push_back(sum);

		std::cout << "The sum is " << (string)sum << std::endl << std::endl;
	}
	catch (std::runtime_error) {}
}

void ConsoleHelper::Multiply() {
	std::string postfix;

	int arg1;
	Polynom_t res;

	try {
		std::cin >> postfix;
		arg1 = InputIndex(false);

		if (postfix == "complex") {
			std::cout << "Enter a complex number" << std::endl;
			std::cout << "(split real and imaginary part using space)" << std::endl;

			Arithmetics::Complex c = InputComplex();

			res = arr[arg1] * c;
			arr.push_back(res);
			
		}
		else {
			std::cout << "Enter a real number" << std::endl;

			double c = InputDouble();

				
			res = arr[arg1] * c;
			arr.push_back(res);
		}

		std::cout << "The result is " << (string)res << std::endl << std::endl;
		//std::cout << "Created " << (string)res << std::endl << std::endl;
	}
	catch (std::runtime_error) {}
}

void ConsoleHelper::Calculate() {
	std::string postfix;

	int arg1;
	Arithmetics::Complex res;

	try {
		std::cin >> postfix;
		arg1 = InputIndex(false);

		if (postfix == "complex") {
			std::cout << "Enter a complex number" << std::endl;
			std::cout << "(split real and imaginary part using space)" << std::endl;

			Arithmetics::Complex c = InputComplex();

			res = arr[arg1].Calculate(c);
			//arr.push_back(res);

		}
		else {
			std::cout << "Enter a real number" << std::endl;

			double c = InputDouble();


			res = arr[arg1].Calculate(c);
			//arr.push_back(res);
		}

		std::cout << "The result is " << (string)res << std::endl << std::endl;
	}
	catch (std::runtime_error) {}
}

void ConsoleHelper::CrossMultiply() {
	int arg1;
	int arg2;
	try {
		arg1 = InputIndex(false);
		arg2 = InputIndex(false);

		Polynom_t prod = arr[arg1] * arr[arg2];
		arr.push_back(prod);

		std::cout << "The product is " << (string)prod << std::endl << std::endl;
	}
	catch (std::runtime_error) {}
}

void ConsoleHelper::Composition() {
	int arg1;
	int arg2;
	try {
		arg1 = InputIndex(false);
		arg2 = InputIndex(false);

		Polynom_t res = *(arr[arg1].Composition(arr[arg2]));
		arr.push_back(res);
		
		std::cout << "The result is " << (string)res << std::endl << std::endl;
	}
	catch (std::runtime_error) {}
}

void ConsoleHelper::Delete() {
	int arg1;
	try {
		arg1 = InputIndex(false);

		std::cout << (string)arr[arg1] << " deleted" << std::endl << std::endl;

		arr.erase(arr.begin() + arg1);
		
	}
	catch (std::runtime_error) {}

}

void ConsoleHelper::Test() {
	int number = InputPositive();

	switch (number) {
	case 1:
		testArraySequence();
		break;
	case 2:
		testListSequence();
		break;
	case 3:
		TestPolynomAddition();
		break;
	case 4:
		TestPolynomMultiplication();
		break;
	case 5:
		TestPolynomCrossMultiplication();
		break;
	case 6:
		TestPolynomComposition();
		break;
	case 7:
		TestPolynomCalculation();
		break;
	case 8:
		testArraySequence();
		testListSequence();
		TestPolynomAddition();
		TestPolynomMultiplication();
		TestPolynomCrossMultiplication();
		TestPolynomComposition();
		TestPolynomCalculation();
		break;
	default:
		std::cout << "test 1 - testing dynamic array based container" << std::endl;
		std::cout << "test 2 - testing linked list based container" << std::endl;
		std::cout << "test 3 - testing polynom addition" << std::endl;
		std::cout << "test 4 - testing polynom multiplication on number" << std::endl;
		std::cout << "test 5 - testing polynom multiplication on each other" << std::endl;
		std::cout << "test 6 - testing polynom composition" << std::endl;
		std::cout << "test 7 - testing polynom calculation" << std::endl;
		std::cout << "test 8 - full test (all of the above)" << std::endl;

		cout << endl;
	}
}

void ConsoleHelper::Help() {

	std::cout << "The list of commands:" << std::endl;

	std::cout << "create type* n\tCreates a polynom with n variables. " 
			  << "You must enter n+1 coefficients after pressing Enter. " << std::endl;

	std::cout << "print n \tPrints a polynom with number n, if n equals 0, "
			  << "prints all existing polynoms and their numbers." << std::endl;

	std::cout << "add a b \tFinds a sum of polynom a and b and adds it to the array of existing polynoms." << std::endl;

	std::cout << "mult type* a\tFinds a product of polynom a and number in the next line "
			  << "and adds it to the array of existing polynoms." << std::endl;

	std::cout << "calc type* n  \tFinds a value of polynom n with known value of x (in the next line) "
			  << "and displays it on the screen." << std::endl;

	std::cout << "cmult a b\tFinds a product of polynom a and b "
			  << "and adds it to the array of existing polynoms." << std::endl;

	std::cout << "comp a b\tFinds a composition of polynom a and b "
			  << "and adds it to the array of existing polynoms." << std::endl;

	std::cout << "del n   \tDeletes a form with number n." << std::endl;

	std::cout << "help    \tDisplays help" << std::endl;

	std::cout << "test    \tAn interface for testing the program. "
			  << "Type in 'test 0' to see the list of tests" << std::endl;

	std::cout << "exit    \tFinishes the work of the application" << std::endl;
	std::cout << "quit    \tFinishes the work of the application" << std::endl << std::endl;

	std::cout << "(*) The list of types:" << std::endl;

	std::cout << "real/float/double \tFor inputting real numbers" << std::endl;

	std::cout << "complex \t\tFor inputting complex numbers" << std::endl;

}