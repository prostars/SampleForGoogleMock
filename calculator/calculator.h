#pragma once

#include <vector>
#include <map>
#include <memory>
#include "AccountStorage.h"



class Calculator {
public:
	Calculator(std::shared_ptr<AccountStorage> storage);
	~Calculator();

	bool sum(int& result);
	bool average(double& result);

protected:
	std::shared_ptr<AccountStorage> storage;
};