#ifndef __SELECT_OR_TEST_HPP_
#define __SELECT_OR_TEST_HPP_

#include "gtest/gtest.h"
#include "Select_Or.hpp"
#include "spreadsheet.cpp"
#include "SELECT_CONTAINS_MOCK.hpp"
#include <string>

TEST(select_orTest, select_OrTT) {
	Spreadsheet sheet;
	Select* sm1 = new Select_Contains_Mock_True();
	Select* sm2 = new Select_Contains_Mock_True();
	Select_Or* test = new Select_Or(sm1, sm2);
	EXPECT_TRUE(test->select(&sheet, 2));
}

TEST(select_orTest, select_OrFF) {
	Spreadsheet sheet;
	Select* sm1 = new Select_Contains_Mock_True();
	Select* sm2 = new Select_Contains_Mock_False();
	Select_Or* test = new Select_Or(sm1, sm2);
	EXPECT_TRUE(test->select(&sheet, 2));
}

TEST(select_orTest, select_OrTF) {
	Spreadsheet sheet;
	Select* sm1 = new Select_Contains_Mock_False();
	Select* sm2 = new Select_Contains_Mock_False();
	Select_Or* test = new Select_Or(sm1, sm2);
	EXPECT_FALSE(test->select(&sheet, 2));
}
#endif

