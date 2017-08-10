#include "stdafx.h"
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	testing::InitGoogleMock(&argc, argv);

	::testing::FLAGS_gmock_verbose = "error";

	auto result = RUN_ALL_TESTS();

	_getch();

	return result;
}