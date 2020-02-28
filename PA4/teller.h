/*Author: Finwë
Class: CSI240 Advanced Programming
Assignment: PA4 Part 3
Date Assigned: 4/3/2019
Due Date: 4/12/2019
Description:
A toys and games shop program. Allows for buying games and books as well as managing their inventory and adding new items.
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)*/


#ifndef TELLER
#define TELLER

#include <string>
#include <iostream>
#include <fstream>
#include "employee.h"

using namespace std;

class Teller
{
	private:
		int mCount;
		Employee *mTellers;
	public:
		Teller();
		~Teller();
		bool loadData(string fileName);
		void storeData(string fileName);
		bool verifyTeller(const string& id, const string& password);
};
#endif