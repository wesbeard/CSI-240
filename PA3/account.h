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

#ifndef ACCOUNT
#define ACCOUNT

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string DATA_FILE = "accounts.dat";

class Account
{
private:
	string mAccountNum;
	string mSSN;
	string mName;
	string mAddress;
	string mPhoneNum;
	double mSavings;
	double mChecking;
	double mTotal;
public:
	Account();
	Account(string accountnum, string ssn, string name, string address, string phonenum, double savings, double checking, double total);
	~Account();

	string getAccountNumber();
	string getAddress();
	string getPhoneNumber();
	double getChecking();
	string getName();
	double getSavings();
	string getSSN();
	double getTotal();

	void setAccountNumber(string accountNum);
	void setPhoneNumber(string phoneNum);
	void setAddress(string address);
	void setChecking(double checking);
	void setName(string name);
	void setSavings(double savings);
	void setSSN(string ssn);

	bool operator == (const Account& rhs);
	bool operator == (const string& rhs);
	bool operator != (const Account& rhs);
	bool operator != (const string& rhs);
	bool operator > (const Account& rhs);
	bool operator < (const Account& rhs);

	friend ostream& operator << (ostream&, const Account&);
	friend ofstream& operator << (ofstream&, const Account&);
	friend istream& operator >> (istream&, Account&);
	friend ifstream& operator >> (ifstream&, Account&);
	friend bool operator == (const string&, const Account& rhs);
	friend bool operator != (const string&, const Account& rhs);
};
#endif