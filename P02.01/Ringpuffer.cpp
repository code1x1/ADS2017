#include "Ringpuffer.h"
#include <iostream>


Ringpuffer::Ringpuffer()
{
	Anker = new RingNode[N];
	head = N - 1;
	tail = 0;
}


Ringpuffer::~Ringpuffer()
{
	delete[] Anker;
}

bool Ringpuffer::addNode(RingNode *rn)
{
	if (!isFull()) {
		rn->setAge(0);
		Anker[tail] = *rn;
		tail = (tail + 1) % N;
		return true;
	}
	return false;
}

RingNode Ringpuffer::search(std::string Data)
{
	return RingNode();
}

void Ringpuffer::print()
{
}

bool Ringpuffer::isFull()
{
	if (head == tail) {
		return true;
	}
	return false;
}
