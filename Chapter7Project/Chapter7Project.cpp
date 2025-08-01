// Chapter7Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

//Function prototype
void getAnswers(char correctAns[], char studentAns[]);
int getExam(char correctAns[], char studentAns[]);
void writeReport(int totalMissed, double& percent , double result);

int main() {

	char correctAns[20];
	char studentAns[20];
	int totalMissed; 
	double percent , result = 0;

	getAnswers(correctAns, studentAns); 

	totalMissed = getExam(correctAns, studentAns); 

	writeReport(totalMissed, percent , result); 

	return 0;
}

// Function to get answers from files
void getAnswers(char correctAns[], char studentAns[]) {
	ifstream correctAnsFile("CorrectAnswers.txt"); 
	ifstream studentAnsFile("StudentAnswers.txt"); 

	// Check if files opened successfully
	if (!correctAnsFile.is_open()) { 
		cout << "Couldn't find correct answer file" << endl;
		exit; 
	}

	if (!studentAnsFile.is_open()) { 
		cout << "Couldn't find student answer file" << endl;
		exit; 
	}

	// Read answers into arrays
	for (int i = 0; i < 20; i++) { 
		correctAnsFile >> correctAns[i];
		studentAnsFile >> studentAns[i];
	}

	// Close files
	correctAnsFile.close();
	studentAnsFile.close();
}

// Function to compare answers and calculate missed questions
int getExam(char correctAns[], char studentAns[]) { 
	int totalMissed = 0; 

	for (int i = 0; i < 20; i++) { 
		if (correctAns[i] != studentAns[i]) {
			cout << "Wrong! " << "Student's answer: " << studentAns[i] << endl;
			cout << "The correct answer was: " << correctAns[i] << endl << endl;
			totalMissed++; 
		}
	}
	return totalMissed; 
}

// Function to write the report
void writeReport(int totalMissed, double& percent , double result) { 

	cout << "\nThe student missed " << totalMissed << " questions" << endl;

	result += (20 - totalMissed); 
	percent = (result / 20) * 100;
	cout << "Percentage answered correctly: " << percent << "%" << endl;

	if (percent >= 70) { 
		cout << "The student has passed the exam!\n";
	}
	else {
		cout << "The student has failed the exam!\n";
	}
}
