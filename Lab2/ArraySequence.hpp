#pragma once
#include "DynamicArray.hpp"
#include "Sequence.hpp"
#include <functional>
#define DEFAULT_SIZE 8
#define min(num1, num2) num1<num2?num1:num2


using namespace DynArray;

namespace Sequences {
	template <class T> class ArraySequence : public Sequence<T> {
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
			:Sequence<T>(), arr(array.arr), curSize(array.curSize)
		{}

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
		Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {

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
			for (int i = 0; i < list->GetLength(); i++) {
				bigArr->Append(list->Get(i));
			}
			return bigArr;
		}
		Sequence<T>* Map(std::function<T(T)> f)
		{
			ArraySequence<T>* newArr = new ArraySequence<T>();
			for (int i = 0; i < this->GetLength(); i++) {
				newArr->Append(f(this->Get(i)));
			}
			return newArr;
		}
		Sequence<T>* Where(std::function<bool(T)> f) override
		{
			ArraySequence<T>* newList = new ArraySequence<T>();
			T cur;
			for (int i = 0; i < this->GetLength(); i++) {
				cur = this->Get(i);
				if (f(cur))
					newList->Append(cur);
			}
			return newList;
		}
		T Reduce(std::function<T(T, T)> f, T c) override
		{
			T arrayItem;
			T funcResult = c;
			for (int i = 0; i < this->GetLength(); i++) {
				arrayItem = this->Get(i);
				funcResult = f(arrayItem, funcResult);
			}
			return funcResult;
		}
		~ArraySequence() 
		{
			delete(arr);
		}
	};
}