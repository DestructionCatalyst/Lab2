#pragma once
#include "LinkedList.hpp"
#include "Sequence.hpp"


using namespace List;

namespace Sequences {
	template <class T> class ListSequence : public Sequence<T> {
	private:
		LinkedList<T>* list;
	public:
		//Creation
		ListSequence(T* items, int count)
			:Sequence<T>()
		{
			list = new LinkedList<T>(items, count);
		}
		ListSequence()
			:Sequence<T>()
		{
			list = new LinkedList<T>();
		}
		ListSequence(LinkedList<T>& newList)
			:Sequence<T>()
		{
			list = new LinkedList<T>();
			for (int i = 0; i < newList.GetLength(); i++)
				list->Append(newList.Get(i));

		}
		ListSequence(ListSequence<T>& newList)
			:Sequence<T>()
		{
			list = new LinkedList<T>();
			for (int i = 0; i < newList.GetLength(); i++)
				list->Append(newList.Get(i));
			
		}
		//Decomposition
		T GetFirst() override
		{
			return list->GetFirst();
		}
		T GetLast() override
		{
			return list->GetLast();
		}
		T Get(int index) override
		{
			return list->Get(index);
		}
		Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
		{
			return new ListSequence<T>(*list->GetSubList(startIndex, endIndex));
		}
		int GetLength() override
		{
			return list->GetLength();
		}
		//Operations
		void Append(T item) override
		{
			list->Append(item);
		}
		void Prepend(T item) override
		{
			list->Prepend(item);
		}
		void InsertAt(T item, int index) override
		{
			list->InsertAt(item, index);
		}
		Sequence<T>* Concat(Sequence<T>* list) override
		{
			ListSequence<T>* bigList = new ListSequence(*this);
			for (int i = 0; i < list->GetLength(); i++) {
				bigList->Append(list->Get(i));
			}
			return bigList;
		}
		template <class T1> Sequence<T1>* Map(T1(*f)(T))
		{
			ListSequence<T1>* newList = new ListSequence<T1>();
			for (int i = 0; i < this->GetLength(); i++) {
				newList->Append(f(this->Get(i)));
			}
			return newList;
		}
		Sequence<T>* Where(bool(*f)(T)) override
		{
			ListSequence<T>* newList = new ListSequence<T>();
			T cur;
			for (int i = 0; i < this->GetLength(); i++) {
				cur = this->Get(i);
				if (f(cur))
					newList->Append(cur);
			}
			return newList;
		}
		T Reduce(T(*f)(T, T), T c) override
		{
			T listItem;
			T funcResult = c;
			for (int i = 0; i < this->GetLength(); i++) {
				listItem = this->Get(i);
				funcResult = f(listItem, funcResult);
			}
			return funcResult;
		}
	};
}
