#pragma once
#include "Node.hpp"

namespace List {
	template <class T> class LinkedList {
	private:
		Node<T>* head;
		Node<T>* tail;
		int length;
	public:
		//Creation

		LinkedList(T* items, int count) {

			head = nullptr;
			tail = nullptr;
			length = 0;
			for (int i = 0; i < count; i++) {
				Append(items[i]);
			}
		}
		LinkedList() {

			head = nullptr;
			tail = nullptr;
			length = 0;
		}
		LinkedList(LinkedList <T>& list) {

			head = nullptr;
			tail = nullptr;
			length = 0;
			Node<T>* iter = list.GetHead();
			for (int i = 0; i < list.GetLength(); i++) {
				Append(iter->GetItem());
				iter = iter->GetNext();
			}
		}
		//Decomposition

		Node<T>* GetHead() {

			return head;
		}
		T GetFirst() {

			if(length != 0)
				return head->GetItem();
			else throw out_of_range("List is empty!");
		}
		T GetLast() {

			if(length != 0)
				return tail->GetItem();
			else throw out_of_range("List is empty!");
		}
		T Get(int index) {

			if ((length != 0) && (index >= 0) && (index < length)) {
				Node<T>* iter;
				iter = head;
				for (int i = 0; i < index; i++) {
					iter = iter->GetNext();
				}
				return iter->GetItem();
			}
			else
				throw out_of_range("List index is out of bounds");
		}
		LinkedList<T>* GetSubList(int startIndex, int endIndex) {

			if ((startIndex <= endIndex) && (startIndex >= 0) && (endIndex < length)) {
				LinkedList<T>* subList = new LinkedList<T>();
				Node<T>* iter = head;
				for (int i = 0; i < startIndex; i++)
					iter = iter->GetNext();
				for (int i = startIndex; i <= endIndex; i++) {
					subList->Append(iter->GetItem());
					iter = iter->GetNext();
				}
				return subList;
			}
			else
				throw out_of_range("List index is out of bounds");
		}
		int GetLength() {

			return length;
		}
		//Operations
		void Append(T item) {

			Node<T>* last = new Node<T>(item, nullptr);
			if (length == 0) {
				tail = last;
				head = tail;
			}
			else {
				tail->SetNext(last);
				tail = last;
			}
			++length;
		}
		void Prepend(T item) {

			head = new Node<T>(item, head);
			if (length == 0)
				tail = head;
			++length;
		}
		void InsertAt(T item, int index) {

			if (index == 0)
				Prepend(item);
			else if (index == length)
				Append(item);
			else if ((index >0) && (index < length)){
				Node<T>* iter;
				iter = head;
				for (int i = 0; i < index - 1; i++) {
					iter = iter->GetNext();
				}
				Node<T>* newNode = new Node<T>(item, iter->GetNext());
				iter->SetNext(newNode);
				++length;
			}
			else 
				throw out_of_range("List index is out of bounds");
		}
		LinkedList<T>* Concat(LinkedList<T>* list) {

			LinkedList<T>* bigList = new LinkedList(*this);
			Node<T>* iter = list->GetHead();
			for (int i = 0; i < list->GetLength(); i++) {
				bigList->Append(iter->GetItem());
				iter = iter->GetNext();
			}
			return bigList;
		}
	};
	
	
	
}