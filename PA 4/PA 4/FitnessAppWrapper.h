#pragma once

#include "ExercisePlan.h"
#include "DietPlan.h" 

//#include <iostream>
//#include <fstream>
//#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::string;

class FitnessApp
{
public:

	//constructor 
	FitnessApp(int newCals = 0, int newSteps = 0, string newName = "", string newDate = "");
	//copy constructor
	FitnessApp(FitnessApp const  &copy);
	//deconstructor
	~FitnessApp();

	//getters
	int getDietArrCals(int index) const;
	int getExArrSteps(int index) const;
	//setters
	void setDietArr(int newSteps, int index);
	void setExArr(int newSteps, int index);

	void displayMenu();
	int MenuOption() const;

	int findPlan(); //might not need
	int findDate();

	void loadDailyPlan(fstream &dietStream, Diet &plan);
	void loadDailyPlan(fstream &exStream, Exercise &plan);

	void loadWeeklyPlan(fstream &dietStream, Diet weeklyPlan[]);
	void loadWeeklyPlan(fstream &exStream, Exercise weeklyPlan[]);

	void displayDailyPlan(Diet const &weeklyPlan);
	void displayDailyPlan(Exercise const &weeklyPlan);

	void displayWeeklyPlan(Diet const weeklyPlan[]);
	void displayWeeklyPlan(Exercise const weeklyPlan[]);

	void storeDailyPlan(fstream &outStream, Diet &weeklyPlan);
	void storeDailyPlan(fstream &outStream, Exercise &weeklyPlan);

	void storeWeeklyPlan(fstream &outstream, Diet weeklyplan[]);
	void storeWeeklyPlan(fstream &outstream, Exercise weeklyplan[]);

	void runApp();

private:
	Diet mDietArr[7];
	Exercise mExerciseArr[7];
};
