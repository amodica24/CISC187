/*
*
* Anthony Modica
*
* Chapter 15, Inheritance
*
* July 17, 2018
*
* main.cpp
*
* Additional files needed to compile this program:
* Assignment.h
*
*/

#include "stdafx.h"
#include "Assignment.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "main.h"
#undef max

using namespace std;
int main()
{
	double value; // user input for the grade of each category
	char userInput = ' '; // user input for the next grade

	// program loops when the user inputs a capital Y & ends when user inputs capital N
	while (userInput != 'N')
	{
		Assignment hw;

		cout << "Please enter data for the next student:\n" << endl;

		cout << setprecision(1) << fixed << left;

		// input for code choice
		cout << setw(45) << "Code choice/execution (50 points possible):";
		cin >> value;
		hw.setCodeChoice(value);

		// input for modular code
		cout << setw(45) << "Modular code (20 points possible):";
		cin >> value;
		hw.setModCode(value);

		// input for formatting and comments
		cout << setw(45) << "Formatting (10 points possible):";
		cin >> value;
		hw.setComments(value);

		// input for input & output professionalism
		cout << setw(45) << "Input/Output (10 points possible):";
		cin >> value;
		hw.setInputOutput(value);

		// input for jing
		cout << setw(45) << "Jing (10 points possible):";
		cin >> value;
		hw.setJing(value);

		// creates a dashed line to separate the outputs from the inputs
		for (int i = 0; i < 46; i++) {
			cout << "-";
		}
		cout << endl;

		// outputs the total grade
		cout << setw(20) << "Total Grade:";
		hw.totalScore(hw.getCodeChoice(), hw.getModCode(), hw.getComments(), hw.getInputOutput(), hw.getJing());
		hw.setScore(hw.totalScore(hw.getCodeChoice(), hw.getModCode(), hw.getComments(), hw.getInputOutput(), hw.getJing()));
		cout << hw.getScore() << endl;

		// outputs the letter grade
		cout << setw(20) << "Letter Grade:";
		hw.getLetterGrade(hw.getScore());

		// user inputs if they want to calculate the next person's data
		cout << setw(21) << "\nNext Person (Y/N):";
		cin >> userInput;
		cout << endl;

		// output message if user inputs a captial N
		if (userInput == 'N')
		{
			cout << "Okay, bye!" << endl;
		}
		if ((userInput != 'Y') && (userInput != 'N'))
		{
			cout << "Invalid, enter Y or N" << endl;
			exit(EXIT_FAILURE);
		}
	}
}
