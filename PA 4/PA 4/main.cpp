/*
Programmer: Mantz Wyrick
Class: CptS 122 Lab Section 5
Programming Assignment: Programming Assignment #4
Date: 10/5/18
Description:
This will create a 7 day basic fintess application in C++, that allows the
user of the application to manually edit “diet” and “exercise” plans. For
this application you will need to create three classes: DietPlan,
ExercisePlan, and FitnessAppWrapper. 

Collaborators: Class, Lab 5, and Deitel & Deitel, Camden Lambe
*/


#include "FitnessAppWrapper.h"
#include "DietPlan.h"
#include "ExercisePlan.h"

int main(void)
{
	FitnessApp You;

	You.runApp();

	return 0;
}