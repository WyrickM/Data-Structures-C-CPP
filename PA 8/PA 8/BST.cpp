#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
}

BST::~BST()
{
	this->destroyTree(this->mpRoot);
}

Node * BST::getRoot() const
{
	return this->mpRoot;
}

void BST::setRoot(Node * const & newRoot)
{
	this->mpRoot = newRoot;
}

void BST::insert(int const newUnits, string const &newString)
{
	this->insert(this->mpRoot, newUnits, newString);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(this->mpRoot);
}

TransactionNode BST::findSmallest(Node *pTree)
{
	TransactionNode pTemp;
	int temp = 0;

	while (pTree != nullptr)
	{
		pTree = pTree->getLeftPtr();
		if (pTree->getLeftPtr() == nullptr)
		{
			temp = seperateStr(pTree->getData());
			pTemp.setUnits(temp);
			pTemp.setData(pTree->getData());
			return pTemp;
		}
	}
}

TransactionNode BST::findLargest(Node *pTree)
{
	TransactionNode pTemp;
	int temp = 0;

	while (pTree != nullptr)
	{
		pTree = pTree->getRightPtr();
		if (pTree->getRightPtr() == nullptr)
		{
			temp = seperateStr(pTree->getData());
			pTemp.setUnits(temp);
			pTemp.setData(pTree->getData());
			return pTemp;
		}
	}
}

void BST::destroyTree(Node * pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		delete pTree;
	}
}

void BST::insert(Node *&pTree, int const newUnits, string const &newString)
{
	int temp = 0;
	if (pTree != nullptr)
	{
		temp = seperateStr(pTree->getData());
		if (newUnits < temp)
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new TransactionNode(newUnits, newString)); //need to pass in units to add to the new TR node
			}
			else
			{
				insert(pTree->getLeftPtr(), newUnits,  newString);
			}
		}
		else if (newUnits > temp)
		{
			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(new TransactionNode(newUnits, newString));
			}
			else
			{
				insert(pTree->getRightPtr(), newUnits, newString);
			}
		}
	}
	else
	{
		this->mpRoot = new TransactionNode(newUnits, newString);
	}
}

void BST::inOrderTraversal(Node *pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeftPtr());
		pTree->printData();
		inOrderTraversal(pTree->getRightPtr());
	}
}

//this is how you seperate a comma seperated string
int seperateStr(string const & newString)
{
	std::istringstream ss(newString); //this puts a string into a stream/file so you can use getline and a delimiter to seperate
	char newUn[100];
	string tempUni = "";
	int units = 0;

	ss.getline(newUn, 100, ',');  //ss is the stream/file
	tempUni = newUn;
	units = stoi(tempUni);
	return units;
}
