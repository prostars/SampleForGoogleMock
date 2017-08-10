#include "stdafx.h"
#include "TestUtil.h"
#include <iostream>
#include <string>

void FEATURE(const std::string& message) {
	std::cout << "FEATURE : " << message << std::endl;
}

void SCENARIO(const std::string& message) {
	std::cout << "SCENARIO : " << message << std::endl;
}

void GIVEN(const std::string& message) {
	std::cout << "GIVEN : " << message << std::endl;
}

void WHEN(const std::string& message) {
	std::cout << "WHEN : " << message << std::endl;
}

void THEN(const std::string& message) {
	std::cout << "THEN : " << message << std::endl;
}

void AND(const std::string& message) {
	std::cout << "AND : " << message << std::endl;
}