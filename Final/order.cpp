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

#include "order.h"
#include "MenuList.h"


/*
PRE: none
POST: initalizes an Order
PURPOSE: default constructor
AUTHOR: Louis Vinton
*/
Order::Order()
{
	mCompleted = false;
}

/*
PRE: none
POST: creates a copy of obj
PURPOSE: copy constructor
AUTHOR: Louis Vinton
*/
Order::Order(const Order &obj)
{
	mCompleted = obj.mCompleted;
	mOrder = MenuList(obj.mOrder);
}

/*
PRE: an initialized order
POST: item is added to the order
PURPOSE: adds an item to the order
AUTHOR: Louis Vinton
*/
void Order::add(Item item)
{
	mOrder.insert(item);
}

/*
PRE: an initailzed order
POST: mCompleted set to true
PURPOSE: completes an order
AUTHOR: Louis Vinton
*/
void Order::completeOrder()
{
	mCompleted = true;
}

/*
PRE: an initialized order
POST: prints the order to the console
PURPOSE: displays the order
AUTHOR: Louis Vinton
*/
void Order::display()
{
	int i;

	for (i = 0; i < mOrder.getCount(); i++)
		cout << mOrder.getData(i);
}

/*
PRE: an initialized order
POST: returns the size of the order
PURPOSE: gets the size of the order
AUTHOR: Louis Vinton
*/
int Order::getSize()
{
	return mOrder.getCount();
}

/*
PRE: an initialized order
POST: returns the total cost of the order
PURPOSE: gets the total price of the order
AUTHOR: Louis Vinton
*/
double Order::getTotal()
{
	int i;
	double total = 0;

	for (i = 0; i < mOrder.getCount(); i++)
	{
		total += mOrder.getData(i).getPrice();
	}

	return total;
}

/*
PRE: an initialized order
POST: returns a specified item
PURPOSE: to remove an item from an order
AUTHOR: Louis Vinton
*/
void Order::remove(string itemName)
{
	mOrder.remove(itemName);
}