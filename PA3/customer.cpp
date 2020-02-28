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

#include "customer.h"

/*
	Pre: None
	Post: All class members set to default values
	Purpose: To reset all members to defaults
*/
Customer::Customer()
{
	mCount = 0;
	mAccounts = NULL;
	mDataFile = "";
}

/*
	Pre: None
	Post: Account objects copied
	Purpose: Copies information from account objects
*/
Customer::Customer(Customer &obj)
{
	mCount = obj.mCount;
	mAccounts = new Account[mCount];
	mDataFile = obj.mDataFile;

	for (int i = 0; i < mCount; i++)
	{
		mAccounts[i] = obj.mAccounts[i];
	}
}

/*
	Pre: None
	Post: Class destructed and members set to default values
	Purpose: To destruct the class
*/
Customer::~Customer()
{
	if (mCount != 0)
	{
		delete[] mAccounts;
	}
	mCount = 0;
	mAccounts = NULL;
	mDataFile = "";
}

/*
	Pre: None
	Post: Value of member Count returned
	Purpose: To return the private variable mCount
*/
int Customer::getCount()
{
	return mCount;
}

/*
	Pre: None
	Post: Value of array mAccounts returned if matching to an account number
	Purpose: To return the private array mAccounts
*/
Account Customer::getCustomer(string accountNumber) 
{
	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i] == accountNumber)
		{
			return mAccounts[i];
		}
	}
	return Account();
}

/*
	Pre: None
	Post: Value of array mAccounts returned if matching to a name
	Purpose: To return the private array mAccounts
*/
Account Customer::getCustomerName(string name)
{
	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i].getName() == name)
		{
			return mAccounts[i];
		}
	}
	return Account();
}

/*
	Pre: None
	Post: Value of array mAccounts returned if matching to an ssn
	Purpose: To return the private array mAccounts
*/
Account Customer::getCustomerSSN(string ssn)
{
	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i].getSSN() == ssn)
		{
			return mAccounts[i];
		}
	}
	return Account();
}

/*
	Pre: None
	Post: Value of array mAccounts returned if matching to an address
	Purpose: To return the private array mAccounts
*/
Account Customer::getCustomerAddress(string address)
{
	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i].getAddress() == address)
		{
			return mAccounts[i];
		}
	}
	return Account();
}

/*
	Pre: None
	Post: Value of array mAccounts returned if matching to a phone number
	Purpose: To return the private array mAccounts
*/
Account Customer::getCustomerPhone(string phone)
{
	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i].getPhoneNumber() == phone)
		{
			return mAccounts[i];
		}
	}
	return Account();
}

/*
	Pre: None
	Post: Value of member DataFile returned
	Purpose: To return the private variable mDataFile
*/
string Customer::getFilename()
{
	return mDataFile;
}

/*
	Pre: None
	Post: Value of member DataFile set to parameter fileName
	Purpose: To set the private member variable to the parameter
*/
void Customer::setFilename(string fileName)
{
	mDataFile = fileName;
}

/*
	Pre: None
	Post: Returns false or true if the file is opened and reads data in from file if true
	Purpose: To read the data in from the data file
*/
bool Customer::loadData()
{
	ifstream fin;
	fin.open(mDataFile);

	if (fin.fail())
	{
		return false;
	}

	else
	{
		string trash;

		fin >> mCount;
		getline(fin, trash);

		mAccounts = new Account[mCount];

		for (int i = 0; i < mCount; i++)
		{
			fin >> mAccounts[i];
		}
		return true;
	}
}

/*
	Pre: Function called
	Post: New account object is added
	Purpose: To promt the user for data entry and add a new account object with that data
*/
void Customer::addNew()
{
	Account account;
	Account *tempArray = new Account[mCount + 1];
	cin >> account;

	for (int i = 0; i < mCount; i++)
	{
		tempArray[i] = mAccounts[i];
	}
	
	tempArray[mCount] = account;

	mCount++;

	delete[] mAccounts;

	mAccounts = tempArray;
}

/*
	Pre: Function called
	Post: New account object is added
	Purpose: To promt the user for data entry and add a new account object with that data
*/
void Customer::addNew(Account account)
{
	Account *tempArray = new Account[mCount + 1];

	for (int i = 0; i < mCount; i++)
	{
		tempArray[i] = mAccounts[i];
	}

	tempArray[mCount] = account;

	mCount++;

	delete[] mAccounts;

	mAccounts = tempArray;
}

/*
	Pre: Function called
	Post: Existing account deleted
	Purpose: To delete the account provided based on the account number
*/
void Customer::removeAccount(string accountNumber)
{
	Account account;
	Account *tempArray = new Account[mCount - 1];
	//cin >> account;
	
	int j = 0;
	bool deleted = false;

	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i].getAccountNumber() == accountNumber)
		{
			deleted = true;
		}
		else
		{
			tempArray[j] = mAccounts[i];
			//j++;
		}
	}

	mCount--;

	delete[] mAccounts;

	mAccounts = tempArray;
}

/*
	Pre: None
	Post: Outputs database variables from the mAccounts array back into the data file
	Purpose: To store current data in the data file where it is saved
*/
void Customer::storeData()
{
	ofstream fout;
	fout.open(mDataFile, ios::trunc);

	fout << mCount << endl;

	for (int i = 0; i < mCount; i++)
	{
		fout << mAccounts[i];
	}
}