/*
You are to write a game similar to the "Linked list game".  There should be 20 nodes.
You can change the struct to your preferences in order to make the game better. 

Make sure the user is not able to move to a NULL location.

The story game should be rated PG-13.  No bad words or gore.

You can add special conditions to where the story will not progress unless you clear a certain obstacle in a
different room, others did enemy encounters where the enemy will drop a key to open a door.  You should make
your story / game interesting (it should also be clear to navigate.. if I get lost in your program, your grade
will suffer!).  A sort of map may help the user to navigate.

**if you look at the game tutorial I submitted, this homework is really not difficult at all.. just time consuming**

Programmer: Cesar Pena
Date: November 9, 2016
*/
#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;


struct ListNode
{
	char name;
	ListNode *up;
	ListNode *down;
	ListNode *left;
	ListNode *right;
	string story;
	string story2;
	int visited;

	ListNode()
	{
		name = ' '; 
		up = NULL; 
		down = NULL; 
		left = NULL; 
		right = NULL;
		story = "Null";
		story2 = "Null";
		visited = 0;
	}
	/*ListNode(double value1, ListNode *next1 = NULL)
	{
		value = value1;
		next = next1;
	}*/
};


int main()
{
	//Equipment Variables
	bool key = false;
	bool key2 = false;
	bool spell = false;
	bool boat = false;
	bool sword = false;
	bool shield = false;
	bool nest = false;
	bool game = true;
	string puzzleChoice = "";
	bool puzzle1 = false;
	string puzzle1Phrase = "Against";
	bool puzzle2 = false;
	string puzzle2Phrase = "all";
	bool puzzle3 = false;
	string puzzle3Phrase = "odds.";

	ListNode *A = new ListNode();
	A->name = 'A';

	ListNode *B = new ListNode();
	B->name = 'B';
	A->up = B;
	B->down = A;

	ListNode *C = new ListNode();
	C->name = 'C';
	A->right = C;
	C->left = A;

	ListNode *D = new ListNode();
	D->name = 'D';
	D->up = A;
	A->down = D;

	ListNode *E = new ListNode();
	E->name = 'E';
	E->right = A;
	A->left = E;

	ListNode *F = new ListNode();
	F->name = 'F';
	F->left = B;
	F->down = C;
	C->up = F;
	B->right = F;

	ListNode *G = new ListNode();
	G->name = 'G';
	G->up = C;
	G->left = D;
	C->down = G;
	D->right = G;

	ListNode *H = new ListNode();
	H->name = 'H';
	H->up = E;
	H->right = D;
	E->down = H;
	D->left = H;

	ListNode *I = new ListNode();
	I->name = 'I';
	I->right = B;
	I->down = E;
	E->up = I;
	B->left = I;

	ListNode *J = new ListNode();
	J->name = 'J';
	J->down = B;
	B->up = J;

	ListNode *K = new ListNode();
	K->name = 'K';
	K->left = C;
	C->right = K;

	ListNode *L = new ListNode();
	L->name = 'L';
	L->up = D;
	D->down = L;

	ListNode *M = new ListNode();
	M->name = 'M';
	M->right = E;
	E->left = M;

	ListNode *N = new ListNode();
	N->name = 'N';
	N->left = F;
	N->down = K;
	F->right = N;
	K->up = N;

	ListNode *O = new ListNode();
	O->name = 'O';
	O->up = K;
	O->left = G;
	G->right = O;
	K->down = O;

	ListNode *P = new ListNode();
	P->name = 'P';
	P->up = G;
	P->left = L;
	G->down = P;
	L->right = P;

	ListNode *Q = new ListNode();
	Q->name = 'Q';
	Q->up = H;
	Q->right = L;
	H->down = Q;
	L->left = Q;

	ListNode *R = new ListNode();
	R->name = 'R';
	R->right = H;
	R->up = M;
	M->down = R;
	H->left = R;

	ListNode *S = new ListNode();
	S->name = 'S';
	S->right = I;
	S->down = M;
	M->up = S;
	I->left = S;

	ListNode *T = new ListNode();
	T->name = 'T';
	T->down = I;
	T->right = J;
	I->up = T;
	J->left = T;

	ListNode *U = new ListNode();
	U->name = 'U';
	U->left = J;
	U->down = F;
	J->right = U;
	F->up = U;

	ListNode *V = new ListNode();
	V->name = 'V';
	V->left = U;
	V->down = N;
	U->right = V;
	N->up = V;

	ListNode *W = new ListNode();
	W->name = 'W';
	W->up = O;
	W->left = P;
	O->down = W;
	P->right = W;

	ListNode *X = new ListNode();
	X->name = 'X';
	X->right = Q;
	X->up = R;
	R->down = X;
	Q->left = X;

	ListNode *Y = new ListNode();
	Y->name = 'Y';
	Y->down = S;
	Y->right = T;
	T->left = Y;
	S->up = Y;

	ListNode *Z = new ListNode();
	Z->name = 'Z';
	Z->down = J;
	J->up = Z;

	A->story = "You appear to be in the middle of a meadow on a bright\nsunny day. In the distance you notice a house.\n"
		"It shines from the suns reflection as though it is made of diamonds.\n"
		"Do you go towards the lighted house or enter the dark woods behind you?\n"
		"W. Head towards the house\n"
		"S. Enter the creepy woods\n";
	A->story2 = "You find yourself in the meadow again\n"
		"The house to the north shines as bright as before.\n"
		"The forest to the south is as dark as ever and faint screams\n"
		"of horror can be heard.\n"
		"You notice two new paths to the west and the east.\n"
		"Do you?\n"
		"A. Go West towards a path leading to a big lake\n"
		"D. Go East towards the path leading to a spiral tower\n"
		"W. Head north towards the shiny house\n"
		"S. Head south to the creepy woods\n";
	B->story = "You notice the sky becoming darker.\n"
		"Do you?\n"
		"A. Go West towards an abandoned cabin.\n"
		"D. Go East towards an old fountain.\n"
		"W. Go North to the shiny house.\n"
		"S. Go South to the open meadow.\n";
	B->story2 = "You notice the sky becoming darker. \n"
		"Do you?\n"
		"A. Go West towards an abandoned cabin.\n"
		"D. Go East towards an old fountain.\n"
		"W. Go North to the shiny house.\n"
		"S. Go South to the open meadow.\n";
	C->story = "You find yourself in a clear path leading\n"
		"to the spiral tower. \n"
		"Do you?\n"
		"A. Go West to the open meadow.\n"
		"D. Go East to the spiral tower.\n"
		"W. Go North to an old fountain.\n"
		"S. Go South to the graveyard.\n";
	C->story2 = "You find yourself back in the clear path leading\n"
		"to the spiral tower.  A faint shadowy figure heads your way\n"
		"and offers some advice.\n"
		"Do you?\n"
		"A. Go West to the open meadow.\n"
		"D. Go East to the spiral tower.\n"
		"W. Go North to an old fountain.\n"
		"S. Go South to the graveyard.\n"
		"F. Listen to what he has to say.\n";
	D->story = "The forest is dark and eerie. \n"
		"You hear screams coming from inside \n"
		"one of the trees. \n"
		"Do you?\n"
		"A. Go West to travel deeper into the forest.\n"
		"D. Go East to the graveyard.\n"
		"W. Go North to the open meadow.\n"
		"S. Go South towards the lone tree stump.\n";
	D->story2 = "The forest is dark and eerie. \n"
		"You hear screams coming from inside \n"
		"one of the trees.  As you approach the tree \n"
		"you notice a phrase that reads: \n"
		"Only those capable of magic can free my victim! \n"
		"Do you?\n"
		"A. Go West to travel deeper into the forest.\n"
		"D. Go East to the graveyard.\n"
		"W. Go North to the open meadow.\n"
		"S. Go South towards the lone tree stump.\n"
		"F. Attempt to cast magic into the screaming tree.\n";
	E->story = "The road leading into the lake is clear.\n"
		"Do you?\n"
		"A. Go West towards the lake\n"
		"D. Go East to the open meadow.\n"
		"W. Go North to the abandoned cabin.\n"
		"S. Go South to the dark forest.\n";
	E->story2 = "You see a man standing by the road.\n"
		"He wants to offer you some advice.\n"
		"Do you?\n"
		"A. Go West towards the lake\n"
		"D. Go East to the open meadow.\n"
		"W. Go North to the abandoned cabin.\n"
		"S. Go South to the dark forest.\n"
		"F. Hear what the man has to say.\n";
	F->story = "You find yourself in front of a dry fountain.\n"
		"Leaning by its side is a wooden shadowy boat.\n"
		"Do you? \n"
		"A. Go West towards the open field leading to the shiny house.\n"
		"D. Go East to an open field.\n"
		"W. Go North to the an open field. \n"
		"S. Go South to the path leading to the spiral tower. \n"
		"F. Touch the shadowy boat.\n";
	F->story2 = "You find yourself in front of a dry fountain.\n"
		"Leaning by its side is a wooden shadowy boat.\n"
		"Do you? \n"
		"A. Go West towards the open field leading to the shiny house.\n"
		"D. Go East to an open field.\n"
		"W. Go North to the an open field. \n"
		"S. Go South to the path leading to the spiral tower. \n"
		"F. Touch the shadowy boat.\n";
	G->story = "The graveyard feels gloomy and terrifying. \n"
		"Do you? \n"
		"A. Go West towards the forest.\n"
		"D. Go East to an open field. \n"
		"W. Go North to the path leading to the spiral tower. \n"
		"S. Go South to the Maze.\n";
	G->story2 = "The graveyard feels gloomy and terrifying. \n"
		"Do you? \n"
		"A. Go West towards the forest.\n"
		"D. Go East to an open field. \n"
		"W. Go North to the path leading to the spiral tower. \n"
		"S. Go South to the Maze.\n";
	H->story = "The forest is dark and creepy. \n"
		"Do you? \n"
		"A. Go West towards the forest.\n"
		"D. Go East towards the forest with the screaming tree.\n"
		"W. Go North to the path leading to the lake. \n"
		"S. Go South into the heart of the forest.\n";
	H->story2 = "The forest is dark and creepy. \n"
		"Do you? \n"
		"A. Go West towards the forest.\n"
		"D. Go East towards the forest with the screaming tree.\n"
		"W. Go North to the path leading to the lake. \n"
		"S. Go South into the heart of the forest.\n";
	I->story = "An abandoned cabin stands before you. \n" 
		"Do you? \n"
		"A. Go West towards the river.\n"
		"D. Go East towards the open field leading to the shiny house.\n"
		"W. Go North to an open field.\n"
		"S. Go South to the path leading to the lake. \n";
	I->story2 = "An abandoned cabin stands before you. The cabin seems to\n"
		"be alive and recognizes your face.  Its front door opens \n"
		"to allow you passage inside.\n"
		"Do you? \n"
		"A. Go West towards the river.\n"
		"D. Go East towards the open field leading to the shiny house.\n"
		"W. Go North to an open field.\n"
		"S. Go South to the path leading to the lake. \n"
		"F. Enter the cabin. \n";
	J->story = "The shiny house stands before you. Its walls are covered \n"
		"with diamonds. As you approach the house you notice a sign by \n"
		"the entrance that read: \n"
		"Only those who have proven themselves may enter\n"
		"Do you? \n"
		"A. Go West towards an open field.\n"
		"D. Go East towards an open field.\n"
		"S. Go South to the open field leading to the shiny house.\n"
		"W. Go North and attempt to enter the shiny house.\n";
	J->story2 = "The shiny house stands before you. Its walls are covered \n"
		"with diamonds. As you approach the house you notice a sign by \n"
		"the entrance that read: \n"
		"Only those who have proven themselves may enter\n"
		"Do you? \n"
		"A. Go West towards an open field.\n"
		"D. Go East towards an open field.\n"
		"S. Go South to the open field leading to the shiny house.\n"
		"W. Go North and attempt to enter the shiny house.\n";
	K->story = "A mighty tower with a spiral staircase stands before you.\n"
		"Do you? \n"
		"A. Go West towards the path leading to the spiral tower. \n"
		"D. East seems to be blocked by an electrified force field. \n"
		"S. Go South to an open field.\n"
		"W. Go North to an open field.\n"
		"F. Climb the spiral tower.\n";
	K->story2 = "A mighty tower with a spiral staircase stands before you.\n"
		"Do you? \n"
		"A. Go West towards the path leading to the spiral tower. \n"
		"D. East seems to be blocked by an electrified force field. \n"
		"S. Go South to an open field.\n"
		"W. Go North to an open field.\n"
		"F. Climb the spiral tower.\n";
	L->story = "A lone tree stump sits in the middle an open field. \n"
		"Do you? \n"
		"A. Go West into the heart of the forest. \n"
		"D. Go East to the Maze. \n"
		"S. South seems to be blocked by an electrified force field.\n"
		"W. Go North towards the forest with the screaming tree.\n";
	L->story2 = "A lone tree stump sits in the middle an open field. \n"
		"Do you? \n"
		"A. Go West into the heart of the forest. \n"
		"D. Go East to the Maze. \n"
		"S. South seems to be blocked by an electrified force field.\n"
		"W. Go North towards the forest with the screaming tree.\n";
	M->story = "You find yourself in front of a vast lake. \n"
		"The waters are clear enough to be navigated by boat. \n"
		"Do you? \n"
		"A. West seems to be blocked by an electrified force field.\n"
		"D. Go East to the path leading to the lake.\n"
		"S. Go South towards the forest.\n"
		"W. Go North towards a river.\n"
		"F. Attempt to set sail on the lake.\n";
	M->story2 = "You find yourself in front of a vast lake. \n"
		"The waters are clear enough to be navigated by boat. \n"
		"Do you? \n"
		"A. West seems to be blocked by an electrified force field.\n"
		"D. Go East to the path leading to the lake.\n"
		"S. Go South towards the forest.\n"
		"W. Go North towards a river.\n"
		"F. Attempt to set sail on the lake.\n";
	N->story = "You entered a large open field. \n"
		"Do you? \n"
		"A. Go West towards an old fountain.\n"
		"D. East seems to be blocked by an electrified force field.\n"
		"S. Go South to the spiral tower.\n"
		"W. Go North to a cave entrance.\n";
	N->story2 = "You entered a large open field. \n"
		"Do you? \n"
		"A. Go West towards an old fountain.\n"
		"D. East seems to be blocked by an electrified force field.\n"
		"S. Go South to the spiral tower.\n"
		"W. Go North to a cave entrance.\n";
	O->story = "You entered a large open field. \n"
		"Do you? \n"
		"A. Go West to the graveyard.\n"
		"D. East seems to be blocked by an electrified force field.\n"
		"S. Go South to the monster infested nests.\n"
		"W. Go North to the spiral tower.\n";
	O->story2 = "You entered a large open field. \n"
		"Do you? \n"
		"A. Go West to the graveyard.\n"
		"D. East seems to be blocked by an electrified force field.\n"
		"S. Go South to the monster infested nests.\n"
		"W. Go North to the spiral tower.\n";
	P->story = "A large maze is before you. \n"
		"Do you? \n"
		"A. Go West to the tree stump.\n"
		"D. Go East to the monster infested nests. \n"
		"S. South seems to be blocked by an electrified force field.\n"
		"W. Go North to the graveyard.\n"
		"F. Enter the maze.\n";
	P->story2 = "A large maze is before you. \n"
		"Do you? \n"
		"A. Go West to the tree stump.\n"
		"D. Go East to the monster infested nests. \n"
		"S. South seems to be blocked by an electrified force field.\n"
		"W. Go North to the graveyard.\n"
		"F. Enter the maze.\n";
	Q->story = "You find yourself in front of a big oak tree. \n"
		"You see an opening on its trunk that can allow you to enter \n"
		"into its heart.\n"
		"Do you? \n"
		"A. Go West into the forest. \n"
		"D. Go East to the tree stump.\n"
		"S. South seems to be blocked by an electrified force field.\n"
		"W. Go North into the forest. \n"
		"F. Enter the trunk of the tree.\n";
	Q->story2 = "You find yourself in front of a big oak tree. \n"
		"You see an opening on its trunk that can allow you to enter \n"
		"into its heart.\n"
		"Do you? \n"
		"A. Go West into the forest. \n"
		"D. Go East to the tree stump.\n"
		"S. South seems to be blocked by an electrified force field.\n"
		"W. Go North into the forest. \n"
		"F. Enter the trunk of the tree.\n";
	R->story = "You find yourself in a forest area. \n"
		"Do you? \n"
		"A. West seems to be blocked by an electrified force field.\n"
		"D. Go East into the forest. \n"
		"S. Go South into the forest. \n"
		"W. Go North towards the lake. \n";
	R->story2 = "You find yourself in a forest area. \n"
		"Do you? \n"
		"A. West seems to be blocked by an electrified force field.\n"
		"D. Go East into the forest. \n"
		"S. Go South into the forest. \n"
		"W. Go North towards the lake. \n";
	S->story = "The river before you is soothing and calm. \n"
		"Do you? \n"
		"A. West seems to be blocked by an electrified force field.\n"
		"D. Go East to the abandoned cabin.\n"
		"S. Go South towards the lake.\n"
		"W. Go North towards the floating suspended box.\n";
	S->story2 = "The river before you is soothing and calm. \n"
		"Do you? \n"
		"A. West seems to be blocked by an electrified force field.\n"
		"D. Go East to the abandoned cabin.\n"
		"S. Go South towards the lake.\n"
		"W. Go North towards the floating suspended box.\n";
	T->story = "You entered a large open field. \n"
		"Do you? \n"
		"A. Go West towards the floating suspended box.\n"
		"D. Go East to the shiny house.\n"
		"S. Go South to the abandoned cabin.\n"
		"W. North seems to be blocked by an electrified force field.\n";
	T->story2 = "You entered a large open field. \n"
		"Do you? \n"
		"A. Go West towards the floating suspended box.\n"
		"D. Go East to the shiny house.\n"
		"S. Go South to the abandoned cabin.\n"
		"W. North seems to be blocked by an electrified force field.\n";
	U->story = "You entered a large open field. \n"
		"Do you? \n"
		"A. Go West to the shiny house.\n"
		"D. Go East to the cave entrance.\n"
		"S. Go South to the old fountain.\n"
		"W. North seems to be blocked by an electrified force field.\n";
	U->story2 = "You entered a large open field. \n"
		"Do you? \n"
		"A. Go West to the shiny house.\n"
		"D. Go East to the cave entrance.\n"
		"S. Go South to the old fountain.\n"
		"W. North seems to be blocked by an electrified force field.\n";
	V->story = "A large cave entrance is in front of you. \n"
		"Do you? \n"
		"A. Go West to an open field. \n"
		"D. East seems to be blocked by an electrified force field.\n"
		"S. Go South to an open field. \n"
		"W. North seems to be blocked by an electrified force field.\n"
		"F. Enter the cave.\n";
	V->story2 = "A large cave entrance is in front of you. \n"
		"Do you? \n"
		"A. Go West to an open field. \n"
		"D. East seems to be blocked by an electrified force field.\n"
		"S. Go South to an open field. \n"
		"W. North seems to be blocked by an electrified force field.\n"
		"F. Enter the cave.\n";
	W->story = "Large monster infested nest surround you. \n"
		"Do you? \n"
		"A. Go West to the Maze. \n"
		"D. East seems to be blocked by an electrified force field.\n"
		"S. South seems to be blocked by an electrified force field.\n"
		"W. Go North to an open field. \n"
		"F. Attempt to destroy the monters and their nests. \n";
	W->story2 = "Large monster infested nest surround you. \n"
		"Do you? \n"
		"A. Go West to the Maze. \n"
		"D. East seems to be blocked by an electrified force field.\n"
		"S. South seems to be blocked by an electrified force field.\n"
		"W. Go North to an open field. \n"
		"F. Attempt to destroy the monters and their nests. \n";
	X->story = "Your have entered an area deep in the forest. \n"
		"You spot an old note on the ground. \n"
		"Do you? \n"
		"A. West seems to be blocked by an electrified force field.\n"
		"D. Go East to the heart of the forest.\n"
		"S. South seems to be blocked by an electrified force field.\n"
		"W. Go North into the forest. \n"
		"F. Pick up and read the old note. \n";
	X->story2 = "Your have entered an area deep in the forest. \n"
		"You spot an old note on the ground. \n"
		"Do you? \n"
		"A. West seems to be blocked by an electrified force field.\n"
		"D. Go East to the heart of the forest.\n"
		"S. South seems to be blocked by an electrified force field.\n"
		"W. Go North into the forest. \n"
		"F. Pick up and read the old note. \n";
	Y->story = "A large crate seems to be suspended in the air \n"
		"in front of you. \n"
		"Do you? \n"
		"A. West seems to be blocked by an electrified force field.\n"
		"D. Go East to an open field. \n"
		"S. Go South to the river. \n"
		"W. North seems to be blocked by an electrified force field.\n"
		"F. Attempt to open the suspended box. \n";
	Y->story2 = "A large crate seems to be suspended in the air \n"
		"in front of you. \n"
		"Do you? \n"
		"A. West seems to be blocked by an electrified force field.\n"
		"D. Go East to an open field. \n"
		"S. Go South to the river. \n"
		"W. North seems to be blocked by an electrified force field.\n"
		"F. Attempt to open the suspended box. \n";
	Z->story = "As you enter the shiny house you see an elevator at its center.\n"
		"You walk into the elevator proud of your accomplishments. \n"
		"The elevator shoots up so fast that you have to grab\n"
		"onto the railings by its walls. When it reaches its \n"
		"destination its doors slowly open and you noticed that the floor \n"
		"outside is pure white and a big gate entrance can be seen.\n"
		"You approach the entrance and spot a man by a podium. \n"
		"He asks for your name and you quickly realize that you were \n"
		"in the afterlife all this time\n"
		"Against all odds you have reached Heaven!\n";
		"Thank you for playing!\n";
	Z->story2 = "As you enter the shiny house you see an elevator at its center.\n"
		"You walk into the elevator proud of your accomplishments. \n"
		"The elevator shoots up so fast that you have to grab\n"
		"onto the railings by its walls. When it reaches its \n"
		"destination its doors slowly open and you noticed that the floor \n"
		"outside is pure white and a big gate entrance can be seen.\n"
		"You approach the entrance and spot a man by a podium. \n"
		"He asks for your name and you quickly realize that you were \n"
		"in the afterlife all this time\n"
		"Against all odds you have reached Heaven!\n"
		"Thank you for playing!\n";
		

	ListNode *ptr = A;
	ListNode *prevNode = NULL;
	char choice;
	while(game)
	{
		do{
		system("cls");
		
		prevNode = ptr;
		
		if (ptr->visited==0)
			cout<<ptr->story;
		else
			cout<<ptr->story2;
		cin>>choice;
		ptr->visited++;
		if (choice == 'A' || choice == 'a')
			ptr=ptr->left;
		else if (choice == 'D' || choice == 'd')
			ptr = ptr->right;
		else if (choice == 'W' || choice == 'w')
			ptr = ptr->up;
		else if (choice == 'S' || choice == 's')
			ptr = ptr->down;

		if(ptr == C)
		{
			if(choice == 'F' || choice == 'f')
			{
				cout << "The shadowy figure explains how he would always \n";
				cout << "get lost in the world.  He attempts to explain how\n";
				cout << "the map works. 'If ye finds to be lost, ye \n";
				cout << "only need to get back to pen and paper.\n";
				cout << "Draw out a 5x5 grid and the meadow is right at its center.'\n";
				system("pause");
			}
		}

		if(ptr == D)
		{
			if(choice == 'F' || choice == 'f')
			{
				if(spell == true)
				{
					cout << "The tree starts to melt and reveal and woman.\n";
					cout << "She thanks you for saving her and gives you 2 clues.\n";
					cout << "'The east is shrouded with monster infested nests.'\n";
					cout << "'You can only wipe them out if you possess a sword, \n";
					cout << "'shield, and the spell you used to free me.'\n";
					cout << "'The second word is: all'\n";
					puzzle2 = true;
					puzzle2Phrase = "all";
					system("pause");
				}
				else
				{
					cout << "You do not yet possess the spell required \n";
					cout << "to break the tree enchantment.\n";
					system("pause");
				}
			}
		}

		if(ptr == E)
		{
			if(choice == 'F' || choice == 'f')
			{
				cout << "The man explains how he would always \n";
				cout << "had trouble solving puzzles.  He attempts to explain how\n";
				cout << "the puzzles work. 'When ye enters an area\n";
				cout << "pay close attention to its letter.\n";
				cout << "For the letter can be used to help you solve\n";
				cout << "this world puzzles better.\n";
				system("pause");
			}
		}

		if(ptr == F)
		{
			if(choice == 'F' || choice == 'f')
			{
				cout << "When you touch the shadowy boat a copy of \n";
				cout << "it goes right to your inventory.\n";
				cout << "Its shadowy apparition remains.\n";
				boat = true;
				system("pause");
			}
		}

		if(ptr == I)
		{
			if(choice == 'F' || choice == 'f')
			{
				cout << "You enter the abandoned cabin and find a \n";
				cout << "locked box.  The box comes to life and says:\n";
				cout << "'I will only open if you answer my question truthfully.\n";
				cout << "What is the shiny house to the north made of?'\n";
				cin >> puzzleChoice;
				if(puzzleChoice == "diamonds" || puzzleChoice == "Diamond" || puzzleChoice == "diamond" || puzzleChoice == "DIAMOND" || puzzleChoice == "Diamonds" || puzzleChoice == "DIAMONDS")
				{
					cout << "Correct! The box opens up and reveals a clue.\n";
					cout << "The first word is: Against" << endl;
					puzzle1 = true;
					puzzle1Phrase = "Against";
				}
				else
					cout << "Incorrect! Your are flown out of the house.\n";
				system("pause");
			}
		}

		if(ptr == Z)
		{
			cout << "You approach the shiny house front door.\n";
			cout << "A message is inscribed by its entrance:\n";
			cout << "If the 3 world puzzles have been solved, you posses a golden key and \n";
			cout << "the monster infested nest has been cleared you may enter.\n";
			if(puzzle1 == true && puzzle2 == true && puzzle3 == true && nest == true && key == true)
			{
				cout << "You are worthy to enter!" << endl;
				if (ptr->visited==0)
					cout<<ptr->story;
				else
					cout<<ptr->story2;

				cout << endl;
				cout << "Thank you for playing!" << endl;
				system("pause");
				return 0;
			}
			else
			{
				cout << "You are missing the following: "<< endl;
				if(puzzle1 == false)
					cout << "The abandoned house puzzle \n";
				if(puzzle2 == false)
					cout << "Save the trap victim from the enchanted tree \n";
				if(puzzle3 == false)
					cout << "Cave entrance puzzle \n";
				if(key == false)
					cout << "Golden key from the spiral tower \n";
				if(nest == false)
					cout << "Clear the monster infested nests to the south \n";

				system("pause");
				ptr = prevNode;
			}
		}

		if(ptr == K)
		{
			if(choice == 'F' || choice == 'f')
			{
				cout << "You reach the stair case top floor and notice a \n";
				cout << "big ogre guarding a jewelry box.\n";
				
				if(sword == true && shield == true)
				{
					cout << "You destroy the ogre and open the jewelry box.\n";
					cout << "You find a golden key inside and take it\n";
					cout << "into your inventory.\n";
					key = true;
				}
				else
				{
					cout << "You do not yet posses the required items to beat \n";
					cout << "the ogre.  You still need:\n";
					if(sword == false)
						cout << "A sword" << endl;
					if(shield == false)
						cout << "A shield" << endl;
				}
				system("pause");
			}
		}

		if(ptr == M)
		{
			if(choice == 'F' || choice == 'f')
			{
				if(boat == true)
				{
					cout << "You take out a boat from your inventory and set sail.\n";
					cout << "A fishing rod gets your attention and you start to fish.\n";
					cout << "You feel a tug on the fishing line and reel your catch in.\n";
					cout << "Your surprised to find that you caught a silver key.\n";
					cout << "You place it in your inventory.\n";
					key2 = true;
				}
				else
				{
					cout << "You do not yet possess a boat to sail the lake.\n";
				}
				system("pause");
			}
		}

		if(ptr == P)
		{
			if(choice == 'F' || choice == 'f')
			{
				cout << "You entered the maze and find its center.\n";
				cout << "In a pedestal you find a shield.\n";
				cout << "You take it and equip it.\n";
				shield = true;
				system("pause");
			}
		}

		if(ptr == Q)
		{
			if(choice == 'F' || choice == 'f')
			{
				cout << "You spot a floating heart in its center.\n";
				cout << "You get close to it and touch it with your bare hands.\n";
				cout << "Your gaze fades away and you remembered\n";
				cout << "how to cast 'Burning Ember'\n";
				spell = true;
				system("pause");
			}
		}

		if(ptr == V)
		{
			if(choice == 'F' || choice == 'f')
			{
				cout << "You enter the cave and find a large bear sleeping on a box. \n";
				cout << "You tried to approach quietly but the bear wakes up.\n";
				cout << "'I will only give you whats in this box \n";
				cout << "if you answer my question truthfully.\n";
				cout << "What is at the top of the spiral tower?'\n";
				cin >> puzzleChoice;
				if(puzzleChoice == "Ogre" || puzzleChoice == "ogre" || puzzleChoice == "OGRE")
				{
					cout << "Correct! He opens the box and reveals a clue.\n";
					cout << "The third word is: odds" << endl;
					puzzle3 = true;
					puzzle3Phrase = "odds";
				}
				else
					cout << "Incorrect! Your are flown out of the cave.\n";
				system("pause");
			}
		}

		if(ptr == W)
		{
			if(choice == 'F' || choice == 'f')
			{
				if(sword == true && shield == true && spell == true)
				{
					cout << "You annihilate the monters with your sword and shield and\n";
					cout << "burn their nests with your 'Burning Ember' spell.\n";
					nest = true;

				}
				else if(sword == true && shield == true && spell == false)
				{
					cout << "You annihilate the monsters with your sword and shield but\n";
					cout << "failed to burn their nests. They respawn!\n";
				}
				else
				{
					cout << "You do not yet possess the right equipment to \n";
					cout << "go against the monsters.";
				}
				system("pause");
			}
		}

		if(ptr == Y)
		{
			if(choice == 'F' || choice == 'f')
			{
				if(key2 == true)
				{
					cout << "The key from the lake fits perfectly into its lock.\n";
					cout << "The chest opens and reveals a sword inside.\n";
					cout << "You take the sword from its resting place and equip it.\n";
					sword = true;
				}
				else
				{
					cout << "You do not possess a key to open its lock.\n";
					cout << "It is said that it can be found in a vast lake.\n";
				}
				system("pause");
			}
		}

		}while(ptr != NULL || game != true);

		ptr = prevNode;
	}


	system("pause");
	return 0;
}
