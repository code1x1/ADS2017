#pragma once
#include"RingNode.h"
class Ringpuffer
{
	RingNode* Anker;
	RingNode* head;
	RingNode* tail;
	const int N = 6;
public:
	Ringpuffer();
	~Ringpuffer();
	bool addNode(std::string Desc, std::string SymbData);
	void search(std::string Data);
	void print();
	

};

