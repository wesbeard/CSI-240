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

#ifndef GAMES
#define GAMES

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "item.h"

using namespace std;

const string GAMES_DATA = "games.dat";
const int MIN_BUFFER = 0;
const int BUFFER = 1;

class Games : public Item
{
	private:
		int mCount;
		Games *mGames;
		string mGenre;
		string mESRB;
		string mDeveloper;
		string mPlatform;
		double mGamesTotal;

	public:
		Games();
		Games(int count, string barcode, string name, double price, int quantity, string genre, string esrb, string developer, string platform, double total);

		int getCount();
		string getDeveloper();
		string getGenre();
		string getESRB();
		string getPlatform();
		Games getGame(int gameNum);
		double getGamesTotal();

		void setDeveloper(string developer);
		void setGenre(string genre);
		void setESRB(string esrb);
		void setPlatform(string platform);
		void setGameQuantity(int gameNum, int quantity);
		void setCount(int count);
		void setGamesTotal(int gameNum);
		
		void addGame();
		bool loadGamesData();
		void storeGamesData();
		void removeGame(string barcode);
		void searchGame(string search);
		

		friend istream& operator >> (istream& input, Games& obj);
		friend ostream& operator << (ostream& output, const Games& obj);
};
#endif