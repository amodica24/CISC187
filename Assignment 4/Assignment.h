/*
*
* Anthony Modica
*
* Chapter 15, Inheritance
*
* July 17, 2018
*
* Assignment.h
*
* Additional files needed to compile this program:
* GradedActivity.h
*
*/


#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <string>
#include "GradedActivity.h"

using namespace std;

class Assignment : public GradedActivity {
private:
	double codeChoice;
	double modCode;
	double com_form;
	double inputOutput;
	double jing;

public:
	// default constructor
	Assignment() : GradedActivity()
	{
		codeChoice = 0.0;
		modCode = 0.0;
		com_form = 0.0;
		inputOutput = 0.0;
		jing = 0.0;
	}

	// Constructor #2
	Assignment(double code, double mod, double com, double inOut, double jingURL) {
		codeChoice = code;
		modCode = mod;
		com_form = com;
		inputOutput = inOut;
		jing= jingURL;
	}

	// ********************************************************
	// name:      setCodeChoice
	// called by: main
	// passed:    double codeChoice
	// returns:   nothing
	// calls:     nobody
	// The setCodeChoice function accepts a double type that is copied to the base of the codeChoice member
	// the program exits if the input is less than 0 or greater than 50.
	// ********************************************************
	void setCodeChoice(double codeChoice) {
		if (codeChoice < 0)
		{
			cout << "Value has to be greater than 0" << endl;
			exit(EXIT_FAILURE);
		}
		else if (codeChoice > 50)
		{
			cout << "Value has to be less than 50" << endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			this->codeChoice = codeChoice;
		}
	}
	
	// ********************************************************
	// name:      setModCode
	// called by: main
	// passed:    double modCode
	// returns:   nothing
	// calls:     nobody
	// The setModCode function accepts a double type that is copied to the base of the modCode member
	// the program exits if the input is less than 0 or greater than 20.
	// ********************************************************
	void setModCode(double modCode) {
		if (modCode < 0)
		{
			cout << "Value has to be greater than 0" << endl;
			exit(EXIT_FAILURE);
		}
		else if (modCode > 20)
		{
			cout << "Value has to be less than 20" << endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			this->modCode = modCode;
		}
	}

	// ********************************************************
	// name:      setComments
	// called by: main
	// passed:    double com_form
	// returns:   nothing
	// calls:     nobody
	// The setModCode function accepts a double type that is copied to the base of the com_form member
	// the program exits if the input is less than 0 or greater than 10.
	// ********************************************************
	void setComments(double com_form) {
		if (com_form < 0)
		{
			cout << "Value has to be greater than 0" << endl;
			exit(EXIT_FAILURE);
		}
		else if (com_form > 10)
		{
			cout << "Value has to be less than 10" << endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			this->com_form = com_form;
		}
	}

	// ********************************************************
	// name:      setInputOutput
	// called by: main
	// passed:    double inputOutput
	// returns:   nothing
	// calls:     nobody
	// The setInputOutput function accepts a double type that is copied to the base of the input_output member
	// the program exits if the input is less than 0 or greater than 10.
	// ********************************************************
	void setInputOutput(double inputOutput) {
		if (inputOutput < 0)
		{
			cout << "Value has to be greater than 0";
			exit(EXIT_FAILURE);
		}
		else if (inputOutput > 10)
		{
			cout << "Value has to be less than 10";
			exit(EXIT_FAILURE);
		}
		else
		{
			this->inputOutput = inputOutput;
		}
	}

	// ********************************************************
	// name:      setJing
	// called by: main
	// passed:    double jing
	// returns:   nothing
	// calls:     nobody
	// The setInputOutput function accepts a double type that is copied to the base of the jing member
	// the program exits if the input is less than 0 or greater than 10.
	// ********************************************************
	void setJing(double jing) {
		if (jing < 0)
		{
			cout << "Value has to be greater than 0" << endl;
			exit(EXIT_FAILURE);
		}
		else if (jing > 10)
		{
			cout << "Value has to be less than 10" << endl;
		}
		else {
			this->jing = jing;
		}
	}

	// ********************************************************
	// name:      getLetterGrade
	// called by: main
	// passed:    double score
	// returns:   nothing
	// calls:     nobody
	// ********************************************************
	void getLetterGrade(double score) {
		GradedActivity::getLetterGrade(score);
	}
	
	// get the grade for the student's code choice
	double getCodeChoice() {
		return codeChoice;
	}

	// get the grade for the student's modular code
	double getModCode() {
		return modCode;
	}

	// get the grade for the student's comments and formatting
	double getComments() {
		return com_form;
	}

	// get the grade for the student's input and output professionalism
	double getInputOutput() {
		return inputOutput;
	}

	// get the grade for the student's use of jing
	double getJing() {
		return jing;
	}

	// sums all of the grades together
	double totalScore(double codeChoice, double modCode, double com_form, double inputOutput, double jing) {
		return codeChoice + modCode + com_form + inputOutput + jing;
	}
};

#endif
