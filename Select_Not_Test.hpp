#ifndef __SELECT_NOT_TEST_HPP__
#define __SELECT_NOT_TEST_HPP__

#include "gtest/gtest.h"
#include "Select_Not.hpp"
#include "spreadsheet.cpp"
#include "SELECT_CONTAINS_MOCK.hpp"
#include <string>

TEST(select_notTest, select_notT) {
	Spreadsheet sheet;
	Select* SelectMockOne = new Select_Contains_Mock_True();
	Select* test = new Select_Not(SelectMockOne);
	EXPECT_FALSE(test->select(&sheet, 2));	
} 

TEST(select_notTest, select_notF) {
	Spreadsheet sheet;
	Select* SelectMockOne = new Select_Contains_Mock_False();
	Select* test = new Select_Not(SelectMockOne);
	EXPECT_TRUE(test->select(&sheet,2));

}
#endif
