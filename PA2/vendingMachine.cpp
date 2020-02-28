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


#include "vendingMachine.h"

/*
   Pre: Class variables have been created and defined.
   Post: Data is imported from file or defaults are used if none is available.
   Purpose: To import data and construct the variables of the class.
*/
VendingMachine::VendingMachine()
{
   ifstream fin;
   string trash;

   fin.open(MACHINE_FILE);

  if (fin.fail())
   {
      mNumItems = MIN_SIZE;
      mMoney = DEFAULT_MONEY;
      mPassword = DEFAULT_PASSWORD;

      for (int i = 0; i <= mNumItems; i++)
      {
         mDrinks[i].mName = DEFAULT_DRINKS[i];
         mDrinks[i].mStock = DEFAULT_STOCK;
         mDrinks[i].mPrice = DEFAULT_PRICE;
      }
   }
   else
   {
      fin >> mNumItems;
      fin >> mMoney;
      fin >> mPassword;
      getline(fin, trash);

      for (int i = 0; i <= mNumItems; i++)
      {
         getline(fin, mDrinks[i].mName);
         fin >> mDrinks[i].mStock;
         fin >> mDrinks[i].mPrice;
         getline(fin, trash);
		 getline(fin, trash);
      }
   }
   fin.close();
}

/*
   Pre: Class variables have been created and defined
   Post: File is updated and class is destructed when program is exited
   Purpose: To destruct the class
*/
VendingMachine::~VendingMachine()
{
	ofstream fout;
	fout.open(MACHINE_FILE);
	
	fout <<  mNumItems << " " << mMoney << " " << mPassword << endl;
	
	for (int i = 0; i < mNumItems; i++)
	{
		fout << mDrinks[i].mName << endl;
		fout << mDrinks[i].mStock << " " << mDrinks[i].mPrice << endl
		<< ":" << endl;
	}
	fout.close();
}

/*
	Pre: User has selected to add an item to the array
	Post: A new item has been added with details from the user
	Purpose: To add a new item to the machine
*/
void VendingMachine::addItem()
{
	mNumItems++;
	string newName;
	double newPrice;

	cout << "Enter a price for item number " << mNumItems << ": " << endl
		<< ">";
	cin >> newPrice;
	cin.ignore();

	cout << "Enter a name for item number " << mNumItems << ":" << endl
		<< ">";
	getline(cin, newName);

	//Sets correct locations info to new data
	mDrinks[mNumItems - 1].mName = newName;
	mDrinks[mNumItems - 1].mPrice = newPrice;
	mDrinks[mNumItems - 1].mStock = DEFAULT_STOCK;

	cout << "New item " << mDrinks[mNumItems - 1].mName << " added for " << mDrinks[mNumItems - 1].mPrice << "...";
	updateFile();
	cout << "Returning to manager menu..." << endl;
	Sleep(2000);
	managerMenu();
}


/*
	Pre: User has selected to change the password from the manager menu
	Post: Password has been changed and data file has been updated
	Purpose: To change the machine password
*/
void VendingMachine::changePassword()
{
	string newPassword;
	cout << "Enter a new password: " << endl << ">";
	cin >> newPassword;
	mPassword = newPassword;
	cout << "New password set, returning to manager menu...";
	updateFile();
	Sleep(2000);
	managerMenu();
}

/*
	Pre: User has selected to change the price of an item
	Post: User has changed the price of a selected item
	Purpose: To change the price of a selected item
*/
void VendingMachine::changePrice()
{
	int item;
	bool validSelection = false;
	int arrayItem;
	double newPrice;

	cout << "Drink List: " << endl;
	for (int i = 0; i < mNumItems; i++)
	{
		cout << (i + 1) << ": " << mDrinks[i].mName << " " << mDrinks[i].mPrice << endl;
	}
	cout << "Select a price to change:" << endl << ">";

	//Checks for a valid selection
	while (validSelection == false)
	{
		cin >> item;
		if (item >= 1 && item <= mNumItems)
		{
			validSelection = true;
		}
		else
		{
			validSelection = false;
			cout << "Please enter a valid selection..." << endl;
		}
	}

	arrayItem = item - 1;
	cout << "Enter a new price for " << mDrinks[arrayItem].mName << "..." << endl << ">";
	cin >> newPrice;
	mDrinks[arrayItem].mPrice = newPrice;
	updateFile();
	cout << "Price changed successfully, returning to manager menu..." << endl;
	Sleep(2000);
	managerMenu();
}

/*
   Pre: None
   Post: Screen is cleared
   Purpose: To clear the screen if called in another function
*/
void VendingMachine::clearScreen()
{
   system("cls");
}

/*
	Pre: User has selected to collect the money from the machine
	Post: Machine money has been reset to default
	Purpose: To reset the money to defaults and allow user to collect accumulated money
*/
void VendingMachine::collectMoney()
{
	cout << "Money collected, returning to manager menu...";
	mMoney = DEFAULT_MONEY;
	updateFile();
	Sleep(2000);
	managerMenu();
}

/*
   Pre: Array data is available to be printed
   Post: Menu is printed to screen and user is prompted for an input
   Purpose: To display a menu for the user to choose between the offered items
*/
void VendingMachine::displayMenu()
{
   int i;

   clearScreen();
   cout << "          ,/                                                         " << endl
	   << "       , '/                                                           " << endl
	   << "     ,'  /        _   _       _            _____      _               " << endl
	   << "   ,'   /_____ , | \\ | |     | |          / ____|    | |             " << endl
	   << " .'____      ,'  |  \\| |_   _| | ____ _  | |     ___ | | __ _        " << endl
	   << "      /    ,'    | . ` | | | | |/ / _` | | |    / _ \\| |/ _` |       " << endl
	   << "     /   ,'      | |\\  | |_| |   < (_| | | |___| (_) | | (_| |       " << endl
	   << "    /  ,'        |_| \\_|\_____|_|\\_\\__,_|  \\_____\\___/|_|\\__,_| " << endl
	   << "   /, '                                                               " << endl
	   << " =============================================================        " << endl
	   << " ||            'Even better than the real thing!'           ||        " << endl;
      

   for (i = 0; i < mNumItems; i++)

      cout << " ||         _______________________________________         ||        " << endl
	   << " ||         | " << i + 1 << " |" << left << setw(25) << mDrinks[i].mName << "| " 
           << right << setw(5) << mDrinks[i].mPrice << " |         ||" << endl;
   cout << " ||                                                         ||        " << endl
	    << " ||       ===========================================       ||        " << endl
        << " ||      | Please Enter a Selection...               |      ||        " << endl
        << " ||       ===========================================       ||        " << endl
        << " =============================================================        " << endl;
}

/*
	Pre: User has selected to check the info for the machine
	Post: Machine info has been displayed and user has returned to the manager menu
	Purpose: To display all of the machine information in the data file
*/
void VendingMachine::machineInfo()
{
	clearScreen();

	cout << "====================" << endl
		<< "=== MACHINE INFO ===" << endl
		<< "==================== " << endl;

	cout << "Number of items: " << right << setw(2) << mNumItems << endl
		<< "Current money: " << right << setw(2) << mMoney << endl;
	cout << endl;

	cout << left << setw(20) << "Drink" << right << setw(10) << "Stock" << right << setw(10) << "Price" << endl;
	for (int i = 0; i < mNumItems; i++)
	{
		cout << left << setw(20) << mDrinks[i].mName << right << setw(10) << mDrinks[i].mStock << right << setw(10) << mDrinks[i].mPrice << endl;
	}

	system("pause");
	managerMenu();
}

/*
	Pre: User selection has been validated and has directed to the manager menu
	Post: User is redirected to the manager menu if password is correct, reprompted if false, or directed back to the main menu
	Purpose: To validate the password provided to enter the manager menu
*/
void VendingMachine::managerPassword()
{
	clearScreen();
	cout << "====================" << endl
		<< "=== MANAGER MENU ===" << endl
		<< "====================" << endl;
	string userPassword;
	bool validPass = false;

	while (validPass == false)
	{
		cout << "Please enter the admin password or type 'M' to return to menu: " << endl;
		cout << ">";
		cin >> userPassword;

		//Checks if password is correct
		if (userPassword == mPassword)
		{
			validPass = true;
			managerMenu();
		}
		//Checks if user wants to return to menu
		else if (userPassword == "m" || userPassword == "M")
		{
			menu();
		}
		else
		{
			validPass = false;
			cout << "Password incorrect... Please try again" << endl;
		}
	}
}
/*
	Pre: User password has been validated and user has been let into the manager menu
	Post: User selection is validated and user is directed to the right menu function
	Purpose: To get input from user to allow them to select a menu option
*/
void VendingMachine::managerMenu()
{
	clearScreen();
	cout << "====================" << endl
		<< "=== MANAGER MENU ===" << endl
		<< "====================" << endl;
	bool validSelection = false;
	int selection;

	cout << "1. Change Password" << endl
		<< "2. Machine Info" << endl
		<< "3. Collect Money" << endl
		<< "4. Restock Items" << endl
		<< "5. Change Price" << endl
		<< "6. Add a new item" << endl
		<< "7. Remove an existing item" << endl
		<< "8. Return to Machine" << endl
		<< "9. Shut Down Machine" << endl
		<< ">";

	//Checks if user input is valid
	while (validSelection == false)
	{
		cin >> selection;

		switch (selection)
		{
		case 1: changePassword();
			validSelection = true;
			break;
		case 2: machineInfo();
			validSelection = true;
			break;
		case 3: collectMoney();
			validSelection = true;
			break;
		case 4: restockItems();
			validSelection = true;
			break;
		case 5: changePrice();
			validSelection = true;
			break;
		case 6: addItem();
			validSelection = true;
			break;
		case 7: removeItem();
			validSelection = true;
			break;
		case 8: menu();
			validSelection = true;
			break;
		case 9: shutdown();
			validSelection = true;
			break;
		default: cout << "Invalid selection..." << endl;
			validSelection = false;
			break;
		}
	}
}

/*
   Pre: Menu has been displayed
   Post: User has selected a menu selection and the selected has been validated
   Purpose: To obtain input from the user and validate it
*/
void VendingMachine::menu()
{
   bool validSelection = false;
   string userSelection;
   stringstream integer;
   int selection = 0;
   string input;

   while (validSelection == false)
   {
      displayMenu();

      //Obtains an input from user
      cout << ">";
      cin >> userSelection;

      integer << userSelection;
      integer >> selection;
      integer.str("");
      integer.clear();

      //Asks if the input is an M to direct to manager menu
      if (userSelection == "m" || userSelection == "M")
      {
         managerPassword();
      }
      //Asks if selection is valid for an item
      else if (selection >= 1 && selection <= mNumItems)
      {
         //Check that the item is in stock
         if (mDrinks[selection - 1].mStock <= 0)
         {
            cout << "Out of stock, please enter a different selection..." << endl;
            validSelection = false;
         }
         else
         {
            validSelection = true;
            moneyInput(selection);
         }
      }
      else
      {
         cout << "Please enter a valid selection..." << endl;
      }
   }
}

/*
	Pre: User has made a valid selection
	Post: Money has been input and drink is ready to be vended
	Purpose: Validates the amount of money that is provided by the user, making sure that the machine can give change and that it is enough money to pay.
*/
void VendingMachine::moneyInput(int selection)
{
	bool validMoney = false;
	double money;
	int vend = selection - 1;

	while (validMoney == false)
	{
		cout << "Insert payment: ";
		cin >> money;

		double change = (money - mDrinks[vend].mPrice);

		//Checks if the machine has enough money to give change
		if (change > mMoney)
		{
			cout << "Insufficient change, please use a smaller denomination..." << endl;
			validMoney = false;
		}
		//Checks if the amount of money is enough to pay for the selection
		else if (money < mDrinks[vend].mPrice)
		{
			cout << "Insufficient money to pay for item, please insert more money..." << endl;
			validMoney = false;
		}
		else
		{
			mMoney += money;
			mMoney -= change;
			mDrinks[vend].mStock -= 1;
			updateFile();
			validMoney = true;
			vendDrink(change, vend);
		}
	}
}

/*
	Pre: User has selected to restock the items in the machine
	Post: All items reset to default stock value
	Purpose: To reset the stock of all items to defaults
*/
void VendingMachine::restockItems()
{
	cout << "All items restocked, returning to manager menu...";
	for (int i = 0; i < mNumItems; i++)
	{
		mDrinks[i].mStock = DEFAULT_STOCK;
	}
	updateFile();
	Sleep(2000);
	managerMenu();
}

/*
	Pre: User has selected to remove an item from the array
	Post: The selected item has been removed from the menu
	Purpose: To remove an item from the menu
*/
void VendingMachine::removeItem()
{
	mNumItems--;
	int item;
	bool validSelection = false;

	cout << "Drink List: " << endl;
	for (int i = 0; i <= mNumItems; i++)
	{
		cout << (i + 1) << ": " << mDrinks[i].mName << " " << mDrinks[i].mPrice << endl;
	}
	cout << "Select an item to remove:" << endl << ">";

	//Checks for a valid selection
	while (validSelection == false)
	{
		cin >> item;
		if (item >= 1 && item <= mNumItems + 1)
		{
			validSelection = true;
		}
		else
		{
			validSelection = false;
			cout << "Please enter a valid selection..." << endl;
		}
	}
	//Switched deleted item with item above it, moving all items above down
	for (int i = item - 1; i <= mNumItems + 1; i++)
	{
		mDrinks[i].mName = mDrinks[i + 1].mName;
		mDrinks[i].mPrice = mDrinks[i + 1].mPrice;
		mDrinks[i].mStock = mDrinks[i + 1].mStock;
	}
	//Erases extra copied data
	mDrinks[mNumItems].mName = "";
	mDrinks[mNumItems].mPrice = 0;
	mDrinks[mNumItems].mStock = 0;

	cout << "Item removed..." << endl;
	updateFile();
	cout << "Returning to manager menu..." << endl;
	Sleep(2000);
	managerMenu();
}

/*
	Pre: None
	Post: Program is exited
	Purpose: To exit the program if called in another function
*/
void VendingMachine::shutdown()
{
	cout << "Shutting down machine...";
	Sleep(2000);
	VendingMachine:: ~VendingMachine();
	exit(0);
}

/*
	Pre: Array data has been loaded and is up to date
	Post: Data file is updated with current information
	Purpose: To update the data file whenever a change is made within the program
*/
void VendingMachine::updateFile()
{
	ofstream fout;
	fout.open(MACHINE_FILE, ios::trunc);

	fout << mNumItems << " " << mMoney << " " << mPassword << endl;

	for (int i = 0; i <= mNumItems; i++)
	{
		fout << mDrinks[i].mName << endl;
		fout << mDrinks[i].mStock << " " << mDrinks[i].mPrice << endl
			<< ":" << endl;
	}
	fout.close();
}

/*
	Pre: User selection and money have both been validated
	Post: Drink has been vended and the user has been returned to the menu, all changes to machine have been recorded
	Purpose: To vend the item to the user and display information
*/
void VendingMachine::vendDrink(double change, int vend)
{
	cout << "Vending " << mDrinks[vend].mName << " for " << fixed << setprecision(2) << mDrinks[vend].mPrice << "... Enjoy Refreshing Nuka Cola!" << endl;
	cout << "Change: " << fixed << setprecision(2) << change << endl;
	system("pause");
	displayMenu();
	menu();
}