/*
*
* Anthony Modica
*
* Chapter 15, Inheritance
*
* July 17, 2018
*
* GradedActivity.h
*
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class GradedActivity {

protected:
	double score;
	char grade;

public:
	// defualt constructor 
	GradedActivity() {
		score = 0.0;
		grade = ' ';
	}

	// Constructor #2
	GradedActivity(double s, char g)
	{
		score = s;
		grade = g;
	}

	void setScore(double score);
	
	double getScore();

	void getLetterGrade(double score) {
		if (score > 89) {
			cout << "A";
		}
		else if (score > 79) {
			cout << "B";
		}
		else if (score > 69) {
			cout << "C";
		}
		else if (score > 59) {
			cout << "D";
		}
		else {
			cout << "F";
		}
	}
};

void GradedActivity::setScore(double score) {
	this->score = score;
}

double GradedActivity::getScore() {
	return score;
}
