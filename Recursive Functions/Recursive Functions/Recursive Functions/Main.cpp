/*
Write a recursive function that accepts two arguments into the parameters x and y.  The function should return the value of x times y.
Remember, multiplication can be performed as repeated addition:

7 * 4 = 4 + 4 + 4 + 4 + 4 + 4 + 4 

Programmer: Cesar Pena
Date: October 14, 2016
*/
#include<iostream>

using namespace std;

//Function Prototypes
int recursiveFunc(int, int);

int main(){
	//Declare Variables
	int x, y;

	//Display Title
	cout << "*************************************\n";
	cout << "**      Multiplication using       **\n";
	cout << "**           recursion             **\n";
	cout << "*************************************\n";
	cout << endl;

	//Prompt user for input
	cout << "Please enter value for x: ";
	cin >> x;
	cout << endl;

	//Input validation for x
	while(x < 1 || !cin){
		cout << "Invalid Entry!\n";
		cout << "Re-enter a positive x value: ";
		cin.clear();
		cin.ignore();
		cin >> x;
		cout << endl;
	}
	cout << "Please enter value for y: ";
	cin >> y;
	cout << endl;

	//Input validation for y
	while(y < 1 || !cin){
		cout << "Invalid Entry!\n";
		cout << "Re-enter a positive y value: ";
		cin.clear();
		cin.ignore();
		cin >> y;
		cout << endl;
	}

	//Display the total value of the multiplication using the recursion function.
	cout << "----------------------------------------------\n";
	cout << "The multiply total of " << x << " and " << y << " is " << recursiveFunc(x,y);
	cout << endl;

	system("pause");
	return 0;
}

//Function Definitions
int recursiveFunc(int x, int y){

	//Returns the value of x if y equals to 1.  
	if(y == 1)
		return x;
	else
		//This else keeps adding x's depending on how many y's were sent by the user
		//Example: 2 y's = x + x
		// 3 y's = x + x + x;
		return x + recursiveFunc(x,y-1);	
}
