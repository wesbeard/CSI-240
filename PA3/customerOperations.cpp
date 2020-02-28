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
	Pre: Function called to get an account number
	Post: Returns account number when called
	Purpose: To get an account number from the user, find the account in the database, and validate that it is a valid account
*/
string getAccountNumber(Customer customer)
{
	string accountNumber;
	Account blank;
	bool validAccount = false;

	while (validAccount == false)
	{
		cout << "Enter an account number: " << endl << "> ";
		getline(cin, accountNumber);

		if (customer.getCustomer(accountNumber) == blank)
		{
			displayMessage(2);
		}
		else
		{
			cout << "Account found..." << endl;
			validAccount = true;
			return accountNumber;
		}
	}
}

/*
	Pre: Function called from main menu to check the balances of the passed account number
	Post: Balance information displayed to the screen
	Purpose: To get the account information and print it to the screen
*/
void checkBalance(Customer customer, string accountNumber)
{
	Account tempAccount = customer.getCustomer(accountNumber);
	cout << "Savings: $" << tempAccount.getSavings() << endl;
	cout << "Checking: $" << tempAccount.getChecking() << endl;
	cout << "Total: $" << tempAccount.getTotal() << endl;
}

/*
	Pre: Function called to return a double value
	Post: Value for amount returned 
	Purpose: To get an amount from the user, validate the input, and return it
*/
double getAmount(string message)
{
	double userAmount;
	string trash;
	bool validInput = false;

	while (validInput == false)
	{
		cout << "Enter an Amount for " << message << ": $";
		cin >> userAmount;
		getline(cin, trash);

		if (userAmount > 0)
		{
			validInput = true;
			return userAmount;
		}
		else
		{
			validInput = false;
			displayMessage(5);
		}
	}
}

/*
	Pre: Function called from main menu
	Post: Database information for the corresponding account changed
	Purpose: To deposit money into a specified account
*/
void deposit(Customer &customer, string accountNumber)
{
	string message = "Deposit";
	double amount = getAmount(message);
	char choice;
	string trash;
	Account temp;

	cout << "Choose an account type to deposit into: Savings[S] or Checking[C]" << endl << "> ";
	cin >> choice;
	getline(cin, trash);

	if (choice == 'C' || choice == 'c')
	{
		temp = customer.getCustomer(accountNumber);
		temp.setChecking(temp.getChecking() + amount);

		cout << "New account balance for account #" << accountNumber << " is: $" << temp.getChecking() << endl;

		customer.removeAccount(accountNumber);
		customer.addNew(temp);
	}
	else if (choice == 'S' || choice == 's')
	{
		temp = customer.getCustomer(accountNumber);
		temp.setSavings(temp.getSavings() + amount);

		cout << "New account balance for account #" << accountNumber << " is: $" << temp.getSavings() << endl;

		customer.removeAccount(accountNumber);
		customer.addNew(temp);
	}
	else
	{
		displayMessage(7);
	}
}

/*
	Pre: Function called from main menu
	Post: Database information for the corresponding account changed
	Purpose: To withdraw money from a specified account
*/
void withdrawal(Customer &customer, string accountNumber)
{
	string message = "Withdrawal";
	double amount = getAmount(message);
	char choice;
	string trash;
	Account temp;

	cout << "Choose an account type to withdraw from: Savings[S] or Checking[C]" << endl << "> ";
	cin >> choice;
	getline(cin, trash);

	if (choice == 'C' || choice == 'c')
	{
		temp = customer.getCustomer(accountNumber);
		temp.setChecking(temp.getChecking() - amount);

		cout << "New account balance for account #" << accountNumber << " is: $" << temp.getSavings() << endl;

		customer.removeAccount(accountNumber);
		customer.addNew(temp);
	}
	else if (choice == 'S' || choice == 's')
	{
		temp = customer.getCustomer(accountNumber);
		temp.setSavings(temp.getSavings() - amount);

		cout << "New account balance for account #" << accountNumber << " is: $" << temp.getSavings() << endl;

		customer.removeAccount(accountNumber);
		customer.addNew(temp);
	}
	else
	{
		displayMessage(7);
	}
}

/*
	Pre: Function called from main menu
	Post: New account added to the customer database
	Purpose: To create a new customer with the user entered information
*/
void addAccount(Customer &customer)
{
	customer.addNew();
	cout << "New account created..." << endl;
	systemPause();
}

/*
	Pre: Function called from main menu
	Post: Account information deleted from database
	Purpose: To delete an existing customer account based on its account number
*/
void deleteAccount(Customer &customer, string accountNumber)
{
	char choice;
	string trash;
	cout << customer.getCustomer(accountNumber);
	cout << "Delete account? Y/N" << endl << "> ";
	cin >> choice;
	getline(cin, trash);

	if (choice == 'y' || choice == 'Y')
	{
		cout << "Deleting account, returning to menu..." << endl;
		customer.removeAccount(accountNumber);
		wait(1500);
		clearScreen();
	}
	else if (choice == 'n' || choice == 'N')
	{
		cout << "Account not deleted, returning to menu..." << endl;
		wait(1500);
		clearScreen();
	}
	else
	{
		displayMessage(7);
		cout << "Returning to menu..." << endl;
		wait(1500);
		clearScreen();
	}
}