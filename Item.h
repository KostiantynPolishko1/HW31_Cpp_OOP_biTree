#pragma once

#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
	int data;
	Item* leftBranch;
	Item* rightBranch;

public:

	Item(const int& data) : data{data}, leftBranch(nullptr), rightBranch(nullptr) {}

	int getData() const {
		return this->data;
	}

	Item& getLeftBranch() const {
		return *this->leftBranch;
	}
	
	Item& getRightBranch() const {
		return *this->rightBranch;
	}

	void setLeftBranch(Item* const& item) {
		this->leftBranch = item;
	}

	void setRightBranch(Item* const& item) {
		this->rightBranch = item;
	}

	~Item() {

	}
};
#endif