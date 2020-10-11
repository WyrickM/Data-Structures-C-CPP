#include "ExercisePlan.h"

/*
Function: Exercise
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is the defualt constructor
Input parameters: int newSteps, string newName, string newDate
Returns: none
Preconditions: none
Postconditions: none
*/
Exercise::Exercise(int newSteps, string newName, string newDate)
{
	mGoalSteps = newSteps;
	mPlanName = newName;
	mDate = newDate;
}

/*
Function: Exercise
Date Created: 10/1/18
Date Last Modified:10/6/18
Description: 
	this is the copy constructor
Input parameters: Exercise & copy
Returns: none
Preconditions: none
Postconditions: none
*/
Exercise::Exercise(Exercise & copy)
{
	this->setSteps(copy.getSteps());
	this->setName(copy.getName());
	this->setDate(copy.getDate());
}

/*
Function: ~Exercise()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is the destructor
Input parameters: none
Returns: none
Preconditions: none
Postconditions: none
*/
Exercise::~Exercise()
{
	//no dynamic memory yet does nothing, if i use a list need to delete nodes 
}

/*
Function: getSteps()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function is a getter to get the mgoalsteps which is a private data member
Input parameters: none
Returns: int mgoalsteps
Preconditions: none
Postconditions: none
*/
int Exercise::getSteps() const
{
	return mGoalSteps;
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
string Exercise::getName() const
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
string Exercise::getDate() const
{
	return mDate;
}

/*
Function: setSteps
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is a setter function to be able to change the private data memeber mGoalsteps
Input parameters: int const newSteps
Returns: none
Preconditions: none
Postconditions: none
*/
void Exercise::setSteps(int const newSteps)
{
	mGoalSteps = newSteps;
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
void Exercise::setName(string const newName)
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
void Exercise::setDate(string const newDate)
{
	mDate = newDate;
}

/*
Function: eidtGoal
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function edits the steps goal. it sets the user's new goal to mgoalsteps by using the setter function
Input parameters: Exercise stepsArr[], int counter
Returns: none
Preconditions: none
Postconditions: none
*/
void Exercise::eidtGoal(Exercise stepsArr[], int counter)
{
	int newGoal = 0;

	cout << "Enter a new steps goal:";
	cin >> newGoal;

	stepsArr[counter].setSteps(newGoal);

}

/*
Function: operator >>
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is the overloaded extraction operator
Input parameters: fstream & lhs, Exercise & rhs
Returns: fstream lhs
Preconditions: file must already be open
Postconditions: extracts the data from the file and puts it into rhs
*/
fstream & operator >> (fstream & lhs, Exercise & rhs)
{
	string name = "";
	lhs >> name;
	rhs.setName(name);

	int steps = 0;
	lhs >> steps;
	rhs.setSteps(steps);

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
Input parameters: ostream & lhs, const Exercise & rhs
Returns: ostream lhs
Preconditions: the array must be full, so the file must already be open
Postconditions: prints to the screen
*/
ostream & operator<<(ostream & lhs, const Exercise & rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getSteps() << endl;
	lhs << rhs.getDate() << endl << endl;

	return lhs;
}

/*
Function: operator<<
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is the overloaded insertion operator to print to the data to the file
Input parameters: fstream & lhs, const Exercise & rhs
Returns: fstream lhs
Preconditions: the array must be full and the file must already be open
Postconditions: writes to the file
*/
fstream & operator<<(fstream & lhs, const Exercise & rhs)
{
	lhs << rhs.getName() << endl << rhs.getSteps() << endl;
	lhs << rhs.getDate() << endl << endl;

	return lhs;
}