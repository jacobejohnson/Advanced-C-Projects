//Jacob Johnson
// 1/16/18
//jejohnson8@dmacc.edu

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int number;
	
	cout << "Hello, please enter a whole number from 10-1000: ";
	cin >> number;
	
	if (number < 10 || number > 1000){ //input validation
		cout << "Error!  Please enter a number from 10-1000: ";
		cin >> number;
	}
	
	int i = 1;
	while (i <= number){
		if (i%3 == 0 && i%5 != 0){
			cout << "Zoom" << endl;//prints Zoom if modulo for 3 only is 0
		}
		else if (i%5 == 0 && i%3 != 0){
			cout << "Schwartz" << endl;//prints Schwartz if modulo for 5 only is 0
		}
		else if (i%3 == 0 && i%5 == 0){
			cout << "Surprise" << endl; //prints Surprise if modulo for 3 and 5 are both 0
			system("pause"); // will ask for any key to remember after multiples of 15
		}
		else 
			cout << i << endl;
		++i;
	}
	
	return 0;
}
