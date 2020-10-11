#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>

#include "TransactionNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

class BST
{
public:
	BST();
	~BST();

	//getter
	Node * getRoot() const;
	//setter
	void setRoot(Node * const &newRoot);

	void insert(int const newUnits, string const &newString); //used to hide pointer info //maybe change to bool
	void inOrderTraversal();

	TransactionNode findSmallest(Node *pTree); //finds smallest mUnits			//this needs to return a reference to a transactionNode
	TransactionNode findLargest(Node *pTree); //finds largest mUnits			//this needs to return a reference to a transactionNode
	
private:
	Node *mpRoot;
	//helper functions
	void destroyTree(Node *pTree); //should visit each nod in postOrder
	void insert(Node *&pTree, int const newUnits, string const &newString);
	//dynamically allocates a TransactionNode and inserts recursively in correct
	//subtree based on mUnits
	void inOrderTraversal(Node *pTree);
	//recursibely visits and prints the contents (mData and mUnits) of each node in tree
	//in order; each node's printData() should be called contents should be printed on
	//seperate line; must call printData() funciton associated w/ TransactionNode
};

int seperateStr(string const &newString);