#include <iostream>
#include <ctime>
#include "biTree.h"

int main() 
{
	std::cout << "BeTree" << std::endl;

	biTree biList;
	srand(time(NULL));

	//function addItem
	for (size_t i = 0; i < 5; i++)
	{
		biList.addItem((-5 + rand()%11), &biList.getHead());
	}

	return 0;
}