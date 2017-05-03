#include "RingNode.h"



RingNode::RingNode()
{
}


RingNode::~RingNode()
{
}

int RingNode::getAge()
{
	return OldAge;
}

void RingNode::setAge(int a)
{
	OldAge = a;
}

std::string RingNode::getDescription()
{
	return Description;
}

void RingNode::setDescription(std::string s)
{
	Description = s;
}

std::string RingNode::getData()
{
	return SymbolicData;
}

void RingNode::setData(std::string s)
{
	SymbolicData = s;
}

RingNode * RingNode::getNext()
{
	return next;
}

void RingNode::setNext(RingNode * n)
{
	next = n;
}
