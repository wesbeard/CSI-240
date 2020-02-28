/*Author: Wes Beard
Class: CSI240 Advanced Programming
Assignment: PA3 Part 3
Date Assigned: 2/18/2019
Due Date: 3/8/2019
Description:
A banking program that allows a teller to manage multiple cutomer accounts.
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)*/

#include "employee.h"

/*
	Pre: None
	Post: Inputs values for the members from the console
	Purpose: To overload the >> operator and input data from the console into the class
*/
istream& operator >> (istream& input, Employee& obj)
{
	string trash;
	cout << "Enter an ID: ";
	input >> obj.mID;

	cout << "Enter a password: ";

	char space = 0;
	string password = "";

	//Password protection, help from http://www.cplusplus.com/forum/general/91313/
	while (space != '\r')
	{
		space = _getch();

		if (space == 8 && obj.mPassword.length() > 0)
		{
			_putch('\b');
			_putch(' ');
			_putch('\b');
			obj.mPassword = obj.mPassword.substr(0, obj.mPassword.size() - 1);
		}
		else if (space == 8 && obj.mPassword.length() == 0)
		{
		}
		else if (space != '\r')
		{
			obj.mPassword.push_back(space);
			_putch('*');					
		}
	}
	cout << endl;
	return input;
}

/*
	Pre: None
	Post: Prints out the values of the members to the console when << is used
	Purpose: To overload the << operator and output the formatted data from the class to the console
*/
ostream& operator << (ostream& output, const Employee& obj)
{
	output << obj.mID << " " << obj.mPassword << endl;
	return output;
}