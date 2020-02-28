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
#include "MenuList.h"
#include "Table.h"

int main()
{
	bool loggedIn = false;
	bool exit = false;
	int dailyOrders = 0;
	double dailyTotal = 0;
	Employee employee;
	MenuList menu;
	Table* tables;


	employee.loadEmployeeData();
	menu.loadData();
	tableSetUp(tables);

	do
	{
		//Login gets position which determines the menu selection
		loggedIn = login(employee);
		while (loggedIn == true && exit == false)
		{
			//Menu selection chosen based off of login credintials
			switch (employee.getPosition())
			{
			case 'H':
				hostMenu(loggedIn, tables);
				wait(1000);
				clearScreen();
				break;
			case 'W':
				waiterMenu(loggedIn, menu, tables, dailyTotal, dailyOrders);
				wait(1000);
				clearScreen();
				break;
			case 'K':
				kitchenMenu(loggedIn, menu, tables);
				wait(1000);
				clearScreen();
				break;
			case 'M':
				managerMenu(loggedIn, menu, tables, dailyTotal, dailyOrders);
				wait(1000);
				clearScreen();
				break;
			}
		}
	} while (loggedIn == false);
}
