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

#ifndef PA3
#define PA3

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include "customer.h"
#include "teller.h"



using namespace std;

const string ACCOUNTS_FILE = "accounts.dat";
const string TELLERS_FILE = "tellers.dat";

//Common Functions
void clearScreen();

void systemPause();

void wait(int time);

void displayLogo();

void displayMessage(int errorCode);

int mainMenu();

//Teller Operations
bool getIdPassword(string &id, string &password);

bool login();

//Customer Operations

string getAccountNumber(Customer customer);

void checkBalance(Customer customer, string accountNumber);

double getAmount(string message);

void deposit(Customer &customer, string accountNumber);

void withdrawal(Customer &customer, string accountNumber);

void addAccount(Customer &customer);

void deleteAccount(Customer &customer, string accountNumber);

void searchAccount(Customer &customer);

void updateAccount(Customer &customer);

void numSearch(Customer &customer);

void nameSearch(Customer &customer);

void ssnSearch(Customer &customer);

void addressSearch(Customer &customer);

void phoneSearch(Customer &customer);

void updateNum(Customer &customer, string accountNumber);

void updateName(Customer &customer, string accountNumber);

void updateSSN(Customer &customer, string accountNumber);

void updateAddress(Customer &customer, string accountNumber);

void updatePhone(Customer &customer, string accountNumber);

#endif