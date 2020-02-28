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

#include "Table.h"

/*
PRE: none
POST: constructs a default table
PURPOSE: default Table constructor
AUTHRO: Louis Vinton
*/
Table::Table()
{
	const int DEFAULT_INT = 0;
	const bool DEFAULT_BOOL = true;

	mTableNumber = DEFAULT_INT;
	mNumberOfSeats = DEFAULT_INT;
	mIsOpen = DEFAULT_BOOL;
}

/*
PRE: none
POST: create a table with the given values
PURPOSE: Table constructor with parameters
AUTHOR: Louis Vinton
*/
Table::Table( int number, int seats)
{
	mIsOpen = true;
	mTableNumber = number;
	mNumberOfSeats = seats;
}

/*
PRE: an initialized Table object
POST: deconstructs the object
PURPOSE: deconstructor
AUTHOR: Louis Vinton
*/
Table::~Table()
{
	const int DEFAULT_INT = 0;
	const bool DEFAULT_BOOL = false;

	mTableNumber = DEFAULT_INT;
	mNumberOfSeats = DEFAULT_INT;
	mIsOpen = DEFAULT_BOOL;
}

void Table::completeOrder()
{
	mTableOrder.completeOrder();
}

/*
PRE: an initialized Table
POST: returns mTableNumber
PURPOSE: gets the table number
AUTHOR: Louis Vinton
*/
int Table::getNumber()
{
	return mTableNumber;
}

/*
PRE: an initialized Table object
POST: returns the mNumberOfSeats
PURPOSE: gets the number of seats that the table has
AUTHOR: Louis Vinton
*/
int Table::getSeats()
{
	return mNumberOfSeats;
}

/*
PRE: Table object is intialized
POST: Returns if it is open
PURPOSE: to tell whether a table is open or not
AUTHOR: Louis Vinton
*/
bool Table::isOpen()
{
	return mIsOpen;
}

/*
PRE: an initialized table object
POST: changes mIsOpen to the given bool
PURPOSE: sets the availability of the seat
AUTHOR: Wes Beard
*/
void Table::setOpen(bool status)
{
	mIsOpen = status;
}

/*
PRE: an initialized order
POST: returns the total of the order for the table
PURPOSE: gets the total of the bill
AUTHOR: Louis Vinton
*/
double Table::getTotal()
{
	return mTableOrder.getTotal();
}

/*
PRE: an initailzed order
POST: returns the mTableOrder
PURPOSE: gets the order
AUTHOR: Louis Vinton
*/
Order Table::getOrder()
{
	return mTableOrder;
}

/*
PRE: an initailzed order
POST: item is added to the order
PURPOSE: adds item to order
AUTHOR: Louis Vinton
*/
void Table::addToOrder(Item item)
{
	mTableOrder.add(item);
}

/*
PRE: an initailzed order
POST: removes item from order
PURPOSE: removes an item from the order
AUTHOR: Louis Vinton
*/
void Table::deleteFromOrder(string toDelete)
{
	mTableOrder.remove(toDelete);
}

/*
PRE: an initailzed order
POST: deconstructs the order
PURPOSE: deletes the order
AUTHOR: Louis Vinton
*/
void Table::deleteOrder()
{
	mTableOrder.~Order();
}

/*
PRE: an initailzed order
POST: displays the order to the console
PURPOSE: displays the order
AUTHOR: Louis Vinton
*/
void Table::displayOrder()
{
	mTableOrder.display();
}