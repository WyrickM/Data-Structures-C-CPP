#include "DietPlan.h"

/*
Function: Diet
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is the defualt constructor
Input parameters: int newCals, string newName, string newDate
Returns: none
Preconditions: none
Postconditions: none
*/
Diet::Diet(int newCals, string newName, string newDate)
{
	mGoalCals = newCals;
	mPlanName = newName;
	mDate= newDate;
}

/*
Function: Diet
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is the copy constructor
Input parameters: Diet & copy
Returns: none
Preconditions: none
Postconditions: none
*/
Diet::Diet(Diet & copy)
{
	this->setCals(copy.getCals());
	this->setName(copy.getName());
	this->setDate(copy.getName());
}

/*
Function: ~Diet()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is the destructor
Input parameters: none
Returns: none
Preconditions: none
Postconditions: none
*/
Diet::~Diet()
{
	//no dynamic memory yet does nothing, if i use a list need to delete nodes 
}

/*
Function: getCals()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function is a getter to get the mGoalCals which is a private data member
Input parameters: none
Returns: int mGoalCals
Preconditions: none
Postconditions: none
*/
int Diet::getCals() const
{
	return mGoalCals;
}

/*
Function: getName
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function is a getter to get the mPlanName which is a private data member
Input parameters: none
Returns: string mPlanName
Preconditions: none
Postconditions: none
*/
string Diet::getName() const
{
	return mPlanName;
}

/*
Function: getDate
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function is a getter to get the mDate which is a private data member
Input parameters: none
Returns: string mDate
Preconditions: none
Postconditions: none
*/
string Diet::getDate() const
{
	return mDate;
}

/*
Function: setCals
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is a setter function to be able to change the private data memeber mGoalCals
Input parameters: int const newCals
Returns: none
Preconditions: none
Postconditions: none
*/
void Diet::setCals(int const newCals)
{
	mGoalCals = newCals;
}

/*
Function: setName
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is a setter function to be able to change the private data memeber mPlanName
Input parameters: string const newName
Returns: none
Preconditions: none
Postconditions: none
*/
void Diet::setName(string const newName)
{
	mPlanName = newName;
}

/*
Function: setDate
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is a setter function to be able to change the private data memeber setDate
Input parameters: string const newDate
Returns: none
Preconditions: none
Postconditions: none
*/
void Diet::setDate(string const newDate)
{
	mDate = newDate;
}

/*
Function: eidtGoal
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function edits the steps goal. it sets the user's new goal to mGoalCals by using the setter function
Input parameters: Diet stepsArr[], int counter
Returns: none
Preconditions: none
Postconditions: none
*/
void Diet::eidtGoal(Diet CalsArr[], int counter)
{
	int newGoal = 0;

	cout << "Enter a new Calories goal:";
	cin >> newGoal;

	CalsArr[counter].setCals(newGoal);
}


/*
Function: operator >>
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is the overloaded extraction operator
Input parameters: fstream & lhs, Diet & rhs
Returns: fstream lhs
Preconditions: file must already be open
Postconditions: extracts the data from the file and puts it into rhs
*/
fstream & operator >> (fstream & lhs, Diet & rhs)
{
	string name = "";
	lhs >> name;
	rhs.setName(name);

	int cals = 0;
	lhs >> cals;
	rhs.setCals(cals);

	string date = "";
	lhs >> date;
	rhs.setDate(date);

	return lhs;
}

/*
Function: operator<<
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
this is the overloaded insertion operator to print the data to the screen
Input parameters: ostream & lhs, const Diet & rhs
Returns: ostream lhs
Preconditions: the array must be full, so the file must already be open
Postconditions: prints to the screen
*/
ostream & operator << (ostream & lhs,const Diet & rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getCals() << endl;
	lhs << rhs.getDate() << endl << endl;

	return lhs;
}

/*
Function: operator<<
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
this is the overloaded insertion operator to print to the data to the file
Input parameters: fstream & lhs, const Diet & rhs
Returns: fstream lhs
Preconditions: the array must be full and the file must already be open
Postconditions: writes to the file
*/
fstream & operator << (fstream & lhs, const Diet & rhs)
{
	lhs << rhs.getName() << endl << rhs.getCals() << endl;
	lhs << rhs.getDate() << endl << endl;

	
	return lhs;
}





/*
Function:
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
Input parameters:
Returns:
Preconditions:
Postconditions:
*/