#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <cstddef>

class Item
{
private:
	int data;
	Item* leftBranch;
	Item* rightBranch;

public:

	Item(const int& data) : data{data}, leftBranch(nullptr), rightBranch(nullptr) {}

	~Item() {
		this->data = NULL;
		this->leftBranch = nullptr;
		this->rightBranch = nullptr;
	}

#pragma region getters
	int getData() const {
		return this->data;
	}

	Item& getLeftBranch() const {
		return *this->leftBranch;
	}
	
	Item& getRightBranch() const {
		return *this->rightBranch;
	}
#pragma endregion

#pragma region  setters
	void setLeftBranch(Item* const& item) {
		this->leftBranch = item;
	}

	void setRightBranch(Item* const& item) {
		this->rightBranch = item;
	}
#pragma endregion
};
#endif