#pragma once

#include "stdafx.h"
#include "../calculator/AccountStorage.h"
#include <vector>
#include <map>

class FakeAccountStorage: public AccountStorage {
public:
	virtual void getMonths(std::vector<int>& months) {
		for (auto iter : storage)
			months.push_back(iter.first);
	}

	virtual bool getValue(int month, int& value) {
		auto found = storage.find(month);
		if (found != storage.end()) {
			value = found->second;
			return true;
		}
		else
			return false;
	}

	virtual bool insertValue(int month, int value) {
		auto found = storage.find(month);
		if (found == storage.end()) {
			storage.insert(std::make_pair(month, value));
			return true;
		}
		else
			return false;
	}

	virtual bool updateValue(int month, int value) {
		auto found = storage.find(month);
		if (found != storage.end()) {
			found->second = value;
			return true;
		}
		else
			return false;
	}

	virtual bool removeMonth(int month) {
		auto found = storage.find(month);
		if (found != storage.end()) {
			storage.erase(found);
			return true;
		}
		else
			return false;
	}

protected:
	std::map<int, int> storage;
};

class MockAccountStorage : public AccountStorage {
public:
	FakeAccountStorage fake;

	MockAccountStorage() {
		delegateToFake();
	}

	MOCK_METHOD1(getMonths, void(std::vector<int>& months));
	MOCK_METHOD2(getValue, bool(int month, int& value));
	MOCK_METHOD2(insertValue, bool(int month, int value));
	MOCK_METHOD2(updateValue, bool(int month, int value));
	MOCK_METHOD1(removeMonth, bool(int month));

	void delegateToFake() {
		ON_CALL(*this, getMonths(_)).WillByDefault(::testing::Invoke(&fake, &FakeAccountStorage::getMonths));
		ON_CALL(*this, getValue(_, _)).WillByDefault(::testing::Invoke(&fake, &FakeAccountStorage::getValue));
		ON_CALL(*this, insertValue(_, _)).WillByDefault(::testing::Invoke(&fake, &FakeAccountStorage::insertValue));
		ON_CALL(*this, updateValue(_, _)).WillByDefault(::testing::Invoke(&fake, &FakeAccountStorage::updateValue));
		ON_CALL(*this, removeMonth(_)).WillByDefault(::testing::Invoke(&fake, &FakeAccountStorage::removeMonth));
	}
};