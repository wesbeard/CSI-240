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


#ifndef ITEM
#define ITEM

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Item
{
	protected:
		string mBarcode;
		string mName;
		double mPrice;
		int	   mQuantity;

	public:
		Item();
		Item(string barcode, string name, double price, int quantity);

		string getBarcode();
		string getName();
		double getPrice();
		int    getQuantity();

		void setBarcode(string barcode);
		void setName(string name);
		void setPrice(double price);
		void setQuantity(int quantity);

		int  operator ++ ();
		int  operator -- ();
		bool operator == (Item rhs);
		bool operator == (string rhs);

		friend bool operator == (string lhs, Item rhs);
};
#endif