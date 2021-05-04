#ifndef __SELECT_CONTAINS_HPP__
#define __SELECT_CONTAINS_HPP__

#include "gtest/gtest.h"
#include "select_contains.cpp"
#include "spreadsheet.cpp"

TEST(select_containsTest, Select_ContainsStr) {
    Spreadsheet* sheet = new Spreadsheet();
    Select_Contains* test = new Select_Contains(sheet, "Last", "John");
    EXPECT_FALSE(test->select(sheet, 1));
}



#endif

