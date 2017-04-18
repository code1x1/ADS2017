#include "List.h"
List::List()
{
	head = new Node;
	tail = new Node;
	_size = 0;
	head->next = tail;
	tail->prev = head;
}
List::~List()
{
	//( ... löschen Sie alle noch vorhandenen Knoten Node dieser Instanz 
	//	Denken Sie auch den die Knoten head und tail.)
	while (head->next != tail)
	{
		int k = head->next->key;
		del(k);
	}
	delete head, tail;
}
void List::InsertFront(int key)
{
	//( ... Erweitern Sie die Methode so, dass ein neuer Knoten Node vorne
	//	(hinter dem Knoten head) in die Liste eingefügt wird. )
	Node* headnext = head->next;
	Node* newnode = new Node(key,headnext,head);
	head->next = newnode;
	headnext->prev = newnode;
	_size++;
}
void List::InsertBack(int key)
{
	//( ... Erweitern Sie die Methode so, dass ein neuer Knoten Node hinten
	//	(vor dem Knoten tail) in die Liste eingefügt wird. )
	Node* tailprev = tail->prev;
	Node* newnode = new Node(key,tail,tailprev);
	tail->prev = newnode;
	tailprev->next = newnode;
	_size++;
}
bool List::getFront(int & key)
{
	//( ... Erweitern Sie die Methode so, dass der erste Knoten der Liste
	//	(hinter head) zurückgegeben und dieser Knoten dann gelöscht wird.
	//	Im Erfolgsfall geben Sie true zurück, sonst false. )

	if (head->next != tail)
	{
		Node* frontnode = head->next;
		key = frontnode->key;
		Node* frontnext = frontnode->next;
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
bool List::getBack(int & key)
{
	//(... Erweitern Sie die Methode so, dass der letzte Knoten der Liste
	//	(vor tail) zurückgegeben und dieser Knoten dann gelöscht wird.
	//	Im Erfolgsfall geben Sie true zurück, sonst false. )

	if (tail->prev != head)
	{
		Node* backnode = tail->prev;
		key = backnode->key;
		Node* backprev = backnode->prev;
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
bool List::del(int key)
{
	//(... Die Methode del sucht den Knoten mit dem Wert Key und löscht diesen
	//	im Erfolgsfall aus der Liste.
	//	Im Erfolgsfall geben Sie true zurück, sonst false. )
	Node* search = head;
	while (search->key != key && search != tail)
	{
		search = search->next;
		if (search->key == key) 
		{
			Node* prevsearch = search->prev;
			Node* nextsearch = search->next;
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
bool List::search(int key)
{
	//(... Die Methode search sucht den Knoten mit dem Wert key
	//	Im Erfolgsfall geben Sie true zurück, sonst false. )
	Node* search = head;
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
bool List::swap(int key1, int key2)
{
	//(... Die Methode swap sucht den Knoten mit dem Wert key1,
	//	dann den Knoten mit dem Wert key2. Diese Knoten werden dann
	//	getauscht, indem die Zeiger der Knoten entsprechend geändert
	//	werden. )
	Node* key1n = head;
	Node* key2n = head;
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
	Node* key1nprev = key1n->prev;
	Node* key1nnext = key1n->next;
	Node* key2nprev = key2n->prev;
	Node* key2nnext = key2n->next;

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
int List::size(void)
{
	//(... Die Methode gibt den Wert von size (Anzahl der Knoten in der Liste) zurück. )
	return _size;
}
bool List::test(void)
{
	//(... Die Methode überprüft die Pointer der Liste. Gestartet wird mit head. Es werden alle 
	//	Knoten bis zum tail durchlaufen von dort aus dann die prev-Zeiger bis zum head.
	//	Bei Erfolg wird true zurück gegeben. )
	Node* nodetest = head->next;
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
void List::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	// Setzen der Formatierung für den überladenen Streamingoperator <<
	_form.start = start;			// Ausgabe zu Beginn der Liste
	_form.zwischen = zwischen;		// Ausgabe zwischen zwei Knoten
	_form.ende = ende;				// Ausgabe am Ende der Liste
}
List & List::operator = (const List & _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == & _List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{
		Node * tmp_del;
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
List & List::operator = (const List * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{	
		Node * tmp_del;
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
	return * this;
}
List & List::operator + (const List & List_Append) const
{
	List * tmp = new List;
	Node * tmp_node;
	tmp_node = head->next;
	while (tmp_node != tail){
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (!List_Append._size) return * tmp;
	tmp_node = List_Append.head->next;
	while (tmp_node != List_Append.tail){
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	return * tmp;
}
List & List::operator + (const List * List_Append) const
{
	List * tmp = new List;
	Node * tmp_node;
	tmp_node = head->next;
	while (tmp_node != tail){
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (!List_Append->_size) return *tmp;
	tmp_node = List_Append->head->next;
	while (tmp_node != List_Append->tail){
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	return *tmp;
}
std::ostream & operator<<(std::ostream  & stream, List const & Liste)
{
	stream << Liste._form.start;
	for (Node * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	return stream;
}
std::ostream & operator << (std::ostream & stream, List const * Liste)
{
	stream << Liste->_form.start;
	for (Node * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	return stream;
}