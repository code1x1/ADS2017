#include "Ringpuffer.h"
#include <iostream>

using namespace std;

Ringpuffer::Ringpuffer()
{
	Anker = nullptr;
}


Ringpuffer::~Ringpuffer()
{
	
}

bool Ringpuffer::addNode(std::string Desc, std::string SymbData)
{
	RingNode* rn = new RingNode();
	rn->setAge(0);
	rn->setData(SymbData);
	rn->setDescription(Desc);
	rn->setNext(Anker);
	Anker = rn;
	RingNode* tmp = Anker;
	int i = 0;
	while (tmp == nullptr)
	{
		tmp->setAge(i);
		tmp = tmp->getNext();
	}
	return true;
}

void Ringpuffer::search(std::string Data)
{
	RingNode* tmp = Anker;
	while (tmp->getData != Data)
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
