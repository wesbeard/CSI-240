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

#include "account.h"

/*
	Pre: None
	Post: All class members set to default values
	Purpose: To reset all members to defaults
*/
Account::Account()
{
	mAccountNum = "";
	mSSN = "";
	mName = "";
	mAddress = "";
	mPhoneNum = "";
	mSavings = 0;
	mChecking = 0;
	mTotal = 0;
}

/*
	Pre: None
	Post: Variables set equal to class member values
	Purpose: To set all variables to the value of the members
*/
Account::Account(string accountnum, string ssn, string name, string address, string phonenum, double savings, double checking, double total)
{
	mAccountNum = accountnum;
	mSSN = ssn;
	mName = name;
	mSavings = savings;
	mChecking = checking;
	mTotal = total;
}

/*
	Pre: None
	Post: Class destructed
	Purpose: To destruct the class
*/
Account::~Account()
{
}

/*
	Pre: None
	Post: Value of account number returned
	Purpose: To return a members value
*/
string Account::getAccountNumber()
{
	return mAccountNum;
}

/*
	Pre: None
	Post: Value address returned
	Purpose: To return a members value
*/
string Account::getAddress()
{
	return mAddress;
}

/*
	Pre: None
	Post: Value of phone number returned
	Purpose: To return a members value
*/
string Account::getPhoneNumber()
{
	return mPhoneNum;
}

/*
	Pre: None
	Post: Value of checking returned
	Purpose: To return a members value
*/
double Account::getChecking()
{
	return mChecking;
}

/*
	Pre: None
	Post: Value of name returned
	Purpose: To return a members value
*/

string Account::getName()
{
	return mName;
}

/*
	Pre: None
	Post: Value of savings returned
	Purpose: To return a members value
*/
double Account::getSavings()
{
	return mSavings;
}

/*
	Pre: None
	Post: Value of SSN returned
	Purpose: To return a members value
*/
string Account::getSSN()
{
	return mSSN;
}

/*
	Pre: None
	Post: Value of total returned
	Purpose: To return a members value
*/
double Account::getTotal()
{
	return mTotal;
}

/*
	Pre: None
	Post: Value of member set to the parameter accountNum
	Purpose: To change the members value
*/
void Account::setAccountNumber(string accountNum)
{
	mAccountNum = accountNum;
}

/*
	Pre: None
	Post: Value of member set to the parameter phoneNum
	Purpose: To change the members value
*/
void Account::setPhoneNumber(string phoneNum)
{
	mPhoneNum = phoneNum;
}

/*
	Pre: None
	Post: Value of member set to the parameter address
	Purpose: To change the members value
*/
void Account::setAddress(string address)
{
	mAddress = address;
}

/*
	Pre: None
	Post: Value of member set to the parameter checking
	Purpose: To change the members value
*/
void Account::setChecking(double checking)
{
	mChecking = checking;
	mTotal = checking + mSavings;
}

/*
	Pre: None
	Post: Value of member set to the parameter name
	Purpose: To change the members value
*/
void Account::setName(string name)
{
	mName = name;
}

/*
	Pre: None
	Post: Value of member set to the parameter savings
	Purpose: To change the members value
*/
void Account::setSavings(double savings)
{
	mSavings = savings;
	mTotal = savings + mChecking;
}

/*
	Pre: None
	Post: Value of member set to the parameter ssn
	Purpose: To change the members value
*/
void Account::setSSN(string ssn)
{
	mSSN = ssn;
}

/*
	Pre: None
	Post: Prints out if the statement was equal or unequal
	Purpose: To overload the == operator and check if the parameters are equivalent
*/
bool Account::operator == (const Account& rhs)
{
	if (mSSN == rhs.mAccountNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Pre: None
	Post: Prints out if the statement was equal or unequal
	Purpose: To overload the == operator and check if the parameters are equivalent
*/
bool Account::operator == (const string& rhs)
{
	if (mAccountNum == rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Pre: None
	Post: Prints out if the statement was equal or unequal
	Purpose: To overload the != operator and check if the parameters are equivalent
*/
bool Account::operator != (const Account& rhs)
{
	if (mSSN != rhs.mAccountNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Pre: None
	Post: Prints out if the statement was equal or unequal
	Purpose: To overload the != operator and check if the parameters are equivalent
*/
bool Account::operator != (const string& rhs)
{
	if (mAccountNum != rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Pre: None
	Post: Prints out if the statement was greater than the other or not
	Purpose: To overload the > operator and check if the parameters are greater than
*/
bool Account::operator > (const Account& rhs)
{
	if (mTotal > rhs.mTotal)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Pre: None
	Post: Prints out if the statement was less than the other or not
	Purpose: To overload the < operator and check if the parameters are less than
*/
bool Account::operator < (const Account& rhs)
{
	if (mTotal < rhs.mTotal)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Pre: None
	Post: Prints out the values of the members to the console when << is used
	Purpose: To overload the << operator and output the formatted data from the class to the console
*/
ostream& operator << (ostream& output, const Account& obj)
{
	output << "Account Number: " << obj.mAccountNum << endl;
	output << "SSN: " << obj.mSSN << endl;
	output << "Name: " << obj.mName << endl;
	output << "Address: " << obj.mAddress << endl;
	output << "Phone Number: " << obj.mPhoneNum << endl;
	output << "Savings: " << obj.mSavings << endl;
	output << "Checking: " << obj.mChecking << endl;

	return output;
}

/*
	Pre: None
	Post: Prints out the values of the members to the file when << is used
	Purpose: To overload the << operator and output the formatted data from the class to the file
*/
ofstream& operator << (ofstream& output, const Account& obj)
{
	ofstream fout;
	output <<  obj.mAccountNum << endl;
	output <<  obj.mSSN << endl;
	output <<  obj.mName << endl;
	output <<  obj.mAddress << endl;
	output <<  obj.mPhoneNum << endl;
	
	fout.open(obj.mAccountNum + ".sav");
	fout << setprecision(2) << fixed << obj.mSavings;
	fout.close();

	fout.open(obj.mAccountNum + ".chk");
	fout << setprecision(2) << fixed << obj.mChecking;
	fout.close();

	return output;
}

/*
	Pre: None
	Post: Inputs values for the members from the console
	Purpose: To overload the >> operator and input data from the console into the class
*/
istream& operator >> (istream& input, Account& obj)
{
	string trash;
	cout << "Enter an account number: ";
	getline(input, obj.mAccountNum);
	cout << "Enter an SSN: ";
	getline(input, obj.mSSN);
	cout << "Enter a name: ";
	getline(input, obj.mName);
	cout << "Enter an address: ";
	getline(input, obj.mAddress);
	cout << "Enter a phone number: ";
	getline(input, obj.mPhoneNum);
	cout << "Enter a savings amount: ";
	input >> obj.mSavings;
	cout << "Enter a checking amount: ";
	input >> obj.mChecking;
	getline(input, trash);

	return input;
}

/*
	Pre: None
	Post: Inputs values for the members from the console
	Purpose: To overload the >> operator and input data from the console into the class
*/
ifstream& operator >> (ifstream& input, Account& obj)
{
	ifstream fin;
	getline(input, obj.mAccountNum);
	getline(input, obj.mSSN);
	getline(input, obj.mName);
	getline(input, obj.mAddress);
	getline(input, obj.mPhoneNum);

	fin.open(obj.mAccountNum + ".sav");
	fin >> obj.mSavings;
	fin.close();

	fin.open(obj.mAccountNum + ".chk");
	fin >> obj.mChecking;
	fin.close();

	obj.mTotal = obj.mChecking + obj.mSavings;

	return input;
}

/*
	Pre: None
	Post: Prints out if the statement was equal or unequal
	Purpose: To overload the == operator and check if the parameters are equivalent
*/
bool operator == (const string& lhs, const Account& rhs)
{
	if (lhs == rhs.mSSN)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Pre: None
	Post: Prints out if the statement was equal or unequal
	Purpose: To overload the != operator and check if the parameters are equivalent
*/
bool operator != (const string& lhs, const Account& rhs)
{
	if (lhs != rhs.mSSN)
	{
		return true;
	}
	else
	{
		return false;
	}
}