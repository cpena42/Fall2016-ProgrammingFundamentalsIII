/*
You are to write a program which is going to use inheritance.  It should start off with the base classes

Account:  contains the string name, int accountnumber, double balance.

Savings:  Derived from Account class, it should contain double interest rate.

Checkings:  Derived from Account class, it should contain double overdraftlimit.

CreditCard:  Derived from Checkings class, it should contain int cardnumber.  


Create a program which will create an array of 3 Savings accounts, 3 Checkings accounts and 3 CreditCards.  

Create 3 files.  Savings.txt, Checkings.txt, CreditCards.txt which contains the information for each and infile the information from the file to the
array of the classes.

You will be graded on the method used to infile (make sure to use loops), the way the classes are constructed (inheritance), and the way the 
the classes are used (make sure the constructor and overloaded constructor is used correctly).  

As for the Main, simply do a display of all 3 savings, checkings and creditcards in a neat fashion (iomanip).  

zip the whole project and upload it (make sure the files are already populated with data).

Programmer: Cesar Pena
Date: October 2, 2016
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

//Base class - Account - used to set up the savings, checkings and creditcard classes
class Account{
private:
	string name;
	int accountNumber;
	double balance;
public:
	//Default Constructor
	Account(){name = " "; accountNumber = 0000; balance = 0;};
	//Overloaded Constructor
	Account(string n, int a, double b){name = n; accountNumber = a; balance = b;};

	//Mutator Functions to set the private members
	//Sets the name
	void setName(string n){
		name = n;
	};

	//Sets the account number
	void setAccountNumber(int a){
		accountNumber = a;
	};

	//Sets the balance
	void setBalance(double b){
		balance = b;
	};

	//Get function - Display the Account information
	void getAccount(){
		cout << name << "\t";
		cout << accountNumber << "\t";
		cout << balance << "\t";
	};
};

//Derived Savings class from account class
class Savings: public Account{
private:
	double interestRate;
public:
	//Default Constructor
	Savings(){interestRate = 0.05;};
	//Overloaded Constructor
	Savings(double i){interestRate = i;};

	//Mutator function
	//Set the interest rate
	void setInterestRate(double i){
		interestRate = i;
	};

	//Get function to display Savings Account
	void getSavings(){
		getAccount();
		cout << "     " << interestRate;
	};
};

//Derived Checkings class from account class
class Checkings: public Account{
private:
	double overdraftLimit;
public:
	//Default Constructor
	Checkings(){overdraftLimit = 50;};
	//Overloaded Constructor
	Checkings(double o){overdraftLimit = o;};

	//Mutator function
	//Set the overdraft limit
	void setOverdraftLimit(double o){
		overdraftLimit = o;
	};

	//Get function to display Checkings Account
	void getChecking(){
		getAccount();
		cout << "     " << overdraftLimit;
	};
};

//Derived CreditCard class from checkings class
class CreditCard: public Checkings{
private:
	int cardNumber;
public:
	//Default Constructor
	CreditCard(){cardNumber = 1111;};
	//Overloaded Constructor
	CreditCard(int c){cardNumber = c;};

	//Mutator Function - Sets the cardNumber
	void setCardNumber(int c){
		cardNumber = c;
	}

	//Get function to display CreditCard Account
	void getCreditCard(){
		getChecking();
		cout << "\t " << cardNumber;
	};
};

//Function Prototypes
void getData(Savings[], Checkings[], CreditCard[], int);

int main()
{
	/* Used for testing
	Savings save1(0.10);
	save1.setName("Cesar");
	save1.setAccountNumber(1111);
	save1.setBalance(50);
	save1.getSavings();

	cout << endl;

	Checkings check1(50);
	check1.setName("June");
	check1.setAccountNumber(1111);
	check1.setBalance(100);
	check1.getChecking();

	cout << endl;

	CreditCard card1(1234);
	card1.setName("Carlos");
	card1.setAccountNumber(3453);
	card1.setBalance(500);
	card1.setOverdraftLimit(50);
	card1.getCreditCard();
	*/
	//Declare variables
	const int SIZE = 3;

	//Declare object arrays to hold the 3 accounts for each class
	Savings save[SIZE];
	Checkings check[SIZE];
	CreditCard card[SIZE];

	//Function call to fill the arrays with the data from the text files
	getData(save, check, card, SIZE);

	//Use iomanip to set the money amounts to display 2 decimal places
	cout << fixed << showpoint << setprecision(2) << endl;

	//Display the Savings Accounts
	cout << "*********************************\n";
	cout << "**       Savings Accounts      **\n";
	cout << "*********************************\n";

	//Titles
	cout << "Name \tAcct# \tBalance\tInterestRate\n";
	//Get data from the savings class
	for(int x = 0; x < SIZE; x++){
		save[x].getSavings();
		cout << endl;
	}
	cout << endl;

	//Display the Checking Accounts
	cout << "*********************************\n";
	cout << "**      Checking Accounts      **\n";
	cout << "*********************************\n";

	//Titles
	cout << "Name \tAcct# \tBalance\tOverdraft Limit\n";
	//Get data from the checkings class
	for(int x = 0; x < SIZE; x++){
		check[x].getChecking();
		cout << endl;
	}
	cout << endl;

	//Display the Credit Card Accounts
	cout << "*********************************\n";
	cout << "**        Credit Cards         **\n";
	cout << "*********************************\n";

	//Titles
	cout << "Name \tAcct# \tBalance\tOverdraft Limit\tCardNumber\n";
	//Get data from the credit card class
	for(int x = 0; x < SIZE; x++){
		card[x].getCreditCard();
		cout << endl;
	}

	system("pause");
	return 0;
}

//Function definitions
//Fill the object arrays with data from text files.
void getData(Savings save[], Checkings check[], CreditCard card[], int SIZE){
	//Open the savings text file
	ifstream inFileSavings;
	inFileSavings.open("Savings.txt");

	//Open the checkings text file
	ifstream inFileChecking;
	inFileChecking.open("Checkings.txt");

	//Open the credit cards text file
	ifstream inFileCreditCards;
	inFileCreditCards.open("CreditCards.txt");

	//Temp Variables - Used to fill the object arrays
	string name;
	int number;
	double balance;
	double interestRate;
	double overdraftLimit;
	int cardNumber;

	//Fill the savings object array with data from the Savings.txt file
	for(int x = 0; x < SIZE; x++){
		//Get data from savings.txt file
		inFileSavings>>name;
		inFileSavings>>number;
		inFileSavings>>balance;
		inFileSavings>>interestRate;

		//Set the data to the save object array
		save[x].setInterestRate(interestRate);
		save[x].setName(name);
		save[x].setAccountNumber(number);
		save[x].setBalance(balance);
	}

	//Fill the checkings object array with the data from the Checkings.txt file
	for(int x = 0; x < SIZE; x++){
		//Get data from checkings.txt file
		inFileChecking>>name;
		inFileChecking>>number;
		inFileChecking>>balance;
		inFileChecking>>overdraftLimit;

		//Set the data to the check object array
		check[x].setOverdraftLimit(overdraftLimit);
		check[x].setName(name);
		check[x].setAccountNumber(number);
		check[x].setBalance(balance);
	}

	//Fill the creditcard object array with the data from the CreditCard.txt file
	for(int x = 0; x < SIZE; x++){
		//Get data from creditcard.txt file
		inFileCreditCards>>name;
		inFileCreditCards>>number;
		inFileCreditCards>>balance;
		inFileCreditCards>>overdraftLimit;
		inFileCreditCards>>cardNumber;

		//Set the data to the check object array
		card[x].setOverdraftLimit(overdraftLimit);
		card[x].setName(name);
		card[x].setAccountNumber(number);
		card[x].setBalance(balance);
		card[x].setCardNumber(cardNumber);

	}

	//Close the text files
	inFileSavings.close();
	inFileChecking.close();
	inFileCreditCards.close();
}