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
    delete test;
}

TEST(select_containsTest, Select_ContainsNull) {
    Spreadsheet sheet;
    Select_Contains* test = new Select_Contains(&sheet, "First", "");
    EXPECT_TRUE(test->select("something")); //no matter the test it should find empty char inside
    delete test;
}

TEST(select_containsTest, Select_ContainsExcess) {
    Spreadsheet sheet;
    Select_Contains* test = new Select_Contains(&sheet, "First", "Something");
    EXPECT_FALSE(test->select("some")); //test selection doesnt only detect first chars
    delete test;
}

TEST(select_containsTest, Select_ContainsSpace) {
    Spreadsheet sheet;
    Select_Contains* test = new Select_Contains(&sheet, "First", " ");
    EXPECT_TRUE(test->select("something  is  afoot")); //test spaces
    delete test;
}

TEST(select_containsTest, Select_ContainsSpacingChars) {
    Spreadsheet sheet;
    Select_Contains* test = new Select_Contains(&sheet, "First", " \t");
    EXPECT_TRUE(test->select("Hello \tworld")); //test multiple spacing chars
    delete test;
}

TEST(select_containsTestSheet, Select_ContainsSheet) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Contains(&sheet, "First", "Brian");
    EXPECT_TRUE(test->select(&sheet, 0)); //normal test case of sheet
    delete test;
}

TEST(select_containsTestSheet, Select_ContainsEmpty) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"","","",""});
    Select* test = new Select_Contains(&sheet, "First", "Brian");
    EXPECT_FALSE(test->select(&sheet, 0)); //test empty row
    delete test;
}

TEST(select_containsTestSheet, Select_ContainsSubstr) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Brian","CaBecker","21","computer science"});
    Select* test = new Select_Contains(&sheet, "Last", "Beck");
    EXPECT_TRUE(test->select(&sheet, 0)); //search for a substring inside of the string
    delete test;
}

TEST(select_containsTestSheet, Select_ContainsSpaces) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Contains(&sheet, "Major", " ");
    EXPECT_TRUE(test->select(&sheet, 0)); //test search for a single space
    delete test;
}

#endif

