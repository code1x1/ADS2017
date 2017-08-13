#include "Ringpuffer.h"
#include <iostream>

using namespace std;

Ringpuffer::Ringpuffer()
{
	Anker = nullptr;
	head = tail = Anker;
}


Ringpuffer::~Ringpuffer()
{
	
}

bool Ringpuffer::isFull() const
{
	return tail->getAge() + 1 == N;
}

bool Ringpuffer::isEmtpy() const
{
	return Anker == nullptr;
}

bool Ringpuffer::addNode(std::string Desc, std::string SymbData)
{
	if (isEmtpy())							// Ringbuffer ist leer
	{
		Anker = new RingNode(0,Desc,SymbData);
		tail = head = Anker;
		Anker->setNext(Anker);
	}
	else if(!isFull())
	{
		head->setNext(new RingNode(0, Desc, SymbData));
		head = head->getNext();
		head->setNext(tail);
		RingNode* it = tail;
		while (it != head) 
		{
			it->setAge(it->getAge() + 1);
			it = it->getNext();
		}
		Anker = head;
	}
	else if (isFull())
	{
		head->setNext(new RingNode(0, Desc, SymbData));
		head = head->getNext();
		RingNode* deletable = tail;
		tail = tail->getNext();
		delete deletable;
		head->setNext(tail);
		RingNode* it = tail;
		while (it != head)
		{
			it->setAge(it->getAge() + 1);
			it = it->getNext();
		}
		Anker = head;
	}
	return true;
}

void Ringpuffer::search(std::string Data)
{
	if (isEmtpy())
	{
		cout << "+Datensatz wurde nicht gefunden!.\n";
		return;
	}
	RingNode* tmp = Anker;
	while (tmp->getData() != Data)
	{
		if (tmp->getNext() == head)
			return;
		tmp = tmp->getNext();
	}
	cout << "+ Gefunden in Backup: OldAge " << tmp->getAge()
		<< ", Beschreibung: " << tmp->getDescription()
		<< ", Daten: " << tmp->getData() << "\n";

}

void Ringpuffer::print()
{
	RingNode* it = Anker;
	bool first = true;
	while (it != head || first) 
	{
		cout << "OldAge: " << it->getAge() << ", "
			<< "Descr: " << it->getDescription() << ", "
			<< "Data: " << it->getData() << endl 
			<< "------------------------" << endl;
		it = it->getNext();
		first = false;
	}
}
