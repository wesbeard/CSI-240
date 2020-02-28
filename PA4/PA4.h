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

#ifndef PA4
#define PA4

#include <windows.h>
#include <conio.h>
#include "teller.h"
#include "games.h"
#include "book.h"
#include "LL-games.h"
#include "LL-books.h"

using namespace std;

const string TELLERS_FILE = "tellers.dat";
const string ORDER_NUMBER = "order-number.dat";
const string ORDERS_FILE = "orders.dat";
const double TAX = .07;
 
//Common Functions
void clearScreen();

void systemPause();

void wait(int time);

void displayLogo();

void displayMessage(int errorCode);

int mainMenu();

void gameTransactionMenu(GamesLinkedList &gamesList, Games &games);

void bookTransactionMenu(BooksLinkedList &booksList, Book &books);

void managmentMenu(Games &games, Book &books);

//Teller Operations
bool getIdPassword(string &id, string &password);

bool login();

//Transaction Operations
void buyGame(GamesLinkedList &gamesList, Games game, Games &games, int gameNum);

void buyBook(BooksLinkedList &booksList, Book book, Book &books, int bookNum);

void manageTransaction(GamesLinkedList &gamesList, BooksLinkedList &booksList, Games &games, Book &books);

void checkOut(GamesLinkedList &gamesList, BooksLinkedList &booksList, Games &games, Book &books);

void printOrder(GamesLinkedList &gamesList, BooksLinkedList &booksList, Games &games, Book &books, double itemTotal, double taxTotal, double cashTotal);

//Stock Operations
void addNewItem(Games &games, Book &books);

void deleteExistingItem(Games &games, Book &books);

void searchItem(Games &games, Book &books);

void displayIventoryInfo(Games &games, Book &books);

#endif