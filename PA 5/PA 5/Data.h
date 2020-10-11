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

class Data
{
public:
	Data(int newCustomerNumber = 0, int newServiceTime = 0, int newTotalTime = 0);
	Data(Data const &copy);
	~Data();

	//getters
	int getCustomerNumber() const;
	int getServiceTime() const;
	int getTotalTime() const;
	int getCounter() const;

	//setters
	void setCustomerNumber(int newCustomerNumber);
	void setServiceTime(int newServiceTime);
	void setTotalTime(int newTotalTime);

	void setCounter(int newCounter);

private:
	int mCustomerNumber;
	int mServiceTime;
	int mTotalTime;
	int mCounter;
};

//overloaded insertion operator that prints to the screen
ostream & operator << (ostream &lhs, const Data *rhs);