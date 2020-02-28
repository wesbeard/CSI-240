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
#include "Table.h"

/*
PRE: Function called from host menu
POST: Correct table selected and set to occupied
PURPOSE: To find and seat a table
AUTHOR: Wes Beard
*/
void findTable(Table* tables)
{
	int requestedSeats;
	int i;
	bool tableFound = false;
	bool closed = false;
	
	cout << endl;
	cout << "How many people in party?" << endl;
	cin >> requestedSeats;

	for (i = 0; i < TOTAL_TABLES; i++)
	{
		if (tables[i].getSeats() >= requestedSeats && tables[i].isOpen() == true)
		{
			cout << "Table #" << tables[i].getNumber() << " with " << tables[i].getSeats() << " seats found..." << endl;
			cout << "Please be seated!" << endl;
			tables[i].setOpen(closed);
			wait(1000);
			tableFound = true;
			break;
		}
	}
	if (tableFound == false)
	{
		cout << "No suitable table found..." << endl;
	}
}

/*
PRE: Function called in host menu
POST: Displays all occupied tables and prompts user for which one to make available
PURPOSE: To make a selected table available
AUTHOR: Wes Beard
*/
void makeAvailable(Table* tables)
{
	int i;
	int tableSelection;
	bool unnoccupied = true;
	bool open = true;

	cout << endl;
	cout << "Currently occupied tables: " << endl;

	for (i = 0; i < TOTAL_TABLES; i++)
	{
		if (tables[i].isOpen() == false)
		{
			unnoccupied = false;
			cout << "Table #" << tables[i].getNumber() << endl;
		}
	}

	if (unnoccupied == false)
	{
		cout << "Enter a table number to make available: ";
		cin >> tableSelection;

		
		cout << "Setting table #" << tables[tableSelection - 1].getNumber() << " to open..." << endl;
		tables[i - 1].setOpen(open);
		
	}
	else
	{
		cout << endl << "All tables available..." << endl;
	}
}