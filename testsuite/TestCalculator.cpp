#include "stdafx.h"
#include "TestCalculator.h"
#include "MockAccountStorage.h"
#include "TestUtil.h"
#include "../calculator/calculator.h"


TEST_F(FixtureTestCalculator, SuccessToSum) {
	FEATURE("Calculator 는 storage 에서 월별 매출에 대한 총합을 구할 수 있다.");
	SCENARIO("storage 에 저장된 월별 매출에 대한 총합을 구한다.");

	GIVEN("1월 부터 5월까지 5개월에 대한 매출 정보가 있다.");
	Calculator calculator(this->storage);

	WHEN("총합을 구했을 때");

	THEN("모든 정보를 1번만 로딩해야 하고,");
	EXPECT_CALL(*(this->storage), getMonths(_)).Times(1);
	int sum = 0;
	calculator.sum(sum);

	AND("총합은 1240 이어야 한다.");
	EXPECT_EQ(sum, 1240);
}

TEST_F(FixtureTestCalculator, SuccessToAverage) {
	FEATURE("Calculator 는 storage 에서 월별 매출에 대한 평균을 구할 수 있다.");
	SCENARIO("storage 에 저장된 월별 매출에 대한 평균을 구한다.");

	GIVEN("1월 부터 5월까지 5개월에 대한 매출 정보가 있다.");
	Calculator calculator(this->storage);

	WHEN("평균을 구했을 때");

	THEN("모든 정보를 2번 로딩해야 하고,");
	EXPECT_CALL(*(this->storage), getMonths(_)).Times(2);
	double average = 0;
	calculator.average(average);

	AND("248 이어야 한다.");
	EXPECT_EQ(average, 248);
}