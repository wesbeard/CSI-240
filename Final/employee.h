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

#ifndef EMPLOYEE
#define EMPLOYEE

#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>
#include "person.h"

using namespace std;

const string EMPLOYEES_FILE = "employees.dat";
const string REPORT_FILE = "report.dat";

class Employee : public Person
{
	public:
		Employee * mStaff;
		int        mCount;
		string     mID;
		string     mPassword;
		char       mPosition;
	
		Employee();
		Employee(Employee *staff, int mCount, string id, string password, char position);
		~Employee();

		//Accessors
		int    getCount();
		Employee getEmployee(int index);
		string getID();
		string getPassword();
		char   getPosition();

		//Setters
		void   setCount(int count);
		void   setID(string id);
		void   setPassword(string password);
		void   setPosition(char position);

		//Data
		bool   loadEmployeeData();
		void   storeEmployeeData();
		bool   verifyEmployee(const string& id, const string& password);

		//Manager Functions
		void   fireEmployee();
		void   hireEmployee();
		void   updateEmployeeInfo();
		void   searchEmployee();
		void   generateReport(double dailyTotal, int dailyOrders);
};
#endif