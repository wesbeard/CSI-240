/*Author: Wes Beard
Class: CSI240 Advanced Programming
Assignment: PA3 Part 3
Date Assigned: 2/18/2019
Due Date: 3/8/2019
Description:
A banking program that allows a teller to manage multiple cutomer accounts.
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)*/
#include "teller.h"

/*
	Pre: None
	Post: All class members set to default values
	Purpose: To reset all members to defaults
*/
Teller::Teller()
{
	mCount = 0;
	mTellers = NULL;
}

/*
	Pre: None
	Post: Class destructed and members set to default values
	Purpose: To destruct the class
*/
Teller::~Teller()
{
	if (mCount != 0)
	{
		delete[] mTellers;
	}
	mCount = 0;
	mTellers = NULL;
}

/*
	Pre: None
	Post: Returns false or true if the file is opened and reads data in from file if true
	Purpose: To read the data in from the data file
*/
bool Teller::loadData(string fileName)
{
	ifstream fin;
	fin.open(fileName);

	if (fin.fail())
	{
		return false;
	}

	else
	{
		string trash;

		fin >> mCount;
		getline(fin, trash);

		Employee *mTellers = new Employee[mCount];

		for (int i = 0; i < mCount; i++)
		{
			fin >> mTellers[i].mID;
			fin >> mTellers[i].mPassword;
		}
		return true;
	}
}

/*
	Pre: None
	Post: Outputs database variables from the mAccounts array back into the data file
	Purpose: To store current data in the data file where it is saved
*/
void Teller::storeData(string fileName)
{
	ofstream fout;
	fout.open(fileName, ios::trunc);

	fout << mCount << endl;

	for (int i = 0; i < mCount; i++)
	{
		fout << mTellers[i].mID << " " << mTellers[i].mPassword << endl;
	}
}

/*
	Pre: None
	Post: True or false returned based on if the id and password matched
	Purpose: To verfy that matching id and password were provided
*/
bool Teller::verifyTeller(const string& id, const string& password)
{
	for (int i = 0; i < mCount; i++)
	{
		if (id == mTellers[i].mID && password == mTellers[i].mPassword)
		{
		return true;
		break;
		}
	}
	return false;
}