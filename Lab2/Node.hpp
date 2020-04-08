#pragma once

namespace List {
	template <class T> class Node {
	private:
		T item;
		Node* next;
	public:
		Node(T newItem, Node* newNext) {
			item = newItem;
			next = newNext;
		}
		T GetItem() {
			return item;
		}
		Node* GetNext() {
			return next;
		}
		void SetItem(T newItem) {
			item = newItem;
		}
		void SetNext(Node* newNext) {
			next = newNext;
		}
	};
}