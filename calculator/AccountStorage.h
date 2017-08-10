#pragma once

#include <vector>

class AccountStorage {
public:
	virtual void getMonths(std::vector<int>& months) = 0;
	virtual bool getValue(int month, int& value) = 0;
	virtual bool insertValue(int month, int value) = 0;
	virtual bool updateValue(int month, int value) = 0;
	virtual bool removeMonth(int month) = 0;
};
