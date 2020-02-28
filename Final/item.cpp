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

#include "item.h"

/*
PRE: none
POST: creates a blank Item object
PURPOSE: default Item constructor
AUTHOR: Louis Vinton
*/
Item::Item()
{
	mName = "";
	mPrice = 0;
}

/*
PRE: none
POST: creates an Item object with the given parameters
PURPOSE: parameter Item constructor
AUTHOR: Louis Vinotn
*/
Item::Item(double price, string name)
{
	mPrice = price;
	mName = name;
}

void Item::display()
{
	cout << this;
}

/*
PRE: an initialized Item object
POST: returns mName
PURPOSE: gets the name of the item
AUTHOR: Louis Vinton
*/
string Item::getName()
{
	return mName;
}

/*
PRE: an initialized Item object
POST: returns mPrice
PURPOSE: gets the price of the item
AUTHOR: Louis Vinton
*/
double Item::getPrice()
{
	return mPrice;
}

/*
PRE: an initialized Item object
POST: sets mName to the given value
PURPOSE: changes the name of the object
AUTHOR: Louis Vinton
*/
void Item::setName(string name)
{
	mName = name;
}

/*
PRE: an initialized Item object
POST: sets mPrice to the given value
PURPOSE: changes the price of the object
AUTHOR: Louis Vinton
*/
void Item::setPrice(double price)
{
	mPrice = price;
}

/*
PRE: an initialized Item object, an initialized istream
POST: reads in the data for an Item in the given format
PURPOSE: input operator for Item
AUTHOR: Louis Vinton
*/
istream& operator>> (istream& input, Item& obj)
{
	string trash;

	cout << "Enter the name of the item: ";
	getline(input, obj.mName);
	cout << "Enter the price of the item: $";
	input >> obj.mPrice;
	getline(input, trash);

	return input;
}

/*
PRE: an initalized ostream and Item
POST: prints the items data to the ostream
PURPOSE: output operator
AUTHOR: Louis Vinton
*/
ostream& operator<< (ostream& output, const Item obj)
{
	output << obj.mName << endl;
	output << fixed << setprecision(2) << "$" << obj.mPrice << endl;

	return output;
}

/*
PRE: an initialized Item object, an initialized istream
POST: reads in the data for an Item in the given format
PURPOSE: input operator for Item
AUTHOR: Louis Vinton
*/
ifstream& operator>> (ifstream& input, Item& obj)
{
	string trash;

	getline(input, obj.mName);
	input >> obj.mPrice;
	getline(input, trash);

	return input;
}

/*
PRE: an initalized ofstream and Item
POST: prints the items data to the ofstream
PURPOSE: output operator
AUTHOR: Louis Vinton
*/
ofstream& operator<< (ofstream& output, const Item obj)
{
	output << obj.mName << endl;
	output << fixed << setprecision(2) << obj.mPrice << endl;

	return output;
}