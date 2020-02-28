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

/*
	Pre: Function called from transaction menu
	Post: Game is added to cart and the price of the game is added to the total
	Purpose: To buy the selected game
*/
void buyGame(GamesLinkedList &gamesList, Games game, Games &games, int gameNum)
{
	games.loadGamesData();

	int quantity = games.getGame(gameNum).getQuantity();

	if (quantity > 0)
	{
		gamesList.insert(game);
		cout << "Game added to cart!" << endl;
		games.setGamesTotal(gameNum);

		quantity--;
		games.setGameQuantity(gameNum, quantity);
	}
	else
	{
		cout << "Item out of stock!" << endl;
	}

	cout << "Current games in shopping cart: " << endl;
	gamesList.display();

	systemPause();
	clearScreen();
}

/*
	Pre: Function called from transaction menu
	Post: Book is added to cart and the price of the book is added to the total
	Purpose: To buy the selected book
*/
void buyBook(BooksLinkedList &booksList, Book book, Book &books, int bookNum)
{
	books.loadBooksData();

	int quantity = books.getBook(bookNum).getQuantity();

	if (quantity > 0)
	{
		booksList.insert(book);
		cout << "Book added to cart!" << endl;
		books.setBooksTotal(bookNum);

		quantity--;
		books.getBook(bookNum).setQuantity(quantity);
	}
	else
	{
		cout << "Item out of stock!" << endl;
	}

	cout << "Current books in shopping cart: " << endl;
	booksList.display();

	systemPause();
	clearScreen();
}

/*
	Pre: Function called from transaction menu
	Post: Selection is obtained and correct function is called
	Purpose: To prompt the user for a selection of how they want to manage the transaction
*/
void manageTransaction(GamesLinkedList &gamesList, BooksLinkedList &booksList, Games &games, Book &books)
{
	int selection;
	string searchKey;

	cout << "Current shopping cart: " << endl;
	gamesList.display();
	booksList.display();

	cout << endl
		<< "1. Remove game" << endl
		<< "2. Remove book" << endl
		<< "3. Delete transaction" << endl
		<< "4. Check out" << endl
		<< "5. Return to menu" << endl
		<< "> " << endl;
	cin >> selection;

	switch (selection)
	{
		case 1:
			cout << "Enter a barcode to delete..." << endl;
			cin >> searchKey;
			gamesList.remove(searchKey);
			Sleep(1000);
			break;
		case 2:
			cout << "Enter an ISBN to delete..." << endl;
			cin >> searchKey;
			booksList.remove(searchKey);
			Sleep(1000);
		case 3:
			cout << "Deleting transaction..." << endl;
			gamesList.deleteList();
			booksList.deleteList();
			Sleep(1000);
			break;
		case 4:
			cout << "Proceeding to check out..." << endl;
			checkOut(gamesList, booksList, games, books);
			Sleep(1000);
			break;
		case 5:
			cout << "Returning to menu..." << endl;
			Sleep(1000);
			clearScreen();
		default:
			cout << "Invalid selection..." << endl;
			Sleep(1000);
			break;
	}
	clearScreen();
}

/*
	Pre: Function called from transaction menu
	Post: Cart is emptied and the order is printed to the orders file
	Purpose: To check out the transaction and calculate the money needed
*/
void checkOut(GamesLinkedList &gamesList, BooksLinkedList &booksList, Games &games, Book &books)
{
	double cashTotal;
	double taxTotal;
	double itemsTotal;
	char proceed;

	if (booksList.isEmpty() == true && gamesList.isEmpty() == true)
	{
		cout << "Shopping cart is empty..." << endl;
		cout << "Returning to menu..." << endl;
	}
	else
	{
		itemsTotal = games.getGamesTotal() + books.getBooksTotal();
		taxTotal = TAX * (games.getGamesTotal() + books.getBooksTotal());
		cashTotal = taxTotal + itemsTotal;
		cout << "Your total is $" << fixed << setprecision(2) << cashTotal << endl;
		cout << "Would you like to proceed to check out? [Y/N]" << endl;
		cin >> proceed;

		if (proceed == 'Y' || proceed == 'y')
		{
			games.storeGamesData();
			books.storeBooksData();
			printOrder(gamesList, booksList, games, books, itemsTotal, taxTotal, cashTotal);
		}
		else
		{
			cout << "Returning to menu..." << endl;
		}
	}
}

/*
	Pre: Function called from check out
	Post: Information is printed to the orders file
	Purpose: To print the information from the cart to the file as well as the transaction information
*/
void printOrder(GamesLinkedList &gamesList, BooksLinkedList &booksList, Games &games, Book &books, double itemTotal, double taxTotal, double cashTotal)
{
	//Get order number from data file
	ifstream fin;
	fin.open(ORDER_NUMBER);
	int orderNum;
	fin >> orderNum;
	fin.close();

	//Open orders file and prints orders to it
	ofstream fout;
	fout.open(ORDERS_FILE, ios::app);
	fout << setfill('0') << setw(7) << orderNum << endl;
	fout.close();
	gamesList.printFile(ORDERS_FILE);
	booksList.printFile(ORDERS_FILE);
	fout.open(ORDERS_FILE, ios::app);
	fout << "$" << itemTotal << endl;
	fout << "$" << taxTotal << endl;
	fout << "$" << cashTotal << endl;
	fout.close();

	//Updates order number
	fout.open(ORDER_NUMBER);
	orderNum++;
	fout << orderNum;
	fout.close();

	//Clears current cart
	if (gamesList.isEmpty() != true)
	{
		gamesList.deleteList();
	}
	if (booksList.isEmpty() != true)
	{
		booksList.deleteList();
	}

	cout << "Processing order..." << endl;
	wait(1000);
	cout << "Order complete!" << endl;
}