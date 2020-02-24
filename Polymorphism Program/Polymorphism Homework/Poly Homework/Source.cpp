#include <iostream>
#include <fstream>
#include <string>
using namespace std;


/*
1.  You are to implement the Consumables and the Accessories class, create files for each containing any number
of consumables and accessories.  (make sure they contain all the information needed).

2.  All files have _ (underscores) for the spaces.  I show how you remove the spaces for the weapons, you
should remove the spaces for all of the words.  **challenge is placing them back when you write to the file**

3.  In the main, have the ability to show all the (weapon / armor / accessories / consumables) depending what 
the user wants to see.  display those items only.

4.  When the program exits, save all the items back in their respective file.  To know what each
item is, you will need to create a variable in Item called whatIsIt which holds a string holding the
item type, so if your object is a weapon, it will say weapon.  This variable should go between the
name and the description.
You will need to UPDATE all files, all the classes, the way you infile and outfile in order for the program
to work well with this new variable.

** also, make sure you start your files with the number of items in the file, so when you are saving
everything back to the file, you need to know how many of those items there are... (maybe sort based on item type?)

Programmer(Debugger): Cesar Pena
Date: October 27, 2016

*/


// This is the base class
class Item
{
private:
	string name;
	string whatIsIt;		//whatIsIt goes here
	string description;
	double weight;
public:
	//these two are the constructors, they will be changed once you include the
	//whatIsIt variable.
	Item(){name = "NULL"; description = "NULL"; weight = 0; whatIsIt = "NULL";}
	Item(string name, string description, double weight, string whatIsIt)
	{
		this->name = name; 
		this->description = description; 
		this->weight = weight;
		this->whatIsIt = whatIsIt;
	}
	string getName(){return name;}
	void setName(string name){this->name = name;}

	string getDescription(){return description;}
	void setDescription(string description){this->description=description;}

	double getWeight(){return weight;}
	void setWeight(double weight){this->weight = weight;}

	string getWhatIsIt(){return whatIsIt;}
	void getWhatIsIt(string whatIsIt){this->whatIsIt = whatIsIt;}
	
	virtual void display()
	{
		cout<<"Name        = "<<name<<endl;
		cout<<"What is it  = "<<whatIsIt<<endl;		//what is it display goes here.
		cout<<"Description = "<<description<<endl;
		cout<<"Weight      = "<<weight<<endl;
		cout<<endl;
	}

	virtual void saveData(){cout<<"Data Saved!"<<endl;}
};


//gear is derived from Item.  There are no gear in our program, but weapon, armor and accessories
//are derived from Gear.
class Gear:public Item
{
private:
	int dmg;
	int def;
	int spd;
public:
	Gear():Item(){dmg = 0; def = 0; spd = 0;}
	//make sure to add the whatIsIt here too.
	Gear(string name, string description, double weight,int dmg, int def, int spd, string whatIsIt)
		:Item(name,description,weight,whatIsIt)
	{
		this->dmg = dmg;
		this->def = def;
		this->spd = spd;
	}

	int getDmg(){return dmg;}
	int getDef(){return def;}
	int getSpd(){return spd;}

	void setDef(int def){this->def = def;}
	void setDmg(int dmg){this->dmg = dmg;}
	void setSpd(int spd){this->spd = spd;}

	virtual void display()
	{
		cout<<"Name        = "<<getName()<<endl;
		cout<<"What is it  = "<<getWhatIsIt()<<endl;  //something missing here..
		cout<<"Description = "<<getDescription()<<endl;
		cout<<"Weight      = "<<getWeight()<<endl;
		cout<<"Defense     = "<<def<<endl;
		cout<<"Damage      = "<<dmg<<endl;
		cout<<"Speed       = "<<spd<<endl;
		cout<<endl;
	}

};

class Weapon : public Gear
{
private:
	int range;
public:
	Weapon():Gear(){range = 0;}
	//whatIsIt missing in this overloaded constructor too.
	Weapon(string name, string description, double weight,int dmg, int def, int spd, int range, string whatIsIt)
		:Gear(name,description,weight,dmg,def,spd,whatIsIt)
	{this->range = range;}

	int getRange(){return range;}
	void setRange(int range){this->range = range;}

	virtual void display()
	{
		cout<<"Name        = "<<getName()<<endl;
		cout<<"What is it  = "<<getWhatIsIt()<<endl; //missing here too.
		cout<<"Description = "<<getDescription()<<endl;
		cout<<"Weight      = "<<getWeight()<<endl;
		cout<<"Defense     = "<<getDef()<<endl;
		cout<<"Damage      = "<<getDmg()<<endl;
		cout<<"Speed       = "<<getSpd()<<endl;
		cout<<"Range       = "<<range<<endl;
		cout<<endl;
	}

};


class Armor : public Gear
{
private:
	string type;
public:
	Armor():Gear(){type = "NULL";}
	//add the whatIsIt here too.
	Armor(string name, string description, double weight,int dmg, int def, int spd, string type, string whatIsIt)
		:Gear(name,description,weight,dmg,def,spd,whatIsIt)
	{this->type = type;}

	string getType(){return type;}
	void setType(string type){this->type = type;}

	virtual void display()
	{
		cout<<"Name        = "<<getName()<<endl;
		cout<<"What is it  = "<<getWhatIsIt()<<endl; //missing here too.
		cout<<"Description = "<<getDescription()<<endl;
		cout<<"Weight      = "<<getWeight()<<endl;
		cout<<"Defense     = "<<getDef()<<endl;
		cout<<"Damage      = "<<getDmg()<<endl;
		cout<<"Speed       = "<<getSpd()<<endl;
		cout<<"Type        = "<<type<<endl;
		cout<<endl;
	}

};

//Implemented Accessory class derived from Gear class
class Accessory: public Gear
{
private:
	string type;
public:
	Accessory(string name, string description, double weight, int dmg, int def, int spd, string type, string whatIsIt)
		:Gear(name,description,weight,dmg,def,spd, whatIsIt)
	{this->type = type;}

	string getType(){return type;}
	void setType(string type){this->type = type;}

	virtual void display()
	{
		cout<<"Name        = "<<getName()<<endl;
		cout<<"What is it  = "<<getWhatIsIt()<<endl; //missing here too.
		cout<<"Description = "<<getDescription()<<endl;
		cout<<"Weight      = "<<getWeight()<<endl;
		cout<<"Defense     = "<<getDef()<<endl;
		cout<<"Damage      = "<<getDmg()<<endl;
		cout<<"Speed       = "<<getSpd()<<endl;
		cout<<"Type        = "<<type<<endl;
		cout<<endl;
	}
};

//Consumables class derived from Item class
class Consumable: public Item
{
private:
	string type;
public:
	Consumable(string name, string description, double weight, string type, string whatIsIt)
		:Item(name,description,weight,whatIsIt)
	{this->type = type;}

	string getType(){return type;}
	void setType(string type){this->type = type;}

	virtual void display()
	{
		cout<<"Name        = "<<getName()<<endl;
		cout<<"What is it  = "<<getWhatIsIt()<<endl; //missing here too.
		cout<<"Description = "<<getDescription()<<endl;
		cout<<"Weight      = "<<getWeight()<<endl;
		cout<<"Type        = "<<type<<endl;
		cout<<endl;
	}
};

void gameTitle();

int main()
{
	//lets create a backpack with 30 size MAX
	Item *inventory[30];
	int lastitemlocation = 0;  //this keeps track of how many items we have currently in inventory
	int size; //used when infile to know how many objects are in the file.
	string name;
	string whatIsIt;  //whatIsIt variable goes here.
	string description;
	double weight;
	int dmg;
	int def;
	int spd;
	int range;
	string type;
	ifstream inFile;
	ofstream outFile;
	int choice; // first original choice to select item.
	int choice2;	// what you want to do with first item.
	int choice3;// select second item

	inFile.open("weapons.txt");
	//FOR ALL THE INFILES, whatIsIt IS ALSO IN THERE, MODIFY THESE.
	inFile>>size;
	getline(inFile,type);
	cout<<type<<endl;
	for (int x=0; x<size; x++)
	{
		inFile>>name>>whatIsIt>>description>>weight>>dmg>>def>>spd>>range;

		//changes all the _ to a space for the names.
		for (size_t y=0; y<name.length();y++)
		{
			if (name.substr(y,1)=="_")
			{
				name[y] = ' ';
			}
		}

		//changes all the _ to a space for the descriptions.
		for (size_t y=0; y<description.length();y++)
		{
			if (description.substr(y,1)=="_")
			{
				description[y] = ' ';
			}
		}
		inventory[lastitemlocation] = new Weapon(name,description,weight,dmg,def,spd,range,whatIsIt);
		lastitemlocation++;
	}
	inFile.close();
	
	
	inFile.open("armors.txt");
	//how many armors there are.
	inFile>>size;
	//gets all the data for the armors.
	for (int x=0; x<size; x++)
	{
		inFile>>name>>whatIsIt>>description>>weight>>dmg>>def>>spd>>type;

		//changes all the _ to a space for the names.
		for (size_t y=0; y<name.length();y++)
		{
			if (name.substr(y,1)=="_")
			{
				name[y] = ' ';
			}
		}

		//changes all the _ to a space for the descriptions.
		for (size_t y=0; y<description.length();y++)
		{
			if (description.substr(y,1)=="_")
			{
				description[y] = ' ';
			}
		}

		inventory[lastitemlocation] = new Armor(name,description,weight,dmg,def,spd,type,whatIsIt);
		lastitemlocation++;
	}
	inFile.close();

	inFile.open("accessories.txt");
	//how many accessories there are.
	inFile>>size;
	//gets all the data for the accessories.
	for (int x=0; x<size; x++)
	{
		inFile>>name>>whatIsIt>>type>>description>>weight>>dmg>>def>>spd;

		//changes all the _ to a space for the names.
		for (size_t y=0; y<name.length();y++)
		{
			if (name.substr(y,1)=="_")
			{
				name[y] = ' ';
			}
		}

		//changes all the _ to a space for the descriptions.
		for (size_t y=0; y<description.length();y++)
		{
			if (description.substr(y,1)=="_")
			{
				description[y] = ' ';
			}
		}

		inventory[lastitemlocation] = new Accessory(name,description,weight,dmg,def,spd,type,whatIsIt);
		lastitemlocation++;
	}
	inFile.close();

	inFile.open("consumables.txt");
	//how many consumables there are.
	inFile>>size;
	//gets all the data for the consumables.
	for (int x=0; x<size; x++)
	{
		inFile>>name>>whatIsIt>>type>>description>>weight;

		//changes all the _ to a space for the names.
		for (size_t y=0; y<name.length();y++)
		{
			if (name.substr(y,1)=="_")
			{
				name[y] = ' ';
			}
		}

		//changes all the _ to a space for the descriptions.
		for (size_t y=0; y<description.length();y++)
		{
			if (description.substr(y,1)=="_")
			{
				description[y] = ' ';
			}
		}

		inventory[lastitemlocation] = new Consumable(name,description,weight,type,whatIsIt);
		lastitemlocation++;
	}
	inFile.close();

	//main loop of the program.
	do
	{
		//Title
		gameTitle();

		//Display all the items in the inventory.
		for (int x=0; x<lastitemlocation;x++)
		{
			//we start the numbers at 1, but remember our array starts at 0!
			cout<<x+1<<":  "<<inventory[x]->getName()<<endl;

		}

	
	
		cout<<"Select an item"<<endl;
		cin>>choice;
		system("cls");
		cout<<"You have selected the following item"<<endl;
		inventory[choice-1]->display();

		//here are the original 4 options.  you will add a new one here to view all items of
		//the same whatIsIt as the one selected.  This means the loop will no longer end at 4 since 
		//4 is now to "view like items", so 5 will be the "exit program"
		cout<<"What would you like to do with this item?"<<endl;
		cout<<"1.  Remove"<<endl;
		cout<<"2.  Duplicate"<<endl;
		cout<<"3.  Swap with another item"<<endl;
		cout<<"4.  Display all items of the same type"<<endl;
		cout<<"5.  Exit program"<<endl;

		cin>>choice2;
		system("cls");
		switch(choice2)
		{
		case 1:
			//will remove the item from the list.
			inventory[choice-1] = new Item();
			
			break;
		case 2:
		
			//this is to duplicate the item selected to the last location in the array.
			//it will then increase the number of items you are holding in the array by 1.
			inventory[lastitemlocation] = new Item();
			inventory[lastitemlocation] = inventory[choice-1];
			lastitemlocation++;
			
			break;
		case 3:
			//simple swap.
			for (int x=0; x<lastitemlocation;x++)
			{
				if (choice-1 == x)
					cout<<x+1<<":  "<<inventory[x]->getName()<<" SELECTED"<<endl;
				else
					cout<<x+1<<":  "<<inventory[x]->getName()<<endl;
			}
			cout<<"Which are you going to swap with the selected item?"<<endl;
			cin>>choice3;
			system("cls");
			swap(inventory[choice-1],inventory[choice3-1]);

			break;
		case 4:
			for(int x=0; x<lastitemlocation;x++)
			{
				if(inventory[choice-1]->getWhatIsIt() == inventory[x]->getWhatIsIt())
					inventory[x]->display();
			}
			system("pause");
			system("cls");
			break;
		case 5:
			break;
		default:
			break;

		};

	}while (choice2!=5);


	//search the array for a null and place it at the end.  decrease size of the array
	for (int x=0; x<lastitemlocation; x++)
	{
		for (int y=0; y<lastitemlocation; y++)
		{
			if (inventory[y]->getName()=="NULL")
			{
				//inventory[x] = inventory[lastitemlocation-1];
				swap(inventory[y],inventory[lastitemlocation-1]);
				lastitemlocation--;
			}
		}
	}

	//used somewhat a version of bubble sort, which is not like that of your book.
	cout<<"Sorted"<<endl;
	for (int x=0; x<lastitemlocation; x++)
	{
		for (int y=0; y<lastitemlocation-1-x; y++)
		{
			if (inventory[y]->getName()>inventory[y+1]->getName())
				swap(inventory[y],inventory[y+1]);
		}
	}
	//display the sorted list.
	for (int x=0; x<lastitemlocation;x++)
	{
		cout<<x+1<<":  "<<inventory[x]->getName()<<endl;

	}

	//Counts to keep track of how many items of each category there are
	int weaponCount = 0;
	int armorCount = 0;
	int accessoryCount = 0;
	int consumableCount = 0;

	//For loop to count number of items in each category
	for(int x=0; x<lastitemlocation;x++)
	{
		if(inventory[x]->getWhatIsIt() == "Weapon")
			weaponCount += 1;
		else if(inventory[x]->getWhatIsIt() == "Armor")
			armorCount += 1;
		else if(inventory[x]->getWhatIsIt() == "Accessory")
			accessoryCount += 1;
		else
			consumableCount += 1;
	}
	cout << endl;
	cout << "Total items saved by category: " << endl;
	cout << "Weapon: " << weaponCount << endl;
	cout << "Armor: " << armorCount << endl;
	cout << "Accessory: " << accessoryCount << endl;
	cout << "Consumable: " << consumableCount << endl;

	//Save the weapons file
	outFile.open("weapons.txt");
	outFile<<weaponCount<<endl;
	for(int x = 0; x < lastitemlocation; x++)
	{
		if(inventory[x]->getWhatIsIt() == "Weapon")
		{
			name = inventory[x]->getName();
			whatIsIt = inventory[x]->getWhatIsIt();
			description = inventory[x]->getDescription();
			weight = inventory[x]->getWeight();
			dmg = static_cast<Gear*>(inventory[x])->getDmg();
			def = static_cast<Gear*>(inventory[x])->getDef();
			spd = static_cast<Gear*>(inventory[x])->getSpd();
			range = static_cast<Weapon*>(inventory[x])->getRange();

			//changes all the spaces to for the names.
			for (size_t y=0; y<name.length();y++)
			{
				if (name.substr(y,1)==" ")
				{
					name[y] = '_';
				}
			}

			//changes all the spaces to for the descriptions.
			for (size_t y=0; y<description.length();y++)
			{
				if (description.substr(y,1)==" ")
				{
					description[y] = '_';
				}
			}

			outFile<<name<<endl;
			outFile<<whatIsIt<<endl;
			outFile<<description<<endl;
			outFile<<weight<<endl;
			outFile<<dmg<<endl;
			outFile<<def<<endl;
			outFile<<spd<<endl;
			outFile<<range<<endl;
		}
	}
	outFile.close();

	//Save the armors file
	outFile.open("armors.txt");
	outFile<<armorCount<<endl;
	for(int x = 0; x < lastitemlocation; x++)
	{
		if(inventory[x]->getWhatIsIt() == "Armor")
		{
			name = inventory[x]->getName();
			whatIsIt = inventory[x]->getWhatIsIt();
			description = inventory[x]->getDescription();
			weight = inventory[x]->getWeight();
			dmg = static_cast<Gear*>(inventory[x])->getDmg();
			def = static_cast<Gear*>(inventory[x])->getDef();
			spd = static_cast<Gear*>(inventory[x])->getSpd();
			type = static_cast<Armor*>(inventory[x])->getType();

			//changes all the spaces to for the names.
			for (size_t y=0; y<name.length();y++)
			{
				if (name.substr(y,1)==" ")
				{
					name[y] = '_';
				}
			}

			//changes all the spaces to for the descriptions.
			for (size_t y=0; y<description.length();y++)
			{
				if (description.substr(y,1)==" ")
				{
					description[y] = '_';
				}
			}

			outFile<<name<<endl;
			outFile<<whatIsIt<<endl;
			outFile<<description<<endl;
			outFile<<weight<<endl;
			outFile<<dmg<<endl;
			outFile<<def<<endl;
			outFile<<spd<<endl;
			outFile<<type<<endl;
		}
	}
	outFile.close();

	//Save accessories file
	outFile.open("accessories.txt");
	outFile<<accessoryCount<<endl;
	for(int x = 0; x < lastitemlocation; x++)
	{
		if(inventory[x]->getWhatIsIt() == "Accessory")
		{
			name = inventory[x]->getName();
			whatIsIt = inventory[x]->getWhatIsIt();
			description = inventory[x]->getDescription();
			weight = inventory[x]->getWeight();
			dmg = static_cast<Gear*>(inventory[x])->getDmg();
			def = static_cast<Gear*>(inventory[x])->getDef();
			spd = static_cast<Gear*>(inventory[x])->getSpd();
			type = static_cast<Accessory*>(inventory[x])->getType();

			//changes all the spaces to _ for the names.
			for (size_t y=0; y<name.length();y++)
			{
				if (name.substr(y,1)==" ")
				{
					name[y] = '_';
				}
			}

			//changes all the spaces to _ for the descriptions.
			for (size_t y=0; y<description.length();y++)
			{
				if (description.substr(y,1)==" ")
				{
					description[y] = '_';
				}
			}

			outFile<<name<<endl;
			outFile<<whatIsIt<<endl;
			outFile<<type<<endl;
			outFile<<description<<endl;
			outFile<<weight<<endl;
			outFile<<dmg<<endl;
			outFile<<def<<endl;
			outFile<<spd<<endl;
		}
	}
	outFile.close();

	
	//Save consumables file
	outFile.open("consumables.txt");
	outFile<<consumableCount<<endl;
	for(int x = 0; x < lastitemlocation; x++)
	{
		if(inventory[x]->getWhatIsIt() == "Consumable")
		{
			name = inventory[x]->getName();
			whatIsIt = inventory[x]->getWhatIsIt();
			description = inventory[x]->getDescription();
			weight = inventory[x]->getWeight();
			type = static_cast<Consumable*>(inventory[x])->getType();

			//changes all the spaces to _ for the names.
			for (size_t y=0; y<name.length();y++)
			{
				if (name.substr(y,1)==" ")
				{
					name[y] = '_';
				}
			}

			//changes all the spaces to _ for the descriptions.
			for (size_t y=0; y<description.length();y++)
			{
				if (description.substr(y,1)==" ")
				{
					description[y] = '_';
				}
			}

			outFile<<name<<endl;
			outFile<<whatIsIt<<endl;
			outFile<<type<<endl;
			outFile<<description<<endl;
			outFile<<weight<<endl;
		}
	}
	outFile.close();

	return 0;
}

//Used to display program title
void gameTitle(){ 	
	cout << "*************************************\n";
	cout << "**          Game Inventory         **\n";
	cout << "*************************************\n";
}