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
PRE: Function called in login()
POST: True or false is returned depending on if the login information is correct or not
PURPOSE: To validate the provided login information
AUTHOR: Wes Beard & Louis Vinton
*/
bool getIdPassword(Employee& employees)
{
	string userID;
	string userPass;
	string trash;

	cout << "Enter an ID: ";
	getline(cin, userID);

	cout << "Enter a password: ";
	getline(cin, userPass);

	if (employees.verifyEmployee(userID, userPass))
	{
		employees.setID(userID);
		employees.setPassword(userPass);

		for (int i = 0; i < employees.getCount(); i++)
		{
			if (employees.getEmployee(i).getID() == userID)
			employees.setPosition(employees.getEmployee(i).getPosition());
		}
		return true;
	}

	return false;
}

/*
PRE: Function called in main
POST: User is logged in and continues to the menu or fails to log in and has to retry
PURPOSE: To prompt the user for their id and password and display if the login was successful or not
AUTHOR: Wes Beard & Louis Vinton
*/
bool login(Employee &employee)
{
	bool successfulLogin = false;

	printLogo();

	cout << "Employee Login" << endl
		<< "==============" << endl;

	while (successfulLogin == false)
	{
		if (getIdPassword(employee))
		{
			cout << "Login successful!" << endl;
			wait(1000);
			clearScreen();
			return true;
		}
		else
		{
			cout << "Login unsuccessful... Try again..." << endl;
			wait(1000);
			clearScreen();
			return false;
		}
	}

	return true;
}