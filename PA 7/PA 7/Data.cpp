#include "Data.h"

Data::Data(string const & newRecNum, string const & newID, string const & newName, string const & newEmail, string const newUnits, string const & newProg, string const & newLevel, int const &newAbsences)
{
	this->mRecordNum = newRecNum;
	this->mID = newID;
	this->mName = newName;
	this->mEmail = newEmail;
	this->mUnits = newUnits;
	this->mProgram = newProg;
	this->mLevel = newLevel;
	this->mpTop = NULL;
	this->mAbsences = newAbsences;
}

Data::Data(Data const & copy)
{
	this->mRecordNum = copy.mRecordNum;
	this->mID = copy.mID;
	this->mName = copy.mName;
	this->mEmail = copy.mEmail;
	this->mUnits = copy.mUnits;
	this->mProgram = copy.mProgram;
	this->mLevel = copy.mLevel;
	this->mpTop = copy.mpTop;
	this->mAbsences = copy.mAbsences;
}

Data::~Data()
{
	//not allocating dynamic memory in this class, doing it in stack, node, and list, I know for sure that I will be deleting the memory in the list so might not need to destructor for stack too.
}

Data & Data::operator=(Data const & rhs)
{
	if(this != &rhs)
	{
		this->mRecordNum = rhs.mRecordNum;
		this->mID = rhs.mID;
		this->mName = rhs.mName;
		this->mEmail = rhs.mEmail;
		this->mUnits = rhs.mUnits;
		this->mProgram = rhs.mProgram;;
		this->mLevel = rhs.mLevel;
		this->mpTop = rhs.mpTop;
		this->mAbsences = rhs.mAbsences;
	}
	return (*this);
}

string Data::getRec() const
{
	return this->mRecordNum;
}

string Data::getId() const
{
	return this->mID;
}

string Data::getName() const
{
	return this->mName;
}

string Data::getEmail() const
{
	return this->mEmail;
}

string Data::getUnits() const
{
	return this->mUnits;
}

string Data::getProg() const
{
	return this->mProgram;
}

string Data::getLevel() const
{
	return this->mLevel;
}

int Data::getAbsences() const
{
	return this->mAbsences;
}

Stack Data::getTopPtr() const
{
	return this->mpTop;
}

void Data::setRec(string const & temp)
{
	this->mRecordNum = temp;
}

void Data::setId(string const & temp)
{
	this->mID = temp;
}

void Data::setName(string const & temp)
{
	this->mName = temp;
}

void Data::setEmail(string const & temp)
{
	this->mEmail = temp;
}

void Data::setUnits(string const & temp)
{
	this->mUnits = temp;
}

void Data::setProg(string const & temp)
{
	this->mProgram = temp;
}

void Data::setLEvel(string const & temp)
{
	this->mLevel = temp;
}

void Data::setAbsences(int const & Absences)
{
	this->mAbsences = Absences;
}

void Data::setTopPtr(Stack &newTop)// , string &newItem)
{
	this->mpTop = newTop;
}

fstream & operator >> (fstream &lhs, Data & rhs)
{
	char temp1[100];
	string tempStr = "";

	lhs.getline(temp1, 100, ',');
	tempStr = temp1;
	rhs.setRec(temp1);

	lhs.getline(temp1, 100, ',');
	tempStr = temp1;
	rhs.setId(temp1);

	if (rhs.getId() != "ID")
	{
		lhs.getline(temp1, 100, '"');
		lhs.getline(temp1, 100, '"');
		tempStr = temp1;
		rhs.setName(temp1);
	}
	else
	{
		lhs.getline(temp1, 100, ',');
		tempStr = temp1;
		rhs.setName(temp1);
	}

	if (rhs.getId() != "ID")
	{
		lhs.getline(temp1, 100, ',');
	}
	lhs.getline(temp1, 100, ',');
	tempStr = temp1;
	rhs.setEmail(temp1);

	lhs.getline(temp1, 100, ',');
	tempStr = temp1;
	rhs.setUnits(temp1);

	lhs.getline(temp1, 100, ',');
	tempStr = temp1;
	rhs.setProg(temp1);

	lhs.getline(temp1, 100, '\n');
	tempStr = temp1;
	rhs.setLEvel(temp1);


	return lhs;
}

fstream & operator<<(fstream & lhs, Data & rhs)
{
	lhs << rhs.getRec() << "," << rhs.getId() << "," << rhs.getName() << "," << rhs.getEmail()
		<< "," << rhs.getUnits() << "," << rhs.getProg() << "," << rhs.getLevel() << endl;
	return lhs;
}
