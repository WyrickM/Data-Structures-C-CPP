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

class Diet
{
public:
	//constructor
	Diet(int newCals = 0, string newName = "", string newDate = "");

	//copy constructor
	Diet(Diet &copy);

	//destructor
	~Diet();


	//getters //might have to make different names for these member
			  //functions becasue they are the same as the exercise ones
	//might need name and date getters for if statments 

	int getCals() const;
	string getName() const;
	string getDate() const;

	//setters
	//might not need name and date setters since i am not changing them

	void setCals(int const newCals);
	void setName(string const newName);
	void setDate(string const newDate);

	void eidtGoal(Diet CalsArr[], int counter);
	//prompts user for a new goal, and use the value to change the goal in the plan.
	//each time a plan is changed, the plan must be displayed to the screen, using 
	//an overloaded stream insertion operator 

private:
	int mGoalCals; //max intake of calories for day is stored in goal calories
	string mPlanName;
	string mDate;

};
//need 3 nonmember functions in each class file
	//Note: an overloaded operator is considered an overloaded function.
	//The overloaded stream insertion(<< ) for both displaying a plan to 
	//the screen and for writing a plan to a file, and the extraction(>> )
	//operator for reading a plan from a file

//overloaded stream extraction operator
fstream & operator >> (fstream &lhs, Diet &rhs);

//overloaded stream insertion operator to screen
ostream & operator << (ostream &lhs, const  Diet &rhs);

//overloaded stream insertion operator to file
fstream & operator<<(fstream &lhs, const Diet &rhs);


