#pragma once
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Polynom.hpp"
#include "Complex.hpp"
#include "Test.h"

typedef Arithmetics::Polynom<Sequences::ArraySequence<Arithmetics::Complex>> Polynom_t;

class ConsoleHelper {
private:
	std::vector<Polynom_t> arr{};

	int InputNumber();
	double InputDouble();
	Arithmetics::Complex InputComplex();
	int InputPositive();
	int InputIndex(bool zeroAllowed);

	void Create();
	void Print();
	void Add();
	void Multiply();
	void Calculate();
	void CrossMultiply();
	void Composition();
	void Help();
	void Delete();
	void Test();

public:
	void Run();
	
};