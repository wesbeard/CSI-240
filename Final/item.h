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

#ifndef ITEM
#define ITEM

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Item 
{
	private:
		double mPrice;
		string mName;

	public:
		Item();
		Item(double price, string name);
		
		void display();

		string getName();
		double getPrice();
		void setName(string name);
		void setPrice(double price);

		friend istream& operator>> (istream& input, Item& obj);
		friend ostream& operator<< (ostream& output, const Item obj);
		friend ifstream& operator>> (ifstream& input, Item& obj);
		friend ofstream& operator<< (ofstream& output, const Item obj);
};


#endif