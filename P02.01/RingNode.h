#pragma once
#include <string>
class RingNode
{
	int OldAge;
	std::string Description;
	std::string SymbolicData;
	RingNode* next;
public:
	RingNode();
	~RingNode();
	int getAge();
	void setAge(int);
	std::string getDescription();
	void setDescription(std::string);
	std::string getData();
	void setData(std::string);
	RingNode* getNext();
	void setNext(RingNode*);
};

