#include <iostream>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "ArraySequence.hpp"

using namespace std;
using namespace DynArray;
using namespace List;
using namespace Sequences;

int main() {
	
	int a[5] = { 1, 3, 5, 7, 9 };
	/*
	DynamicArray<int>* arr = new DynamicArray<int>(a, 5);
	DynamicArray<int>* arr1 = new DynamicArray<int>(*arr);
	arr->Set(0, 0);
	arr->Set(1, 5);
	//arr->Resize(2);

	cout << arr->Get(0) << " " << arr->Get(1) << " " << arr->Get(2) << " " << arr->Get(3) << " " << arr->Get(4) << endl;
	cout << arr1->Get(0) << " " << arr1->Get(1) << " " << arr1->Get(2) << " " << arr1->Get(3) << " " << arr1->Get(4) << endl;
	*/
	ArraySequence<int>* list = new ArraySequence<int>();
	list->Append(5);
	list->Append(10);
	list->Prepend(1);
	list->InsertAt(2, 2);
	list->InsertAt(100, 1);
	ArraySequence<int>* list2 = new ArraySequence<int>(a, 5);
	ArraySequence<int>* subList = list2->GetSubsequence(1, 3);
	ArraySequence<int>* list1 = new ArraySequence<int>(*subList);
	ArraySequence<int>* list3 = dynamic_cast<ArraySequence<int>*>(list->Concat(subList));
	cout << list->GetFirst() << " " << list->Get(1) << " " << list->Get(2) << " " << list->Get(3) << " " << list->GetLast() << endl;
	cout << list2->GetFirst() << " " << list2->Get(1) << " " << list2->Get(2) << " " << list2->Get(3) << " " << list2->GetLast() << endl;
	//cout << list1->GetFirst() << " " << list1->Get(1) << " "  << list1->GetLast() << endl;
	cout << list3->GetFirst() << " " << list3->Get(1) << " " << list3->Get(2) << " " << list3->Get(3) 
		<< " " << list3->Get(4) << " " << list3->Get(5) << " " << list3->Get(6) << " " << list3->GetLast() << endl;
	return 0;
}