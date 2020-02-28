/*Author: Finwë
Class: CSI240 Advanced Programming
Assignment: PA4 Part 3
Date Assigned: 4/3/2019
Due Date: 4/12/2019
Description:
A toys and games shop program. Allows for buying games and books as well as managing their inventory and adding new items.
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)*/

#include "Item.h"

/*
	Pre: None
	Post: All class members set to default values
	Purpose: To reset all members to defaults
*/
Item::Item()
{
	mBarcode = "";
	mName = "";
	mPrice = 0;
	mQuantity = 0;
}

/*
	Pre: None
	Post: Variables set equal to class member values
	Purpose: To set all variables to the value of the members
*/
Item::Item(string barcode, string name, double price, int quantity)
{
	mBarcode = barcode;
	mName = name;
	mPrice = price;
	mQuantity = quantity;
}

/*
	Pre: None
	Post: Value of barcode returned
	Purpose: To return a members value
*/
string Item::getBarcode()
{
	return mBarcode;
}

/*
	Pre: None
	Post: Value of name returned
	Purpose: To return a members value
*/
string Item::getName()
{
	return mName;
}

/*
	Pre: None
	Post: Value of price returned
	Purpose: To return a members value
*/
double Item::getPrice()
{
	return mPrice;
}

/*
	Pre: None
	Post: Value of quantity returned
	Purpose: To return a members value
*/
int Item::getQuantity()
{
	return mQuantity;
}

/*
	Pre: None
	Post: Value of member variable mBarcode set to the parameter barcode
	Purpose: To change the members value
*/
void Item::setBarcode(string barcode)
{
	mBarcode = barcode;
}

/*
	Pre: None
	Post: Value of member variable mName set to the parameter name
	Purpose: To change the members value
*/
void Item::setName(string name)
{
	mName = name;
}

/*
	Pre: None
	Post: Value of member variable mPrice set to the parameter price
	Purpose: To change the members value
*/
void Item::setPrice(double price)
{
	mPrice = price; 
}

/*
	Pre: None
	Post: Value of member variable mQuantity set to the parameter quantity
	Purpose: To change the members value
*/
void Item::setQuantity(int quantity)
{
	mQuantity = quantity;
}

/*
	Pre: None
	Post: Increments variable mQuantity and returns mQuantity
	Purpose: To overload the ++ operator and increment the variable mQuantity
*/
int Item::operator ++ ()
{
	mQuantity++;
	return mQuantity;
}


/*
	Pre: None
	Post: Decrements variable mQuantity and returns mQuantity
	Purpose: To overload the -- operator and decrement the variable mQuantity
*/
int Item::operator -- ()
{
	mQuantity--;
	return mQuantity;
}

/*
	Pre: None
	Post: Prints out if the statement was equal or unequal based on the item and an Item variable
	Purpose: To overload the == operator and check if the parameters are equivalent
*/
bool Item::operator == (Item rhs)
{
	if (rhs.mBarcode == getBarcode())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Pre: None
	Post: Prints out if the statement was equal or unequal based on the item and a string
	Purpose: To overload the == operator and check if the parameters are equivalent
*/
bool Item::operator == (string rhs)
{
	if (rhs == getBarcode())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Pre: None
	Post: Prints out if the statement was equal or unequal based on a string and Item
	Purpose: To overload the == operator and check if the parameters are equivalent
*/
bool operator == (string lhs, Item rhs)
{
	if (lhs == rhs.mBarcode)
	{
		return true;
	}
	else
	{
		return false;
	}
}