//Jacob Johnson
//jejohnson8@dmacc.edu or jacob.johnson365@gmail.com
/* This program allows a user to buy and sell four predetermined stocks over a 30 day period beginning on a Monday.  Market is closed on weekends.
Stocks slide up and down and stay stable based on a random draw matched with a pre determined pattern changing every 3-8 days.
User may also call up information on each of the four companies, and can decide to be done for the day at any time.  Information
is displayed after each day and completed info callup, purchase, and sale. If player profits 3% or more of initial seed money a 
message of congratulations will appear after day 30.*/


#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;
//struct for calling up company and stock information
struct Stock
{
	string Ticker;
	string Info;
	double Revenue;
	double AvgVol;
	double High52;
	double Low52;
	string Chairman;
};
//function prototype for function that provides company and stock information to the user upon request
void stockInfo(string choice);



int main(){
	//delcare and initialize variables
	string choice;
	string stockBuy;
	string stockSell;
	double applePrice = 173.04;
	double chipotlePrice = 328.17;
	double disneyPrice = 101.63;
	double teslaPrice = 299.65;
	double appleShares = 0;
	double chipotleShares = 0;
	double disneyShares = 0;
	double teslaShares = 0;
	double balance = 100000.00;
	double shares = 0;
	int day = 1;
	
	srand (time(NULL)); //seeds random number generator with machine time
	int state = rand()%3+1; //selects a random integer between 1 and 3 (including 1 and 3) to be used to determine stock trend
	
	//loop to run simulation for 30 days
	while (day <= 30){
		//if statement that excludes weekends assuming day 1 is a Monday and we are on earth circa 2018
		if(day == 6 || day == 7 || day == 13 || day == 14 || day == 20 || day == 21 || day == 27 || day == 28){
			day++;
		}else{
			cout << "\nDay: " << day << endl; //dispay informatioin and options for the user
			cout << "---------------" << endl;
			cout << "Cash balance: $" << fixed << setprecision(2) << balance << endl;
			cout << "Account value: $" << fixed << setprecision(2) << balance + (appleShares*applePrice) + (chipotleShares*chipotlePrice) + (disneyShares*disneyPrice) + (teslaShares*teslaPrice) << endl;
			cout << "You have " << appleShares << " shares of Apple, " << chipotleShares << " shares of Chipotle, " << disneyShares << " shares of Disney, and " << teslaShares << " shares of Tesla." << endl;
			cout << "For information on Apple ($" << fixed << setprecision(2) << applePrice << ") enter \"A\"" << endl;
			cout << "For information on Chipotle ($" << fixed << setprecision(2) << chipotlePrice << ") enter \"C\"." << endl;
			cout << "For information on Disney ($" << fixed << setprecision(2) << disneyPrice << ") enter \"D\"." << endl;
			cout << "For information on Tesla ($" << fixed << setprecision(2) << teslaPrice << ") enter \"T\"." << endl;
			cout << "To buy stock enter \"B\"." << endl;
			cout << "To sell stock enter \"S\"." << endl;
			cout << "To be done for the day enter \"X\"." << endl;
			cout << "Please enter your selection: ";
			cin >> choice;
	
			if(choice == "A" || choice == "C" || choice == "D" || choice == "T"){
				stockInfo(choice);//calls up information of the company user chose
			//allows user to buy stocks
			}else if (choice == "B"){
				cout << "Which stock would you like to purchase?\n";
				cout << "Apple \"A\", Chipotle \"C\", Disney \"D\", or Tesla \"T\": ";
				cin >> stockBuy;
				if(stockBuy == "A"){
					cout << "Current price $" << fixed << setprecision(2) << applePrice << endl;
					cout << "How many shares of Apple would you like to purchase? ";
					cin >> shares;
					if (shares*applePrice > balance){//example of input validation for available funds necessary to complete buy request
						cout << "\nYou do not have enough cash to complete this transaction.\n";
					}else{
						balance -= (applePrice*shares);
						appleShares += shares;
						cout << "You purchased " << shares << " shares of Apple stock for $" << fixed << setprecision(2) << applePrice << " each. Current cash balance is $" << fixed << setprecision(2) << balance << endl;
						cout << "You now have " << appleShares << " shares of Apple worth $" <<fixed << setprecision(2) << appleShares*applePrice << endl;
						cout << endl;	
					} 
				}else if (stockBuy == "C"){
					cout << "Current price $" << fixed << setprecision(2) << chipotlePrice << endl;
					cout << "How many shares of Chipotle would you like to purchase? ";
					cin >> shares;
					if (shares*chipotlePrice > balance){
						cout << "\nYou do not have enough cash to complete this transaction.\n";
					}else{
						balance -= (chipotlePrice*shares);
						chipotleShares += shares;
						cout << "You purchased " << shares << " shares of Chipotle stock for $" << fixed << setprecision(2) << chipotlePrice << " each. Current cash balance is $" << fixed << setprecision(2) << balance << endl;
						cout << "You now have " << chipotleShares << " shares of Chipotle worth $" <<fixed << setprecision(2) << chipotleShares*chipotlePrice << endl;
						cout << endl; 
					}
					
				}else if (stockBuy == "D"){
					cout << "Current price $" << fixed << setprecision(2) << disneyPrice << endl;
					cout << "How many shares of Disney would you like to purchase? ";
					cin >> shares;
					if (shares*disneyPrice > balance){
						cout << "\nYou do not have enough cash to complete this transaction.\n";
					}else{
						balance -= (disneyPrice*shares);
						disneyShares += shares;
						cout << "You purchased " << shares << " shares of Disney stock for $" << fixed << setprecision(2) << disneyPrice << " each. Current cash balance is $" << fixed << setprecision(2) << balance << endl;
						cout << "You now have " << disneyShares << " shares of Disney worth $" <<fixed << setprecision(2) << disneyShares*disneyPrice << endl;
						cout << endl; 	
					}
				}else if (stockBuy == "T"){
					cout << "Current price $" << fixed << setprecision(2) << teslaPrice << endl;
					cout << "How many shares of Tesla would you like to purchase? ";
					cin >> shares;
					if (shares*teslaPrice > balance){
						cout << "\nYou do not have enough cash to complete this transaction.\n";
					}else{
						balance -= (teslaPrice*shares);
						teslaShares += shares;
						cout << "You purchased " << shares << " shares of Tesla stock for $" << fixed << setprecision(2) << teslaPrice << " each. Current cash balance is $" << fixed << setprecision(2) << balance << endl;
						cout << "You now have " << teslaShares << " shares of Tesla worth $" <<fixed << setprecision(2) << teslaShares*teslaPrice << endl;
						cout << endl; 	
					}
				}else{
					cout << "Incorrect entry." << endl;
				}
			}else if (choice == "S"){//allows user to sell stocks
				cout << "Which stock would you like to sell?\n";
				cout << "Apple \"A\", Chipotle \"C\", Disney \"D\", or Tesla \"T\": ";
				cin >> stockSell;
				if(stockSell == "A"){
					cout << "Current price $" << fixed << setprecision(2) << applePrice << endl;
					cout << "How many shares of Apple would you like to sell? ";
					cin >> shares;
					if (shares > appleShares){ //example of input validation to check if user has sufficient funds to complete sale
						cout << "\nYou do not have that many shares to sell.\n";
					}else{
						balance += (applePrice*shares);
					appleShares -= shares;
					cout << "You sold " << shares << " shares of Apple stock for $" << fixed << setprecision(2) << applePrice << " each. Current cash balance is $" << fixed << setprecision(2) << balance << endl;
					cout << "You now have " << appleShares << " shares of Apple worth $" <<fixed << setprecision(2) << appleShares*applePrice << endl;
					cout << endl; 
					}
				}else if (stockSell == "C"){
					cout << "Current price $" << fixed << setprecision(2) << chipotlePrice << endl;
					cout << "How many shares of Chipotle would you like to sell? ";
					cin >> shares;
					if (shares > chipotleShares){
						cout << "\nYou do not have that many shares to sell.\n";
					}else{
						balance += (chipotlePrice*shares);
						chipotleShares -= shares;
						cout << "You sold " << shares << " shares of Chipotle stock for $" << fixed << setprecision(2) << chipotlePrice << " each. Current cash balance is $" << fixed << setprecision(2) << balance << endl;
						cout << "You now have " << chipotleShares << " shares of Chipotle worth $" <<fixed << setprecision(2) << chipotleShares*chipotlePrice << endl;
						cout << endl; 
						}
				}else if (stockSell == "D"){
					cout << "Current price $" << fixed << setprecision(2) << disneyPrice << endl;
					cout << "How many shares of Disney would you like to sell? ";
					cin >> shares;
					if (shares > disneyShares){
						cout << "\nYou do not have that many shares to sell.\n";
					}else{
						balance += (disneyPrice*shares);
						disneyShares -= shares;
						cout << "You sold " << shares << " shares of Disney stock for $" << fixed << setprecision(2) << disneyPrice << " each. Current cash balance is $" << fixed << setprecision(2) << balance << endl;
						cout << "You now have " << disneyShares << " shares of Disney worth $" <<fixed << setprecision(2) << disneyShares*disneyPrice << endl;
						cout << endl; 
					}
				}else if (stockSell == "T"){
					cout << "Current price $" << fixed << setprecision(2) << teslaPrice << endl;
					cout << "How many shares of Tesla would you like to sell? ";
					cin >> shares;
					if (shares > teslaShares){
						cout << "\nYou do not have that many shares to sell.\n";
					}else{
						balance += (teslaPrice*shares);
						teslaShares -= shares;
						cout << "You sold " << shares << " shares of Tesla stock for $" << fixed << setprecision(2) << teslaPrice << " each. Current cash balance is $" << fixed << setprecision(2) << balance << endl;
						cout << "You now have " << teslaShares << " shares of Tesla worth $" <<fixed << setprecision(2) << teslaShares*teslaPrice << endl;
						cout << endl; 
					}	
				}else{
					cout << "Incorrect entry." << endl;
				}
			}else if (choice == "X"){ //updates prices for each stock based on trend determined by RNG at beginning of program
				while (day <=5){
					if (state == 1){
						applePrice *= 1.02;
						chipotlePrice *= .986;
						disneyPrice *= 1.001;
						teslaPrice *= .979;
						break;
					}else if (state == 2){
						applePrice *= .999;
						chipotlePrice *= .974;
						disneyPrice *= 1.019;
						teslaPrice *= 1.012;
						break;
					}else{
						applePrice *= .991;
						chipotlePrice *= 1.001;
						disneyPrice *= 1.01;
						teslaPrice *= 1.012;
						break;
					}
				}while (day >5 && day <=11){
					if (state == 1){
						applePrice *= 1.041;
						chipotlePrice *= .999;
						disneyPrice *= 1.001;
						teslaPrice *= .973;
						break;
					}else if (state == 2){
						applePrice *= 1.015;
						chipotlePrice *= .974;
						disneyPrice *= 1.03;
						teslaPrice *= 1.0025;
						break;
					}else{
						applePrice *= .989;
						chipotlePrice *= 1.001;
						disneyPrice *= 1.0124;
						teslaPrice *= .999;
						break;
					}
		    	}while (day >11 && day <=16){
		    		if (state == 1){
						applePrice *= .989;
						chipotlePrice *= 1.02;
						disneyPrice *= 1.032;
						teslaPrice *= .994;
						break;
					}else if (state == 2){
						applePrice *= 1.02;
						chipotlePrice *= 1.013;
						disneyPrice *= .971;
						teslaPrice *= 1.009;
						break;
					}else{
						applePrice *= .995;
						chipotlePrice *= .96;
						disneyPrice *= 1.012;
						teslaPrice *= .989;
						break;
					}
				}while (day >16 && day <=24){
		    		if (state == 1){
						applePrice *= 1.01;
						chipotlePrice *= 1.005;
						disneyPrice *= 1.004;
						teslaPrice *= 1.032;
						break;
					}else if (state == 2){
						applePrice *= .984;
						chipotlePrice *= .963;
						disneyPrice *= 1.003;
						teslaPrice *= 1.009;
						break;
					}else{
						applePrice *= .998;
						chipotlePrice *= .975;
						disneyPrice *= 1.01;
						teslaPrice *= .98;
						break;
					}
				}while (day >24 && day <=30){
		    		if (state == 1){
						applePrice *= 1.01;
						chipotlePrice *= 1.011;
						disneyPrice *= .98;
						teslaPrice *= 1.002;
						break;
					}else if (state == 2){
						applePrice *= .991;
						chipotlePrice *= 1.002;
						disneyPrice *= 1.006;
						teslaPrice *= 1.01;
						break;
					}else{
						applePrice *= .994;
						chipotlePrice *= .993;
						disneyPrice *= 1.001;
						teslaPrice *= .989;
						break;
					}
				}
		    	day++;
			}else{
				cout << "Error, incorrect input. Please try again";
			}
		}
	}
	if (balance + (appleShares*applePrice) + (chipotleShares*chipotlePrice) + (disneyShares*disneyPrice) + (teslaShares*teslaPrice) >+ 103000.00){ //checks if user surpassed the 103K goal
		cout << "\nCongratulations, you realized a positive return of 3% or more!!\n";
	}
	//outputs final totals	
	cout << "\nThank you for taking part in the stock simulator." << endl;
	cout << "Your final cash balance is $" << balance << endl;
	cout << "Your final Apple stock balance is " << appleShares << " shares worth $" << appleShares*applePrice << endl;
	cout << "Your final Chipotle stock balance is " << chipotleShares << " shares worth $" << chipotleShares*chipotlePrice << endl;
	cout << "Your final Disney stock balance is " << disneyShares << " shares worth $" << disneyShares*disneyPrice << endl;
	cout << "Your final Tesla stock balance is " << teslaShares << " shares worth $" << teslaShares*teslaPrice << endl;
	cout << "The total value of your account is $" << balance + (appleShares*applePrice) + (chipotleShares*chipotlePrice) + (disneyShares*disneyPrice) + (teslaShares*teslaPrice);
	
	return 0;
}


void stockInfo(string choice){
	Stock Apple;
	Apple.Ticker = "APPL";
	Apple.Info = "Apple Inc. (Apple), incorporated on January 3, 1977, designs, \n manufactures and markets mobile communication and media devices,\n personal computers and portable digital music players \n and sells a variety of related software, services, peripherals,\n networking solutions and third-party digital content and applications. \n The Company's products and services include iPhone, iPad,\n Mac, iPod, Apple TV, a portfolio of consumer and professional software\n applications, the iOS and OS X operating systems, iCloud and a variety\n of accessory, service and support offerings. The Company offers a range\n of mobile communication and media devices, personal computing products\n and portable digital music players, as well as a variety of related\n software, services, peripherals, networking solutions and third-party hardware\n and software products. In addition, the Company offers its own\n software products, including iOS, the Company's mobile operating system;\n OS X, the Company's Mac operating system; and server and application software.\n The Company's primary products include iPhone, iPad, Mac, iPod, iTunes,\n Mac App Store, iCloud, Operating System Software, Application Software and\n Other Application Software.";
	Apple.Revenue = 50577.00;
	Apple.AvgVol = 8007.73;
    Apple.High52 = 123.81;
	Apple.Low52 = 89.47;
	Apple.Chairman = "Art Levinson";
	
	Stock Chipotle;
	Chipotle.Ticker = "CMG";
	Chipotle.Info = "Chipotle Mexican Grill, Inc., incorporated on January 30, 1998, together with its subsidiaries operates Chipotle Mexican Grill restaurants. The Company's Chipotle Mexican Grill restaurants serve a menu of burritos, tacos, burrito bowls (a burrito without the tortilla) and salads. The Company operates approximately 1,970 Chipotle restaurants throughout the United States, over 10 in Canada, seven in England, four in France and one in Germany. The Company's restaurants include over 10 ShopHouse Southeast Asian Kitchen restaurants, serving Asian-inspired cuisine. The Company owned and operated approximately three Pizzeria Locale restaurants, a fast casual pizza concept, resulting in a totaling of approximately 2,010 restaurants. The Company sells gift cards which do not have an expiration date.";
	Chipotle.Revenue = 1898.00;
	Chipotle.AvgVol = 161937;
	Chipotle.High52 = 757.00;
	Chipotle.Low52 = 384.80;
	Chipotle.Chairman = "Steve Ells";
	
	Stock Disney;
	Disney.Ticker = "DIS";
	Disney.Info = "The Walt Disney Company, incorporated on July 28, 1995, is a diversified entertainment company. The Company operates through five business segments: Media Networks, Parks and Resorts, Studio Entertainment, Consumer Products and Interactive.";
	Disney.Revenue = 12969.00;
	Disney.AvgVol = 2238425;
	Disney.High52 = 120.65;
	Disney.Low52 = 86.25;
	Disney.Chairman = "Robert Iger";
	
	Stock Tesla;
	Tesla.Ticker = "TSLA";
	Tesla.Info = "Tesla Motors, Inc., incorporated on July 1, 2003, designs, develops, manufactures and sells electric vehicles and energy storage products. The Company produces and sells two electric vehicles: the Model S sedan and the Model X sport utility vehicle (SUV). The Company has delivered over 107,000 Model S vehicles across the world. In addition to developing its own vehicles, it sells energy storage products. Its energy storage products include the seven kilowatt-hour and 10 kilowatt-hour Powerwall for residential applications, and the 100 kilowatt-hour Powerpack for commercial and industrial applications. The Company delivers energy storage products products under the Tesla Energy brand. It manufactures its products primarily at its facilities in Fremont, California, Lathrop, California, Tilburg, Netherlands and at its Gigafactory near Reno, Nevada. It is using battery packs manufactured at the Gigafactory for its energy storage products.";
	Tesla.Revenue = 2236.16;
	Tesla.AvgVol = 924800;
	Tesla.High52 = 269.34;
	Tesla.Low52 = 141.13;
	Tesla.Chairman = "Elon Musk";
	
	if (choice == "A"){
		cout << "*****************************************" << endl;
		cout << "Information for Apple, Inc." << endl;
		cout << "Ticker Sympol: " << Apple.Ticker << endl;
		cout << "Revenue: " << Apple.Revenue << endl;
		cout << "Avg. Vol.: " << Apple.AvgVol << endl;
		cout << "52 Week High: " << Apple.High52 << endl;
		cout << "52 Week Low:  " << Apple.Low52 << endl;
		cout << "Chairman: " << Apple.Chairman << endl;
		cout << "Company Info: " << Apple.Info << endl;
		cout << "*****************************************" << endl;
	}else if (choice == "C"){
		cout << "*****************************************" << endl;
		cout << "Information for Chipotle Mexican Grill, Inc." << endl;
		cout << "Ticker Sympol: " << Chipotle.Ticker << endl;
		cout << "Revenue: " << Chipotle.Revenue << endl;
		cout << "Avg. Vol.: " << Chipotle.AvgVol << endl;
		cout << "52 Week High: " << Chipotle.High52 << endl;
		cout << "52 Week Low:  " << Chipotle.Low52 << endl;
		cout << "Chairman: " << Chipotle.Chairman << endl;
		cout << "Company Info: " << Chipotle.Info << endl;
		cout << "*****************************************" << endl;
	}else if (choice == "D"){
		cout << "*****************************************" << endl;
		cout << "Information for The Walt Disney Company" << endl;
		cout << "Ticker Sympol: " << Disney.Ticker << endl;
		cout << "Revenue: " << Disney.Revenue << endl;
		cout << "Avg. Vol.: " << Disney.AvgVol << endl;
		cout << "52 Week High: " << Disney.High52 << endl;
		cout << "52 Week Low:  " << Disney.Low52 << endl;
		cout << "Chairman: " << Disney.Chairman << endl;
		cout << "Company Info: " << Disney.Info << endl;
		cout << "*****************************************" << endl;
	}else if (choice == "T"){
		cout << "*****************************************" << endl;
		cout << "Information for Tesla Motors, Inc." << endl;
		cout << "Ticker Sympol: " << Tesla.Ticker << endl;
		cout << "Revenue: " << Tesla.Revenue << endl;
		cout << "Avg. Vol.: " << Tesla.AvgVol << endl;
		cout << "52 Week High: " << Tesla.High52 << endl;
		cout << "52 Week Low:  " << Tesla.Low52 << endl;
		cout << "Chairman: " << Tesla.Chairman << endl;
		cout << "Company Info: " << Tesla.Info << endl;
		cout << "*****************************************" << endl;
	}	
}


