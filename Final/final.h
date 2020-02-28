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

#ifndef FINAL
#define FINAL

#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include "MenuList.h"
#include "order.h"
#include "Table.h"
#include "employee.h"

using namespace std;

const double TAX = 0.11;
const int TOTAL_TABLES = 10;

//System operations
void wait(int time);
void clearScreen();
void pause();
int getSelection(int numSelection);
void printLogo();
void shutDown();
void tableSetUp(Table*& tables);

//Login operations
bool getIdPassword(Employee &employee);
bool login(Employee &employee);

//Menu Functions
void hostMenu(bool &loggedIn, Table* tables);
void waiterMenu(bool &loggedIn, MenuList menu, Table* tables, double& dailyTotal, int& dailyOrders);
void kitchenMenu(bool &loggedIn, MenuList& menu, Table* tables);
void managerMenu(bool &loggedIn, MenuList& menu, Table* tables, double& dailyTotal, int& dailyOrders);
void switchMenu(bool &loggedIn, MenuList menu, Table* tables, double& dailyTotal, int& dailyOrders);

//Host Functions
void findTable(Table* tables);
void makeAvailable(Table* tables);

//Waiter Fuinctions
void deleteFromOrder(Table* tables);
void generateBill(Table* tables, double& dailyTotal, int& dailyOrders);
void takeOrder(MenuList menu, Table* tables);

//Kitchen Functions
void addItem(MenuList& menu);
bool createMenu(MenuList& menu);
void completeOrder(Table* tables);
void deleteItem(MenuList& menu);
void modifyItem(MenuList& menu);
void modifyMenu(MenuList& menu);
void viewOrders(Table* tables);

//Manager functions located in employee.cpp

#endif