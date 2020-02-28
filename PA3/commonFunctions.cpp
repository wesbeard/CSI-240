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

/*
	Pre: Function called
	Post: Screen cleared
	Purpose: To clear the console when called
*/
void clearScreen()
{
	system("cls");
}

/*
	Pre: Function called
	Post: System paused
	Purpose: To pause the console when called
*/
void systemPause()
{
	system("pause");
}

/*
	Pre: Function called
	Post: Sleeps for specific amount of time
	Purpose: To sleep when called
*/
void wait(int time)
{
	Sleep(time);
}

/*
	Pre: Function called in main menu
	Post: Logo printed to screen
	Purpose: To print the logo to the screen when called
*/
void displayLogo() 
{
	cout <<" _____ _                  _               _   _    _       _                     " << endl
		<< "/ ____| |                | |             | | | |  | |     (_)                    " << endl
		<< "| (___| |_ __ _ _ __   __| | __ _ _ __ __| | | |  | |_ __  _  ___  _ __          " << endl
		<< "\\___ \\| __/ _` | '_ \\ / _` |/ _` | '__/  _`| | |  | | '_ \\| |/ _ \\| '_ \\   " << endl
		<< "____) | || (_| | | | | (_| | (_| | |  | (_|| | |__| | | | | | (_) | || |        " << endl
		<< "|____/\\__ \\__,_|_| |_|\\__,_|\\__,_|_|  \\__,_|  \\____/|_| |_|_|\\___/|_||_| " << endl;
}

/*
	Pre: Function called when error occurs
	Post: Specific message printed to screen
	Purpose: To display an error message corresponding to the passed error code
*/
void displayMessage(int errorCode)
{
	int code = errorCode;

	switch (code)
	{
		case 1:
			cout << "Error: Account Already Exists" << endl;
			break;
		case 2:
			cout << "Error: Account Not Found" << endl;
			break;
		case 3:
			cout << "Error: Insufficient Funds For Withdrawal" << endl;
			break;
		case 4:
			cout << "Error: Invalid Amount" << endl;
			break;
		case 5:
			cout << "Error: Invalid Data Entry" << endl;
			break;
		case 6:
			cout << "Error: Invalid ID/Password" << endl;
			break;
		case 7:
			cout << "Error: Invalid Selection" << endl;
			break;
		case 8:
			cout << "Error: Account Database Not Available" << endl;
			break;
		case 9:
			cout << "Error: Teller Database Not Available" << endl;
			break;
		case 10:
			cout << "Please enter a valid selection" << endl;
	}
}

/*
	Pre: Function called
	Post: Menu printed to screen and user input is acquired, validated, and returned
	Purpose: To display the menu to the user, prompt them for a selection, validate that selection, and return a valid selection.
*/
int mainMenu()
{
	bool validSelection = false;
	int selection;
	string trash;
	displayLogo();

		cout << "=========================================================================" << endl
			<< "|||    MAIN MENU -- please make a selection...                        |||" << endl
			<< "=========================================================================" << endl;

		cout <<"1: Check Balance" << endl
			<< "2: Deposit Money" << endl
			<< "3: Withdraw Money" << endl
			<< "4: Add Account" << endl
			<< "5: Delete Account" << endl
			<< "6: Search Account" << endl
			<< "7. Update Account" << endl
			<< "8: Teller Logout" << endl
			<< "9. Exit" << endl
			<< "> ";

		while (validSelection == false)
		{
		cin >> selection;
		getline(cin, trash);

		if (selection >= 1 && selection <= 9)
		{
			validSelection = true;
			return selection;
		}
		else
		{
			displayMessage(10);
			validSelection = false;
		}
	}
}