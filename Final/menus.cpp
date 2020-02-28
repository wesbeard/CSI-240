/*
PRE: an initialized order
POST: returns the total cost of the order
PURPOSE: gets the total price of the order
AUTHOR: Louis Vinton
*/

#include "final.h"
#include "employee.h"

/*
PRE: Function called from main after host role is found
POST: Menu printed and selection is obtained
PURPOSE: User redirected to the correct host menu selection
AUTHOR: Wes Beard
*/
void hostMenu(bool &loggedIn, Table* tables)
{
	clearScreen();
	printLogo();
	cout << "===============" << endl
		<< "|| HOST MENU ||" << endl
		<< "===============" << endl;

	cout << "[1] Find empty table" << endl
		<< "[2] Make table available" << endl
		<< "[3] Logout" << endl;

	switch (getSelection(3))
	{
		case 1:
			findTable(tables);
			break;
		case 2:
			makeAvailable(tables);
			break;
		case 3:
			cout << "Logging out..." << endl;
			wait(1000);
			loggedIn = false;
			break;
	}
}

/*
PRE: Function called from main after waiter role is found
POST: Menu printed and selection is obtained
PURPOSE: User redirected to the correct waiter menu selection
AUTHOR: Wes Beard & Louis Vinton
*/
void waiterMenu(bool &loggedIn, MenuList menu, Table* tables, double& dailyTotal, int& dailyOrders)
{
	clearScreen();
	printLogo();
	cout << "=================" << endl
		<< "|| WAITER MENU ||" << endl
		<< "=================" << endl;

	cout << "[1] Take order" << endl
		<< "[2] Delete item from order" << endl
		<< "[3] Generate bill" << endl
		<< "[4] Log out" << endl;

	switch (getSelection(4))
	{
	case 1:
		takeOrder(menu, tables);
		break;
	case 2:
		deleteFromOrder(tables);
		break;
	case 3:
		generateBill(tables, dailyTotal, dailyOrders);
		break;
	case 4:
		cout << "Logging out..." << endl;
		wait(1000);
		loggedIn = false;
		break;
	}
}

/*
PRE: Function called from main after kitchen role is found
POST: Menu printed and selection is obtained
PURPOSE: User redirected to the correct kitchen menu selection
AUTHOR: Wes Beard
*/
void kitchenMenu(bool &loggedIn, MenuList& menu, Table* tables)
{
	clearScreen();
	printLogo();
	cout << "==================" << endl
		<< "|| KITCHEN MENU ||" << endl
		<< "==================" << endl;

	cout << "[1] Change menu" << endl
		<< "[2] View orders" << endl
		<< "[3] Complete order" << endl
		<< "[4] Log out" << endl;

	switch (getSelection(5))
	{
	case 1:
		modifyMenu(menu);
		break;
	case 2:
		viewOrders(tables);
		break;
	case 3:
		completeOrder(tables);
		break;
	case 4:
		cout << "Logging out..." << endl;
		wait(1000);
		loggedIn = false;
		break;
	}
}

/*
PRE: Function called from main after manager role is found
POST: Menu printed and selection is obtained
PURPOSE: User redirected to the correct manager menu selection
AUTHOR: Wes Beard & Louis Vinton
*/
void managerMenu(bool &loggedIn, MenuList& menu, Table* tables, double& dailyTotal, int& dailyOrders)
{
	Employee employee;
	employee.loadEmployeeData();

	clearScreen();
	printLogo();
	cout << "==================" << endl
		<< "|| MANAGER MENU ||" << endl
		<< "==================" << endl;

	cout << "[1] Hire employee" << endl
		<< "[2] Fire employee" << endl
		<< "[3] Update employee info" << endl
		<< "[4] Search employee" << endl
		<< "[5] Generate end of day report" << endl
		<< "[6] Switch role menu" << endl
		<< "[7] Log out" << endl
		<< "[8] Shut down" << endl;

	switch (getSelection(8))
	{
	case 1:
		employee.hireEmployee();
		break;
	case 2:
		employee.fireEmployee();
		break;
	case 3:
		employee.updateEmployeeInfo();
		break;
	case 4: 
		employee.searchEmployee();
		break;
	case 5:
		employee.generateReport(dailyTotal, dailyOrders);
		break;
	case 6: 
		switchMenu(loggedIn, menu, tables, dailyTotal, dailyOrders);
		break;
	case 7:
		cout << "Logging out..." << endl;
		wait(1000);
		loggedIn = false;
		break;
	case 8:
		shutDown();
		break;
	}
}

/*
PRE: Function called from manager menu
POST: Menu printed and selection is obtained
PURPOSE: User redirected to the correct menu based on their selection
AUTHOR: Wes Beard
*/
void switchMenu(bool &loggedIn, MenuList menu, Table* tables, double& dailyTotal, int& dailyOrders)
{
	clearScreen();
	printLogo();
	cout << "SWITCH MENU" << endl
		<< "=============" << endl;
	cout << "[1] Manager menu" << endl
		<< "[2] Waiter menu" << endl
		<< "[3] Kitchen menu" << endl
		<< "[4] Host menu" << endl
		<< "[5] Log out" << endl;

	switch (getSelection(5))
	{
	case 1:
		managerMenu(loggedIn, menu, tables, dailyTotal, dailyOrders);
		break;
	case 2:
		waiterMenu(loggedIn, menu, tables, dailyTotal, dailyOrders);
		break;
	case 3:
		kitchenMenu(loggedIn, menu, tables);
		break;
	case 4:
		hostMenu(loggedIn, tables);
		break;
	case 5:
		cout << "Logging out..." << endl;
		wait(1000);
		loggedIn = false;
		break;

	}
}