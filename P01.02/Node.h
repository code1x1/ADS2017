#ifndef _NODE_H
#define _NODE_H

template <class T>
class Node
{
public:
	T key;
	Node * next, * prev;
public:
	template<class T>
	Node();
	template <class T>
	Node(T key, Node<T> * next = 0, Node<T> * prev = 0);
	~Node();
};

template <class T>
Node::Node() 
{
}

template <class T>
Node::Node(T key, Node<T> * next, Node<T> * prev)
{
	this->key = key;
	this->next = next;
	this->prev = prev;
}
template <class T>
Node::~Node()
{
}


#endif