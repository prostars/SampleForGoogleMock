// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <gtest\gtest.h>
#include <gmock\gmock.h>

using ::testing::_;

#pragma comment(lib, "gtest.lib")
#pragma comment(lib, "gmock.lib")
#pragma comment(lib, "calculator.lib")

#define _write(log)  std::cout << log << std::endl
#define _trace( log )	_write(log)
#define _debug( log )	_write(log)
#define _info( log )	_write(log)
#define _warn( log )	_write(log)
#define _error( log )	_write(log)
#define _fatal( log )	_write(log)