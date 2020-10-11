#include "FitnessAppWrapper.h"
/*
Function: FitnessApp ()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is the default constructor for my fitnessapp class
Input parameters: int newCals, int newSteps, string newName, string newDate
Returns: none
Preconditions: none
Postconditions: each array gets intialized
*/
FitnessApp::FitnessApp(int newCals, int newSteps, string newName, string newDate)
{
	int index = 0;
	while (index < 7)
	{
		this->mDietArr[index].setCals(newCals);
		this->mDietArr[index].setName(newName);
		this->mDietArr[index].setDate(newDate);

		this->mExerciseArr[index].setSteps(newSteps);
		this->mExerciseArr[index].setName(newName);
		this->mExerciseArr[index].setDate(newDate);

		index++;
	}
}
/*
Function: FitnessApp()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is the copy constructor
Input parameters: FitnessApp const &copy
Returns: none
Preconditions: none
Postconditions: none
*/
FitnessApp::FitnessApp(FitnessApp const &copy)
{
	int index = 0;
	while (index < 7)
	{
		mDietArr[index].setCals(copy.mDietArr[index].getCals());
		mDietArr[index].setName(copy.mDietArr[index].getName());
		mDietArr[index].setDate(copy.mDietArr[index].getDate());

		mExerciseArr[index].setSteps(copy.mExerciseArr[index].getSteps());
		mExerciseArr[index].setName(copy.mExerciseArr[index].getName());
		mExerciseArr[index].setDate(copy.mExerciseArr[index].getDate());
		index++;
	}
}

/*
Function: ~FitnessApp()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is my desctructor
Input parameters: none
Returns: none
Preconditions: none
Postconditions: none
*/
FitnessApp::~FitnessApp()
{
	//no dynamic memory yet does nothing, if i use a list need to delete nodes 
}

/*
Function: getDietArrCals()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function gets the calories goal from the Diet array
Input parameters: int index
Returns: int mDietArr[index].getCals(), which is really just mGoalCals from that index in the array
Preconditions: file is already open
Postconditions: none
*/
int FitnessApp::getDietArrCals(int index) const //might not need
{
	return mDietArr[index].getCals();
}

/*
Function: getExArrSteps()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this gets the goal steps from the Exercise array
Input parameters: int index
Returns: int mExerciseArr[index].getSteps(), which is really just the mGoalSteps from that index in the array
Preconditions: file is already open
Postconditions: none
*/
int FitnessApp::getExArrSteps(int index) const
{
	return mExerciseArr[index].getSteps();
}

/*
Function: setDietArr
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this sets a specific index's goal calories from the mDietArr
Input parameters: int newCals, int index
Returns: none
Preconditions: none 
Postconditions: changes mGoalCals to what newCals is equal to
*/
void FitnessApp::setDietArr(int newCals, int index)
{
	mDietArr[index].setCals(newCals);
}

/*
Function: setExArr
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this sets a specific index's goal steps from the mExerciseArr
Input parameters: int newSteps, int index
Returns: none
Preconditions: none
Postconditions: changes mGoalCals to what newCals is equal to
*/
void FitnessApp::setExArr(int newSteps, int index)
{
	mExerciseArr[index].setSteps(newSteps);
}

/*
Function: displayMenu
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this displays the menu that the user gets to choose from
Input parameters: none
Returns: none
Preconditions: none
Postconditions: none
*/
void FitnessApp::displayMenu()
{
	cout << "1. Load weekly diet plan from file" << endl;
	cout << "2. Load weekly exercise plan from file" << endl;
	cout << "3. Store weekly diet plan to file" << endl;
	cout << "4. Store weekly exercise plan to file" << endl;
	cout << "5. Display weekly diet plan to screen" << endl;
	cout << "6. Display weekly exercise  plan to screen" << endl;
	cout << "7. Edit daily diet plan" << endl;
	cout << "8. Edit daily exercise plan" << endl;
	cout << "9. Exit" << endl;

}

/*
Function: MenuOption
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this gets the user input that the user wants the app to do based on the menu, the user can only enter a number 1-9
Input parameters: none
Returns: int option
Preconditions: none
Postconditions: returns int option
*/
int FitnessApp::MenuOption() const
{
	int option = 0;

	do {
		cin >> option;
		if ((option < 0) || (option > 10))
		{
			cout << "Error: Invalid choice! Try again." << endl;
		}
	} while ((option < 0) || (option > 10));

	system("cls");

	return option;
}

/*
Function: findPlan
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function gets the user input for a specific plan if needed
Input parameters: none
Returns: int plan
Preconditions: none
Postconditions: returns int plan
*/
int FitnessApp::findPlan()
{
	int plan;

	cout << "What plan would you like?" << endl << "1. Diet Plan" << endl
		<< "2. Exercise Plan" << endl;
	cin >> plan;
	do
	{
		cout << "Error: Invalid entry! Try again." << endl;
		cin >> plan;
	} while ((plan < 0) || (plan > 3));

	return plan;
}

/*
Function: findDate
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function is used in the editgoals for both the exercise and diet plans. It asks for user input to select a day they want to change the goal
Input parameters: none
Returns: int counter
Preconditions: none
Postconditions: returns int counter that will correspond to an index on specifc array
*/
int FitnessApp::findDate()
{
	int counter = 0, day = 0;

	cout << "What day would you like?" << endl <<
		"Day 1: 01/01/2018\nDay 2: 01/02/2018\nDay 3: 01/03/2018\nDay 4: 01/04/2018\n"
		"Day 5: 01/05/2018\nDay 6: 01/06/2018\nDay 7: 01/07/2018\nDay:";
	do
	{
		cin >> day;
		if ((day < 0) || (day > 7))
		{
			cout << "Error: invalid entry! Try again." << endl;
		}
	} while ((day < 0) || (day > 7));

	counter = day - 1;
	return counter;
}

/*
Function: loadDailyPlan
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this loads a single daily diet plan
Input parameters: fstream & dietStream, Diet & plan
Returns: none
Preconditions: file must be already open
Postconditions: none
*/
void FitnessApp::loadDailyPlan(fstream & dietStream, Diet & plan)
{
	dietStream >> plan;
}

/*
Function: loadDailyPlan
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this loads a single daily exercise plan
Input parameters: fstream & exStream, Exercise & plan
Returns: none
Preconditions: file must be already open
Postconditions: none
*/
void FitnessApp::loadDailyPlan(fstream & exStream, Exercise & plan)
{
	exStream >> plan;
	/*char name[100];
	fileStream.getline(name, 100);
	plan.setName(name);
	char goal[100];
	fileStream.getline(goal, 100);
	plan.setSteps(atoi(goal));
	char date[100];
	fileStream.getline(date, 100);
	plan.setDate(date);
	char blank[100];
	fileStream.getline(blank, 100);*/
}

/*
Function: loadWeeklyPlan
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this loads the weekly diet plan into the mDietArr by calling loadDailyPlan()
Input parameters: fstream & dietStream, Diet weeklyPlan[]
Returns: none
Preconditions: file already has to be open
Postconditions: the array gets filled
*/
void FitnessApp::loadWeeklyPlan(fstream & dietStream, Diet weeklyPlan[])
{
	int i = 0;

	while (i < 7)
	{
		loadDailyPlan(dietStream, weeklyPlan[i]);
		i++;
	}
}

/*
Function: loadWeeklyPlan
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
this loads the weekly exercise plan into the mExerciseArr by calling loadDailyPlan()
Input parameters: fstream & exStream, Exercise weeklyPlan[]
Returns: none
Preconditions: file already has to be open
Postconditions: the array gets filled
*/
void FitnessApp::loadWeeklyPlan(fstream & exStream, Exercise weeklyPlan[])
{
	int i = 0;

	while (i < 7)
	{
		loadDailyPlan(exStream, weeklyPlan[i]);
		i++;
	}
}

/*
Function: displayDailyPlan()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function displays the daily plan to the screen, by using the overloaded insertion  operator
Input parameters: Diet const &weeklyPlan
Returns: none
Preconditions: file must already be open and the weeklyplan must have values 
Postconditions: prints everything to the screen
*/
void FitnessApp::displayDailyPlan(Diet const &weeklyPlan)
{
	cout << weeklyPlan;
}

/*
Function: displayDailyPlan()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function displays the daily plan to the screen by using the overloaded insertion operator
Input parameters: Exercise const &weeklyPlan
Returns: none
Preconditions: file must already be open and the weeklyplan must have values
Postconditions: prints everything to the screen
*/
void FitnessApp::displayDailyPlan(Exercise const &weeklyPlan)
{
	cout << weeklyPlan;
}

/*
Function: displayWeeklyPlan
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this prints all of the plans from the seven days
Input parameters: Diet const weeklyPlan[]
Returns: none
Preconditions: the array must be full with right values, list must already be open for that to happen
Postconditions: prints week to the screen
*/
void FitnessApp::displayWeeklyPlan(Diet const weeklyPlan[])
{
	int index = 0;
	while (index < 7)
	{
		displayDailyPlan(weeklyPlan[index]);
		index++;
	}
}

/*
Function: displayWeeklyPlan
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this prints all of the plans from the seven days
Input parameters: Exercise const weeklyPlan[]
Returns: none
Preconditions: the array must be full with right values, list must already be open for that to happen
Postconditions: prints week to the screen
*/
void FitnessApp::displayWeeklyPlan(Exercise const weeklyPlan[])
{
	int index = 0;
	while (index < 7)
	{
		displayDailyPlan(weeklyPlan[index]);
		index++;
	}
}

/*
Function: storeDailyPlan
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function stores the daily plan to the file by using the overloaded insertion file operator
Input parameters:  fstream &outStream, Diet &weeklyPlan
Returns: none
Preconditions: array must be full, for this to happen the file must already be open
Postconditions: writes to daily plan to the file
*/
void FitnessApp::storeDailyPlan(fstream &outStream, Diet &weeklyPlan)
{
	outStream << weeklyPlan;
}

/*
Function: storeDailyPlan
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this function stores the daily plan to the file by using the overloaded insertion file operator
Input parameters:  fstream &outStream, Exercise &weeklyPlan
Returns: none
Preconditions: array must be full, for this to happen the file must already be open
Postconditions: writes to daily plan to the file
*/
void FitnessApp::storeDailyPlan(fstream &outStream, Exercise &weeklyPlan)
{
	outStream << weeklyPlan;
}

/*
Function: storeWeeklyPlan()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this stroes the weekly plans to the file using the storeDailyPlan()
Input parameters: fstream &outstream, Diet weeklyplan[]
Returns: none
Preconditions: file must already be open and the array must be full
Postconditions: writes all 7 days to the file
*/
void FitnessApp::storeWeeklyPlan(fstream &outstream, Diet weeklyplan[])
{
	int index = 0;
	while (index < 7)
	{
		storeDailyPlan(outstream, weeklyplan[index]);
		index++;
	}

}

/*
Function: storeWeeklyPlan()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
this stroes the weekly plans to the file using the storeDailyPlan()
Input parameters: fstream &outstream, Exercise weeklyplan[]
Returns: none
Preconditions: file must already be open and the array must be full
Postconditions: writes all 7 days to the file
*/
void FitnessApp::storeWeeklyPlan(fstream &outstream, Exercise weeklyplan[])
{
	int index = 0;
	while (index < 7)
	{
		storeDailyPlan(outstream, weeklyplan[index]);
		index++;
	}
}

/*
Function: runApp()
Date Created: 10/1/18
Date Last Modified:10/6/18
Description:
	this is the runApp(). This will be the only function in main because everything is run through this function.
	it takes the users option from MenuOption and correctly uses the right operation that was requested by the user.
	since option 9 on the menu is exit, case 9 exits the run app and then the program.
Input parameters: none
Returns: none
Preconditions: none
Postconditions: none
*/
void FitnessApp::runApp()
{
	int option = 0, counter = 0;
	Diet dWeeklyPlan;
	Exercise eWeeklyPlan;
	fstream dietFileStream, exFileStream;
	//dietFileStream.open("dietPlans.txt");
	//exFileStream.open("exercisePlans.txt");

	cout << "Welcome to the Fitness App" << endl << endl;

	do
	{
		dietFileStream.open("dietPlans.txt");
		exFileStream.open("exercisePlans.txt");
		displayMenu();
		option = MenuOption();

		switch (option)
		{
		case 1: //load weekly diet
			loadWeeklyPlan(dietFileStream, mDietArr);
			break;
		case 2: //load weekly exercise
			loadWeeklyPlan(exFileStream, mExerciseArr);
			break;
		case 3: //store weekly diet to file
			storeWeeklyPlan(dietFileStream, mDietArr);
			break;
		case 4: //store weekly exercise to file
			storeWeeklyPlan(exFileStream, mExerciseArr);
			break;
		case 5: //display weekly diet
			displayWeeklyPlan(mDietArr);
			break;
		case 6: //display weekly exercise
			displayWeeklyPlan(mExerciseArr);
			break;
		case 7: //edit daily diet
			counter = findDate();
			dWeeklyPlan.eidtGoal(mDietArr, counter);
			break;
		case 8: //edit daily exercise
			counter = findDate();
			eWeeklyPlan.eidtGoal(mExerciseArr, counter);
			//this shows a syntax error? why wont editGoal pop up when i try to get it with eWeeklyPlan.
			break;
		}
		dietFileStream.close();
		exFileStream.close();
	} while (option != 9);


}


