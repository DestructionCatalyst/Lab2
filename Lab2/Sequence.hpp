#pragma once

namespace Sequences {
	template <class T> class Sequence {
	public:

		Sequence() {
		};

		//Decomposition
		virtual T GetFirst() = 0;
		virtual T GetLast() = 0;
		virtual T Get(int index) = 0;
		virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
		virtual int GetLength() = 0;

		//Operations
		virtual void Append(T item) = 0;
		virtual void Prepend(T item) = 0;
		virtual void InsertAt(T item, int index) = 0;
		virtual Sequence<T>* Concat(Sequence<T>* list) = 0;
	};
}