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
#include "customer.h"
#include "teller.h"

/*
	Pre: Function called from main menu
	Post: Function called depending on the type of search
	Purpose: To search all existing account for specific information
*/
void searchAccount(Customer &customer)
{
	char searchType;
	bool validInput = false;

	while (validInput == false)
	{
		cout << "What would you like to search for? (Number[#], Name[N], SSN[S], Address[A], or Phone Number[P])" << endl << "> ";
		cin >> searchType;

		if (searchType == '#')
		{
			numSearch(customer);
			validInput = true;
		}
		else if (searchType == 'N' || searchType == 'n')
		{
			nameSearch(customer);
			validInput = true;
		}
		else if (searchType == 'S' || searchType == 's')
		{
			ssnSearch(customer);
			validInput = true;
		}
		else if (searchType == 'A' || searchType == 'a')
		{
			addressSearch(customer);
			validInput = true;
		}
		else if (searchType == 'P' || searchType == 'p')
		{
			phoneSearch(customer);
			validInput = true;
		}
		else
		{
			validInput = false;
			displayMessage(7);
		}
	}
}

/*
	Pre: Function called from searchAccount()
	Post: Information is searched for and returns all account information if found
	Purpose: To search all existing accounts for a specified account number and return all account information
*/
void numSearch(Customer &customer)
{
	Account blank;
	string accountNumber;

	cout << "Enter an account number: " << endl << "> ";
	cin >> accountNumber;

	if (customer.getCustomer(accountNumber) == blank)
	{
		displayMessage(2);
		systemPause();
	}
	else
	{
		cout << customer.getCustomer(accountNumber);
		systemPause();
	}
}

/*
	Pre: Function called from searchAccount()
	Post: Information is searched for and returns all account information if found
	Purpose: To search all existing accounts for a specified name and return all account information
*/
void nameSearch(Customer &customer)
{
	Account blank;
	string name;

	cout << "Enter a name: " << endl << "> ";
	cin.ignore();
	getline(cin, name);

	if (customer.getCustomerName(name) == blank)
	{
		displayMessage(2);
		systemPause();
	}
	else
	{
		cout << customer.getCustomerName(name);
		systemPause();
	}
}

/*
	Pre: Function called from searchAccount()
	Post: Information is searched for and returns all account information if found
	Purpose: To search all existing accounts for a specified SSN and return all account information
*/
void ssnSearch(Customer &customer)
{
	Account blank;
	string ssn;

	cout << "Enter an SSN: " << endl << "> ";
	cin >> ssn;

	if (customer.getCustomerSSN(ssn) == blank)
	{
		displayMessage(2);
		systemPause();
	}
	else
	{
		cout << customer.getCustomerSSN(ssn);
		systemPause();
	}
}

/*
	Pre: Function called from searchAccount()
	Post: Information is searched for and returns all account information if found
	Purpose: To search all existing accounts for a specified address and return all account information
*/
void addressSearch(Customer &customer)
{
	Account blank;
	string address;

	cout << "Enter an address: " << endl << "> ";
	cin >> address;

	if (customer.getCustomerAddress(address) == blank)
	{
		displayMessage(2);
		systemPause();
	}
	else
	{
		cout << customer.getCustomerAddress(address);
		systemPause();
	}
}

/*
	Pre: Function called from searchAccount()
	Post: Information is searched for and returns all account information if found
	Purpose: To search all existing accounts for a specified phone number and return all account information
*/
void phoneSearch(Customer &customer)
{
	Account blank;
	string phone;
	string trash;

	cout << "Enter a phone number: " << endl << "> ";
	cin >> phone;
	getline(cin, trash);

	if (customer.getCustomerPhone(phone) == blank)
	{
		displayMessage(2);
		systemPause();
	}
	else
	{
		cout << customer.getCustomerPhone(phone);
		systemPause();
	}
}