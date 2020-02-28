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

#include "PA4.h"
#include "employee.h"

/*
	Pre: Function called in login()
	Post: True or false is returned depending on if the login information is correct or not
	Purpose: To validate the provided login information
*/
bool getIdPassword(string &id, string &password)
{
	Employee employee;

	cin >> employee;

	ifstream fin;
	fin.open(TELLERS_FILE);

	int numTellers = 0;
	int i;
	string tempUser;
	string tempPass;
	string trash;

	fin >> numTellers;
	getline(fin, trash);

	for (i = 0; i < numTellers; i++)
	{
		fin >> tempUser >> tempPass;
		if (employee.mID == tempUser && employee.mPassword == tempPass)
		{
			return true;
			break;
		}
	}
	return false;
}


/*
	Pre: Function called in main
	Post: User is logged in and continues to the menu or fails to log in and has to retry
	Purpose: To prompt the user for their id and password and display if the login was successful or not
*/
bool login()
{
	bool successfulLogin = false;
	string id;
	string password;

	cout << "Teller Login" << endl 
		<< "==============" << endl;

	while (successfulLogin == false)
	{
		if (getIdPassword(id, password))
		{
			cout << "Login successful!" << endl;
			wait(1000);
			clearScreen();
			return true;
		}
		else
		{
			cout << "Login unsuccessful... Try again..." << endl;
			return false;
		}
	}
}