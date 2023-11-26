#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <cstddef>

class Item
{
private:
	int data;
	int height;
	Item* leftBranch;
	Item* rightBranch;

public:

	Item(const int& data) : data{ data }, height{0}, leftBranch(nullptr), rightBranch(nullptr) {}

	~Item() {
		this->data = NULL;
		this->height = NULL;
		this->leftBranch = nullptr;
		this->rightBranch = nullptr;
	}

#pragma region getters
	int getData() const {
		return this->data;
	}

	int getHeight(const Item* item) const {
		return item == nullptr? -1 : this->height;
	}

	Item& getLeftBranch() const {
		return *this->leftBranch;
	}
	
	Item& getRightBranch() const {
		return *this->rightBranch;
	}
#pragma endregion

#pragma region  setters
	void setHeight(int height) {
		this->height = height;
	}

	void setLeftBranch(Item* const& item) {
		this->leftBranch = item;
	}

	void setRightBranch(Item* const& item) {
		this->rightBranch = item;
	}
#pragma endregion
};
#endif