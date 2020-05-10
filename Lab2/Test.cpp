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
	/*
	ArraySequence<int>* list6 = dynamic_cast<ArraySequence<int>*>(list3->Zip(
		[](int a, int b) -> int
		{
			return a + b;
		}
		, list5
			));
*/
	cout << list->GetFirst() << " " << list->Get(1) << " " << list->Get(2) << " " << list->Get(3) << " " << list->GetLast() << endl;
	cout << list2->GetFirst() << " " << list2->Get(1) << " " << list2->Get(2) << " " << list2->Get(3) << " " << list2->GetLast() << endl;
	cout << list3->GetFirst() << " " << list3->Get(1) << " " << list3->Get(2) << " " << list3->Get(3)
		<< " " << list3->Get(4) << " " << list3->Get(5) << " " << list3->Get(6) << " " << list3->GetLast() << endl;
	cout << list4->GetFirst() << " " << list4->Get(1) << " " << list4->Get(2) << " " << list4->Get(3)
		<< " " << list4->Get(4) << " " << list4->Get(5) << " " << list4->Get(6) << " " << list4->GetLast() << endl;
	cout << list5->GetFirst() << " " << list5->Get(1) << " " << list5->Get(2) << " " << list5->Get(3)
		<< " "  << list5->Get(4) << endl;
	//cout << list6->GetFirst() << " " << list6->Get(1) << " " << list6->Get(2) << " " << list6->Get(3)
	//	<< " " << list6->Get(4) << " " << list6->Get(5) << " " << list6->Get(6) << " " << list6->GetLast() << endl;
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
	list5->Append(0);
	list5->Append(0);
	list5->Append(0);
	list5->Append(0);
	list5->Append(0);
	/*/
	ListSequence<int>* list6 = dynamic_cast<ListSequence<int>*>(list3->Zip(
		[](int a, int b) -> int
		{
			return a + b;
		}
		, list5
	));
	*/
	cout << list->GetFirst() << " " << list->Get(1) << " " << list->Get(2) << " " << list->Get(3) << " " << list->GetLast() << endl;
	cout << list2->GetFirst() << " " << list2->Get(1) << " " << list2->Get(2) << " " << list2->Get(3) << " " << list2->GetLast() << endl;
	cout << list3->GetFirst() << " " << list3->Get(1) << " " << list3->Get(2) << " " << list3->Get(3)
		<< " " << list3->Get(4) << " " << list3->Get(5) << " " << list3->Get(6) << " " << list3->GetLast() << endl;
	cout << list4->GetFirst() << " " << list4->Get(1) << " " << list4->Get(2) << " " << list4->Get(3)
		<< " " << list4->Get(4) << " " << list4->Get(5) << " " << list4->Get(6) << " " << list4->GetLast() << endl;
	cout << list5->GetFirst() << " " << list5->Get(1) << " " << list5->Get(2) << endl;
	//cout << list6->GetFirst() << " " << list6->Get(1) << " " << list6->Get(2) << " " << list6->Get(3)
	//	<< " " << list6->Get(4) << " " << list6->Get(5) << " " << list6->Get(6) << " " << list6->GetLast() << endl;
	cout << prod << endl;
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
	Polynom<Complex>* poly = new Polynom<Complex>(coef, 5);
	Polynom<Complex>* poly1 = new Polynom<Complex>(coef1, 3);
	cout << poly1->GetLength() << endl;
	Polynom<Complex>* poly2 = new Polynom<Complex>();
	*poly2 = *poly + *poly1;
	cout << (string)*poly2 << endl;
	cout << poly1->GetLength() << endl;

	Polynom<Complex>* poly3 = new Polynom<Complex>();
	*poly3 = *poly * Complex(2, 1);
	cout << (string)*poly3 << endl;

	Complex coef2[2] = { Complex(-1), Complex(1) };
	Complex coef3[2] = { Complex(2), Complex(1) };
	Polynom<Complex>* poly4 = new Polynom<Complex>(coef2, 2);
	Polynom<Complex>* poly45 = new Polynom<Complex>(coef3, 2);
	Polynom<Complex>* poly5 = new Polynom<Complex>();
	*poly5 = *poly4 * *poly45;
	cout << (string)*poly5 << endl;
	cout << (string)((*poly) * (*poly1)) << endl;

	Polynom<Complex>* poly7 = poly5->Composition(*poly4);
	cout << (string)*poly7 << endl;
	cout << (string)*poly->Composition(*poly1) << endl;
}