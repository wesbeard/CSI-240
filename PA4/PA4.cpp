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

int main()
{
	bool loggedIn = false;
	bool exit = false;
	Teller teller;
	Games games;
	Book books;
	GamesLinkedList gamesList;
	BooksLinkedList booksList;


	if (!teller.loadData(TELLERS_FILE))
	{
		cout << "File not found...";
		wait(2000);
	}
	else
	{
		do
		{
			loggedIn = login();
			while (loggedIn == true && exit == false)
			{
				games.loadGamesData();
				books.loadBooksData();
				int numSelection = mainMenu();

				switch (numSelection)
				{
				case 1:
					clearScreen();
					gameTransactionMenu(gamesList, games);
					break;
				case 2:
					clearScreen();
					bookTransactionMenu(booksList, books);
					break;
				case 3:
					clearScreen();
					manageTransaction(gamesList, booksList, games, books);
					break;
				case 4:
					clearScreen();
					managmentMenu(games, books);
					break;
				case 5:
					clearScreen();
					loggedIn = login();
					break;
				case 6:
					cout << "Exiting program..." << endl;
					wait(2000);
					exit = true;
					break;
				default:
					cout << "Invalid input..." << endl;
					wait(2000);
					break;
				}
			}
		} while (loggedIn == false);
	}
}