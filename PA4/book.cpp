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


#include "book.h"

/*
	Pre: None
	Post: All class members set to default values
	Purpose: To reset all members to defaults
*/
Book::Book()
{
	mCount = 0;
	mAuthor = "";
	mGenre = "";
	mPublisher = "";
	mYearPublished = 0;
	mBooksTotal = 0;
}

/*
	Pre: None
	Post: Variables set equal to class member values
	Purpose: To set all variables to the value of the members
*/
Book::Book(int count, string barcode, string name, double price, int quantity, string genre, string author, string publisher, int year, double total)
{
	mCount = count;
	mBarcode = barcode;
	mName = name;
	mPrice = price;
	mQuantity = quantity;
	mGenre = genre;
	mAuthor = author;
	mPublisher = publisher;
	mYearPublished = year;
	mBooksTotal = total;
}

/*
	Pre: None
	Post: Value of member variable returned
	Purpose: To return a members value
*/
int Book::getCount()
{
	return mCount;
}
string Book::getAuthor()
{
	return mAuthor;
}
string Book::getGenre()
{
	return mGenre;
}
string Book::getPublisher()
{
	return mPublisher;
}
int Book::getYearPublished()
{
	return mYearPublished;
}
Book Book::getBook(int bookNum)
{
	return mBooks[bookNum];
}
double Book::getBooksTotal()
{
	return mBooksTotal;
}

/*
	Pre: None
	Post: Value of member variable mDeveloper set to provided parameter
	Purpose: To change the members value
*/
void Book::setAuthor(string author)
{
	mAuthor = author;
}
void Book::setGenre(string genre)
{
	mGenre = genre;
}
void Book::setPublisher(string publisher)
{
	mPublisher = publisher;
}
void Book::setYearPublished(int year)
{
	mYearPublished = year;
}
void Book::setBooksTotal(int booksNum)
{
	mBooksTotal += mBooks[booksNum].getPrice();
}

/*
	Pre: Function called
	Post: Books data is loaded from file
	Purpose: To update the books array data based on what's in the books file
*/
bool Book::loadBooksData()
{
	ifstream fin;
	fin.open(BOOK_DATA);

	if (fin.fail())
	{
		cout << "Could not load file";
		return false;
	}

	else
	{
		string trash;

		fin >> mCount;
		getline(fin, trash);

		mBooks = new Book[mCount];

		for (int i = 0; i < mCount; i++)
		{
			fin >> mBooks[i];
		}
		return true;
	}
}

/*
	Pre: Function called
	Post: Bookd data is stored in the file
	Purpose: To store the books array data back into the books file
*/
void Book::storeBooksData()
{
	ofstream fout;
	fout.open(BOOK_DATA);

	fout << mCount << endl;

	for (int i = 0; i < mCount; i++)
	{
		fout << mBooks[i];
	}
	fout.close();
}

/*
	Pre: Called from managment menu
	Post: Book added to books array
	Purpose: To prompt the user for a books information and add it to the books array
*/
void Book::addBook()
{
	int  i;
	Book *tmp = new Book[mCount + 1];

	for (i = 0; i < mCount; i++)
	{
		tmp[i] = mBooks[i];
	}

	delete[] mBooks;

	cout << "Enter the following information for the new book..." << endl;
	cout << "ISBN: " << endl;
	cin.ignore(256, '\n');
	getline(cin, tmp[mCount].mBarcode);
	cout << "Quantity: " << endl;
	cin >> tmp[mCount].mQuantity;
	cout << "Price: " << endl;
	cin >> tmp[mCount].mPrice;
	cin.ignore(256, '\n');
	cout << "Title: " << endl;
	getline(cin, tmp[mCount].mName);
	cout << "Author: " << endl;
	getline(cin, tmp[mCount].mAuthor);
	cout << "Genre: " << endl;
	getline(cin, tmp[mCount].mGenre);
	cout << "Publisher: " << endl;
	getline(cin, tmp[mCount].mPublisher);
	cout << "Year published: " << endl;
	cin >> tmp[mCount].mYearPublished;

	mBooks = tmp;
	mCount++;
	storeBooksData();

	cout << "Book added!" << endl
		<< "Returning to menu..." << endl;
}

/*
	Pre: Called from managment menu
	Post: Book removed from the books array
	Purpose: To prompt the user for a books information and remove it from the books array
*/
void Book::removeBook(string isbn)
{
	Book book;
	Book *tempArray = new Book[mCount - 1];

	int j = 0;

	for (int i = 0; i < mCount; i++)
	{
		if (mBooks[i].getBarcode() == isbn)
		{
			cout << "Book removed..." << endl
				<< "Returning to menu..." << endl;
		}
		else
		{
			tempArray[j] = mBooks[i];
			j++;
		}
	}

	mCount--;
	delete[] mBooks;
	mBooks = tempArray;
	storeBooksData();
}

/*
	Pre: Called from managment menu
	Post: Book information is printed if found
	Purpose: To print out information in the books array if the item is found
*/
void Book::searchBook(string search)
{
	bool found = false;

	for (int i = 0; i < mCount; i++)
	{
		if (mBooks[i].getBarcode() == search)
		{
			cout << "Book found..." << endl
				<< "Book information: " << endl;
			cout << mBooks[i] << endl;
			system("pause");
			found = true;
		}
	}
	if (found == false)
	{
		cout << "Book not found..." << endl
			<< "Returning to menu..." << endl;
	}
}

/*
	Pre: Data file defined
	Post: Data loaded from data file
	Purpose: To import the books data from the specified data file
*/
istream& operator >> (istream& input, Book& obj)
{
	string garbage;
	input >> obj.mBarcode >> obj.mQuantity >> obj.mPrice;
	getline(input, garbage);
	getline(input, obj.mName);
	getline(input, obj.mAuthor);
	getline(input, obj.mGenre);
	input >> obj.mYearPublished;
	getline(input, garbage);
	getline(input, obj.mPublisher);

	return input;
}

/*
	Pre: Data file defined
	Post: Games data is printed to the screen
	Purpose: To display all current data to the user
*/
ostream& operator << (ostream& output, const Book& obj)
{
	output << obj.mBarcode << " " << obj.mQuantity << " " << obj.mPrice << endl;
	output << obj.mName << endl;
	output << obj.mAuthor << endl;
	output << obj.mGenre << endl;
	output << obj.mYearPublished << endl;
	output << obj.mPublisher << endl;

	return output;
}