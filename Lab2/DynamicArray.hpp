#pragma once
#include <cstdlib>
#include <cstring>
#include <exception>

using namespace std;

namespace DynArray {

	template <class T> class DynamicArray {
	private:

		T* el;
		int capacity;
	public:

		//Creation
		DynamicArray(int size) {

			capacity = size;
			T* tmp = (T*)malloc(size * sizeof(T));
			if (tmp != nullptr)
				el = tmp;
			else throw bad_alloc();
		}

		DynamicArray(T* items, int count) {

			capacity = count;
			T* tmp = (T*)malloc(count * sizeof(T));
			if (tmp != nullptr)
				el = tmp;
			else throw bad_alloc();
			memcpy(el, items, count * sizeof(T));
		}

		DynamicArray(DynamicArray<T>& dynamicArray) {

			capacity = dynamicArray.GetSize();
			T* tmp = (T*)malloc(capacity * sizeof(T));
			if (tmp != nullptr)
				el = tmp;
			else throw bad_alloc();
			memcpy(el, dynamicArray.GetPointer(), capacity * sizeof(T));
		}


		//Decomposition
		T Get(int index) {
			if ((index < 0) || (index >= capacity))
				throw out_of_range("Array index is out of bounds");
			else
				return *(el + index);
		}

		T* GetPointer() {
			return el;
		}

		int GetSize() {
			return capacity;
		}

		//Operations
		void Set(int index, T value) {
			if ((index < 0) || (index >= capacity))
				throw out_of_range("Array index is out of bounds");
			else
				*(el + index) = value;
		}

		void Resize(int newSize) {
			capacity = newSize;
			T* tmp = (T*)realloc(el, newSize * sizeof(T));
			if (tmp != nullptr)
				el = tmp;
			else 
				throw bad_alloc();
		}
	};
}