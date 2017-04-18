#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
#include <string>
#include <iostream>

template <class T>
class List 
{
/* 
	Die Klasse List dient zur Verwaltung von Knoten (Node). Mit Hilfe der Klasse List
	kann ein Stapel oder Warteschlange realisiert werden.
*/
private:
	struct form { std::string start = "<< "; std::string zwischen = ", "; std::string ende = " >>\n"; } _form;
	Node<T> * head, * tail;
	int _size;
public:

	List()
	{
		head = new Node<T>;
		tail = new Node<T>;
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}

	~List()
	{
		//( ... löschen Sie alle noch vorhandenen Knoten Node dieser Instanz 
		//	Denken Sie auch den die Knoten head und tail.)
		while (head->next != tail)
		{
			T k = head->next->key;
			del(k);
		}
		delete head, tail;
	}
	
	void InsertFront(T key)
	{
		//( ... Erweitern Sie die Methode so, dass ein neuer Knoten Node vorne
		//	(hinter dem Knoten head) in die Liste eingefügt wird. )
		Node<T>* headnext = head->next;
		Node<T>* newnode = new Node<T>(key, headnext, head);
		head->next = newnode;
		headnext->prev = newnode;
		_size++;
	}
	
	void InsertBack(T key)
	{
		//( ... Erweitern Sie die Methode so, dass ein neuer Knoten Node hinten
		//	(vor dem Knoten tail) in die Liste eingefügt wird. )
		Node<T>* tailprev = tail->prev;
		Node<T>* newnode = new Node<T>(key, tail, tailprev);
		tail->prev = newnode;
		tailprev->next = newnode;
		_size++;
	}
	
	bool getFront(T & key)
	{
		//( ... Erweitern Sie die Methode so, dass der erste Knoten der Liste
		//	(hinter head) zurückgegeben und dieser Knoten dann gelöscht wird.
		//	Im Erfolgsfall geben Sie true zurück, sonst false. )

		if (head->next != tail)
		{
			Node<T>* frontnode = head->next;
			key = frontnode->key;
			Node<T>* frontnext = frontnode->next;
			head->next = frontnext;
			frontnext->prev = head;
			delete frontnode;
			_size--;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool getBack(T & key)
	{
		//(... Erweitern Sie die Methode so, dass der letzte Knoten der Liste
		//	(vor tail) zurückgegeben und dieser Knoten dann gelöscht wird.
		//	Im Erfolgsfall geben Sie true zurück, sonst false. )

		if (tail->prev != head)
		{
			Node<T>* backnode = tail->prev;
			key = backnode->key;
			Node<T>* backprev = backnode->prev;
			tail->prev = backprev;
			backprev->next = tail;
			delete backnode;
			_size--;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool del(T key)
	{
		//(... Die Methode del sucht den Knoten mit dem Wert Key und löscht diesen
		//	im Erfolgsfall aus der Liste.
		//	Im Erfolgsfall geben Sie true zurück, sonst false. )
		Node<T>* search = head;
		while (search->key != key && search != tail)
		{
			search = search->next;
			if (search->key == key)
			{
				Node<T>* prevsearch = search->prev;
				Node<T>* nextsearch = search->next;
				prevsearch->next = nextsearch;
				nextsearch->prev = prevsearch;
				delete search;
				_size--;
				return true;
			}

		}
		search = nullptr;
		delete search;
		return false;
	}
	
	bool search(T key)
	{
		//(... Die Methode search sucht den Knoten mit dem Wert key
		//	Im Erfolgsfall geben Sie true zurück, sonst false. )
		Node<T>* search = head;
		while (search->key != key && search != tail)
		{
			search = search->next;
			if (search->key == key)
			{
				search = nullptr;
				delete search;
				return true;
			}

		}
		search = nullptr;
		delete search;
		return false;
	}
	
	bool swap(T key1, T key2)
	{
		//(... Die Methode swap sucht den Knoten mit dem Wert key1,
		//	dann den Knoten mit dem Wert key2. Diese Knoten werden dann
		//	getauscht, indem die Zeiger der Knoten entsprechend geändert
		//	werden. )
		Node<T>* key1n = head;
		Node<T>* key2n = head;
		while (key1n->key != key1)
		{
			key1n = key1n->next;
			if (key1n == tail) {
				key1n = key2n = nullptr;
				delete key1n, key2n;
				return false;
			}
		}

		while (key2n->key != key2)
		{
			key2n = key2n->next;
			if (key2n == tail) {
				key1n = key2n = nullptr;
				delete key1n, key2n;
				return false;
			}
		}
		Node<T>* key1nprev = key1n->prev;
		Node<T>* key1nnext = key1n->next;
		Node<T>* key2nprev = key2n->prev;
		Node<T>* key2nnext = key2n->next;

		// key1 zeiger verändern

		key1n->next = key2nnext;
		key1n->prev = key2nprev;
		key2nnext->prev = key1n;
		key2nprev->next = key1n;


		// key2 zeiger verändern

		key2n->next = key1nnext;
		key2n->prev = key1nprev;
		key1nnext->prev = key2n;
		key1nprev->next = key2n;

		key1n = key2n =
			key1nprev = key1nnext =
				key2nprev = key2nnext = nullptr;
		delete key1n, key2n, key1nprev, key1nnext, key2nprev, key2nnext;
		return true;
	}
	
	int size()
	{
		//(... Die Methode gibt den Wert von size (Anzahl der Knoten in der Liste) zurück. )
		return _size;
	}
	
	bool test()
	{
		//(... Die Methode überprüft die Pointer der Liste. Gestartet wird mit head. Es werden alle 
		//	Knoten bis zum tail durchlaufen von dort aus dann die prev-Zeiger bis zum head.
		//	Bei Erfolg wird true zurück gegeben. )
		Node<T>* nodetest = head->next;
		while (nodetest != tail)
		{
			nodetest = nodetest->next;
			if (nodetest == nullptr)
				return false;
		}
		while (nodetest != head)
		{
			nodetest = nodetest->prev;
			if (nodetest == nullptr)
				return false;
		}
		return true;
	}
	
	void format(const std::string &start, const std::string &zwischen, const std::string &ende)
	{
		_form.start = start;
		_form.zwischen = zwischen;
		_form.ende = ende;
	}
	
	List<T> & operator = (const List<T> & _List)
	{
		// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
		// Kopiert wird in das Objekt "this"
		if (this == &_List) return *this;	//  !! keine Aktion notwendig
		Node<T> * tmp_node;
		if (_size)
		{
			Node<T> * tmp_del;
			tmp_node = head->next;
			while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this löschen
			{
				tmp_del = tmp_node;
				tmp_node = tmp_node->next;
				delete tmp_del;
			}
			_size = 0;
			head->next = tail;
			tail->prev = head;
		}
		tmp_node = _List.head->next;
		while (tmp_node != _List.tail)
		{
			InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
		return *this;
	}

	List<T> & operator = (const List<T> *_List)
	{
		 //in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
		 //Kopiert wird in das Objekt "this"
		if (this == &_List) return *this;	//  !! keine Aktion notwendig
		Node<T> *tmp_node;
		if (_size)
		{
			Node<T> *tmp_del;
			tmp_node = head->next;
			while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this löschen
			{
				tmp_del = tmp_node;
				tmp_node = tmp_node->next;
				delete tmp_del;
			}
			_size = 0;
			head->next = tail;
			tail->prev = head;
		}
		tmp_node = _List->head->next;
		while (tmp_node != _List->tail)
		{
			InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
		return *this;
	}

	List<T> & operator + (const List<T> & List_Append) const
	{
		List<T> * tmp = new List;
		Node<T> * tmp_node;
		tmp_node = head->next;
		while (tmp_node != tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
		if (!List_Append._size) return *tmp;
		tmp_node = List_Append.head->next;
		while (tmp_node != List_Append.tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
		return *tmp;
	}

	List<T> & operator + (const List<T> * List_Append) const
	{
		List<T> * tmp = new List<T>;
		Node<T> * tmp_node;
		tmp_node = head->next;
		while (tmp_node != tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
		if (!List_Append->_size) return *tmp;
		tmp_node = List_Append->head->next;
		while (tmp_node != List_Append->tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
		return *tmp;
	}

	template<typename T>
	friend std::ostream & operator<<(std::ostream  & stream, List<T> const & Liste);

	template<typename T>
	friend std::ostream & operator << (std::ostream & stream, List<T> const * Liste);
};


template<class T>
std::ostream & operator<<(std::ostream  & stream, List<T> const & Liste)
{
	stream << Liste._form.start;
	for (Node<T> * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	return stream;
}

template<class T>
std::ostream & operator<<(std::ostream & stream, List<T> const * Liste)
{
	stream << Liste->_form.start;
	for (Node<T> * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	return stream;
}

#endif