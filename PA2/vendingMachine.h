/*Author: Halfred Greenhand
Class: CSI240 Advanced Programming
Assignment: Programming Assignment 2
Date Assigned: 2/6/2019
Due Date: 2/13/2019
Description:
A vending machine program that outputs a menu with a selection of items to buy. Each item has a price and stock which can be changed and updated from a hidden manager menu (m).
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)*/

#ifndef VM_H
#define VM_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <windows.h>

using namespace std;

const int MAX_SIZE = 20;
const int MIN_SIZE = 6;
const double DEFAULT_MONEY = 5.00;
const int DEFAULT_STOCK = 20;
const double DEFAULT_PRICE = 1;
const string DEFAULT_PASSWORD = "password";
const string MACHINE_FILE = "data.txt";
const string DEFAULT_DRINKS[MIN_SIZE] = {"Nuka Cola Classic", "Nuka Cola Cherry", 
                                         "Nuka Cola Orange",  "Nuka Cola Wild",
                                         "Nuka Cola Victory", "Nuka Cola Quantum"};


struct Items
{
   string mName;
   int mStock;
   double mPrice;
};

class VendingMachine
{
   private:
      string mPassword;
      double mMoney;
      int mNumItems;
	  Items  mDrinks[MAX_SIZE];

   public:
      VendingMachine();
      ~VendingMachine();

	  void clearScreen();
      void displayMenu();
      void menu();
	  void moneyInput(int selection);
	  void vendDrink(double change, int vend);
	  void managerPassword();
	  void managerMenu();
	  void changePassword();
	  void machineInfo();
	  void collectMoney();
	  void restockItems();
	  void changePrice();
	  void addItem();
	  void removeItem();
	  void updateFile();
	  void shutdown();
};
#endif