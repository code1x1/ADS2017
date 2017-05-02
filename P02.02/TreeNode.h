#pragma once
#include<string>
class TreeNode
{
	int NodePosID;
	int NodeID;
	std::string Name;
	int Alter;
	double Einkommen;
	int PLZ;
	TreeNode *links;
	TreeNode *rechts;
public:
	TreeNode();
	~TreeNode();
	std::string getName();
	int getAlter();
	double getEinkommen();
	int getPLZ();
	void setName(std::string);
	void setAlter(int);
	void setEinkommen(double);
	void setPLZ(int);
	void printData();
};

