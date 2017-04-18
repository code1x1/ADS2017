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
	Node * head, * tail;
	int _size;
public:
	List();
//	List(List & _List);				// Copy Operator überladen
	~List();
	void InsertFront(T key);		// Einfügen eines Knotens am Anfang
	void InsertBack(T key);		// Einfügen eines Knotesn am Ende
	bool getFront(T & key);		// Entnehmen eines Knoten am Anfang
	bool getBack(T & key);		// Entnehmen eines Knoten am Ende
	bool del(T key);			// löschen eines Knotens [key]
	bool search(T key);			// Suchen eines Knoten
	bool swap(T key1, T key2);	// Knoten in der Liste vertauschen
	int size(void);					// Größe der Lise (Anzahl der Knoten)
	bool test(void);				// Überprüfen der Zeigerstruktur der Liste
	void format(const std::string &start, const std::string &zwischen, const std::string &ende); // Mit der format−Methode kann die Ausgabe gesteuert werden: operator <<
	List<T> & operator=(const List<T> &_List); // Zuweisungsoperator definieren
	List<T> & operator=(const List<T> ∗_List); // Zuweisungsoperator definieren
	List<T> & operator+(const List<T> &List_Append) const; // Listen zusammenfuehren zu einer Liste
	List<T> & operator+(const List<T> ∗List_Append) const; // Listen zusammenfuehren zu einer Liste
/*	template <typename T>
	friend std::ostream & operator << (std::ostream & stream, const List<T> &Liste);*/ // Ausgabeoperator ueberladen
	template <typename T>
	friend std::ostream & operator << (std::ostream & stream, const List<T> ∗Liste); // Ausgabeoperator ueberladen
};


template <class T>
List::List()
{
	head = new Node<T>;
	tail = new Node<T>;
	_size = 0;
	head->next = tail;
	tail->prev = head;
}
template <class T>
List::~List()
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
template <class T>
void List::InsertFront(T key)
{
	//( ... Erweitern Sie die Methode so, dass ein neuer Knoten Node vorne
	//	(hinter dem Knoten head) in die Liste eingefügt wird. )
	Node<T>* headnext = head->next;
	Node<T>* newnode = new Node<T>(key, headnext, head);
	head->next = newnode;
	headnext->prev = newnode;
	_size++;
}
template <class T>
void List::InsertBack(T key)
{
	//( ... Erweitern Sie die Methode so, dass ein neuer Knoten Node hinten
	//	(vor dem Knoten tail) in die Liste eingefügt wird. )
	Node<T>* tailprev = tail->prev;
	Node<T>* newnode = new Node<T>(key, tail, tailprev);
	tail->prev = newnode;
	tailprev->next = newnode;
	_size++;
}
template <class T>
bool List::getFront(T & key)
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
template <class T>
bool List::getBack(T & key)
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
template <class T>
bool List::del(T key)
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
template <class T>
bool List::search(T key)
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
template <class T>
bool List::swap(T key1, T key2)
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
template <class T>
int List::size()
{
	//(... Die Methode gibt den Wert von size (Anzahl der Knoten in der Liste) zurück. )
	return _size;
}
template <class T>
bool List::test()
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
template <class T>
void List<T>::format(const std::string &start, const std::string &zwischen, const std::string &ende)
{
	_form.start = start;
	_form.zwischen = zwischen;
	_form.ende = ende;
}
template <class T>
List<T> & List<T>::operator = (const List<T> &_List)
{
	// in dem Objekt List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return ∗this; // !! keine Aktion notwendig
	Node<T> ∗ tmp_node;
	if (_size)
	{
		Node<T> ∗ tmp_del;
		tmp_node = head−>next;
		while (tmp_node != tail) // Alle eventuell vorhandenen Knoten in this loeschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node−>next;
			delete tmp_del;
		}
		_size = 0;
		head−>next = tail;
		tail−>prev = head;
	}
	tmp_node = _List.head−>next;
	while (tmp_node != _List.tail)
	{
		InsertBack(tmp_node−>key);
		tmp_node = tmp_node−>next;
	}
	return ∗this;
}
template <class T>
List<T> & List<T>::operator = (const List<T> ∗_List)
{
	// in dem Objekt List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return ∗this; // !! keine Aktion notwendig
	Node<T> ∗ tmp_node;
	if (_size)
	{
		Node<T> ∗ tmp_del;
		tmp_node = head−>next;
		while (tmp_node != tail) // Alle eventuell vorhandenen Knoten in this loeschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node−>next;
			delete tmp del;
		}
		_size = 0;
		head−>next = tail;
		tail−>prev = head;
	}
	tmp_node = _List.head−>next;
	while (tmp_node != _List.tail)
	{
		InsertBack(tmp_node−>key);
		tmp_node = tmp_node−>next;
	}
	return ∗this;
}
template <class T>
List<T> & List<T>::operator + (List<T> const &List_Append) const
{
	List<T> ∗ tmp = new List<T>;
	Node<T> ∗ tmp_node;
	tmp_node = head− >next;
	while (tmp_node != tail)
	{
		tmp−>InsertBack(tmp_node− >key);
		tmp_node = tmp_node−>next;
	}
	if (!List_Append._size) return ∗tmp;
	tmp_node = List_Append.head−>next;
	while (tmp_node != List_Append.tail)
	{
		tmp−>InsertBack(tmp_node−>key);
		tmp_node = tmp_node−>next;
	}
	return ∗tmp;
}
template <class T>
List<T> & List<T>::operator + (List<T> const ∗List_Append) const
{
	List<T> ∗ tmp = new List<T>;
	Node<T> ∗ tmp_node;
	tmp_node = head−>next;
	while (tmp_node != tail)
	{
		tmp−>InsertBack(tmp node−>key);
		tmp_node = tmp_node−>next;
	}
	if (!List_Append−>_size) return ∗tmp;
	tmp_node = List_Append−>head−>next;
	while (tmp_node != List_Append−>tail)
	{
		tmp−>InsertBack(tmp_node−>key);
		tmp_node = tmp_node−>next;
	}
	return ∗tmp;
}
//template <class T>
//std::ostream & operator << (std::ostream & stream, const List<T> &Liste)
//{
//	stream << Liste._form.start;
//	for (Node<T> ∗ tmp = Liste.head−>next; tmp != Liste.tail; tmp = tmp−>next)
//		stream << tmp−>key << (tmp−>next == Liste.tail ? Liste._form.ende : Liste._form.zwischen
//			);
//	return stream;
//}
template <class T>
std::ostream & operator << (std::ostream & stream, const List<T> ∗Liste)
{
	stream << Liste−>_form.start;
	for (Node<T> ∗tmp = Liste−>head−>next; tmp != Liste−>tail; tmp = tmp−>next)
	stream << tmp−>key << (tmp−>next == Liste−>tail ? Liste−>_form.ende : Liste−>_form.
		zwischen);
	return stream;
}



#endif