//Jacob Johnson
//jejohnson8@dmacc.edu
/*This program takes information from three seperate .txt files and compiles and displays
that information in a readable format.  I used a buble sort algorithm that I found in 
Gaddis ch. 8 for the descending sorting based on number of WS wins. The starter code provided 
by the instructor was used as a base for the program.*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main(){
	//variables and their values taken from starter code
	ifstream WinnersIn;		
	ifstream TeamsIn;			
	ifstream LeagueIn;        
	string input;
	string Teams[30];
	int Wins[30];
	string League[30];
	int counter;
	//reads in documents provided by instructor
	TeamsIn.open("Teams.txt");
	LeagueIn.open("Leagues.txt");
	WinnersIn.open("WorldSeriesWinners.txt");

	counter = 0;
	while (getline(TeamsIn, input))
	{
		Teams[counter] = input;
		Wins[counter] = 0;
		counter++;
	}

	counter = 0;
	while (getline(LeagueIn, input))
	{
		League[counter] = input;
		counter++;
	}

	counter = 0;
	while (getline(WinnersIn, input))
	{
		for (int x = 0; x < 30; x++)
		{
			if (Teams[x] == input)
			{
				Wins[x]++;
			}
		}
		counter++;

	}
	
	cout << setw(22) << left << "Team" << " | "<< setw(18) << "League" << " | " << left << setw(4) << "Wins" << " | " << left << "Year" << endl;
	cout << "--------------------------------------------------------------" << endl;
	//this function will sort the teams by league, then sort them by WS wins in descending order.  I used chapter 8 section 3 in Gaddis
	//for the buble sorting algorithim.
	int max = 29;
	for (int x = 0; x < 30; x++)
	{
		if(League[x] == "American League"){
			for(max; max > 0; max--){
				for (int index = 0; index < max; index++){
					if(Wins[index] < Wins[index + 1]){
						swap(Wins[index], Wins[index +1]);
					}
				}
			}
			cout << setw(22) << left << Teams[x] << " | " << setw(18) << League[x] << " | " << setw(4) << Wins[x] << " | " << endl; //output american league results
		}	
	}
	//sorts National league teams
	for (int x = 0; x < 30; x++)
	{
		if(League[x] == "National League"){
			cout << setw(22) << left << Teams[x] << " | " << setw(18) << League[x] << " | " << setw(4) << Wins[x] << " | " << endl; //output national league results
		}	
	}

	TeamsIn.close();
	LeagueIn.close();
	WinnersIn.close();

	return 0;
}
