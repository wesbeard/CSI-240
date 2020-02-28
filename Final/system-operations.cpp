/*
Authors: Wes Beard & Louis Vinton
Class: CSI240 Advanced Programming
Assignment: Final Project
Date Assigned: 4/10/2019
Due Date: 4/26/2019
Description:
	A restaurant program that uses four different roles to manage tables, orders, and the menu. Each role can only access their own functions except for the manager
	which can access all of them. The program will run continuosly until a manager signs in and shuts down the system manually.
Certification of Authenticity:
	I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
	I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
		- Reproduce this assignment and provide a copy to another member of academic staff; and/or
		- Communicate a copy of this assignment to a plagiarism checking service
		(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include "final.h"

/*
PRE: Function called
POST: System sleeps for the designated amount of time
PURPOSE: To sleep the program if called
AUTHOR: Wes Beard
*/
void wait(int time)
{
	Sleep(time);
}

/*
PRE: Function called
POST: Screen is cleared
PURPOSE: To clear the screen
AUTHOR: Wes Beard
*/
void clearScreen()
{
	system("cls");
}

/*
PRE: Function called
POST: System is paused until user input
PURPOSE: To clear the screen
AUTHOR: Wes Beard
*/
void pause()
{
	system("pause");
}

/*
PRE: Function called
POST: Logo is displayed
PURPOSE: To display the logo when called
AUTHOR: Wes Beard
*/
void printLogo()
{
	cout << "   ___   _           __ __       __                     " << endl
		<< "  / _ ) (_)___ _    / //_/__ _  / /  __ __ ___  ___ _    " << endl
		<< " / _  |/ // _ `/   /, <  /_ ` // _ \\/ // // _ \\/ _ `/  " << endl
		<< "/____//_/ \\_, /   /_/|_| \\_,_//_//_/\\_,_//_//_/\\_,_/ " << endl
		<< "   ___   /___/                       _.====.._           " << endl
		<< "  / _ ) __ __ ____ ___ _ ___  ____ ,:._       ~-_        " << endl
		<< " / _  |/ // // __// _ `// -_)/ __/    `\\        ~-_     " << endl
		<< "/____ /\\_,_//_/   \\_, / \\__//_/         |          `. " << endl
		<< "                 /___/                ,/             '   " << endl
		<< endl;
}

/*
PRE: Function called
POST: Selection is returned after being validated
PURPOSE: To get and validate a selection
AUTHOR: Louis Vinton
*/
int getSelection(int options)
{
	const char ZERO = '0';
	const char NINE = '9';
	const char BAD = 'a';

	int size = 0;
	string choice = "";
	char input = BAD;

	//while the input isnt enter
	while (input != '\r')
	{
		input = _getch();
		//if the input is between 0 and 9 add it the choice
		if (input >= ZERO && input <= NINE)
		{
			choice += input;
			size++;
			cout << input;
		}

		//if the input is backspace made the proper changes
		if (input == '\b' && choice.length() > 0)
		{
			choice.resize(choice.length() - 1);
			cout << "\b \b";
		}
	}

	//if the int parsed out of choice is larger than the number of options return bad
	if (choice.length() == 0 || stoi(choice) < 0 || stoi(choice) > options)
	{
		return BAD;
	}

	//else return choice
	return stoi(choice);
}

/*
PRE: Function called
POST: System is shut down
PURPOSE: To shut down the system if called
AUTHOR: Wes Beard
*/
void shutDown()
{
	cout << endl;
	cout << "Shutting down..." << endl;
	wait(1000);
	exit(0);
}

/*
PRE: Tables is intialized
POST: Tables are filled with the correct number and seats
PURPOSE: To populate the tables array with the correct information
AUTHOR: Wes Beard
*/
void tableSetUp(Table*& tables)
{
	int i;

	tables = new Table[TOTAL_TABLES];

	for (i = 0; i < TOTAL_TABLES; i++)
	{
		if (i < 3)
		{
			tables[i] = Table(i + 1, 2);
		}
		if (i < 7 && i > 3)
		{
			tables[i] = Table(i + 1, 4);
		}
		if (i < TOTAL_TABLES && i > 7)
		{
			tables[i] = Table(i + 1, 8);
		}
	}
}