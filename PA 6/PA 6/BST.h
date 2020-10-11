#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include"BSTNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;



template<class T, class S>
class BST
{
public:
	//constructor opens, reads, closes file, creates nodes for each character, insert nodes
	//in tree using insert function
	BST();
	~BST();

	//getters
	BSTNode<T, S> getRootPtr() const;

	//insert function
	void insertInTree(T const &newLetterData, S const &newStringData);

	//print function
	void inOrderPrint();

	//Search function
	S searchTree(T const &newChar);
		
	//destroy tree
	void destroyTree();

private:
	BSTNode<T, S> *mpRoot;

	//insert helper function
	void insertInTree(BSTNode<T,S> *pTree, T const &newLetterData, S const &newStringData);
	//inOrderPrint helper function
	void inOrderPrint(BSTNode<T, S> const *pTree);
	//search helper funciton
	S searchTree(BSTNode<T, S> const *pTree, T const &newChar);
	//destroy tree helper function
	void destroyTree(BSTNode<T, S> *pTree);
};

/*
Function: BST()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the defualt constructor for the BST Class, it constructs the morse code look up tree
Input parameters: none
Returns: none
Preconditions: none
Postconditions: creates the morse code look up tree
*/
template<class T, class S>
BST<T, S>::BST()
{
	fstream MorseTable;
	this->mpRoot = nullptr;

	MorseTable.open("MorseTable.txt");
	while (!MorseTable.eof())
	{
		T letter;
		MorseTable >> letter;
		char morseCode[100] = "";
		MorseTable.getline(morseCode,100);
		(S)morseCode;
		insertInTree(letter, morseCode);
	}
	MorseTable.close();

}

/*
Function:~BST()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description: 
	this is the destructor for the BST class, it calls the destroy tree function to deallocate the memory
Input parameters: none
Returns: none
Preconditions: the tree must be created
Postconditions: none
*/
template<class T, class S>
BST<T, S>::~BST()
{
	this->destroyTree();
}

/*
Function: insertInTree()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the insert function that is public that uses the insert helper function. pTree is not an argument ot protect the data member
Input parameters: T const &newLetterData, S const &newStringData
Returns: none
Preconditions: none
Postconditions: none
*/
template<class T, class S>
void BST<T, S>::insertInTree(T const &newLetterData, S const &newStringData)
{
	insertInTree(this->mpRoot, newLetterData, newStringData);
}

/*
Function: inOrderPrint
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the inorder print function that uses the inorder print helper function, this style protects the data member
Input parameters: none
Returns: none
Preconditions:  none
Postconditions: none
*/
template<class T, class S>
void BST<T, S>::inOrderPrint()
{
	inOrderPrint(this->mpRoot);
}

/*
Function:searchTree()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the search tree function that calls the search tree helper function, this helps protect the data member mpRoot
Input parameters: T const &newChar
Returns: S morseCode (template type)
Preconditions: none
Postconditions: return the morsecode string
*/
template<class T, class S>
S BST<T, S>::searchTree(T const &newChar)
{
	S morseCode;
	morseCode = searchTree(this->mpRoot, newChar);
	return morseCode;
}

/*
Function: destroyTree()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the destroy tree function that calls the destroy tree helper function
Input parameters: none
Returns: none
Preconditions: none
Postconditions: none
*/
template<class T, class S>
void BST<T, S>::destroyTree()
{
	destroyTree(mpRoot);
}

/*
Function: getRootPtr()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is a getter function for mpRoot
Input parameters: none
Returns: mpRoot
Preconditions: none
Postconditions: none
*/
template<class T, class S>
BSTNode<T, S> BST<T, S>::getRootPtr() const
{
	return this->mpRoot;
}

/*
Function: insertInTree()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the insertInTree helper function that allocates memory for a new node and inserts it into the tree based on the new letter data
Input parameters: BSTNode<T, S> *pTree, T const &newLetterData, S const &newStringData
Returns: none
Preconditions: needs to be called by the public overloaded function of it
Postconditions: inserts the node into the right spot in the tree
*/
template<class T, class S>
void BST<T, S>::insertInTree(BSTNode<T, S> *pTree, T const &newLetterData, S const &newStringData)
{
	if (pTree != nullptr)
	{
		//left subtree
		if (newLetterData < pTree->getLetterData())
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new BSTNode<T,S>(newLetterData, newStringData));
			}
			else
			{
				insertInTree(pTree->getLeftPtr(), newLetterData, newStringData);
			}
		}
		else if (newLetterData > pTree->getLetterData())
		{
			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(new BSTNode<T,S>(newLetterData, newStringData));
			}
			else
			{
				insertInTree(pTree->getRightPtr(), newLetterData, newStringData);
			}
		}
	}
	else //pTree == nullptr
	{
		this->mpRoot = new BSTNode<T, S>(newLetterData, newStringData);
	}
}

/*
Function: inOrderPrint()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the inorder print function that uses inorder traversal to print the tree in order
Input parameters: BSTNode<T, S> const * pTree
Returns: none
Preconditions: the tree must be created 
Postconditions: none
*/
template<class T, class S>
void BST<T, S>::inOrderPrint(BSTNode<T, S> const * pTree)
{
	if (pTree != nullptr)
	{
		inOrderPrint(pTree->getLeftPtr());
		cout << pTree->getLetterData()<< ":" << pTree->getStringData() << endl;
		inOrderPrint(pTree->getRightPtr());
	}
}

/*
Function: searchTree()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the overloaded search tree function that searchs the morse code loop up tree to find the morse code that corresponds with the target character
Input parameters: BSTNode<T, S> const * pTree, T const &newChar
Returns: S morsecode (template type)
Preconditions: tree must be created
Postconditions: returns the morse code
*/
template<class T, class S>
S BST<T, S>::searchTree(BSTNode<T, S> const * pTree, T const &newChar)
{
		S morseCode;
		
			if (newChar == '\n')
			{
				morseCode = "\n";
				cout << newChar;
			}
			else if (newChar == pTree->getLetterData())
			{
				morseCode = pTree->getStringData();
				cout << newChar << ":" << morseCode << endl;
			}
			else
			{
				if (newChar < pTree->getLetterData())
				{
					if (pTree->getLeftPtr() == nullptr)
					{
						cout << newChar<< ": Error character not found!" << endl;
						return morseCode;
					}
					else if (newChar == pTree->getLeftPtr()->getLetterData())
					{
						morseCode = pTree->getLeftPtr()->getStringData();
						cout << newChar << ":" << morseCode << endl;
					}
					else
					{
						morseCode = searchTree(pTree->getLeftPtr(), newChar);
					}
				}
				else if (newChar > pTree->getLetterData())
				{
					if (pTree->getRightPtr() == nullptr)
					{
						cout << newChar << ": Error character not found!" << endl;
						return morseCode;
					}
					else if (newChar == pTree->getRightPtr()->getLetterData())
					{
						morseCode = pTree->getRightPtr()->getStringData();
						cout << newChar << ":" << morseCode << endl;
					}
					else
					{
						morseCode = searchTree(pTree->getRightPtr(), newChar);
					}
				}
			}
	return morseCode;
}

/*
Function: destroyTree()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the destroy tree funciton that uses the postorder traversal to delete the tree to not get a dangling tree
Input parameters: BSTNode<T, S> * pTree
Returns: none
Preconditions: none
Postconditions: deletes the tree 
*/
template<class T, class S>
void BST<T, S>::destroyTree(BSTNode<T, S> * pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		delete pTree;
	}
}

