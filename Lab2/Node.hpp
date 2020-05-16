#pragma once
#include <memory>

namespace List {
	template <class T> class Node {
	private:
		T item;
		shared_ptr<Node<T>> next{ nullptr };
		//Node* next;
	public:
		Node(T newItem, Node* newNext) {
			item = newItem;
			next = make_shared<Node<T>>(*newNext);
		}
		Node(T newItem, shared_ptr<Node<T>> newNext) {
			item = newItem;
			next = newNext;
		}
		T GetItem() {
			return item;
		}
		shared_ptr<Node<T>> GetNext() {
			return next;
		}
		void SetItem(T newItem) {
			item = newItem;
		}
		void SetNext(Node* newNext) {
			next.reset(newNext);
		}
		void SetNext(shared_ptr<Node<T>> newNext) {
			next = newNext;
		}
	};
}