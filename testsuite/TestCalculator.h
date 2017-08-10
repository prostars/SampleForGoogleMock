#pragma once

#include "stdafx.h"
#include <memory>
#include "MockAccountStorage.h"


class FixtureTestCalculator : public ::testing::Test {
protected:
	void SetUp() override {
		storage = std::make_shared<MockAccountStorage>();

		storage->fake.insertValue(1, 100);
		storage->fake.insertValue(2, 300);
		storage->fake.insertValue(3, 200);
		storage->fake.insertValue(4, 600);
		storage->fake.insertValue(5, 40);
	}

	void TearDown() override {
		storage.reset();
	}

public:
	std::shared_ptr<MockAccountStorage> storage;
};