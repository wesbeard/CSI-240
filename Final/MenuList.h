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

#ifndef MENU_LIST
#define MENU_LIST

#include <string>
#include <iostream>
#include "item.h"

using namespace std;

const string MENU_FILE = "menu.dat";

class MenuList
{
	struct Node
	{
		Item mData;
		Node* mNext;

		Node();
		Node(Item data);
	};

private:
	Node *mHead, *mTail;
	int  mCount;

public:
	MenuList();
	MenuList(const MenuList& obj);
	~MenuList();
	int  getCount();
	Item getData(int index);
	void setData(int index, Item data);
	void display();
	bool insert(Item data);
	bool isEmpty();
	bool isExist(string searchKey);
	bool remove(string searchKey);
	void loadData();
};



#endif
