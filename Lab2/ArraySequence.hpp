#pragma once
#include "DynamicArray.hpp"
#include "Sequence.hpp"
#define DEFAULT_SIZE 8


using namespace DynArray;

namespace Sequences {
	template <class T> class ArraySequence : Sequence<T> {
	private:
		DynamicArray<T>* arr;
		int curSize;
	public:
		
		//Creation
		ArraySequence(T* items, int count)
			:Sequence<T>()
		{
			arr = new DynamicArray<T>(items, count);
			curSize = count;
		}
		ArraySequence()
			:Sequence<T>()
		{
			arr = new DynamicArray<T>(DEFAULT_SIZE);
			curSize = 0;
		}
		ArraySequence(ArraySequence<T>& array)
			:Sequence<T>()
		{
			arr = new DynamicArray<T>(array.GetLength());
			for (int i = 0; i < array.GetLength(); i++)
				arr->Set(i, array.Get(i));
			curSize = array.GetLength();
		}

		//Decomposition
		T GetFirst() override {
			return arr->Get(0);
		}
		T GetLast() override {
			return arr->Get(curSize - 1);
		}
		T Get(int index) override {
			return arr->Get(index);
		}
		ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) override {

			if ((startIndex <= endIndex) && (startIndex >= 0) && (endIndex < curSize)) {
				ArraySequence<T>* sub = new ArraySequence();
				for (int i = startIndex; i <= endIndex; i++) {
					sub->Append(Get(i));
				}
				return sub;
			}
			else
				throw out_of_range("List index is out of bounds");
		}
		int GetLength() override {
			return curSize;
		}
		//Operations
		void Append(T item) override {
			if (curSize >= arr->GetSize()) {
				arr->Resize(arr->GetSize() * 2);
			}
			arr->Set(curSize, item);
			curSize++;
		}
		void Prepend(T item) override {
			if (curSize >= arr->GetSize()) {
				arr->Resize(arr->GetSize() * 2);
			}
			for (int i = curSize; i > 0 ; i--)
				arr->Set(i, arr->Get(i - 1));
			arr->Set(0, item);
			curSize++;
		}
		void InsertAt(T item, int index) override {
			if (index == 0)
				Prepend(item);
			else if (index == curSize)
				Append(item);
			else if ((index > 0) && (index < curSize)) {
				if (curSize >= arr->GetSize()) {
					arr->Resize(arr->GetSize() * 2);
				}
				for (int i = curSize; i >= index; i--)
					arr->Set(i, arr->Get(i - 1));
				arr->Set(index, item);
				curSize++;
			}
			else
				throw out_of_range("Array index is out of bounds");
		}
		Sequence<T>* Concat(Sequence<T>* list) override {
			ArraySequence<T>* bigArr = new ArraySequence(*this);
			ArraySequence<T>* arr2 = dynamic_cast<ArraySequence<T>*>(list);
			for (int i = 0; i < arr2->GetLength(); i++) {
				bigArr->Append(arr2->Get(i));
			}
			return nullptr;
		}
	};
}