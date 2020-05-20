#include <iostream>
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Test.h"
#include "Polynom.hpp"
#include "Complex.hpp"

using namespace std;
using namespace Sequences;
using namespace Arithmetics;

void testArraySequence() {
	int a[5] = { 1, 3, 5, 7, 9 };
	ArraySequence<int>* list = new ArraySequence<int>();

	list->Append(5);
	list->Append(10);
	list->Prepend(1);
	list->InsertAt(2, 2);
	list->InsertAt(100, 1);

	ArraySequence<int>* list2 = new ArraySequence<int>(a, 5);
	ArraySequence<int>* subList = dynamic_cast<ArraySequence<int>*>(list2->GetSubsequence(1, 3));
	ArraySequence<int>* list1 = new ArraySequence<int>(*subList);
	ArraySequence<int>* list3 = dynamic_cast<ArraySequence<int>*>(list->Concat(subList));
	ArraySequence<int>* list4 = dynamic_cast<ArraySequence<int>*>(list3->Map(
		[](int a) -> int
		{
			return a / 2;
		}
	));
	ArraySequence<int>* list5 = dynamic_cast<ArraySequence<int>*>(list3->Where(
		[](int a) -> bool
		{
			return a % 2 != 0;
		}
	));
	int prod = list5->Reduce(
		[](int a1, int a2) -> int
		{
			return a1 * a2;
		}
		, 1
	);
	list5->Append(0);
	list5->Append(0);
	list5->Append(0);
	
	//cout << list->GetFirst() << " " << list->Get(1) << " " << list->Get(2) << " " << list->Get(3) << " " << list->GetLast() << endl;
	//cout << list2->GetFirst() << " " << list2->Get(1) << " " << list2->Get(2) << " " << list2->Get(3) << " " << list2->GetLast() << endl;
	cout << "Array operations test:" << endl;
	cout << "Expected output:" << endl;
	cout << "1 100 5 2 10 3 5 7" << endl;
	cout << "Program output:" << endl;
	cout << list3->GetFirst() << " " << list3->Get(1) << " " << list3->Get(2) << " " << list3->Get(3)
		<< " " << list3->Get(4) << " " << list3->Get(5) << " " << list3->Get(6) << " " << list3->GetLast() << endl;
	cout << endl;

	cout << "Map function test:" << endl;
	cout << "Expected output:" << endl;
	cout << "0 50 2 1 5 1 2 3" << endl;
	cout << "Program output:" << endl;
	cout << list4->GetFirst() << " " << list4->Get(1) << " " << list4->Get(2) << " " << list4->Get(3)
		<< " " << list4->Get(4) << " " << list4->Get(5) << " " << list4->Get(6) << " " << list4->GetLast() << endl;
	cout << endl;

	cout << "Where function test:" << endl;
	cout << "Expected output:" << endl;
	cout << "1 5 3 5 7" << endl;
	cout << "Program output:" << endl;
	cout << list5->GetFirst() << " " << list5->Get(1) << " " << list5->Get(2) << " " << list5->Get(3)
		<< " "  << list5->Get(4) << endl;
	cout << endl;

	cout << "Reduce function test:" << endl;
	cout << "Expected output:" << endl;
	cout << 525 << endl;
	cout << "Program output:" << endl;
	cout << prod << endl;
	cout << endl;
}

void testListSequence() {
	int a[5] = { 1, 3, 5, 7, 9 };
	ListSequence<int>* list = new ListSequence<int>();

	list->Append(5);
	list->Append(10);
	list->Prepend(1);
	list->InsertAt(2, 2);
	list->InsertAt(100, 1);

	//cout << list->GetFirst() << " " << list->Get(1) << " " << list->Get(2) << " " << list->Get(3) << " " << list->GetLast() << endl;

	ListSequence<int>* list2 = new ListSequence<int>(a, 5);
	ListSequence<int>* subList = dynamic_cast<ListSequence<int>*>(list2->GetSubsequence(1, 3));
	ListSequence<int>* list1 = new ListSequence<int>(*subList);
	ListSequence<int>* list3 = dynamic_cast<ListSequence<int>*>(list->Concat(subList));
	ListSequence<int>* list4 = dynamic_cast<ListSequence<int>*>(list3->Map(
		[](int a) -> int
		{
			return a / 2;
		}
	));
	ListSequence<int>* list5 = dynamic_cast<ListSequence<int>*>(list3->Where(
		[](int a) -> bool
		{
			return a % 2 == 0;
		}
	));
	int prod = list5->Reduce(
		[](int a1, int a2) -> int
		{
			return a1 * a2;
		}
		, 1
	);


	cout << "List operations test:" << endl;
	cout << "Expected output:" << endl;
	cout << "1 100 5 2 10 3 5 7" << endl;
	cout << "Program output:" << endl;
	cout << list3->GetFirst() << " " << list3->Get(1) << " " << list3->Get(2) << " " << list3->Get(3)
		<< " " << list3->Get(4) << " " << list3->Get(5) << " " << list3->Get(6) << " " << list3->GetLast() << endl;
	cout << endl;

	cout << "Map function test:" << endl;
	cout << "Expected output:" << endl;
	cout << "0 50 2 1 5 1 2 3" << endl;
	cout << "Program output:" << endl;
	cout << list4->GetFirst() << " " << list4->Get(1) << " " << list4->Get(2) << " " << list4->Get(3)
		<< " " << list4->Get(4) << " " << list4->Get(5) << " " << list4->Get(6) << " " << list4->GetLast() << endl;
	cout << endl;

	cout << "Where function test:" << endl;
	cout << "Expected output:" << endl;
	cout << "100 2 10" << endl;
	cout << "Program output:" << endl;
	cout << list5->GetFirst() << " " << list5->Get(1) << " " << list5->Get(2) << endl;
	cout << endl;

	cout << "Reduce function test:" << endl;
	cout << "Expected output:" << endl;
	cout << 2000 << endl;
	cout << "Program output:" << endl;
	cout << prod << endl;
	cout << endl;
}

void TestPolynomAddition()
{
	double a[10] = { 1, 0, 0, 7, 0.5, 0.25, 0, 0, 10, 1000 };
	double b[6] = { 5, 10, 0, 15, 0.5, 0 };
	Complex coef[5];
	Complex coef1[3];
	for (int i = 0; i < 5; i++) {
		coef[i] = Complex(a[2 * i], a[2 * i + 1]);
	}
	for (int i = 0; i < 3; i++) {
		coef1[i] = Complex(b[2 * i], b[2 * i + 1]);
	}
	Polynom<ArraySequence<Complex>> poly(coef, 5);
	Polynom<ArraySequence<Complex>> poly1(coef1, 3);
	Polynom<ArraySequence<Complex>> poly2 = poly1 + poly;

	cout << "Polynom addition test:" << endl;
	cout << "Expected output:" << endl;
	cout << "(6 + 10*i) + (22*i)*(x^1) + (1 + 0.25*i)*(x^2) + (10 + 1000*i)*(x^4)" << endl;
	cout << "Program output:" << endl;
	cout << (string)poly2 << endl;
	cout << endl;
	
}

void TestPolynomCrossMultiplication()
{
	double a[6] = { 1, 0, 3, 0, 4, 0 };
	double b[4] = { 2, 1, 1, 0 };
	Complex coef[3];
	Complex coef1[2];
	for (int i = 0; i < 3; i++) {
		coef[i] = Complex(a[2 * i], a[2 * i + 1]);
	}
	for (int i = 0; i < 2; i++) {
		coef1[i] = Complex(b[2 * i], b[2 * i + 1]);
	}
	Polynom<ArraySequence<Complex>> poly(coef, 3);
	Polynom<ArraySequence<Complex>> poly1(coef1, 2);
	Polynom<ArraySequence<Complex>> poly2 = poly * poly1;

	cout << "Polynom multiplication test:" << endl;
	cout << "Expected output:" << endl;
	cout << "(2 + 1*i) + (7 + 3*i)*(x^1) + (11 + 4*i)*(x^2) + (4)*(x^3)" << endl;
	cout << "Program output:" << endl;
	cout << (string)poly2 << endl;
	cout << endl;

}

void TestPolynomMultiplication()
{
	double a[10] = { 0, 10, 1, 1, 0.5, 0.25, 0, 0, 7, 8 };
	double b[6] = { 5, 0, 0, 20, 0.5, 0 };
	Complex coef[5];
	Complex coef1[3];
	for (int i = 0; i < 5; i++) {
		coef[i] = Complex(a[2 * i], a[2 * i + 1]);
	}
	for (int i = 0; i < 3; i++) {
		coef1[i] = Complex(b[2 * i], b[2 * i + 1]);
	}
	Polynom<ArraySequence<Complex>> poly(coef, 5);
	Polynom<ArraySequence<Complex>> poly1(coef1, 3);
	Polynom<ArraySequence<Complex>> poly2 = poly * Complex(3);
	Polynom<ArraySequence<Complex>> poly3 = poly1 * Complex(0.5, 2);

	cout << "Polynom multiplication on number test:" << endl;
	cout << "Expected output:" << endl;
	cout << "(30*i) + (3 + 3*i)*(x^1) + (1.5 + 0.75*i)*(x^2) + (21 + 24i)*(x^4)" << endl;
	cout << "Program output:" << endl;
	cout << (string)poly2 << endl;
	cout << endl;

	cout << "Expected output:" << endl;
	cout << "(2.5 + 10*i) + (-40 + 10*i)*(x^1) + (0,25 + 1*i)*(x^2)" << endl;
	cout << "Program output:" << endl;
	cout << (string)poly3 << endl;
	cout << endl;
}

void TestPolynomComposition()
{
	double a[6] = { 1, 0, 3, 0, 1, 0 };
	double b[4] = { 2, 1, 1, 0 };
	Complex coef[3];
	Complex coef1[2];
	for (int i = 0; i < 3; i++) {
		coef[i] = Complex(a[2 * i], a[2 * i + 1]);
	}
	for (int i = 0; i < 2; i++) {
		coef1[i] = Complex(b[2 * i], b[2 * i + 1]);
	}
	Polynom<ArraySequence<Complex>> poly(coef, 3);
	Polynom<ArraySequence<Complex>> poly1(coef1, 2);
	Polynom<ArraySequence<Complex>> poly2 = *poly.Composition(poly1);

	cout << "Polynom composition test:" << endl;
	cout << "Expected output:" << endl;
	cout << "(10 + 7*i) + (7 + 2*i)*(x^1) + (1)*(x^2)" << endl;
	cout << "Program output:" << endl;
	cout << (string)poly2 << endl;
	cout << endl;

}

void TestPolynomCalculation()
{
	double a[8] = { 2, 2, 7, 1, 3, 2, 0, 1 };
	Complex coef[4];
	for (int i = 0; i < 4; i++) {
		coef[i] = Complex(a[2 * i], a[2 * i + 1]);
	}
	Polynom<ArraySequence<Complex>> poly(coef, 4);

	cout << "Polynom calculation test:" << endl;
	cout << "Expected output:" << endl;
	cout << "0 (-1 + 7*i)" << endl;
	cout << "Program output:" << endl;
	cout << (string)poly.Calculate(Complex(-2)) << " " << (string)poly.Calculate(Complex(0, 1)) << endl;
	cout << endl;

}

void TestPolynom()
{
	double a[10] = { 1, 0, 0, 7, 0.5, 0.25, 0, 0, 10, 1000 };
	double b[6] = { 5, 10, 0, 15, 0.5, 0};
	Complex coef[5];
	Complex coef1[3];
	for (int i = 0; i < 5; i++) {
		coef[i] = Complex(a[2 * i], a[2 * i + 1]);
	}
	for (int i = 0; i < 3; i++) {
		coef1[i] = Complex(b[2 * i], b[2 * i + 1]);
	}
	Polynom<ArraySequence<Complex>>* poly = new Polynom<ArraySequence<Complex>>(coef, 5);
	Polynom<ArraySequence<Complex>>* poly1 = new Polynom<ArraySequence<Complex>>(coef1, 3);
	Polynom<ArraySequence<Complex>>* poly2 = new Polynom<ArraySequence<Complex>>(*poly + *poly1);
	//*poly2 = *poly + *poly1;
	cout << (string)*poly2 << endl;

	Polynom<ArraySequence<Complex>>* poly3 = new Polynom<ArraySequence<Complex>>(*poly * Complex(2, 1));
	//*poly3 = *poly * Complex(2, 1);
	cout << (string)*poly3 << endl;

	Complex coef2[2] = { Complex(-1), Complex(1) };
	Complex coef3[2] = { Complex(2), Complex(1) };
	Polynom<ArraySequence<Complex>>* poly4 = new Polynom<ArraySequence<Complex>>(coef2, 2);
	Polynom<ArraySequence<Complex>>* poly45 = new Polynom<ArraySequence<Complex>>(coef3, 2);
	Polynom<ArraySequence<Complex>>* poly5 = new Polynom<ArraySequence<Complex>>((*poly4 * *poly45));
	//*poly5 = *poly4 * *poly45;
	cout << (string)*poly5 << endl;
	cout << (string)((*poly) * (*poly1)) << endl;

	Polynom<ArraySequence<Complex>>* poly7 = new Polynom<ArraySequence<Complex>>(*poly5->Composition(*poly4));
	cout << (string)*poly7 << endl;
	cout << (string)*poly->Composition(*poly1) << endl;
	cout << (string)poly5->Calculate(Complex(5, 7)) << endl;
}