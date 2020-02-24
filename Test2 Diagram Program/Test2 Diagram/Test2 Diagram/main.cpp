/*
Using the diagram presented in the section called “Diagram 1” on page 2.  You are to first create the
4 directional linked list to appear as illustrated in the diagram.  Use the same names for each node
as shown in the diagram and the directions between the nodes are two way.  You can directly input
these nodes and their directions in the main.  

Your program should then ask the user for a starting node and an ending node.  They are able to choose
any starting and ending locations and your program should be able to begin from that starting node
(by placing a pointer to that node) and going through each of the 4 directions until it finds the ending node.
At this point, it should output the path it took.  An example of the ending result is shown below.

This test will be covering linked lists as well as recursion.  Because of this, you are to
solve the problem using one recursive function.  This function’s base case is if the current
node it is located in is equal to the node the user typed in as the ending node.  If it is,
you are to output the name of that node and terminate the current node (this base case gives
us the path in reverse, which is what we want).


Programmer: Cesar Pena
Date: November 23, 2016
*/
#include<iostream>
#include<string>
#include <cstdlib>

using namespace std;

//Structure for Linked List
struct ListNode
{
	char name;
	ListNode *up;
	ListNode *down;
	ListNode *left;
	ListNode *right;
	int visited;			//Used for testing
	int path;				//Used for testing
	bool terminated;		//Used for testing

	ListNode()
	{
		name = ' '; 
		up = NULL; 
		down = NULL; 
		left = NULL; 
		right = NULL;
		visited = 0;
		path = 0;
		terminated = false;
	}

};

int nodePoint(char);
void findNodePath(ListNode *, ListNode *, ListNode *);


int main(){

	ListNode *A = new ListNode();
	A->name = 'A';

	ListNode *B = new ListNode();
	B->name = 'B';
	A->right = B;
	B->left = A;

	ListNode *C = new ListNode();
	C->name = 'C';
	
	ListNode *D = new ListNode();
	D->name = 'D';
	A->down = D;
	D->up = A;

	ListNode *E = new ListNode();
	E->name = 'E';
	B->down = E;
	E->up = B;

	ListNode *F = new ListNode();
	F->name = 'F';
	C->down = F;
	F->up = C;
	F->left = E;
	E->right = F;

	ListNode *G = new ListNode();
	G->name = 'G';

	ListNode *H = new ListNode();
	H->name = 'H';
	E->down = H;
	H->up = E;
	H->left = G;
	G->right = H;

	ListNode *I = new ListNode();
	I->name = 'I';
	F->down = I;
	I->up = F;

	char start;
	char end;
	ListNode *startNode = NULL;
	ListNode *endNode = NULL;


	//Display title and instructions
	cout << "======================================================\n";
	cout << "==          Find the path between 2 nodes           ==\n";
	cout << "==         Testing:  Up, Left, Down, Right          ==\n";
	cout << "======================================================\n";
	cout << endl;
	cout << " -------      -------      -------\n";
	cout << " -- A -- <--> -- B --      -- C --\n";
	cout << " -------      -------      -------\n";
	cout << "    |            |            |   \n";
	cout << " -------      -------      -------\n";
	cout << " -- D --      -- E -- <--> -- F --\n";
	cout << " -------      -------      -------\n";
	cout << "                 |            |   \n";
	cout << " -------      -------      -------\n";
	cout << " -- G -- <--> -- H --      -- I --\n";
	cout << " -------      -------      -------\n";
	cout << endl;

	//Do while loop to ensure the user only selects A - I
	do{
		cout << "Please enter the starting node: ";
		cin >> start;
	}while(start != 'A' && start != 'a' && start != 'B' && start != 'b' && start != 'C' && start != 'c' && start != 'D' && start != 'd' && start != 'E' && start != 'e' && start != 'F' && start != 'f' && start != 'G' && start != 'g' && start != 'H' && start != 'h' && start != 'I' && start != 'i');
	
	//Use a switch statement to assign the startNode from the user
	switch(nodePoint(start))
	{
		case 1: 
			startNode = A;
			break;
		case 2: 
			startNode = B;
			break;
		case 3:
			startNode = C;
			break;
		case 4:
			startNode = D;
			break;
		case 5:
			startNode = E;
			break;
		case 6:
			startNode = F;
			break;
		case 7:
			startNode = G;
			break;
		case 8:
			startNode = H;
			break;
		case 9:
			startNode = I;
			break;
	}
	
	//Do while loop to ensure the user only selects A - I
	do{
		cout << "Please enter the destination node: ";
		cin >> end;
	}while(end != 'A' && end != 'a' && end != 'B' && end != 'b' && end != 'C' && end != 'c' && end != 'D' && end != 'd' && end != 'E' && end != 'e' && end != 'F' && end != 'f' && end != 'G' && end != 'g' && end != 'H' && end != 'h' && end != 'I' && end != 'i');
	
	//Use a switch statement to assign the endNode from the user
	switch(nodePoint(end))
	{
		case 1: 
			endNode = A;
			break;
		case 2: 
			endNode = B;
			break;
		case 3:
			endNode = C;
			break;
		case 4:
			endNode = D;
			break;
		case 5:
			endNode = E;
			break;
		case 6:
			endNode = F;
			break;
		case 7:
			endNode = G;
			break;
		case 8:
			endNode = H;
			break;
		case 9:
			endNode = I;
			break;
	}

	ListNode *begin = startNode;

	//Call the recursive function findNodePath
	findNodePath(begin, startNode, endNode);

	system("pause");
	return 0;
}


void findNodePath(ListNode *begin, ListNode *startNode, ListNode *endNode){
	while(true)
	{
			//Add 1 to the variable visited in the node - for testing purposes
			begin->visited++;

			//Begin testing up, left, down, right
			if(begin->up != NULL && begin->up->visited == 0 && begin->up->terminated == false){
				begin = begin->up;
				cout << "Going up to " << begin->name << endl;
			}
			else if(begin->left != NULL && begin->left->visited == 0 && begin->left->terminated == false){
				begin = begin->left;
				cout << "Going left to " << begin->name << endl;
			}
			else if(begin->down != NULL && begin->down->visited == 0 && begin->down->terminated == false){
				begin = begin->down;
				cout << "Going down to " << begin->name << endl;
			}
			else if(begin->right != NULL && begin->right->visited == 0 && begin->right->terminated == false){
				begin = begin->right;
				cout << "Going right to " << begin->name << endl;
			}
			//If it doesn't find nodes up, left, down, right, then the code has hit a dead end, begin terminating them by backtracking
			else
			{
				cout << begin->name << " ends" << endl;
					
				if(begin->down != NULL && begin->down->terminated == false)
				{
					begin = begin->down;
					begin->up->terminated = true;
				}
				else if(begin->left != NULL && begin->left->terminated == false)
				{
					begin = begin->left;
					begin->right->terminated = true;
				}
				else if(begin->up != NULL && begin->up->terminated == false)
				{
					begin = begin->up;
					begin->down->terminated = true;
				}
				else if(begin->right != NULL && begin->right->terminated == false)
				{
					begin = begin->right;
					begin->left->terminated = true;
				}
				//Recursively call the findNodePath function
				//If another path is found in between the previous one - find it by calling on the function again.
				//Example: B -> E -> H -> G  - theres another path from E -> F so E does not need to be terminated.
				findNodePath(begin, startNode, endNode);			
			}

			//Use this if statement to add 1 to the path variable,  used for testing purposes
			//The nodes with path 1 are the ones that are gonna be use to display the path found
			if(begin->path == 0)
			{
				begin->path = 1;
			}

			//Function's base case
			//If it finds the current node equal to the user entered end note run this if statement
			if(begin == endNode){
				cout << "Destination reached, ";
				cout << "path was: ";
				cout << begin->name << " ";
				startNode->path++;		//Add 1 to path in the starting node
				do{
					begin->path++;		//Add 1 to the current node - meaning the last one

					if(begin->down != NULL && begin->down->path == 1 && begin->down->terminated == false)
					{
						begin = begin->down;
						cout << begin->name << " ";
					}
					else if(begin->left != NULL && begin->left->path == 1 && begin->left->terminated == false)
					{
						begin = begin->left;
						cout << begin->name << " ";
					}
					else if(begin->up != NULL && begin->up->path == 1 && begin->up->terminated == false)
					{
						begin = begin->up;
						cout << begin->name << " ";
					}
					else if(begin->right != NULL && begin->right->path == 1 && begin->right->terminated == false)
					{
						begin = begin->right;
						cout << begin->name << " ";
					}
				}while(begin != startNode);
				
				cout << endl;
				system("pause");
				exit(0);		//Ends the program - Path solved!
			}
	};
}

//Function used to calculate the start and end of the nodes entered by the user
int nodePoint(char node){
	int nodePointer;

	if(node == 'A' || node == 'a')
		nodePointer = 1;
	else if(node == 'B' || node == 'b')
		nodePointer = 2;
	else if(node == 'C' || node == 'c')
		nodePointer = 3;
	else if(node == 'D' || node == 'd')
		nodePointer = 4;
	else if(node == 'E' || node == 'e')
		nodePointer = 5;
	else if(node == 'F' || node == 'f')
		nodePointer = 6;
	else if(node == 'G' || node == 'g')
		nodePointer = 7;
	else if(node == 'H' || node == 'h')
		nodePointer = 8;
	else if(node == 'I' || node == 'i')
		nodePointer = 9;

	return nodePointer;
}