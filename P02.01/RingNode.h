#pragma once
#include <string>
class RingNode
{
	int OldAge;
	std::string Description;
	std::string SymbolicData;
public:
	RingNode* next;
	RingNode();
	~RingNode();
	int getAge();
	void setAge(int);
	std::string getDescription();
	void setDescription(std::string);
	std::string getData();
	void setData(std::string);
};

