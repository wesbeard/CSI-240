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

#ifndef EMPLOYEE
#define EMPLOYEE

#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

struct Employee
{
	string mID;
	string mPassword;

	friend istream& operator >> (istream& input, Employee& obj);
	friend ostream& operator << (ostream& output, const Employee& obj);
};
#endif