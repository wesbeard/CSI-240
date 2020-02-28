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

#include "person.h"

/*
PRE: None
POST: All member variables initialized
PURPOSE: To initialize all members
AUTHOR: Wes Beard
*/
Person::Person()
{
	mName = "";
	mTableNumber = 0;
}

/*
PRE: None
POST: All member variables initialized to parameters
PURPOSE: To initialize all members
AUTHOR: Wes Beard
*/
Person::Person(string name, int number)
{
	mName = name;
	mTableNumber = number;
}

/*
PRE: None
POST: Value of private member returned
PURPOSE: To return the value of a member variable
AUTHOR: Wes Beard
*/
string Person::getName()
{
	return mName;
}
int Person::getTableNumber()
{
	return mTableNumber;
}

/*
PRE: None
POST: Private member value is set to parameter
PURPOSE: To set a member to a specified value
AUTHOR: Wes Beard
*/
void Person::setName(string name)
{
	mName = name;
}
void Person::setTableNumber(int number)
{
	mTableNumber = number;
}