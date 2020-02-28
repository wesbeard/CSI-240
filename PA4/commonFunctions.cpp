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
#include "LL-books.h"
#include "LL-games.h"
#include "games.h"
#include "book.h"

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
	cout << "   ___           __"            << endl
		<< "  / _/___  ___  / /_ ___"       << endl
		<< " / _ / _ \\/ _ \\/ '_/(_-<"     << endl
		<< "/___/\\___/\\___/_/\\_\\/__/"   << endl
		<< "         / |/ /()"				<< endl
		<< "        /    /|/"				<< endl
		<< "  ____ /_/|_/ "					<< endl
		<< " / ___/________  ___ ___"		<< endl
		<< "/ (_ /_ ` /  ' \\/ -_|_-<"      << endl
		<< "\\___/\\_,_/_/_/_/\\__/___/"	<< endl;
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
			cout << "Invalid selection..." << endl;
			break;
	}
}

/*
	Pre: Function called
	Post: Menu printed to screen and user input is acquired, validated, and returned
	Purpose: To display the menu to the user, prompt them for a selection, validate that selection, and return a valid selection.
*/
int mainMenu()
{
	int selection;

	displayLogo();

	cout << endl
		<< "=====================" << endl
		<< "===   MAIN MENU   ===" << endl
		<< "=====================" << endl;

	cout << "1. Browse Games" << endl
		<< "2. Browse Books" << endl
		<< "3. Manage cart" << endl
		<< "4. Manage Stock" << endl
		<< "5. Log out" << endl
		<< "6. Shut down" << endl
		<< "> ";
	
	cin >> selection;
	 
	return selection;
}

/*
	Pre: Games transaction menu called from main menu
	Post: Games transaction menu is printed and user is prompted to choose a game or return to the main menu
	Purpose: To display the games transaction menu to the user and obtain an input.
*/
void gameTransactionMenu(GamesLinkedList &gamesList, Games &games)
{
	games.loadGamesData();

	int selection;

	cout << endl
		<< "=================" << endl
		<< "===   GAMES   ===" << endl
		<< "=================" << endl
		<< "Choose a game to buy... " << endl;

	for (int i = 0; i < games.getCount(); i++)
	{
		cout << i + 1 << ". " << games.getGame(i).getName() << " - $" << fixed << setprecision(2) << games.getGame(i).getPrice() << endl;
	}
	cout << games.getCount() + 1 << ". Return to menu" << endl;
	cin >> selection;
	if (selection != (games.getCount() + 1))
	{
		buyGame(gamesList, games.getGame(selection - 1), games, selection - 1);
	}
	else
	{
		cout << "Returning to menu..." << endl;
		Sleep(1000);
		clearScreen();
	}
}

/*
	Pre: Books transaction menu called from main menu
	Post: Books transaction menu is printed and user is prompted to choose a book or return to the main menu
	Purpose: To display the books transaction menu to the user and obtain an input.
*/
void bookTransactionMenu(BooksLinkedList &booksList, Book &books)
{
	books.loadBooksData();

	int selection;

	cout << endl
		<< "=================" << endl
		<< "===   BOOKS   ===" << endl
		<< "=================" << endl
		<< "Choose a book to buy... " << endl;

	for (int i = 0; i < books.getCount(); i++)
	{
		cout << i + 1 << ". " << books.getBook(i).getName() << " - $" << fixed << setprecision(2) << books.getBook(i).getPrice() << endl;
	}
	cout << books.getCount() + 1 << ". Return to menu" << endl;
	cin >> selection;
	if (selection != (books.getCount() + 1))
	{
		buyBook(booksList, books.getBook(selection - 1), books, selection - 1);
	}
	else
	{
		cout << "Returning to menu..." << endl;
		Sleep(1000);
		clearScreen();
	}
}

/*
	Pre: Managment menu called from main menu
	Post: managment menu is printed and user is prompted to choose a managment operation or return to the main menu
	Purpose: To display the managment menu to the user and obtain an input.
*/
void managmentMenu(Games &games, Book &books)
{
	int selection;

	cout << endl
		<< "=================" << endl
		<< "===    MGMT   ===" << endl
		<< "=================" << endl
		<< " Make a selection... " << endl
		<< endl;

	cout << "1. Add an item" << endl
		<< "2. Remove an item" << endl
		<< "3. Search for an item" << endl
		<< "4. Display inventory information" << endl
		<< "5. Return to menu" << endl
		<< ">";
	cin >> selection;

	switch (selection)
	{
		case 1:
			addNewItem(games, books);
			Sleep(1000);
			clearScreen();
			break;
		case 2:
			deleteExistingItem(games, books);
			Sleep(1000);
			clearScreen();
			break;
		case 3:
			searchItem(games, books);
			Sleep(1000);
			clearScreen();
			break;
		case 4:
			displayIventoryInfo(games, books);
			Sleep(1000);
			clearScreen();
			break;
		case 5:
			cout << "Returning to menu..." << endl;
			Sleep(1000);
			clearScreen();
			clearScreen();
			break;
		default:
			cout << "Invalid selection..." << endl;
			Sleep(1000);
			clearScreen();
			clearScreen();
			break;
	}
}