#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

//not a template
//have to resolve the types in the data types, doing it by putting
//it in our list node, the one type T will get replaced by Data

//track number of absences, track the dates that they were absent,
//use a stack for this, marking absences, ask user to mark student
//or not, run through entire list

class Data
{
public:
	Data(string const &newRecNum = "", string const &newID = "", string const &newName = "",
		string const &newEmail = "", string const newUnits = "", string const &newProg = "",
		string const &newLevel = "", int const &newAbsences = 0);
	Data(Data const &copy);
	~Data();

	Data & operator=(Data const &rhs);

	//getters
	string getRec() const;
	string getId() const;
	string getName() const;
	string getEmail() const;
	string getUnits() const;
	string getProg() const;
	string getLevel() const;
	int getAbsences() const;
	Stack getTopPtr() const;

	//setters
	void setRec(string const &temp);
	void setId(string const &temp);
	void setName(string const &temp);
	void setEmail(string const &temp);
	void setUnits(string const &temp);
	void setProg(string const &temp);
	void setLEvel(string const &temp);
	void setAbsences(int const &Absences);
	void setTopPtr(Stack &newTop);// , string &newItem);

private:
	string mRecordNum;
	string mID;
	string mName;
	string mEmail;
	string mUnits;
	string mProgram;
	string mLevel;
	Stack mpTop; //stores the dates of absences
	int mAbsences;
};

//overloaded extraction operator
fstream & operator >> (fstream &lhs, Data &rhs);
//overloaded insertion operator
fstream & operator << (fstream &lhs, Data &rhs);