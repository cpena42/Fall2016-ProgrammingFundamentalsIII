/*
You are to write an ATM Program.

The ATM should allow the user to do the following:

1.  Create account

2.  Log in

3.  Exit

When they press 1, they are asked for first name (capital first letter).  Then it should ask for password.  The computer should give the user a random 4 digit account number (cant start with a 0).  Make sure you follow these rules:

The user name should not be the same as another user's name.  The account number should not be the same as the other user's account number.
The new account should start off with 50 dollars.
The accounts (including name, password and account number) should be on a file called Accounts.  **use arrays to hold everyones information from the file, use a function to retrieve this data, which is done at the start of the program**
When you press 2, they are prompted to enter name, and password.  You should have already received all information from the Accounts file as mentioned above.  If they enter the wrong information 3 times, exit back to the previous window with the 3 choices.  If they enter correctly, should do the followint:

Withdraw  - take money, if there is not enough money it should warn them and allow them to try again OR press -1 to return to previous window.  Any other negative number should not work.
Deposit - add money, if they do not want to add money, -1 will return to previous window while any other negative number will not work.
View Balance - display balance and have user press enter to return to previous window.
Exit - exit the account and return back to the original screen with the 3 options.  When this option is selected, it should update the Accounts file with the new information.
Any other number will not work
When they press 3, thank them and exit program.

**Again we are using only condition statements, loops, functions, files, and arrays.  Do not use material from 1337 such as classes.  Make sure to add comments**

When you are done, zip the entire folder with all the files as they are  (I want to be able to simply unzip your folder and open your project, the Accounts file should have Minimum 5 accounts already in there)

If you have any questions about this assignment, please let me know so I can clarify the instructions and requirements.


Cesar Pena
Date: September 9, 2016

*/
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <iomanip>
//#include <cstdlib>	Book showed it was required for using random numbers

using namespace std;

//Function Prototypes - Divided by type
//Display main menu and account menu, returning the option the user selects
int mainMenu();
int accountMenu();

//Bool function to test if a username and password combination exist
bool login(string, string, int, string[], string[], int&);

//Changes the first letter of a string to a capital
string toUppercase(string);

//Get and save data to the Accounts text file.
void getData(string[], string[], unsigned int[], double[], int, int&);
void saveData(string[], string[], unsigned int[], double[], int);

//Create a new account function
void createAccount(int&, string[], string[], double[], unsigned int[], int);

//Void functions used to display program titles
void title();
void accountTitle();
void accountOptions();
void loginMenu();
void withdrawMenu();
void depositMenu();

// void allAccounts(string[], string[], double[], unsigned int[], int);  Used for testing!

int main()
{
	srand(static_cast<unsigned int>(time(NULL))); // seed rand()

	//Declare variables
	const int NUM = 50;					// Program will hold a maximum of 50 accounts, can be changed later.
	int accountPos = 0;
	string accountName[NUM];
	string accountPassword[NUM];
	unsigned int accountNumber[NUM];
	double money[NUM];

	string username;
	string password;

	//Variables for calculations and tests
	int choice;
	bool boolValue = false;
	bool test = false;
	int attempts = 0;
	int loginPos;
	double withdrawAmount;
	double depositAmount;

	//Initialize all the arrays
	for(int x = 0; x < NUM; x++){
		accountName[x] = "";
		accountPassword[x] = "";
		accountNumber[x] = NULL;
		money[x] = NULL;
	}

	//Get accounts data from the Accounts file
	getData(accountName, accountPassword, accountNumber, money, NUM, accountPos);

	//do while statement to make sure that the main menu is displayed always if invalid data is entered.
	do
	{
		system("cls");	//Clear the screen
		title();		//Display program title

		// allAccounts(accountName, accountPassword, money, accountNumber, NUM); Used for testing!

		//Get the menu choice from the user
		choice = mainMenu();

		//Switch statement that'll execute a case depending on choice from user.
		switch(choice){
			case 1:
				//Run this case statement if the user selects to create a new account.
				system("cls");		// Clear the screen
				accountTitle();		// Display the create account title

				//Function call to create a new account
				createAccount(accountPos, accountName, accountPassword, money, accountNumber, NUM);

				break;

			case 2:
				//Run this case statement if the user selects to login.
				//Give the user 3 attempts to enter the username and password correctly.
				while(attempts <= 2){
					system("cls");		// Clear the system
					
					loginMenu();		// Display the login title

					//Prompt user for username and password
					cout << "Enter your username: ";
					cin >> username;
					cout << "Enter your password: ";
					cin >> password;

					//Function call to test if the username and password combination is found in the username and password arrays.
					boolValue = login(username, password, NUM, accountName, accountPassword, loginPos);
					if(boolValue)
						attempts += 3;		// If a user was found then attempts will be change to 3 to exit the while loop.
					else
						attempts += 1;		// Else increment attempts by 1 and allow another username and password combination to be entered, remain in while loop.
				}

				//If attempts is greater than 3 and no user was found run this if statement to let
				//the user know that the maximum number of logins have been attempted
				//Exits back to the main menu.
				if(attempts >= 2 && !boolValue){
					cout << "You have entered the maximum login attempts" << endl;
					cout << "Returning to main menu" << endl;
					system("pause");
				}

				//Sets attempts back to 0 in case Login is used again.
				attempts = 0;

				//If a user was found run this statement and display the accounts menu options, "withdraw", "deposit", "balance", and "logout"
				if(boolValue){
					//do while loop to continue displaying the accounts menu options unless the logout options is used
					do{
						system("cls");			// Clear the screen.

						accountOptions();		// Display the accounts option menu title		

						choice = accountMenu();	// Display the accounts options menu choices and returns the choice from the user

						//Switch statement that will execute depending on the choice 
						//selected from the user.
						switch(choice){
						case 1:
							//Run this case statement if the user selects to withdraw from the account
							//do while loop to continue displaying the menu unless a valid amount is entered.
							do{
								system("cls");		// Clear the system
								
								withdrawMenu();		// Display the withdraw menu title

								//Prompt the user to enter a withdraw amount
								cout << "Enter amount to withdraw OR -1 to cancel: ";
								cin >> withdrawAmount;

								//If the withdraw amount is greater than the balance on their account
								//warn the user and allow them to reenter the amount.
								if(withdrawAmount > money[loginPos]){
									cout << "Not enough money to withdraw that amount. " << endl;
									cout << "Please try again!"<< endl;
									system("pause");
								}
								//If the withdraw amount is less than or equal 0 but not equal to -1
								//warn the user that only valid amounts are accepted
								else if (withdrawAmount <= 0 && withdrawAmount != -1){
									cout << "Please enter a valid withdraw amount! " << endl;
									cout << "Please try again!"<< endl;
									system("pause");
								}
								//If the user entered a valid amount that did not exceed the balance
								//or the -1 then this else will run which will deduct the amount
								//entered from the balance and set the test bool variable to true to
								//exit the do while loop
								else{
									money[loginPos] -= withdrawAmount;
									test = true;
								}

							}while(!test);
							
							//Sets the test bool variable back to false to future testing
							test = false;

							break;
						case 2:
							//Run this case statement if the user selects to deposit into their account.
							//do while loop to display the deposit menu continously unless a valid amount is entered.
							do{

								system("cls");		// Clear the screen
							
								depositMenu();		// Display the deposit menu title

								//Prompt the user to enter the deposit amount
								cout << "Enter amount to deposit OR -1 to cancel: ";
								cin >> depositAmount;

								//If the depositAmount is less than or equal to 0 but not equal to 0 then run this statement
								//to prevent the user from entering negatives.
								if (depositAmount <= 0 && depositAmount != -1){
									cout << "Please enter a valid deposit amount! " << endl;
									cout << "Please try again!"<< endl;
									system("pause");
								}
								//Run this else statement if the depositAmount is a positive value greater or equal to 1
								else{
									money[loginPos] += depositAmount;
									test = true;	// change the test value to true to exit the while loop
								}
							}while(!test);

							//Change the test value back to false for future testing
							test = false;

							break;
						case 3:
							//Run this case statement if the user selects to view the Account Balance.
							system("cls");	//Clear the screen

							//Display the account balance title
							cout <<"-------------------------------------"<<endl;
							cout <<"--        Account Balance          --"<<endl;
							cout <<"-------------------------------------"<<endl;
							cout<<endl;

							//Sets the cout to 2 decimal places so that the amount is
							//displayed like in currency style.
							cout << fixed << showpoint << setprecision(2) << endl;
							cout << "Balance: $" << money[loginPos] << endl << endl;

							system("pause");

							break;
						case 4:
							//Run this case statement if the user selects to logout
							//from the account, saving all changes to the Accounts text file
							//Function call to send all changes to the Accounts file
							saveData(accountName, accountPassword, accountNumber, money, NUM);

							break;
						}
					}while(choice != 4);	//Exits the while loop if the logout option was selected
				}

				break;

			case 3:
				//Run this case statement if the user chooses to exit the program
				//Saving all changes to the Accounts text file
				saveData(accountName, accountPassword, accountNumber, money, NUM);

				//Thank the user for using the program
				cout << endl;
				cout << "Thank you for using the ATM";
				cout << endl;
				break;
		}
	}while(choice != 3);	// Exits the while loop if the user selects the exit option

	system("pause");		// Pauses the system to allow the user to see the Thank you message.
	return 0;
}

//Function definitions

// This function will get the data from the Accounts.txt file and store it
// in the accountName, accountPassword, accountNumber, and money arrays
void getData(string accountName[], string accountPassword[], unsigned int accountNumber[], double money[], int NUM, int& accountPos){
	ifstream inFile;				
	inFile.open("Accounts.txt");	// Open the data Accounts.txt file to prepare to read to the variables
	
	//Loop to fill all the array with the data
	for (int x = 0; x < NUM; x++)
	{
		//Get the accounts from the Accounts.txt file
		inFile>>accountName[x];
		inFile>>accountPassword[x];
		inFile>>accountNumber[x];
		inFile>>money[x];
	}
	
	//Loop to find the position of the first empty account
	for (int x = 0; x < NUM; x++)
	{
		if(accountNumber[x] == NULL){
			accountPos = x;
			x = 50;
		}
	}

	inFile.close(); // Close the file
}

//This function will save the data from all the arrays back into the Accounts.txt file
void saveData(string accountName[], string accountPassword[], unsigned int accountNumber[], double money[], int NUM){
	ofstream outFile;
	outFile.open("Accounts.txt");		// Opens the outfile to prepare for data saving.
	for (int x = 0; x < NUM; x++)
	{
		//Get the accounts from the Accounts.txt file
		outFile << accountName[x] << endl;
		outFile << accountPassword[x] << endl;
		outFile << accountNumber[x] << endl;
		outFile << money[x] << endl;
	}
	outFile.close(); // Close the file
}

//Function that'll display the main menu to the user and return the selection back to main
int mainMenu(){
	int choice;
	cout << "1 < Create an Account" << endl;
	cout << "2 < Log in" << endl;
	cout << "3 < Exit" << endl;

	cout << endl;
	cout << "Make your selection by using (1-3): ";
	cin >> choice;

	return choice;
}

//Function that'll check if a username and password combination was found.
bool login(string username, string password, int NUM, string accountName[], string accountPassword[], int& loginPos){

	for (int x = 0; x < NUM; x++){
		if (username == accountName[x] && password == accountPassword[x]){
			loginPos = x;
			return true;		// Returns true if a combination was found
		}
	}
	return false;	// Return false if a combination was not found
}

//Function that will create a new account to the system.
//Allows the user to enter a user name and a password and the system
//will automatically generate an accountNumber and beginning balance of 50.00
void createAccount(int& accountPos, string accountName[], string accountPassword[], double money[], unsigned int accountNumber[], int NUM){
	//Function variables
	int pos = accountPos;
	bool tester = true;
	int x;
	unsigned int randomNum;
	const double begCash = 50;
	string name;
	string password;

	//do while loop to test for accountNumber duplicates, it'll continue to generate a random number
	//until no duplicates are found in the accountNumber array
	do{
		randomNum = 1000 + rand() % 9999;

		for(x = 0; x < NUM; x++){
			if(randomNum == accountNumber[x])
				tester = false;
			}
			
	}while(!tester);
	
	//Prompt the user for a name.
	cout << "Name: ";
	cin >> name;

	//Function call to make sure that the first letter of the entered name is capitalized.
	name = toUppercase(name);

	//For loop that'll check if the name entered is already in the accountName array,
	//if it is it'll warn the user and exit back to main menu.
	for(x = 0; x < NUM; x++){
		if(name == accountName[x]){
			cout << "Account name already exists " << endl;
			cout << "Please try again " << endl;

			system("pause");
			return;
		}
	}

	//Prompt the user for a password
	cout << "Password: ";
	cin >> password;

	//Assign the new values to all the arrays using the pos variable as the element number
	accountNumber[pos] = randomNum;
	accountName[pos] = name;
	accountPassword[pos] = password;
	money[pos] = begCash;

	//Display the newly created account
	cout << "ACCOUNT CREATED! " << endl;
	cout << "Account #: " << accountNumber[pos] << endl;
	cout << "Account Name: " << accountName[pos] << endl;
	cout << "Account Password: " << accountPassword[pos] << endl;
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Balance: $" << money[pos] << endl;

	//Warn the user that the Account name was capitalized and will need to be entered
	//exactly like that to login into the system.
	cout << endl;
	cout << "Note: Account name capitalized automatically, make sure to use " << endl;
	cout << "      this format to login into your account." << endl;
	system("pause");

	accountPos += 1;
}

//Function definition used to display the account menu and will
//return the choice back to main.
int accountMenu(){
	int choice;
	cout << "1 < Withdraw" << endl;
	cout << "2 < Deposit" << endl;
	cout << "3 < View Balance" << endl;
	cout << "4 < Log out" << endl;

	cout << endl;
	cout << "Make your selection by using (1-4): ";
	cin >> choice;

	return choice;
}

/* View all accounts for testing purposes!
   was used to view all accounts in the running program.
void allAccounts(string accountName[], string accountPassword[], double money[], unsigned int accountNumber[], int NUM){
	
	for(int x = 0; x < NUM; x++){
		cout << "Account #: " << accountNumber[x] << endl;
		cout << "Account Name: " << accountName[x] << endl;
		cout << "Account Password: " << accountPassword[x] << endl;
		cout << "Balance: " << money[x] << endl;
	}
}*/

//Function definition that'll capitalize the first letter of a string
string toUppercase(string username){
	username[0] = toupper(username[0]);				//Change the first letter of the string to an uppercase

	return username;
}

//Function definition to display the program's main title
void title(){
	cout <<"-------------------------------------"<<endl;
	cout <<"--           ATM MACHINE           --"<<endl;
	cout <<"-------------------------------------"<<endl;
	cout <<"Choose from the following menu: " << endl;
	cout<<endl;
}

//Function definition to display the programs new account title
void accountTitle(){
	cout <<"-------------------------------------"<<endl;
	cout <<"--       Create New Account        --"<<endl;
	cout <<"-------------------------------------"<<endl;
	cout <<"Please provide the following: " << endl;
	cout<<endl;
}

//Function definition to display the account options title
void accountOptions(){
	cout <<"-------------------------------------"<<endl;
	cout <<"--        Account Options          --"<<endl;
	cout <<"-------------------------------------"<<endl;
	cout <<"Choose from the following menu: " << endl;
	cout<<endl;
}

//Function definition to display the login menu title
void loginMenu(){
	cout <<"-------------------------------------"<<endl;
	cout <<"--           Login Menu            --"<<endl;
	cout <<"-------------------------------------"<<endl;
	cout <<"Please provide the following: " << endl;
	cout <<"Info is case sensitive! " << endl;
	cout<<endl;
}

//Function definition to display the withdraw menu title
void withdrawMenu(){
	cout <<"-------------------------------------"<<endl;
	cout <<"--         Withdraw Money          --"<<endl;
	cout <<"-------------------------------------"<<endl;
	cout <<"Please provide the following: " << endl;
	cout<<endl;
}

//Function definition to display the deposit menu title
void depositMenu(){
	cout <<"-------------------------------------"<<endl;
	cout <<"--         Deposit Money           --"<<endl;
	cout <<"-------------------------------------"<<endl;
	cout <<"Please provide the following: " << endl;
	cout<<endl;
}