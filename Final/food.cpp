#include "food.h"

/*
PRE: none
POST: initialized the Menu object
PURPOSE: default constructor
AUTHOR: Louis Vinton
*/
Menu::Menu()
{
	mFileName = "";
}

/*
PRE: none
POST: initalized the Menu with the given file name
PURPOSE: parameter constructro
AUTHOR: Louis Vinton
*/
Menu::Menu(string fileName)
{
	mFileName = fileName;
}

/*
PRE: an initialized Item and Food object
POST: inserts the Item to the end of the linke list
PURPOSE: adds an item to the menu
AUTHOR: Louis Vinton
*/
void Menu::addItem(Item newItem)
{
	mMenu.insert(newItem);
}

/*
PRE: an initialized Menu
POST: removes the item with the specified searchkey
PURPOSE: deletes an item
AUTHOR: Louis Vinton
*/
void Menu::deleteItem(string searchKey)
{
	mMenu.remove(searchKey);
}

/*
PRE: an initialized Menu
POST: modifies an item
PURPOSE: modifies an item
AUTHOR: Louis Vinton
*/
void Menu::modifyItem()
{
	//idk how you want to do this
}

/*
PRE: an initialized Menu
POST: returns the length of the menu
PURPOSE: gets the size of the menu
AUTHOR: Louis Vinton
*/
int Menu::getCount()
{
	return mMenu.getCount();
}

/*
PRE: an initialized Menu
POST: returns the Item at the index or the a blank Item if none it failed to find
PURPOSE: gets the Item at a specific index
AUTHOR: Louis Vinton
*/
Item Menu::getItem(int index)
{
	return mMenu.getData(index);
}

/*
PRE: an initialized Menu
POST: mFileName is set to the given name
PURPOSE: sets the file name used to load and save the menu
AUTHOR: Louis Vinton
*/
void Menu::setFileName(string fileName)
{
	mFileName = fileName;
}

/*
PRE: an initialized Menu, a file with the proper format
POST: a linkedlist is created with the data from the file
PURPOSE: loads data from a file
AUTHOR: Louis Vinton
*/
bool Menu::loadMenu()
{
	int numItems, i;
	string trash;
	Item tempItem;
	ifstream input;

	input.open(mFileName);

	if (!input.good())
		return false;

	input >> numItems;
	getline(input, trash);

	for (i = 0; i < numItems; i++)
	{
		input >> tempItem;
		mMenu.insert(tempItem);
	}
	
	return true;
}

/*
PRE: an initialized Menu
POST: saves data to a file, overwrites the previous one
PURPOSE: saves the data to a file
AUTHOR: Louis Vinton
*/
void Menu::saveMenu()
{
	int i;
	ofstream output;

	output.open(mFileName);

	output << mMenu.getCount();

	for (i = 0; i < mMenu.getCount(); i++)
	{
		output << mMenu.getData(i);
	}
}

/*
PRE: an initialized Menu
POST: prints out the list to the console
PURPOSE: displays the menu
AUTHOR: Louis Vinton
*/
void Menu::display()
{
	mMenu.display();
}