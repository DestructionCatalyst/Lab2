#include <iostream>
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Test.h"

using namespace std;
using namespace Sequences;

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
	ArraySequence<double>* list4 = dynamic_cast<ArraySequence<double>*>(list3->Map<double>(
		[](int a) -> double
		{
			return a / 2.;
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

	cout << list->GetFirst() << " " << list->Get(1) << " " << list->Get(2) << " " << list->Get(3) << " " << list->GetLast() << endl;
	cout << list2->GetFirst() << " " << list2->Get(1) << " " << list2->Get(2) << " " << list2->Get(3) << " " << list2->GetLast() << endl;
	cout << list3->GetFirst() << " " << list3->Get(1) << " " << list3->Get(2) << " " << list3->Get(3)
		<< " " << list3->Get(4) << " " << list3->Get(5) << " " << list3->Get(6) << " " << list3->GetLast() << endl;
	cout << list4->GetFirst() << " " << list4->Get(1) << " " << list4->Get(2) << " " << list4->Get(3)
		<< " " << list4->Get(4) << " " << list4->Get(5) << " " << list4->Get(6) << " " << list4->GetLast() << endl;
	cout << list5->GetFirst() << " " << list5->Get(1) << " " << list5->Get(2) << " " << list5->Get(3)
		<< " "  << list5->GetLast() << endl;
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
	ListSequence<double>* list4 = dynamic_cast<ListSequence<double>*>(list3->Map<double>(
		[](int a) -> double
		{
			return a / 2.;
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

	cout << list->GetFirst() << " " << list->Get(1) << " " << list->Get(2) << " " << list->Get(3) << " " << list->GetLast() << endl;
	cout << list2->GetFirst() << " " << list2->Get(1) << " " << list2->Get(2) << " " << list2->Get(3) << " " << list2->GetLast() << endl;
	cout << list3->GetFirst() << " " << list3->Get(1) << " " << list3->Get(2) << " " << list3->Get(3)
		<< " " << list3->Get(4) << " " << list3->Get(5) << " " << list3->Get(6) << " " << list3->GetLast() << endl;
	cout << list4->GetFirst() << " " << list4->Get(1) << " " << list4->Get(2) << " " << list4->Get(3)
		<< " " << list4->Get(4) << " " << list4->Get(5) << " " << list4->Get(6) << " " << list4->GetLast() << endl;
	cout << list5->GetFirst() << " " << list5->Get(1) << " " << list5->GetLast() << endl;
	cout << prod << endl;
	cout << endl;
}