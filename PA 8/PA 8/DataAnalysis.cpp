#include "DataAnalysis.h"

DataAnalysis::DataAnalysis() //need to make a constructor
{
	this->mTreeSold;
	this->mTreePurchased;
	this->mCsvStream;
}

DataAnalysis::~DataAnalysis()
{
}

void DataAnalysis::runAnalysis()
{
	readAllLines();
	/*cout << "Purchased Tree" << endl << endl;
	mTreePurchased.inOrderTraversal();
	cout << endl;
	cout << "Sold Tree" << endl << endl;
	mTreeSold.inOrderTraversal();
	cout << endl;*/
	this->mostLeast();
}

void DataAnalysis::openFile(ifstream & newStream)
{
	newStream.open("data.csv");
}

void DataAnalysis::readLine(ifstream & newStream, string & units, string & type, string & transaction)
{
	char temp[100];

	newStream.getline(temp, 100, ',');
	units = temp;
	newStream.getline(temp, 100, ',');
	type = temp;
	newStream.getline(temp, 100, '\n');
	transaction = temp;
}

void DataAnalysis::readAllLines()
{
	string units, type, transaction;
	this->openFile(this->mCsvStream);

	while (!mCsvStream.eof())
	{
		this->readLine(mCsvStream, units, type, transaction);
		this->compare(units, type, transaction);
	}
	mCsvStream.close();
}

void DataAnalysis::compare(string & units, string & type, string & transaction)
{
	int tempUnit = 0;
	string tempUnits, tempString, str;

	tempUnits = units;
	if (tempUnits != "Units")
	{
		if (tempUnits != "")
		{
			tempUnit = stoi(tempUnits);
		}
	}
	tempString = units + ',' + type + ',' + transaction;

	if (transaction == "Purchased")
	{
		this->mTreePurchased.insert(tempUnit, tempString);
	}
	else if (transaction == "Sold")
	{
		this->mTreeSold.insert(tempUnit, tempString);
	}
}

void DataAnalysis::mostLeast()
{
	TransactionNode pTemp;
	//Node *pTemp = new TransactionNode;
	
	cout << "Most Purchased:" << endl;
	pTemp = mTreePurchased.findLargest(mTreePurchased.getRoot());
	pTemp.printData();
	cout << "Least Purchased:" << endl;
	pTemp = this->mTreePurchased.findSmallest(mTreePurchased.getRoot());
	pTemp.printData();
	cout << endl;
	cout << "Most Sold:" << endl;
	pTemp = this->mTreeSold.findLargest(mTreeSold.getRoot());
	pTemp.printData();
	cout << "Least Sold:" << endl;
	pTemp = this->mTreeSold.findSmallest(mTreeSold.getRoot());
	pTemp.printData();
}
