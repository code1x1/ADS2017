#ifndef _NODE_H
#define _NODE_H

template <class T>
class Node
{
public:
	T key;
	Node<T> * next, * prev;
public:
	Node() {
		
		key = T();
		next = 0;
		prev = 0;
	}

	template <class T>
	Node(T key, Node<T> * next = 0, Node<T> * prev = 0) {
		this->key = key;
		this->next = next;
		this->prev = prev;
	}

	~Node() {

	}
};

#endif