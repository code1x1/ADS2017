#include "Ringpuffer.h"
#include <iostream>

using namespace std;

Ringpuffer::Ringpuffer()
{
	Anker = new RingNode();
	head = tail = Anker;
}


Ringpuffer::~Ringpuffer()
{
	
}

bool Ringpuffer::addNode(std::string Desc, std::string SymbData)
{
	if (tail == head)		// Ringbuffer ist leer!
	{
		Anker->setAge(0);
		Anker->setDescription(Desc);
		Anker->setData(SymbData);
	}

}

void Ringpuffer::search(std::string Data)
{
	RingNode* tmp = Anker;
	while (tmp->getData() != Data)
	{
		if (tmp = nullptr)
		{
			cout << "+Datensatz wurde nicht gefunden!.\n";
			return;
		}
		tmp = tmp->getNext();
	}
	cout << "+ Gefunden in Backup: OldAge " << tmp->getAge()
		<< ", Beschreibung: " << tmp->getDescription()
		<< ", Daten: " << tmp->getData() << "\n";

}

void Ringpuffer::print()
{
}
