#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

template<class T, class S>
class BSTNode
{
public:
	BSTNode(T const &newLetterData, S const &newStringData);
	BSTNode(BSTNode<T, S> const &copy);
	~BSTNode();

	//copy assignment operator 
	BSTNode<T, S> & operator=(BSTNode<T, S> const &rhs);

	//getters
	T getLetterData() const;
	S getStringData() const;
	BSTNode<T, S> * getLeftPtr() const;
	BSTNode<T, S> * getRightPtr() const;

	//setters
	void setLetterData(T const &newLData);
	void setStringData(S const &newSData);
	void setLeftPtr(BSTNode<T, S> * const &newLeftPtr);
	void setRightPtr(BSTNode<T, S> * const &newRightPtr);



private:
	T mLetterData;
	S mStringData; 
	BSTNode<T,S> *mpLeft;
	BSTNode<T,S> *mpRight;
};

/*
Function: BSTNode()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	This is the defualt constructor for the BSTNode class, the input types are template types
Input parameters: T const &newLetterData, S const &newStringData
Returns: none
Preconditions: the type has to declared for the inputs
Postconditions: none
*/
template<class T, class S>
BSTNode<T, S>::BSTNode(T const &newLetterData, S const &newStringData)
{
	this->mLetterData = newLetterData;
	this->mStringData = newStringData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

/*
Function: BSTNode()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the copy constructor for the BSTNode class
Input parameters: BSTNode<T, S> const &copy
Returns: none
Preconditions: none
Postconditions: none
*/
template<class T, class S>
BSTNode<T, S>::BSTNode(BSTNode<T, S> const &copy)
{
	this->mLetterData = copy.mLetterData;
	this->mStringData = copy.mStringData;
	this->mpLeft = copy.mpLeft;
	this->mpRight = copy.mpRight;
}

/*
Function: ~BSTNode()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the destructor for the BSTNode class
Input parameters:none
Returns: none
Preconditions: none
Postconditions: none
*/
template<class T, class S>
BSTNode<T, S>::~BSTNode()
{
}

/*
Function: operator=()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is the overloaded copy assignment operator for the BSTNode class
Input parameters: BSTNode<T, S> const &rhs
Returns: none
Preconditions: none
Postconditions: none
*/
template<class T, class S>
BSTNode<T, S> & BSTNode<T, S>::operator=(BSTNode<T, S> const &rhs)
{
	if (this != &rhs)
	{
		this->mLetterData = rhs.getLetterData();
		this->mStringData = rhs.getStringData();
		this->mpLeft = rhs.getLeftPtr();
		this->mpRight = rhs.getRightPtr();
	}
}

/*
Function: getLetterData()
Date Created: 10/22/18
Date Last Modified:10/23/18
Description:
	this is a getter funciton to get the letter data 
Input parameters: none
Returns: return type T mLetterData
Preconditions: none
Postconditions: none
*/
template<class T, class S>
 T BSTNode<T, S>::getLetterData() const
{
	return this->mLetterData;
}

 /*
 Function: getStringData()
 Date Created: 10/22/18
 Date Last Modified:10/23/18
 Description:
	this is a getter funciton to get the string data
 Input parameters: none
 Returns: return type T mStringData
 Preconditions: none
 Postconditions: none
 */
 template<class T, class S>
 S BSTNode<T, S>::getStringData() const
 {
	 return this->mStringData;
 }

 /*
 Function: getLeftPtr()
 Date Created: 10/22/18
 Date Last Modified:10/23/18
 Description:
	this is a getter funciton to get the left pointer
 Input parameters: none
 Returns: mpLeft
 Preconditions: none
 Postconditions: none
 */
 template<class T, class S>
 BSTNode<T, S> * BSTNode<T, S>::getLeftPtr() const
 {
	 return this->mpLeft;
 }

 /*
 Function: getRightPtr()
 Date Created: 10/22/18
 Date Last Modified:10/23/18
 Description:
	this is a getter funciton to get the right pointer
 Input parameters: none
 Returns: mpRight
 Preconditions: none
 Postconditions: none
 */
 template<class T, class S>
 BSTNode<T, S> * BSTNode<T, S>::getRightPtr() const
 {
	 return this->mpRight;
 }

 /*
 Function: setLetterData()
 Date Created: 10/22/18
 Date Last Modified:10/23/18
 Description:
	this is a setter function for the letter data
 Input parameters: T const &newLData
 Returns: none
 Preconditions: none
 Postconditions: none
 */
 template<class T, class S>
 void BSTNode<T, S>::setLetterData(T const &newLData)
 {
	 this->mLetterData = newLData;
 }

 /*
 Function: setStringData()
 Date Created: 10/22/18
 Date Last Modified:10/23/18
 Description:
	this is a setter function for the string data
 Input parameters: T const &newSData
 Returns: none
 Preconditions: none
 Postconditions: none
 */
 template<class T, class S>
 void BSTNode<T, S>::setStringData(S const &newSData)
 {
	 this->mStringData = newSData;
 }

 /*
 Function: setLeftPtr()
 Date Created: 10/22/18
 Date Last Modified:10/23/18
 Description:
	this is a setter function for the left pointer
 Input parameters: T const &newLeftPtr
 Returns: none
 Preconditions: none
 Postconditions: none
 */
 template<class T, class S>
 void BSTNode<T, S>::setLeftPtr(BSTNode<T, S> * const &newLeftPtr)
 {
	 this->mpLeft = newLeftPtr;
 }

 /*
 Function: setRightPtr()
 Date Created: 10/22/18
 Date Last Modified:10/23/18
 Description:
	 this is a setter function for the right pointer
 Input parameters: T const &newRightPtr
 Returns: none
 Preconditions: none
 Postconditions: none
 */
 template<class T, class S>
 void BSTNode<T, S>::setRightPtr(BSTNode<T, S> * const &newRightPtr)
 {
	 this->mpRight = newRightPtr;
 }









 /*
 Function: 
 Date Created: 10/22/18
 Date Last Modified:10/23/18
 Description:
 Input parameters: 
 Returns: 
 Preconditions: 
 Postconditions: 
 */