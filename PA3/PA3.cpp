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

#include "PA3.h"

int main()
{
	bool loggedIn = false;
	bool exit = false;
	Teller teller;
	Customer customer;
	
	
	if (!teller.loadData(TELLERS_FILE))
	{
		displayMessage(9);
	}

	customer.setFilename(ACCOUNTS_FILE);

	if (customer.loadData())
	{
		displayMessage(8);
	}

	do
	{
		loggedIn = login();

		while (loggedIn == true && exit == false)
		{
			int numSelection = mainMenu();

			switch (numSelection)
			{
			case 1:
				checkBalance(customer, getAccountNumber(customer));
				systemPause();
				clearScreen();
				break;
			case 2:
				deposit(customer, getAccountNumber(customer));
				systemPause();
				clearScreen();
				break;
			case 3:
				withdrawal(customer, getAccountNumber(customer));
				systemPause();
				clearScreen();
				break;
			case 4:
				addAccount(customer);
				clearScreen();
				break;
			case 5:
				deleteAccount(customer, getAccountNumber(customer));
				clearScreen();
				break;
			case 6:
				searchAccount(customer);
				clearScreen();
				break;
			case 7:
				updateAccount(customer);
				clearScreen();
				break;
			case 8:
				loggedIn = false;
				cout << "Logging out...";
				wait(1500);
				clearScreen();
				break;
			case 9:
				cout << "Exiting...";
				wait(1000);
				exit = true;
				break;
			}
		}
	} while (loggedIn == false);

	customer.storeData();
}