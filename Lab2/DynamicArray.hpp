#pragma once
#include <cstdlib>
#include <cstring>
#include <exception>

using namespace std;

namespace DynArray {

	template <class T> class DynamicArray {
	private:

		unique_ptr<T[]> el;
		//T* el;
		int capacity;
	public:

		//Creation
		DynamicArray(int size) {

			capacity = size;
			el = make_unique<T[]>(capacity);
			//T* tmp = (T*)malloc(size * sizeof(T));
			//if (tmp != nullptr)
				//el = tmp;
			//else throw bad_alloc();
		}

		DynamicArray(T* items, int count) {

			capacity = count;
			el = make_unique<T[]>(capacity);
			//T* tmp = (T*)malloc(count * sizeof(T));
			//if (tmp != nullptr)
				//el = tmp;
			//else throw bad_alloc();
			memcpy(el.get(), items, count * sizeof(T));
		}

		DynamicArray(DynamicArray<T>& dynamicArray) {

			capacity = dynamicArray.GetSize();
			el = make_unique<T[]>(capacity);
			//T* tmp = (T*)malloc(capacity * sizeof(T));
			//if (tmp != nullptr)
				//el = tmp;
			//else throw bad_alloc();
			//el = tmp.get();
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
			capacity = newSize;
			T* ptr_new = (T*)realloc(el.get(), newSize * sizeof(T));
			if (!ptr_new) {
				throw bad_alloc();
			}

			el.release();
			el.reset(ptr_new);
/*
			unique_ptr<T[]> new_ptr = make_unique<T[]>(newSize);
			auto old_ptr = el.release();
			el.reset(new_ptr);
			T* tmp = (T*)realloc(el.get(), newSize * sizeof(T));
			if (tmp != nullptr)
				el = tmp;
			else 
				throw bad_alloc();*/
		}
	};
}