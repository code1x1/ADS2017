#pragma once
#include"TreeNode.h"
#include<string>
class Tree
{
	TreeNode* anker;
	TreeNode* nullnode;
	TreeNode* wurzel;
public:
	Tree();
	~Tree();
	void insertNode(std::string name, int alter, double einkommen, int plz);
	void insertCSV(std::string csv);
	bool deleteNode(int PosID);
	void printPreorder();
};

