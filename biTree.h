#pragma once

#ifndef BITREE_H
#define BITREE_H

#include "Item.h"
#include <iostream>
#include <string>

class biTree
{
private:
	Item* head;
	int size;

	std::string& printTree(Item* headBranch, std::string& out)
	{
		if (!headBranch)
			return out;

		printTree(&headBranch->getLeftBranch(), out);
		out += std::to_string(headBranch->getData()) + "\n";

		printTree(&headBranch->getRightBranch(), out);

		return out;
	}

	int datecmp(const int& valSearch, const int& valItem) const
	{
		if (valSearch == valItem)
			return 0;
		else if (valSearch < valItem)
			return -1;
		else if (valSearch > valItem)
			return 1;
	}

	void clearTree(const Item* headBranch)
	{
		if (!headBranch)
			return;
		clearTree(&headBranch->getLeftBranch());
		clearTree(&headBranch->getRightBranch());

		delete headBranch;
		return;
	}

	int maxHeight(const Item* branchLeft, const Item* branchRight) const 
	{
		return (branchLeft->getHeight(branchLeft) > branchRight->getHeight(branchRight) ? branchLeft->getHeight(branchLeft) : branchRight->getHeight(branchRight)) + 1;
	}

	int getBalance(Item* const& item) const
	{
		return item == nullptr ? 0 : item->getHeight(&item->getRightBranch()) - item->getHeight(&item->getLeftBranch());
	}

	void swapItem(Item* const& itemA, Item* const& itemB) 
	{
		int heightA = itemA->getData();
		itemA->setData(itemB->getData());
		itemB->setData(heightA);
		heightA = NULL;
	}

	void rightRotate(Item* item)
	{
		swapItem(item, &item->getLeftBranch());

		*item->getRightBranchRotate() = *item->getLeftBranchRotate();

		*item->getLeftBranchRotate() = *item->getRightBranchRotate()->getLeftBranchRotate();

	}

public:
	biTree() : head(nullptr), size{} {}

	~biTree() {
		clearTree(&(*this->head));
	}

	Item& getHead() const {
		return *this->head;
	}

	void updateHeight(Item* headBranch) 
	{
		if (!headBranch)
			return;

		if (&headBranch->getLeftBranch() == nullptr && &headBranch->getRightBranch() == nullptr)
			return;

		updateHeight(&headBranch->getLeftBranch());
		updateHeight(&headBranch->getRightBranch());

		headBranch->setHeight(maxHeight(&headBranch->getLeftBranch(), &headBranch->getRightBranch()));
		std::cout << "\tNode: " << headBranch->getData();
		std::cout << "\t| height: " << headBranch->getHeight(headBranch) << "\n";
	}

	void balanceTree(Item* headBranch) 
	{
		if (!headBranch)
			return;

		if (&headBranch->getLeftBranch() == nullptr && &headBranch->getRightBranch() == nullptr)
			return;

		balanceTree(&headBranch->getLeftBranch());
		balanceTree(&headBranch->getRightBranch());

		if (getBalance(headBranch) == -2)
			rightRotate(headBranch);
	}

	void addItem(const int& data, Item* headBranch)
	{
		if (!this->head)
		{
			this->head = new Item(data);
			size++;
			return;//point for exit from function recursion
		}
		else
		{
			if (data < headBranch->getData())
			{
				if (!&headBranch->getLeftBranch()) {
					headBranch->setLeftBranch(new Item(data));
					size++;
					return;
				}
				addItem(data, &headBranch->getLeftBranch());
			}
			else
			{
				if (!&headBranch->getRightBranch()) {
					headBranch->setRightBranch(new Item(data));
					size++;
					return;
				}
				addItem(data, &headBranch->getRightBranch());
			}
		}
	}

	Item* searchItemByDate(const int& valSearch) const
	{
		Item* item = this->head;

		while (item != nullptr && datecmp(valSearch, item->getData()) != 0) 
		{
			if (datecmp(valSearch, item->getData()) < 0)
				item = &item->getLeftBranch();
			else
				item = &item->getRightBranch();
		}

		return item != nullptr? new Item(valSearch) : nullptr;
	}

	friend std::ostream& operator<< (std::ostream& out, Item*& const item)
	{	
		return out << (*&item != nullptr ? item->getData() : 0);
	}

	friend std::ostream& operator<< (std::ostream& out, biTree& const biList)
	{
		std::string txt = "data\n";
		out << biList.printTree(&biList.getHead(), txt);
		return out;
	}
};
#endif