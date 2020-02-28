#ifndef FOOD
#define FOOD

#include "item.h"
#include "MenuList.h"
#include <fstream>

using namespace std;

class Menu {
	private:
		string mFileName;
		MenuList mMenu;

	public:
		Menu();
		Menu(string fileName);
		void addItem(Item newItem);
		void deleteItem(string searchKey);
		void modifyItem();

		int getCount();
		Item getItem(int index);
		void setFileName(string fileName);

		bool loadMenu();
		void saveMenu();

		void display();
};

#endif
