/* Jacob Johnson
 * jejohnson8@dmacc.edu
 * jacob.johnson365@gmail.com
 * 4/15/18
 * This is a text based game modeled after the science fiction television series The Expanse.  
 * The user will need to navigate the Solar System, collecting items needed to save the Belt
 * and all of humanity from the alien protomolecule.  Collect all four gems and trade them for the 
 * protomolecule then shoot that nasty weapon into the sun and destroy it forever. 
 */
#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

void introduction();

int main(){
	//universal variables
	string command = "";
	int count = 35, x = 2, y = 3, isItem = 0;
	int numobj = 6;
	
	introduction();//print out introduction and game rules.
	string universe[4][4];//initialize 2D array for 16 locations as instructed.
	string lookAround[4][4];//holds information on what is around at a certain location
	string obj[numobj];//holds 7 objects, 4 gems, 1 bag of currency, 1 protomolecule
	int objloc[numobj];//location of each object
	
	//fill game universe with locations
	universe[0][0] = "by Ganymede.";
	universe[0][1] = "by Saturn.";
	universe[0][2] = "by Titan.";
	universe[0][3] = "heading towards Pluto.";
	universe[1][0] = "by Ceres.";
	universe[1][1] = "by Eros.";
	universe[1][2] = "at Tycho mobile station.";
	universe[1][3] = "by Jupiter.";
	universe[2][0] = "approaching a destroyed Mars battleship.";
	universe[2][1] = "by Mars.";
	universe[2][2] = "approaching a battle between Mars and Earth armadas.";
	universe[2][3] = "in the asteroid belt.";
	universe[3][0] = "by the Sun.";
	universe[3][1] = "by Venus.";
	universe[3][2] = "approaching a destroyed Earth battleship.";
	universe[3][3] = "by Earth.";
	
	//look around at locations for hints on if there is something to pick up
	lookAround[0][0] = "The station looks scary, let's get out of here.";
	lookAround[0][1] = "Docked with the pleasure yacht of Jules-Pierre Mao, he has something to sell you...";//sells protomolecule if you have 4 gems
	lookAround[0][2] = "Not much to see here captain, better keep moving.";
	lookAround[0][3] = "Captain...there is nothing out this way...we should turn back.";
	lookAround[1][0] = "I don't think we have time to party on Ceres Station Captain.";
	lookAround[1][1] = "Captain, everyone at Eros Station has perished from the protomolecule...what's that over there?"; //get money here
	lookAround[1][2] = "Fred Johnson has taken control of Tycho, maybe he has something for us...";//get gem 1
	lookAround[1][3] = "Beautiful planet, the moons here house many stations.";
	lookAround[2][0] = "Looks like Earth won this battle. Maybe there is something inside this ship!"; //get gem 2
	lookAround[2][1] = "A Mars ship has locked on, torpedo incoming...we have been hit!";
	lookAround[2][2] = "We took a hit Captain!  Why did you bring us here?!";
	lookAround[2][3] = "Home sweet home.  Maybe our Belter comrades have something for us!";//get gem 3
	lookAround[3][0] = "This looks like a good place to send the protomolecule...";//can drop protomolecule here to win game
	lookAround[3][1] = "Only thing you'll find on Venus are Mars and Earth Marines. Better keep moving.";
	lookAround[3][2] = "Let's dock and look around...";//get gem 4
	lookAround[3][3] = "Warning, Earth battleship!  They Fired! We sustained a hit!";
	
	//possible objects to pick up
	obj[0] = "a red gem"; 
	obj[1] = "a green gem.";
	obj[2] = "a blue gem.";
	obj[3] = "a purple gem.";
	obj[4] = "a bag of money.";
	obj[5] = "the protomolecule.";
	
	//location of objects to be picked up (location value is x*10+y
	objloc[0] = 12;
	objloc[1] = 20;
	objloc[2] = 23;
	objloc[3] = 32;
	objloc[4] = 11;
	objloc[5] = 1;
	
	vector<int> gems; //vector to store gems, 4 needed to get protomolecule
	vector<int> proto;//vector to hold protomolecule
	vector<int> cash;//vector to hold cash
	vector<int> hits;//vector to count hits to ship. 4 hits destorys ship and ends game
	
	
	
	while (!((command == "Q") || (count < 1)))
	{
		cout << "\n*******************************************************************";
		cout << "\nYou are " << universe[x][y] << endl; 
		cout << "Travel Forward - F, Backward - B, Port - P, Starboard - S, dock and Look around - L, ";
		cout << "\nGet item - G, check Inventory - I, Hurl protomolecule - H, Quit - Q\n";
		cout << "\nCommands remaining: " << count << ". Captain, your command: ";
		cin >> command;
		// Convert to uppercase (this function taken from cupcakeadventure example, slightly altered)
    	transform(command.begin(), command.end(), command.begin(), ::toupper);
    	
    	if (command == "F")
   		{   x--;  count--; } 
		else if (command == "B")
		{   x++;   count--; }
		else if (command == "S")
		{   y++;   count--; }
		else if (command == "P")
		{   y--;   count--; }
		else if (command == "Q"){
			cout << "\nThis adventure isn't for everyone...\n";//exit game message after "Q" selected
			cout << "\nGAME OVER";
		}else if (command == "L"){
			cout << endl << lookAround[x][y] << endl;
			if (x==2 && y==2 || x==2 && y==1 || x==3 && y==3){
				hits.push_back(1);//add to hits vector for tracking health of ship
				if ((int)hits.size() > 3){
					cout << "\nYour ship has been destroyed, you and your crew have perished, humanity is doomed!\n" << endl;//dead from 4 hits
					return 0;
				}else{
					cout << "We can only sustain " << 4 - (int)hits.size() << " more hits Captain!" << endl;//countdown to ship destruction
				}
			}	
		}else if(command == "I"){
			cout << "You have: ";
			if(objloc[4] == -1){
					cout << "a bag of money, ";
			}
			cout << gems.size() << " gems." << endl;
		}
		
		else if (command == "G")
		{
			isItem = x*10 + y;
			for (int i = 0; i < numobj; i++)
			{
				if (objloc[i] == isItem)
				{
					if (!((isItem == 1) || (isItem == 11) || (isItem == 12))){ //cannot pick up protomolecule without all 4 gems
						cout << "\nYou got " << obj[i] << endl;
						gems.push_back(1);
						objloc[i] = 99;//kills the gem that has been picked up					
					}else if (isItem == 1 && (int)gems.size() != 4){
						cout << "\nCaptain, we do not yet have what Jules-Pierre Mao wants.... " << endl;
					}else if (isItem == 1 && (int)gems.size() == 4){
						cout << "\nJules-Pierre Mao has sold us the protomolecule for the 4 gems, lets get to the sun ASAP!" << endl;
						proto.push_back(1);//add protomolecule to proto vector
						gems.clear();//clear all gems from gem vector, gems gone forever
					}else if (isItem == 11){
						cout << "\nYou got " << obj[i] << endl;
						cash.push_back(1);//add cash to cash vector 
						objloc[i] = -1;//kills money location and allows for inventory search
					}else if (isItem == 12 && (int)cash.size() < 1){
						cout << "\nFred Johnson won't give it up without getting his money first..." << endl;
					}else if (isItem == 12 && (int)cash.size() > 0){
						cout << "\nFred Johnson has sold you " << obj[i] << " for the bag of money!" << endl;
						objloc[i] = 99;//kills the gem
						cash.clear();//clear cash from cash vector since we spent it on a gem
						gems.push_back(1);//add gem to gem vector 
						break;
					}
				}
			}
		}else if (command == "H" && x == 3 && y == 0 && (int)proto.size() > 0){//if you are at the sun and have the protomolecule 
				cout << endl;
				cout << "Firing the protomolecule into the Sun Capatain..." << endl << endl;
				cout << "...it worked! We did it!  Humanity is safe!" << endl << endl;
				cout << "For now..."; //you win the game
				return 0;//game over, victory
		}else {
			cout << "\nWe haven't gotten the protomolecule close enough to the Sun yet Captain!" << endl;//need proton molecule at Sun
		}
			// Catch over-the-edge and return to grid on the other side, borrowed from cupcake adventure and altered to fit larger 2D array
		if (x > 3) {x = 0;}
    	if (x < 0) {x = 3;}
    	if (y > 3) {y = 0;}
    	if (y < 0) {y = 3;}
	}	
    		
    cout << "\n\nGAME OVER";	
	return 0;//game over	
		
}
	
//introduction function, called once at start of the game
void introduction(){
	cout << "The year is 2218. Earth and Mars have been overcome by their greed \n";
	cout << "to dominate the Solar System.  The Belt and its inhabitants find themselves \n";
	cout << "caught between two warring superpowers, struggling to survive. Fueling hostilities \n";
	cout << "is the protomolecule, an alien molecule that aggressively seeks to destory humanity. \n";
	cout << "Both Earth and Mars seek to weaponize the molecule against one another, but the Belter \n";
	cout << "crew of the Rocinante know the only option is to destory the protomolecule forever. \n";
	cout << "Captain the Rocinante through the colonized Solar System in search of the 4 gems needed \n";
	cout << "to secure the protomolecule, then destory the protomolecule by shooting it into the sun. \n";
	cout << "Mars and Earth's navies are in battlemode so you better be quick. 30 commands or less or you're dead.\n";
	cout << "\nGood luck...and welcome to The Expanse.\n";
	cout << endl;
}
