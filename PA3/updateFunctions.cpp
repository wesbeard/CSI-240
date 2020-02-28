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
	Purpose: To update current information on an existing account
*/
void updateAccount(Customer &customer)
{
	string accountNum = getAccountNumber(customer);
	bool validInput = false;
	char updateType;

	while (validInput == false)
	{
		cout << "What information would you like to update? (Number[#], Name[N], SSN[S], Address[A], or Phone Number[P])" << endl << "> ";
		cin >> updateType;

		if (updateType == '#')
		{
			updateNum(customer, accountNum);
			validInput = true;
		}
		else if (updateType == 'N' || updateType == 'n')
		{
			updateName(customer, accountNum);
			validInput = true;

		}
		else if (updateType == 'S' || updateType == 's')
		{
			updateSSN(customer, accountNum);
			validInput = true;
		}
		else if (updateType == 'A' || updateType == 'a')
		{
			updateAddress(customer, accountNum);
			validInput = true;
		}
		else if (updateType == 'P' || updateType == 'p')
		{
			updatePhone(customer, accountNum);
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
	Pre: Function called from updateAccount()
	Post: Information is updated in the database
	Purpose: To update the account number for the specified account
*/
void updateNum(Customer &customer, string accountNumber)
{
	Account account = customer.getCustomer(accountNumber);
	string newNum;

	cout << "Enter a new account number: " << endl << "> ";
	cin >> newNum;

	account.setAccountNumber(newNum);
	customer.removeAccount(accountNumber);
	customer.addNew(account);
	cout << "Account Number Updated..." << endl;
	systemPause();
}

/*
	Pre: Function called from updateAccount()
	Post: Information is updated in the database
	Purpose: To update the name for the specified account
*/
void updateName(Customer &customer, string accountNumber)
{
	Account account = customer.getCustomer(accountNumber);
	string newName;

	cout << "Enter a new name: " << endl << "> ";
	cin.ignore();
	getline(cin, newName);

	account.setName(newName);
	customer.removeAccount(accountNumber);
	customer.addNew(account);
	cout << "Account Name Updated..." << endl;
	systemPause();
}

/*
	Pre: Function called from updateAccount()
	Post: Information is updated in the database
	Purpose: To update the SSN for the specified account
*/
void updateSSN(Customer &customer, string accountNumber)
{
	Account account = customer.getCustomer(accountNumber);
	string newSSN;

	cout << "Enter a new SSN: " << endl << "> ";
	cin.ignore();
	getline(cin, newSSN);

	account.setSSN(newSSN);
	customer.removeAccount(accountNumber);
	customer.addNew(account);
	cout << "Account SSN Updated..." << endl;
	systemPause();
}

/*
	Pre: Function called from updateAccount()
	Post: Information is updated in the database
	Purpose: To update the address for the specified account
*/
void updateAddress(Customer &customer, string accountNumber)
{
	Account account = customer.getCustomer(accountNumber);
	string newAddress;

	cout << "Enter a new address: " << endl << "> ";
	cin.ignore();
	getline(cin, newAddress);

	account.setAddress(newAddress);
	customer.removeAccount(accountNumber);
	customer.addNew(account);
	cout << "Account address Updated..." << endl;
	systemPause();
}

/*
	Pre: Function called from updateAccount()
	Post: Information is updated in the database
	Purpose: To update the phone number for the specified account
*/
void updatePhone(Customer &customer, string accountNumber)
{
	Account account = customer.getCustomer(accountNumber);
	string newPhone;

	cout << "Enter a new phone number: " << endl << "> ";
	cin.ignore();
	getline(cin, newPhone);

	account.setPhoneNumber(newPhone);
	customer.removeAccount(accountNumber);
	customer.addNew(account);
	cout << "Account phone number Updated..." << endl;
	systemPause();
}