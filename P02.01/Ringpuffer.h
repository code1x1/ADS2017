#pragma once
#include"RingNode.h"
class Ringpuffer
{
	RingNode* Anker;
	const int N = 6;
	int head;
	int tail;
public:
	Ringpuffer();
	~Ringpuffer();
	bool addNode(RingNode*);
	RingNode search(std::string Data);
	void print();
	bool isFull();

};

