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
#include "employee.h"

/*
PRE: an initialized menu
POST: adds an item to the menu
PUROSE: adds item to menu
AUTHOR: Louis Vinton
*/
void addItem(MenuList& menu)
{
	Item tempItem;

	clearScreen();
	printLogo();

	cout << "Enter item details:" << endl;
	cin >> tempItem;

	menu.insert(tempItem);
}

/*
PRE: an initailzed menu
POST: loads data from file into menu
PURPOSE: creates a starting menu
AUTHOR: Louis Vinton
*/
bool createMenu(MenuList& menu)
{
	const string FILE_NAME = "menu.dat";

	int numItems, i;
	string trash;
	Item tempItem;
	ifstream input;

	input.open(FILE_NAME);

	if (!input.good())
		return false;

	input >> numItems;
	getline(input, trash);

	for (i = 0; i < numItems; i++)
	{
		input >> tempItem;
		menu.insert(tempItem);
	}

	return true;
}

/*
PRE: a Table pointer
POST: changes mComplete to true
PURPOSE: completes a tables order
AUTHOR: Louis Vinton & Wes Beard
*/
void completeOrder(Table* tables)
{
	int tableSelection;
	int i;

	clearScreen();
	printLogo();

	cout << "Currently occupied tables: " << endl;

	for (i = 0; i < TOTAL_TABLES; i++)
	{
		if (tables[i].isOpen() == false)
		{
			cout << "Table #" << tables[i].getNumber() << endl;
		}
	}

	cout << "Enter a table number: ";
	tableSelection = getSelection(10);
	cout << endl;

	if (tables[tableSelection].isOpen())
	{
		cout << "No open orders for this table..." << endl;
	}
	else
	{
		tables[tableSelection].completeOrder();
		cout << "Order completed!";
	}
}

/*
PRE: an initailzed menu
POST: an item is removed from the menu
PURPOSE: deletes an item
AUTHOR: Louis Vinton
*/
void deleteItem(MenuList& menu)
{
	string choice;

	clearScreen();
	printLogo();

	menu.display();

	cout << endl << "Enter the item you wish you delete: ";
	getline(cin, choice);
	menu.remove(choice);

}

/*
PRE: an initailzed menu
POST: edits an items details
PURPOSE: changes an items details
AUTHOR: Louis Vinton
*/
void modifyItem(MenuList& menu)
{
	string choice;
	Item newItem;

	clearScreen();
	printLogo();

	menu.display();
	cout << "Enter the name of the item you wish to modify: ";
	getline(cin, choice);

	clearScreen();
	printLogo();
	if (menu.isExist(choice))
	{
		cout << "Enter the new information for the item." << endl << endl;
		cin >> newItem;

		menu.remove(choice);
		menu.insert(newItem);
	}
	else
		cout << "No item with that name." << endl;
}

/*
PRE: an initailzed menu
POST: none
PURPOSE: shows user options to modify menu
AUTHOR: Louis Vinton & Wes Beard
*/
void modifyMenu(MenuList& menu)
{
	int selection;

	clearScreen();
	printLogo();

	cout << "[1] Add Item" << endl
		<< "[2] Remove Item" << endl
		<< "[3] Modify Item" << endl
		<< "Selection: ";
	selection = getSelection(3);

	switch (selection) {
		case 1: addItem(menu);
				break;
		case 2: deleteItem(menu);
				break;
		case 3: modifyItem(menu);
				break;
	}
}

/*
PRE: an initailzed menu
POST: orders printed to screen
PURPOSE: shows orders
AUTHOR: Louis Vinton
*/
void viewOrders(Table* tables)
{
	int i;

	clearScreen();
	printLogo();

	for (i = 0; i < TOTAL_TABLES; i++)
	{
		if (!tables[i].isOpen())
		{
			cout << "Table #" << i << ":" << endl;
			tables[i].displayOrder();
			cout << endl;
		}
		else
		{
			cout << "No open orders..." << endl;
		}
	}
	system("pause");
}