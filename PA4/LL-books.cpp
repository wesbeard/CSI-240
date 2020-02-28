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


#include "LL-books.h"

/*
	Pre: None
	Post: All class members set to default values
	Purpose: To reset all members to defaults
*/
BooksLinkedList::Node::Node()
{
	mNext = NULL;
}

/*
	Pre: None
	Post: Variables set equal to class member values
	Purpose: To set all variables to the value of the members
*/
BooksLinkedList::Node::Node(Book book)
{
	mData = book;
	mNext = NULL;
}

/*
	Pre: None
	Post: All class members set to default values
	Purpose: To reset all members to defaults
*/
BooksLinkedList::BooksLinkedList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}

/*
	Pre: None
	Post: Value of mTitle returned
	Purpose: To return a members value
*/
BooksLinkedList::~BooksLinkedList()
{
	Node *toBeDeleted;

	toBeDeleted = mHead;

	while (mHead != NULL)
	{
		mHead = mHead->mNext;
		toBeDeleted->mNext = NULL;
		delete toBeDeleted;
		toBeDeleted = mHead;
	}

	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}

/*
	Pre: mCount has been initialized
	Post: Value of mCount returned
	Purpose: To return a members value
*/
int BooksLinkedList::getCount()
{
	return mCount;
}

/*
	Pre: Linked list created
	Post: Value of mCount returned
	Purpose: To display the contents of the linked list
*/
void BooksLinkedList::display()
{
	Node *tmp;

	if (mHead == NULL)
	{
		cout << "No books in shopping cart..." << endl;
	}
	else
	{
		tmp = mHead;
		while (tmp != NULL)
		{
			cout << tmp->mData << " ";
			tmp = tmp->mNext;
		}
	}
}

/*
	Pre: Function called
	Post: Books linked list is printed to the specified file
	Purpose: To print out the contents of the books list
*/
void BooksLinkedList::printFile(string filename)
{
	ofstream fout;
	fout.open(filename, ios::app);

	Node* tmp;

	tmp = mHead;
	while (tmp != NULL)
	{
		fout << tmp->mData << " " << endl;
		tmp = tmp->mNext;
	}
}

/*
	Pre: Linked list created
	Post: Item added to the linked list
	Purpose: To insert an item at the tail of a linked list
*/
bool BooksLinkedList::insert(Book bookData)
{
	Node *newNode;
	newNode = new Node(bookData);

	if (newNode == NULL)
	{
		return false;
	}
	if (mHead == NULL)
	{
		mHead = newNode;
	}
	else
	{
		mTail->mNext = newNode;
	}

	mTail = newNode;

	mCount++;
	return true;
}

/*
	Pre: Linked list created
	Post: Item added to the linked list
	Purpose: To insert an item at the head of a linked list
*/
bool BooksLinkedList::insertHead(Book bookData)
{
	Node *newNode;

	newNode = new Node(bookData);
	if (newNode == NULL)
	{
		return false;
	}
	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = mHead;
	}
	else
	{
		mHead = newNode;
		newNode->mNext = mHead;
		mCount++;
		return true;
	}
}

/*
	Pre: Linked list created
	Post: Returned if empty
	Purpose: To check if the linked list is currently empty or not
*/
bool BooksLinkedList::isEmpty()
{
	if (mCount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Pre: Linked list created
	Post: Returned if found
	Purpose: To check for a specific part of a linked list
*/
bool BooksLinkedList::isExist(string searchKey)
{
	bool found = false;
	Node *tmp;
	tmp = mHead;

	while (tmp != NULL && !found)
	{
		if (searchKey == tmp->mData)
			found = true;
		else
			tmp = tmp->mNext;
	}
	return found;
}

/*
	Pre: Linked list created
	Post: Item removed if it exists
	Purpose: To remove a specific item in a linked list according to a search key
*/
bool BooksLinkedList::remove(string searchKey)
{
	{
		Node *oneBefore, *toBeDeleted;
		bool deleted = false;
		toBeDeleted = mHead;
		oneBefore = mHead;
		while (toBeDeleted != NULL)
		{
			if (searchKey == toBeDeleted->mData)
			{
				break;
			}
			else
			{
				oneBefore = toBeDeleted;
				toBeDeleted = toBeDeleted->mNext;
			}
		}
		if (toBeDeleted != NULL)
		{
			if (toBeDeleted == mHead)
			{
				mHead = mHead->mNext;
				toBeDeleted->mNext = NULL;
				if (mHead == NULL)
					mTail = NULL;
			}
			else if (toBeDeleted == mTail)
			{
				oneBefore->mNext = NULL;
				mTail = oneBefore;
			}
			else
			{
				oneBefore->mNext = toBeDeleted->mNext;
				toBeDeleted->mNext = NULL;
			}
			cout << "Deleting book with barcode " << searchKey << "..." << endl;
			cout << endl;
			delete toBeDeleted;
			mCount--;
			deleted = true;
		}

		return deleted;
	}
}

/*
	Pre: Function called from cart managment
	Post: Linked list is deleted which clears the cart
	Purpose: To delete the current linked list
*/
void BooksLinkedList::deleteList()
{
	Node *current = mHead, *nextNode;
	bool deleted = false;

	while (current->mNext != NULL)
	{
		nextNode = current->mNext;
		free(current);
		current = nextNode;
		mCount--;
	}
	mHead = NULL;
}