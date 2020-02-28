/*
Authors: Wes Beard & Louis Vinton
Class: CSI240 Advanced Programming
Assignment: Final Project
Date Assigned: 4/10/2019
Due Date: 4/26/2019
Description:
	A restaurant program that uses four different roles to manage tables, orders, and the menu. Each role can only access their own functions except for the manager
	which can access all of them. The program will run continuosly until a manager signs in and shuts down the system manually.
Certification of Authenticity:
	I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
	I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
		- Reproduce this assignment and provide a copy to another member of academic staff; and/or
		- Communicate a copy of this assignment to a plagiarism checking service
		(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include "MenuList.h"

/*
PRE: none
POST: initializes the Node
PURPOSE: default node constructor
AUTHOR: Louis Vinton
*/
MenuList::Node::Node()
{
	mData = Item();
	mNext = NULL;
}

/*
PRE: none
POST: initializes a Node with the given data 
PURPOSE: parameterized constructor
AUTHOR: Louis Vinton
*/
MenuList::Node::Node(Item data)
{
	mData = data;
	mNext = NULL;
}

/*
PRE: none
POST: initializes a menuList
PURPOSE: default constructor
AUTHOR: Louis Vinton
*/
MenuList::MenuList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}

/*
PRE: none
POST: creates a copy of the given menulist
PURPOSE: copy constructor for menuList
AUTHOR: Louis Vinton
*/
MenuList::MenuList(const MenuList& obj)
{
	Node* temp;
	Node* newList;

	mHead = NULL;
	mTail = NULL;
	mCount = 0;

	if (obj.mHead == NULL) {

	}
	else
	{
		mHead = new Node(obj.mHead->mData);
		temp = obj.mHead;
		newList = mHead;

		while (temp->mNext != NULL)
		{
			newList->mNext = new Node(temp->mNext->mData);
			temp = temp->mNext;
			newList = newList->mNext;
			mCount++;
		}
	}
}

/*
PRE: an initialized menuList
POST: menuList is deleted
PURPOSE: deconstructor
AUTHOR: Louis Vinton
*/
MenuList::~MenuList()
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
PRE: an initialized menuList
POST: returns mCount
PURPOSE: gets the count of the list
AUTHOR: Louis Vinton
*/
int  MenuList::getCount()
{
	return mCount;
}

/*
PRE: an initialized menuList
POST: returns the data at the given index, returns a blank Item if index not found
PURPOSE: gets the data at a specific index
AUTHOR: Louis Vinton
*/
Item MenuList::getData(int index)
{
	int  i;
	Node *tmp;

	if (index < 0 || index >= mCount)
		return Item();
	else
	{
		tmp = mHead;
		for (i = 0; i < index; i++)
			tmp = tmp->mNext;

		return tmp->mData;
	}
}

/*
PRE: an initialized menuList
POST: modifes a node at the given index with the given data
PURPOSE: changes the data of a node
AUTHOR: Louis Vinton
*/
void MenuList::setData(int index, Item data)
{
	int  i;
	Node *tmp;

	if (index >= 0 && index < mCount)
	{
		tmp = mHead;
		for (i = 0; i < index; i++)
			tmp = tmp->mNext;

		tmp->mData = data;
	}
}

/*
PRE: an initialized menuList
POST: the list is printed to the console
PURPOSE: prints the list
AUTHOR: Louis Vinton
*/
void MenuList::display()
{
	Node *tmp;
	int i = 1;

	if (mHead == NULL)
	{
		cout << "The menu is empty\n";
		return;
	}

	tmp = mHead;
	while (tmp != NULL)
	{
		cout << "[" << i << "] "<< tmp->mData;
		tmp = tmp->mNext;
		i++;
	}
	cout << endl;
}

/*
PRE: an initialized menuList
POST: data is added to the end of the list
PURPOSE: adds Items to the list
AUTHOR: Louis Vinton
*/
bool MenuList::insert(Item data)
{
	Node *newNode;

	newNode = new Node(data);

	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		mTail->mNext = newNode;
		mTail = newNode;
		mTail->mNext = NULL;
	}
	mCount++;
	return true;
}

/*
PRE: an initialized menu
POST: returns true if empty, false if not
PURPOSE: returns whether hte list is empty
AUTHOR: Louis Vinton
*/
bool MenuList::isEmpty()
{
	return mCount == 0;
}

/*
PRE: an initialized menuList
POST: returns true if a node is found with the give searchkey
PURPOSE: determines if an Item exists
AUTHOR: Louis Vinton
*/
bool MenuList::isExist(string searchKey)
{
	Node *tempNode;

	tempNode = mHead;

	while (tempNode != NULL)
	{
		if (tempNode->mData.getName() == searchKey)
			return true;
		else
			tempNode = tempNode->mNext;
	}

	return false;
}

/*
PRE: an initialized menuList
POST: removes a node from the list, returns true if deleted succesfully
PURPOSE: deletes a node
AUTHOR: Louis Vinton
*/
bool MenuList::remove(string searchKey)
{
	Node *oneBefore, *toBeDeleted;
	bool deleted = false;

	toBeDeleted = mHead;
	oneBefore = mHead;
	while (toBeDeleted != NULL && !(toBeDeleted->mData.getName() == searchKey))
	{
		oneBefore = toBeDeleted;
		toBeDeleted = toBeDeleted->mNext;
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

		delete toBeDeleted;

		mCount--;

		deleted = true;
	}

	return deleted;
}

/*
PRE: an initialized menuList
POST: list is populated with data from the file
PURPOSE: loads data from file
AUTHOR: Louis Vinton
*/
void MenuList::loadData()
{
	int numItems;
	int i;
	string trash;
	Item tempItem;

	ifstream fin;
	fin.open(MENU_FILE);
	
	fin >> numItems;
	getline(fin, trash);

	for (i = 0; i < numItems; i++)
	{
		fin >> tempItem;
		insert(tempItem);
	}
}