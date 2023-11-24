#pragma once

#ifndef BITREE_H
#define BITREE_H

#include "Item.h"

class biTree
{
private:
	Item* head;
	int size;

public:
	biTree() : head(nullptr), size{} {}

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
					return;
				}
				addItem(data, &headBranch->getLeftBranch());
			}
			else
			{
				if (!&headBranch->getRightBranch()) {
					headBranch->setRightBranch(new Item(data));
					return;
				}
				addItem(data, &headBranch->getRightBranch());
			}
		}
	}

	Item& getHead() const {
		return *this->head;
	}
};
#endif