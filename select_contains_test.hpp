#ifndef __SELECT_CONTAINS_TEST_HPP__
#define __SELECT_CONTAINS_TEST_HPP__

#include "gtest/gtest.h"
#include "select_contains.cpp"
#include "spreadsheet.cpp"
#include <string>

//Spreadsheet sheet;
//    sheet.set_column_names({"First","Last","Age","Major"});
//    sheet.add_row({"","","",""}); //empty row, row = 0
//    sheet.add_row({"Brian","Becker","21","computer science"});//normal row, row = 1
//    sheet.add_row({"Bri","Beck","2","comp sci"});//normal row abbrev, row = 2
//    sheet.add_row({"CaBrio","CaBecko","Ca2o","Macomp scio"});//normal row appended, row = 3
//    sheet.add_row({"   ","\n   ","\t","\t\n "});//spacing row, row = 4

TEST(select_containsTest, Select_ContainsStr) {
    Spreadsheet sheet;
    Select_Contains* test = new Select_Contains(&sheet, "Last", "Becker");
    EXPECT_TRUE(test->select("Becker"));
}

TEST(select_containsTest, Select_ContainsNull) {
    Spreadsheet sheet;
    Select_Contains* test = new Select_Contains(&sheet, "First", "");
    EXPECT_TRUE(test->select("something")); //no matter the test it should find empty char inside
}

TEST(select_containsTest, Select_ContainsExcess) {
    Spreadsheet sheet;
    Select_Contains* test = new Select_Contains(&sheet, "First", "Something");
    EXPECT_FALSE(test->select("some")); //test selection doesnt only detect first chars
}

TEST(select_containsTest, Select_ContainsSpace) {
    Spreadsheet sheet;
    Select_Contains* test = new Select_Contains(&sheet, "First", " ");
    EXPECT_TRUE(test->select("something  is  afoot")); //test spaces
}

TEST(select_containsTest, Select_ContainsSpacingChars) {
    Spreadsheet sheet;
    Select_Contains* test = new Select_Contains(&sheet, "First", " \t");
    EXPECT_TRUE(test->select("Hello \tworld")); //test multiple spacing chars
}




#endif

