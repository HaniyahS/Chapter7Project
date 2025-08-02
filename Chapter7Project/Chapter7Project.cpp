// Chapter7Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // For std::count

using namespace std;

// Function prototypes
void getTeams(vector<string>& teams, vector<string>& wins);
int findWinner(string teamName, const vector<string>& wins);

int main() {
	vector<string> teams;
	vector<string> wins;

	// Get the teams and winners from the files
	getTeams(teams, wins);

	// Display the list of teams to the user
	for (int i = 0; i < teams.size(); ++i) {
		cout << teams[i] << endl;
	}
	cout << endl;

	string teamName;
	while (teamName != "quit") { // Loop until the user enters "quit"
		cout << "Enter the name of a team (exactly as written above) or type 'quit' to exit: ";
		getline(cin, teamName); // Use getline for names with spaces

		if (teamName == "quit") {
			break;
		}

		// Count the number of times the selected team has won
		int count = findWinner(teamName, wins);

		if (count > 0) {
			cout << "\nThe " << teamName << " won the World Series " << count << " times." << endl << endl;
		}
		else {
			cout << "\nThe " << teamName << " never won the World Series (or the name is misspelled)." << endl << endl;
		}
	}

	cout << "\nGoodbye" << endl;

	return 0;
}

// Function to get teams from "Teams.txt" and winners from "WorldSeriesWinners.txt"
void getTeams(vector<string>& teams, vector<string>& wins) {
	ifstream teamsFile("Teams.txt");
	ifstream winnersFile("WorldSeriesWinners.txt");

	if (!teamsFile) {
		cout << "Error opening Teams.txt" << endl;
		exit;
	}

	if (!winnersFile) {
		cout << "Error opening WorldSeriesWinners.txt" << endl;
		exit;
	}

	string line;
	while (getline(teamsFile, line)) {
		teams.push_back(line);
	}

	while (getline(winnersFile, line)) {
		wins.push_back(line);
	}

	teamsFile.close();
	winnersFile.close();
}

// Function to count how many times a team has won
int findWinner(string teamName, const vector<string>& wins) {
	int count = 0;
	// Iterate through the vector of winners and increment the count if the team name matches
	for (int i = 0; i < wins.size(); ++i) {
		if (teamName == wins[i]) {
			count++;
		}
	}
	return count;
}

