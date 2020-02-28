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
PRE: an initailzed MenuList, and Table pointer
POST: adds an order to a table
PURPOSE: gets the tables order
AUTHOR: Louis Vinton & Wes Beard
*/
void takeOrder(MenuList menu, Table* tables) 
{
	bool exit = false;
	int tableChoice, itemChoice;
	Order newOrder;
	int i;
	
		clearScreen();
		printLogo();
		cout << endl;

		cout << "Currently occupied tables: " << endl;

		for (i = 0; i < TOTAL_TABLES; i++)
		{
			if (tables[i].isOpen() == false)
			{
				cout << "Table #" << tables[i].getNumber() << endl;
			}
		}

		cout << "Enter a table number: ";
		tableChoice = (getSelection(10) - 1);
		cout << endl;

		if (tables[tableChoice].isOpen())
		{
			cout << "Table is empty." << endl;
			wait(200);
		}
		else
		{
			clearScreen();
			printLogo();
			cout << "=== MENU ===" << endl;
			menu.display();
			cout << "[0] Exit" << endl;
			do
			{
				//displays order and asks for choice
				cout << "Select an item to add to the order: ";
				itemChoice = getSelection(menu.getCount() + 1);
				cout << endl;

				if (itemChoice == 0)
				{
					exit = true;
					cout << "Current order: " << endl;
					tables[tableChoice].displayOrder();
					cout << endl;
					pause();
				}
				else if (itemChoice < menu.getCount() + 1)
				{
					tables[tableChoice].addToOrder((menu.getData(itemChoice - 1)));
					cout << "Item added to order..." << endl;
				}
				else
				{
					exit = true;
				}

			} while (!exit);

		}
}

/*
PRE: an initailzed Table pointer
POST: removes items from a tables orders
PURPOSE: deletes items from order
AUTHOR: Louis Vinton & Wes Beard
*/
void deleteFromOrder(Table* tables)
{
	int tableChoice;
	string itemChoice;
	int i;

	clearScreen();
	printLogo();
	cout << endl;

	cout << "Currently occupied tables: " << endl;

	for (i = 0; i < TOTAL_TABLES; i++)
	{
		if (tables[i].isOpen() == false)
		{
			cout << "Table #" << tables[i].getNumber() << endl;
		}
	}

	cout << "Enter a table number: ";
	tableChoice = (getSelection(10) - 1);
	cout << endl;

	if (tables[tableChoice].isOpen())
	{
		cout << "Table is empty." << endl;
		wait(200);
	}
	else
	{
		clearScreen();
		printLogo();
		//displays the order to be deleted from
		cout << "Current order: " << endl;
		tables[tableChoice].displayOrder();
		cout << endl;

		//deletes the item
		cout << "Enter the name of the item to delete: ";
		getline(cin, itemChoice);

		tables[tableChoice].deleteFromOrder(itemChoice);
		cout << "Removing item..." << endl;
	}
}

/*
PRE: an initailzed Table, double, and int
POST: calculates the total and increases the dailyTotal and dailyOrder
PURPOSE: creates the bill for the table
AUTHOR: Louis Vinton & Wes Beard
*/
void generateBill(Table* tables, double& dailyTotal, int& dailyOrders)
{
	int tableChoice;
	double total;
	int i;

	cout << "Currently occupied tables: " << endl;

	for (i = 0; i < TOTAL_TABLES; i++)
	{
		if (tables[i].isOpen() == false)
		{
			cout << "Table #" << tables[i].getNumber() << endl;
		}
	}

	cout << "Enter a table number: ";
	tableChoice = (getSelection(10) - 1);
	cout << endl;


	clearScreen();
	printLogo();
	cout << endl;

	if (tables[tableChoice].isOpen())
	{
		cout << "Table is empty." << endl;
		wait(200);
	}
	else
	{
		total = tables[tableChoice].getTotal();
		dailyTotal = (total + (total * TAX));

		cout << "The total is : " << fixed << setprecision(2) << total << endl;
		cout << "Tax : " << fixed << setprecision(2) << (total * TAX) << endl;
		cout << "Grand total: " << fixed << setprecision(2) << (total * TAX) + total << endl << endl;
		system("pause");

		tables[tableChoice].deleteOrder();
		tables[tableChoice].setOpen(true);
		dailyOrders++;
	}
}