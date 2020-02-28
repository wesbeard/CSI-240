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



#ifndef BOOK_H
#define BOOK_H

#include "item.h"
const string BOOK_DATA = "books.dat";

using namespace std;

class Book : public Item
{
	private:
		string mAuthor, mGenre, mPublisher;
		int mYearPublished, mCount;
		Book *mBooks;
		double mBooksTotal;
	public:
		Book();
		Book(int count, string barcode, string name, double price, int quantity, string genre, string author, string publisher, int year, double total);

		//accessors
		int getCount();
		string getAuthor();
		string getGenre();
		string getPublisher();
		int getYearPublished();
		Book getBook(int bookNum);
		double getBooksTotal();

		//mutators
		void setAuthor(string);
		void setGenre(string);
		void setPublisher(string);
		void setYearPublished(int);
		void setBooksTotal(int bookNum);

		//array functions
		bool loadBooksData();
		void storeBooksData();
		void addBook();
		void removeBook(string isbn);
		void searchBook(string search);

		//operators
		friend istream& operator>>(istream&, Book&);
		friend ostream& operator<<(ostream&, const Book&);
};

#endif