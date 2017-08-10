#include "calculator.h"


Calculator::Calculator(std::shared_ptr<AccountStorage> storage) {
	this->storage = storage;
}

Calculator::~Calculator() {
}

bool Calculator::sum(int &result) {
	std::vector<int> months;
	storage->getMonths(months);

	int sum = 0;
	for (auto month : months) {
		int value = 0;
		if (storage->getValue(month, value))
			sum += value;
		else
			return false;
	}

	result = sum;
	return true;
}

bool Calculator::average(double& result) {
	std::vector<int> months;
	storage->getMonths(months);

	if (months.empty()) {
		result = 0;
		return true;
	}

	int sum = 0;
	if (this->sum(sum)) {
		result = sum / months.size();
		return true;
	}
	else
		return false;
}