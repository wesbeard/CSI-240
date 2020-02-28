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

#include "employee.h"
#include "final.h"

/*
Pre: None
Post: Member Variables are initialized and uninitialized
Purpose: To initialize and uninitialize member variables
Author: Wes Beard
*/
Employee::Employee()
{
	mStaff = NULL;
	mCount = 0;
	mID = "";
	mPassword = "";
	mPosition = ' ';
}
Employee::Employee(Employee *staff, int count, string id, string password, char position)
{
	mStaff = staff;
	mCount = count;
	mID = id;
	mPassword = password;
	mPosition = position;
}
Employee::~Employee()
{
	if (mCount != 0)
	{
		delete[] mStaff;
	}
	mCount = 0;
	mCount = 0;
	mStaff = NULL;
	mPosition = ' ';
}

/*
Pre: None
Post: Requested member variable is returned
Purpose: To return the private member variables
Author: Wes Beard
*/
int Employee::getCount()
{
	return mCount;
}
string Employee::getID()
{
	return mID;
}
string Employee::getPassword()
{
	return mPassword;
}
char Employee::getPosition()
{
	return mPosition;
}

/*
PRE: an initialized employee object
POST: returns mStaff[index] if found, returns a blank Employee if index is out of bounds
PURPOSE: gets an employee
AUTHOR: Louis Vinton
*/
Employee Employee::getEmployee(int index)
{
	if (index < mCount && index >= 0)
		return mStaff[index];
	else
		return Employee();
}

/*
Pre: None
Post: Member variables are set to parameters
Purpose: To set private member variables to speicfied value
Author: Wes Beard
*/
void Employee::setCount(int count)
{
	mCount = count;
}
void Employee::setID(string id)
{
	mID = id;
}
void Employee::setPassword(string password)
{
	mPassword = password;
}
void Employee::setPosition(char position)
{
	mPosition = position;
}

/*
Pre: None
Post: Returns false or true if the file is opened and reads data in from file if true
Purpose: To read the data in from the data file
Author: Wes Beard
*/
bool Employee::loadEmployeeData()
{
	ifstream fin;
	fin.open(EMPLOYEES_FILE);

	if (fin.fail())
	{
		cout << "Employees file not found..." << endl;
		return false;
	}

	else
	{
		string trash;

		fin >> mCount;
		getline(fin, trash);

		mStaff = new Employee[mCount];

		for (int i = 0; i < mCount; i++)
		{
			getline(fin, mStaff[i].mName);
			getline(fin, mStaff[i].mID);
			getline(fin, mStaff[i].mPassword);
			fin >> mStaff[i].mPosition;
			getline(fin, trash);
		}
		return true;
	}
}

/*
Pre: None
Post: Outputs database variables back into the data file
Purpose: To store current data in the data file where it is saved
Author: Wes Beard
*/
void Employee::storeEmployeeData()
{
	ofstream fout;
	fout.open(EMPLOYEES_FILE, ios::trunc);

	fout << mCount << endl;

	for (int i = 0; i < mCount; i++)
	{
		fout << mStaff[i].mName << endl;
		fout << mStaff[i].mID << endl;
		fout << mStaff[i].mPassword << endl;
		fout << mStaff[i].mPosition << endl;
	}
}

/*
Pre: None
Post: True or false returned based on if the id and password matched
Purpose: To verfy that matching id and password were provided
Author: Wes Beard
*/
bool Employee::verifyEmployee(const string& id, const string& password)
{
	for (int i = 0; i < mCount; i++)
	{
		if (id == mStaff[i].mID && password == mStaff[i].mPassword)
		{
			return true;
			break;
		}
	}
	return false;
}

/*
Pre: Function called in the manager menu
Post: Selected employee is removed from the staff
Purpose: To display all staff and remove the selected staff member
Author: Wes Beard
*/
void Employee::fireEmployee()
{
	Employee* tempArray = new Employee[mCount - 1];
	string fireName;
	int i;
	int j = 0;
	bool deleted = false;

	cout << endl;
	cout << "Employees: " << endl;
	for (i = 0; i < mCount; i++)
	{
		cout << i + 1 << ". "<< mStaff[i].mName << endl;
	}
	cout << "Enter an employee name to fire or [exit]: " << endl;
	getline(cin, fireName);

	if (fireName == "exit")
	{
		cout << "Exiting..." << endl;
	}
	else
	{
		for (i = 0; i < mCount; i++)
		{
			if (mStaff[i].getName() == fireName)
			{
				deleted = true;
				cout << "Employee fired..." << endl
					<< "Returning to menu..." << endl;
			}
			else
			{
				tempArray[j] = mStaff[i];
				j++;
			}
		}
	}

	if (deleted == false && fireName != "exit")
	{
		cout << "Name not found..." << endl;
	}
	if (deleted == true)
	{
		mCount--;
		delete[] mStaff;
		mStaff = tempArray;
		storeEmployeeData();
	}
}

/*
Pre: Function called in the manager menu
Post: New employee with entered information added
Purpose: To add a new employee based on the prompted information
Author: Wes Beard
*/
void Employee::hireEmployee()
{
	int  i;
	string trash;
	Employee* tmp = new Employee[mCount + 1];

	cout << endl;
	for (i = 0; i < mCount; i++)
	{
		tmp[i] = mStaff[i];
	}

	delete[] mStaff;

	cout << "Enter the following information for the new hire..." << endl;
	cout << "Name: ";
	getline(cin, tmp[mCount].mName);
	cout << "ID: ";
	getline(cin, tmp[mCount].mID);
	cout << "Password: ";
	getline(cin, tmp[mCount].mPassword);
	cout << "Position (H/W/K/M): ";
	cin >> tmp[mCount].mPosition;
	getline(cin, trash);

	mStaff = tmp;
	mCount++;
	storeEmployeeData();

	cout << "New employee hired!" << endl
		<< "Returning to menu..." << endl;
}

/*
Pre: Function called in the manager menu
Post: Employee information is updated based on entered information
Purpose: To update the selected employees information
Author: Wes Beard
*/
void Employee::updateEmployeeInfo()
{
	int i;
	bool changed = false;
	string changeName;
	string newName;
	string newPass;
	string newID;
	char newPos;
	
	cout << endl;
	cout << "Employees: " << endl;
	for (i = 0; i < mCount; i++)
	{
		cout << i + 1 << ": " << mStaff[i].mName << endl;
	}
	cout << "Enter an employee name to change info or [exit]: " << endl;
	cin.ignore(256, '\n');
	getline(cin, changeName);

	for (i = 0; i < mCount; i++)
	{
		if (mStaff[i].getName() == changeName)
		{
			changed = true;
			cout << "What would you like to change?" << endl
				<< "[1] Name" << endl
				<< "[2] ID" << endl
				<< "[3] Password" << endl
				<< "[4] Position" << endl
				<< "[5] Exit" << endl;

			switch (getSelection(5))
			{
			case 1:
				cout << "Enter a new name: ";
				cin.ignore(256, '\n');
				getline(cin, newName);
				mStaff[i].mName = newName;
				cout << "Name changed..." << endl;
				break;
			case 2:
				cout << "Enter a new ID: ";
				cin.ignore(256, '\n');
				getline(cin, newID);
				mStaff[i].mID = newID;
				cout << "ID changed..." << endl;
				break;
			case 3:
				cout << "Enter a new password: ";
				cin.ignore(256, '\n');
				getline(cin, newPass);
				mStaff[i].mPassword = newPass;
				cout << "Password changed..." << endl;
				break;
			case 4:
				cout << "Enter a new position: ";
				cin >> newPos;
				mStaff[i].mPosition = newPos;
				cout << "Position changed..." << endl;
				break;
			case 5:
				cout << "No information changed..." << endl;
				break;
			}
		}
		else if (changeName == "exit")
		{
			cout << "Exiting..." << endl;
			break;
		}
	}
	if (changed == false && changeName != "exit")
	{
		cout << "Name not found..." << endl;
	}
	storeEmployeeData();
}

/*
Pre: Function called in the manager menu
Post: Searched employees information is printed if found
Purpose: To check for an employee and display all information
Author: Wes Beard
*/
void Employee::searchEmployee()
{
	string searchName;
	int i;
	bool found = false;

	cout << endl;
	cout << "Enter an employee name to search for: ";
	cin.ignore(256, '\n');
	getline(cin, searchName);

	for (i = 0; i < mCount; i++)
	{
		if (mStaff[i].mName == searchName)
		{
			found = true;
			cout << "Employee found..." << endl;
			cout << "Name: " << mStaff[i].mName << endl;
			cout << "ID: " << mStaff[i].mID << endl;
			cout << "Password: " << mStaff[i].mPassword << endl;
			cout << "Position: " << mStaff[i].mPosition << endl;
			pause();
			cout << "Returning to menu..." << endl;
			break;
		}
	}
	if (found == false)
	{
		cout << "Employee not found..." << endl;
	}
}

/*
Pre: Function called in the manager menu
Post: Report generated and printed to specified file
Purpose: To create a daily report based on orders info and print it to the report file
Author: Wes Beard & Louis Vinton
*/
void Employee::generateReport(double dailyTotal, int dailyOrders)
{
	string date;
	ofstream fout;
	fout.open(REPORT_FILE, ios::app);

	cout << endl;
	cout << "Enter todays date: ";
	cin.ignore(256, '\n');
	getline(cin, date);

	fout << date << endl;
	fout << "====" << endl;
	fout << "Total sales: $" << fixed << setprecision(2) << dailyTotal << endl;
	fout << "# of orders: " << dailyOrders << endl;
	fout << "Average amount per order: $" << fixed << setprecision(2) << (dailyTotal / dailyOrders) << endl;
	fout << endl;

	cout << "Printing report..." << endl;
	wait(1000);
	cout << "Report printed..." << endl;
	fout.close();
}