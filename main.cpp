#include <ctime>
#include "biTree.h"

int main() 
{
	std::cout << "BeTree" << std::endl;
	int arr[] = {6, 8, 4, 5, 2, 3, 0};	//biTree is balanced
	// arr[] = {3, 2, 1};		//biTree is not balanced

	int sizeArr = std::size(arr);
	biTree biList;
	srand(time(NULL));

	//function addItem()
	for (size_t i = 0; i < sizeArr; i++)
	{
		//biList.addItem((-5 + rand()%11), &biList.getHead());
		biList.addItem(arr[i], &biList.getHead());
	}

	//ostream operator<<
	std::cout << biList << "\n";

	//functioin searchItemByDate
	Item* item = biList.searchItemByDate(1);
	std::cout << (item != nullptr? item->getData() : 0) << "\n";

	//std::cout << *item << "\n";

	//function for update heigt of items
	std::cout << "\n";
	biList.updateHeight(&biList.getHead());

	//function for balance beTree
	//biList.balanceTree(&biList.getHead());

	return 0;//call destructor -> function clearTree()
}