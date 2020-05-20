#pragma once
#include <cstdlib>
#include <memory>
#include <cstring>
#include <exception>
#include <algorithm>

using namespace std;

namespace DynArray {

	template <class T> class DynamicArray {
	private:

		unique_ptr<T[]> el;
		
		int capacity;
	public:

		//Creation
		DynamicArray(int size) {

			capacity = size;
			el = make_unique<T[]>(capacity);
		}

		DynamicArray(T* items, int count) {

			capacity = count;
			el = make_unique<T[]>(capacity);
			memcpy(el.get(), items, count * sizeof(T));
		}

		DynamicArray(DynamicArray<T>& dynamicArray) {

			capacity = dynamicArray.GetSize();
			el = make_unique<T[]>(capacity);
			memcpy(el.get(), dynamicArray.el, capacity * sizeof(T));
		}


		//Decomposition
		T Get(int index) {
			if ((index < 0) || (index >= capacity))
				throw out_of_range("Array index is out of bounds");
			else
				return el[index];
		}


		int GetSize() {
			return capacity;
		}

		//Operations
		void Set(int index, T value) {
			if ((index < 0) || (index >= capacity))
				throw out_of_range("Array index is out of bounds");
			else
				el[index] = value;
		}

		void Resize(int newSize) {
			
			T* ptr_old = el.release();
			
			el = make_unique<T[]>(newSize);

			for (int i = 0; i < min(capacity, newSize); i++) {
				el[i] = ptr_old[i];
			}

			capacity = newSize;

		}

		~DynamicArray() {
		}
	};
}