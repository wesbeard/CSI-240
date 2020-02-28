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

#include "games.h"

/*
	Pre: None
	Post: All class members set to default values
	Purpose: To reset all members to defaults
*/
Games::Games()
{
	mCount = 0;
	mGenre = "";
	mESRB = "";
	mDeveloper = "";
	mPlatform = "";
	mGamesTotal = 0;
}

/*
	Pre: None
	Post: Variables set equal to class member values
	Purpose: To set all variables to the value of the members
*/
Games::Games(int count, string barcode, string name, double price, int quantity, string genre, string esrb, string developer, string platform, double total)
{
	mCount = count;
	mBarcode = barcode;
	mName = name;
	mPrice = price;
	mQuantity = quantity;
	mGenre = genre;
	mESRB = esrb;
	mDeveloper = developer;
	mPlatform = platform;
	mGamesTotal = total;
}

/*
	Pre: None
	Post: Value of mCount returned
	Purpose: To return a members value
*/
int Games::getCount()
{
	return mCount;
}

/*
	Pre: None
	Post: Value of mDeveloper returned
	Purpose: To return a members value
*/
string Games::getDeveloper()
{
	return mDeveloper;
}

/*
	Pre: None
	Post: Value of mGenre returned
	Purpose: To return a members value
*/
string Games::getGenre()
{
	return mGenre;
}

/*
	Pre: None
	Post: Value of mESRB returned
	Purpose: To return a members value
*/
string Games::getESRB()
{
	return mESRB;
}

/*
	Pre: None
	Post: Value of mPlatform returned
	Purpose: To return a members value
*/
string Games::getPlatform()
{
	return mPlatform;
}

/*
	Pre: None
	Post: Value of mGames[i] returned
	Purpose: To return a members value
*/
Games Games::getGame(int gameNum)
{
	return mGames[gameNum];
}

/*
	Pre: None
	Post: Value of mGamesTotal returned
	Purpose: To return a members value
*/
double Games::getGamesTotal()
{
	return mGamesTotal;
}

/*
	Pre: None
	Post: Value of member variable mDeveloper set to the parameter developer
	Purpose: To change the members value
*/
void Games::setDeveloper(string developer)
{
	mDeveloper = developer;
}

/*
	Pre: None
	Post: Value of member variable mGenre set to the parameter genre
	Purpose: To change the members value
*/
void Games::setGenre(string genre)
{
	mGenre = genre;
}

/*
	Pre: None
	Post: Value of member variable mESRB set to the parameter esrb
	Purpose: To change the members value
*/
void Games::setESRB(string esrb)
{
	mESRB = esrb;
}

/*
	Pre: None
	Post: Value of member variable mPlatform set to the parameter platform
	Purpose: To change the members value
*/
void Games::setPlatform(string platform)
{
	mPlatform = platform;
}

/*
	Pre: None
	Post: Value of member variable mGames[i].mQuantity set to the parameter platform
	Purpose: To change the members value
*/
void Games::setGameQuantity(int gameNum, int quantity)
{
	mGames[gameNum].setQuantity(quantity);
}

/*
	Pre: None
	Post: Value of member variable mCount set to the parameter platform
	Purpose: To change the members value
*/
void Games::setCount(int count)
{
	mCount = count;
}

/*
	Pre: None
	Post: Value of member variable gameNum added to the current mGamesTotal variable
	Purpose: To change the members value
*/
void Games::setGamesTotal(int gameNum)
{
	mGamesTotal += mGames[gameNum].getPrice();
}

/*
	Pre: Called from managment menu
	Post: Game added to games array
	Purpose: To prompt the user for a games information and add it to the games array
*/
void Games::addGame()
{
	int  i;
	Games *tmp = new Games[mCount + 1];

	for (i = 0; i < mCount; i++)
	{
		tmp[i] = mGames[i];
	}

	delete[] mGames;

	cout << "Enter the following information for the new game..." << endl;
	cout << "Barcode: " << endl;
	cin.ignore(256, '\n');
	getline(cin, tmp[mCount].mBarcode);
	cout << "Quantity: " << endl;
	cin >> tmp[mCount].mQuantity;
	cout << "Price: " << endl;
	cin >> tmp[mCount].mPrice;
	cin.ignore(256, '\n');
	cout << "Title: " << endl;
	getline(cin, tmp[mCount].mName);
	cout << "Developer: " << endl;
	getline(cin, tmp[mCount].mDeveloper);
	cout << "Genre: " << endl;
	getline(cin, tmp[mCount].mGenre);
	cout << "ESRB: " << endl;
	cin >> tmp[mCount].mESRB;
	cin.ignore(256, '\n');
	cout << "Platform: " << endl;
	getline(cin, tmp[mCount].mPlatform);

	mGames = tmp;
	mCount++;
	storeGamesData();

	cout << "New game added!" << endl
		<< "Returning to menu..." << endl;
}

/*
	Pre: Function called
	Post: Game data is loaded from file
	Purpose: To update the games array data based on what's in the games file
*/
bool Games::loadGamesData()
{
	ifstream fin;
	fin.open(GAMES_DATA);

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

		mGames = new Games[mCount];

		for (int i = 0; i < mCount; i++)
		{
			fin >> mGames[i];
		}
		return true;
	}
}

/*
	Pre: Function called
	Post: Game data is stored in the file
	Purpose: To store the games array data back into the games file
*/
void Games::storeGamesData()
{
	ofstream fout;
	fout.open(GAMES_DATA);

	fout << mCount << endl;

	for (int i = 0; i < mCount; i++)
	{
		fout << mGames[i];
	}
	fout.close();
}

/*
	Pre: Called from managment menu
	Post: Game removed from the games array
	Purpose: To prompt the user for a games information and remove it from the games array
*/
void Games::removeGame(string barcode)
{
	Games game;
	Games *tempArray = new Games[mCount - 1];

	int j = 0;
	bool deleted = false;

	for (int i = 0; i < mCount; i++)
	{
		if (mGames[i].getBarcode() == barcode)
		{
			deleted = true;
			cout << "Game removed..." << endl
				<< "Returning to menu..." << endl;
		}
		else
		{
			tempArray[j] = mGames[i];
			j++;
		}
	}
	mCount--;
	delete[] mGames;
	mGames = tempArray;
	storeGamesData();
}

/*
	Pre: Called from managment menu
	Post: Game information is printed if found
	Purpose: To print out information in the games array if the item is found
*/
void Games::searchGame(string search)
{
	bool found = false;

	for (int i = 0; i < mCount; i++)
	{
		if (mGames[i].getBarcode() == search)
		{
			cout << "Game found..." << endl
				<< "Game information: " << endl;
			cout << mGames[i] << endl;
			system("pause");
			found = true;
		}
	}
	if (found == false)
	{
		cout << "Game not found..." << endl
			<< "Returning to menu..." << endl;
	}
}

/*
	Pre: Data file defined
	Post: Data loaded from data file
	Purpose: To import the games data from the specified data file
*/
istream& operator >> (istream& input, Games& obj)
{
	string trash;
	input >> obj.mBarcode >> obj.mQuantity >> obj.mPrice;
	getline(input, trash);
	getline(input, obj.mName);
	getline(input, obj.mDeveloper);
	getline(input, obj.mGenre);
	getline(input, obj.mESRB);
	getline(input, obj.mPlatform);
	
	return input;
}

/*
	Pre: Data file defined
	Post: Games data is printed to the screen
	Purpose: To display all current data to the user
*/
ostream& operator << (ostream& output, const Games& obj)
{
	output << obj.mBarcode << " " << obj.mQuantity << " " << obj.mPrice << endl;
	output << obj.mName << endl;
	output << obj.mDeveloper << endl;
	output << obj.mGenre << endl;
	output << obj.mESRB << endl;
	output << obj.mPlatform << endl;

	return output;
}