#include "Data.h"

/*
Function: Data()
Date Created: 10/19/18
Date Last Modified:10/20/18
Description:
	this is my default constructor
Input parameters: int newCustomerNumber, int newServiceTime, int newTotalTime
Returns: none
Preconditions: none
Postconditions: none
*/

Data::Data(int newCustomerNumber, int newServiceTime, int newTotalTime)
{
	mCustomerNumber = newCustomerNumber;
	mServiceTime = newServiceTime;
	mTotalTime = newTotalTime;
	mCounter = 0;
}

/*
Function: Data()
Date Created: 10/19/18
Date Last Modified:10/20/18
Description:
	this is my copy constructor
Input parameters: Data const & copy
Returns: none
Preconditions: none
Postconditions: none
*/
Data::Data(Data const & copy)
{
	mCustomerNumber = copy.mCustomerNumber;
	mServiceTime = copy.mServiceTime;
	mTotalTime = copy.mTotalTime;
	mCounter = copy.mCounter;
}

/*
Function: ~Data()
Date Created: 10/19/18
Date Last Modified:10/20/18
Description:
	this is my destructor
Input parameters: none
Returns: none
Preconditions: none
Postconditions: none
*/
Data::~Data()
{
}

/*
Function: getCustomerNumber()
Date Created: 10/19/18
Date Last Modified:10/20/18
Description:
	this is a getter function for the customer number
Input parameters: none
Returns: int mCustomerNumber
Preconditions: none
Postconditions: none
*/
int Data::getCustomerNumber() const
{
	return mCustomerNumber;
}

/*
Function: getServiceTime()
Date Created: 10/19/18
Date Last Modified:10/20/18
Description:
	this is a getter function for the service time
Input parameters: none
Returns: int mServiceTime
Preconditions: none
Postconditions: none
*/
int Data::getServiceTime() const
{
	return this->mServiceTime;
}

/*
Function: getTotalTime
Date Created: 10/19/18
Date Last Modified:10/20/18
Description:
	this is a getter function for total time
Input parameters: none
Returns: int mTotalTime
Preconditions: none
Postconditions: none
*/
int Data::getTotalTime() const
{
	return this->mTotalTime;
}

/*
Function: getCounter()
Date Created: 10/19/18
Date Last Modified:10/20/18
Description:
	this is a getter function for a counter
Input parameters: none
Returns: int mCounter
Preconditions:none
Postconditions: none
*/
int Data::getCounter() const
{
	return this->mCounter;
}

/*
Function: setCustomerNumber()
Date Created: 10/19/18
Date Last Modified:10/20/18
Description:
	this is a setter function for the customer number
Input parameters: int newCustomerNumber
Returns: none
Preconditions: none
Postconditions: none
*/
void Data::setCustomerNumber(int newCustomerNumber)
{
	this->mCustomerNumber = newCustomerNumber;
}

/*
Function: setServiceTime()
Date Created: 10/19/18
Date Last Modified:10/20/18
Description:
	this is a setter function for service time
Input parameters: int newServiceTime
Returns: none
Preconditions: none
Postconditions: none
*/
void Data::setServiceTime(int newServiceTime)
{
	this->mServiceTime = newServiceTime;
}

/*
Function: setTotalTime
Date Created: 10/19/18
Date Last Modified:10/20/18
Description: 
	this is a setter function for total time
Input parameters: int newTotalTime
Returns: none
Preconditions:  none
Postconditions: none
*/
void Data::setTotalTime(int newTotalTime)
{
	this->mTotalTime = newTotalTime;
}

/*
Function: setCounter
Date Created: 10/19/18
Date Last Modified:10/20/18
Description:
	this is a settter function for the data memeber counter
Input parameters: int newCounter
Returns: none
Preconditions: none
Postconditions: none
*/
void Data::setCounter(int newCounter)
{
	this->mCounter = newCounter;
}

/*
Function: operator<<
Date Created: 10/19/18
Date Last Modified:10/20/18
Description:
	this is the overloaded insertion operator that prints the data to the screen
Input parameters: ostream & lhs, const Data *rhs
Returns: ostream lhs
Preconditions: the queue must not be nullptr
Postconditions: prints to the screen
*/
ostream & operator<<(ostream & lhs, const Data *rhs)
{
	lhs << "Customer number:" << rhs->getCustomerNumber() << endl;
	lhs << "Service time:" << rhs->getServiceTime() << endl;
	lhs << "Total Time:" << rhs->getTotalTime() << endl << endl;

	return lhs;
}
