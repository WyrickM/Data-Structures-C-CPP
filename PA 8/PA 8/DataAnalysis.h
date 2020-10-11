#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "BST.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis(); //calls the private functions
private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	//helper functions
		//funciton that opens data.csv must use mCsvStream to open file
	void openFile(ifstream &newStream);
		
		//function that reads one line from the file and splits the line
		//into units, type and transaction fields
	void readLine(ifstream &newStream, string &units, string &type, string &transaction);
		
		//function that loops until all lines are read from file; calls 
		//function below, and then displays the current contents of both BSTs;
		//use inOrderTraversal to display trees
	void readAllLines();

		//function that compares the transaction field and inserts the units
		// and type into the appropriate tree(sold or purchased)
		//tress will be fairly balanced
	void compare(string &units, string &type, string &transaction);

		//function that writes to the screen the trends we see in our tree; the 
		// function must display the type and number of units that are least purchased
		// and sold, and the most sold and purchased
	void mostLeast();
};