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

/*
	Pre: Function called from managment menu
	Post: Correct function is called for the type of object being added
	Purpose: To prompt the user for the type of object to be added and call the correct function
*/
void addNewItem(Games &games, Book &books)
{
	char type;
	string itemInfo;
	int gamesCount = games.getCount() + 1;
	int booksCount = books.getCount() + 1;
	cout << "Would you like to add a book or a game? [B/G]" << endl
		<< "> ";
	cin >> type;

	if (type == 'B' || type == 'b')
	{
		books.addBook();
	}
	else if (type == 'G' || type == 'g')
	{
		games.addGame();
	}
	else
	{
		cout << "Invalid selection..." << endl;
	}
}

/*
	Pre: Function called from managment menu
	Post: Correct function is called for the type of object being removed
	Purpose: To prompt the user for the type of object to be removed and call the correct function
*/
void deleteExistingItem(Games &games, Book &books)
{
	char type;
	string toRemove;
	string itemInfo;
	int gamesCount = games.getCount() + 1;
	int booksCount = books.getCount() + 1;
	cout << "Would you like to remove a book or a game? [B/G]" << endl
		<< "> ";
	cin >> type;

	if (type == 'B' || type == 'b')
	{
		cout << "Enter an ISBN to delete: " << endl;
		cin >> toRemove;
		books.removeBook(toRemove);
	}
	else if (type == 'G' || type == 'g')
	{
		cout << "Enter a barcode to delete: " << endl;
		cin >> toRemove;
		games.removeGame(toRemove);
	}
	else
	{
		cout << "Invalid selection..." << endl;
	}
}

/*
	Pre: Function called from managment menu
	Post: Correct function is called for the type of object being searched
	Purpose: To prompt the user for the type of object to search and call the correct function
*/
void searchItem(Games &games, Book &books)
{
	string search;
	char type;

	cout << "Would you like to search for a book or a game? [B/G]" << endl
		<< "> ";
	cin >> type;

	if (type == 'B' || type == 'b')
	{
		cout << "Enter an ISBN to search for: " << endl;
		cin >> search;
		books.searchBook(search);
	}
	else if (type == 'G' || type == 'g')
	{
		cout << "Enter a barcode to search for: " << endl;
		cin >> search;
		games.searchGame(search);
	}
	else
	{
		cout << "Invalid selection..." << endl;
	}
}

/*
	Pre: Function called from managment menu
	Post: Inventory information is displayed to the screen
	Purpose: To display the information for games and books
*/
void displayIventoryInfo(Games &games, Book &books)
{
	cout << "=== INVENTORY ===" << endl;
	
	cout << "Games# : " << games.getCount() << endl;
	cout << "Books# : " << books.getCount() << endl;

	systemPause();
}