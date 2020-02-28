#include "LL-games.h"
#include "LL-books.h"

//int main()
//{
//	GamesLinkedList gamesList;
//	BooksLinkedList booksList;
//	Games game;
//	Book book;
//	string toDelete;
//	Games toInsert;
//	int i;
//	ifstream fin;
//
//	//Tests the games operations
//	cout << "=== GAMES ===" << endl;
//	fin.open(GAMES_DATA);
//
//	//Creates a linked list with the data from game
//	for (i = 1; i <= 2; i++)
//	{
//		fin >> game;
//		gamesList.insert(game);
//	}
//
//	//Displays the current list
//	cout << "Current Linked List :" << endl;
//	gamesList.display();
//
//	//Deletes a selected game from the list
//	cout << "Enter the barcode of a game in the list to remove: " << endl;
//	getline(cin, toDelete);
//	gamesList.remove(toDelete);
//	cout << "Current Linked List :" << endl;
//	gamesList.display();
//	cout << endl;
//	fin.close();
//
//	//Tests the books operations
//	cout << "=== BOOKS ===" << endl;
//	fin.open(BOOK_DATA);
//
//	//Creates a linked list with the data from game
//	for (i = 1; i <= 2; i++)
//	{
//		fin >> book;
//		booksList.insert(book);
//	}
//
//	//Displays the current list
//	cout << "Current Linked List :" << endl;
//	booksList.display();
//
//	//Deletes a selected game from the list
//	cout << "Enter the ISBN of a book in the list to remove: " << endl;
//	getline(cin, toDelete);
//	booksList.remove(toDelete);
//	cout << "Current Linked List :" << endl;
//	booksList.display();
//	cout << endl;
//
//	system("pause");
//}