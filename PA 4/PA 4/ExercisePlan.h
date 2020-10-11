#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::string;

class Exercise
{
public:
	//constructor
	Exercise(int newSteps = 0, string newName = "", string newDate = "");

	//copy constructor
	Exercise(Exercise &copy);

	//destructor
	~Exercise();

	//getters 
	//might need name and date getters for if statments 
	int getSteps() const;
	string getName() const;
	string getDate() const;

	//setters
	//might not need name and date setters since i am not changing them
	void setSteps(int const newSteps);
	void setName(string const newName);
	void setDate(string const newDate);

	void eidtGoal(Exercise StepsArr[], int counter/*, Exercise &steps*/);
	//should it be FitnessApp StepsArr[]??

		//prompts user for a new goal, and use the value to change the goal in the plan.
		//each time a plan is changed, the plan must be displayed to the screen, using 
		//an overloaded stream insertion operator 

private:
	int mGoalSteps; //goal steps represent the number of desired steps for a day
	string mPlanName;
	string mDate;
};

//need 3 nonmember functions in each class file
	//Note: an overloaded operator is considered an overloaded function.
	//The overloaded stream insertion(<< ) for both displaying a plan to 
	//the screen and for writing a plan to a file, and the extraction(>> )
	//operator for reading a plan from a file.

//overloaded stream extraction operator
fstream & operator >> (fstream & lhs, Exercise &rhs);

//overloaded stream insertion operator to screen
ostream & operator << (ostream &lhs, const  Exercise &rhs);

//overloaded stream insertion operator to file
fstream & operator<<(fstream &lhs, const Exercise &rhs);

