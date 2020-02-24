/*
You are to write a program which will ask the user for number of students (dynamic array of class Student).
For each student, you will ask for first name and number of grades (dynamic array of grades as a variable in Student).

**The program should give the student random grades from 0-100**
Find the averages of each student and display the information.

**Display name, grades, and average neatly**
Sort the students by average (least to greatest).

Programmer: Cesar Pena
Date: September 18, 2016
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>		//Needed to use time for generating random numbers

using namespace std;

//Student class will be used as a dynamic array
//to create a user defined number of students with amount of grades
//that will be randomized between 0-100
class Student{
private:
	//Declare private member variables
	string name;
	double *grades;
	int numGrades;		//Holds the size of the grades array  - Used to calculate the average
public:
	//Default constructor
	Student(){name = ""; grades = new double[1]; grades[0] = 0;}

	//Overloaded constructor
	Student(string sName, int size){name = sName; numGrades = size; generateScores(size);}

	//Mutator Function
	void setStudent(string sName, int size){name = sName; numGrades = size; generateScores(size);}

	//Class Functions
	void generateScores(int size){
		double *array = new double[size];	//Dynamically sets the temporary pointer array to size of user defined "size"

		//Generate random scores from 0 - 100
		for(int i=0; i<size; i++)
		{
			array[i] = rand() % 100 + 1;
		}
		
		//Set the dynamic member variable array grades with the specified size
		grades = new double[size];

		//Copy contents of the temporary pointer array to the new grades array
		for(int i = 0; i < size; i++)
			grades[i] = array[i];
			
	}

	//Calculate the grade average;
	double average(){
		//Declare variables
		double average;		//Will hold calculated average
		double total = 0;	//Counter variable that will be used to add up all the grades
		
		//Used a for loop to add up all the grades into the total variable
		for(int i = 0; i < numGrades; i++){
			total += grades[i];
		}
		
		//Calculate the average using the total and the size of the array
		average = total / numGrades;

		//Returns the average
		return average;
	}

	//Get Functions - Used to return the values from the private member variables back to main
	string getName(){return name;}
	double getAverage(){return average();}

	//Function to display the grades in the private member array "grades"
	void getGrades(){
		for(int i = 0; i < numGrades; i++)
			cout << grades[i] << "\t"; 
	}
};

int main(){
	srand(static_cast<unsigned int>(time(NULL))); // seed rand()

	//Declare Variables
	int size;		//Holds number of students
	string name;	//Holds name of student
	int numGrades;	//Holds how many grades each student has

	//Display title
	cout << "*******************************************\n";
	cout << "**         Random Student Grades         **\n";
	cout << "*******************************************\n";

	//Get number of students from the user
	cout << "Enter number of students: ";
	cin >> size;

	//While loop to make sure that the user doesn't enter a negative number or letter for the number of students
	while(cin.fail() || size <= 0){
		system("cls");

		//Display title
		cout << "*******************************************\n";
		cout << "**         Random Student Grades         **\n";
		cout << "*******************************************\n";

		cout << "Invalid value entered!" << endl;
		cout << "Only positive numeric values accepted." << endl;
		cout << "Please try again! " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Enter number of students: ";
		cin >> size;
	}

	//Dynamically create an array named students using the class Student and the size
	//entered by the user.
	Student **students = new Student*[size];

	//Fill the students class array using a for loop
	for(int i = 0; i < size; i++){
		//Prompt user for the student name
		cout << "Name of student #" << i+1 << ": ";
		cin >> name;

		//Prompt user for amount of grades
		cout << "Number of grades: ";
		cin >> numGrades;

		//While loop to make sure user doesn't enter negatives for number of grades or letters
		while(cin.fail() || numGrades <= 0){
			cout << "Grades cannot be negative or letters!" << endl;

			cin.clear();
			cin.ignore(256,'\n');
			cout << "Enter number of grades: ";
			cin >> numGrades;
		}


		//Create the array element using the Student class constructor
		//by sending the name and number of grades as parameters.
		students[i] = new Student(name, numGrades);
	}
	
	//Additional Variables for Sorting
	Student *temp;	//Holds temporary value
	bool swap;		//Used for bubble sort swap

	//do while loop to begin sorting the students class array by the average.
	//It calls the function getAverage from the Student class as the comparison
	do
	{
		swap = false;	//Sets swap value to false
		for(int count = 0; count < (size - 1); count++)		//For loop to begin comparing
		{
			if(students[count]->getAverage() > students[count + 1]->getAverage())		//If students[0] is greater than students[1] run this statement
			{
				temp = students[count];			//Sets temp variable to students[0]
				students[count] = students[count + 1];	//Sets students[0] to students[1]
				students[count + 1] = temp;		//Sets students[1] to temp variable
				swap = true;			//Sets swap to true because a swap did occur
			}
		}
	} while(swap); //While swap is true stay in the do/while loop

	cout << endl;
	cout << "Student \t Avg \t\t Grades" << endl;
	cout << "-----------------------------------------------" << endl;

	//Display all students with their averages and all grades
	for(int i = 0; i < size; i++){
		cout << students[i]->getName() << "\t";				//Get student name
		//Add extra tab if student name if less than 8 characters long
		if(students[i]->getName().length() < 8){
			cout << "\t";
		}
		cout << fixed << showpoint << setprecision(1);		//Display 1 decimal place for average
		cout << students[i]->getAverage() << "   ||\t";		//Get student average
		cout << fixed << noshowpoint << setprecision(0);	//Remove decimal places
		students[i]->getGrades();							//Get and display student grades
		cout << endl;
	}
	
	system("pause");
	return 0;
}
