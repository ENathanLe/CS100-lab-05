#ifndef __SELECT_AND_TEST_HPP__
#define __SELECT_AND_TEST_HPP__

#include "gtest/gtest.h"
#include "select_and.hpp"
#include "spreadsheet.hpp"
#include "select_mock.hpp"
#include <string>

//Spreadsheet sheet;
////    sheet.set_column_names({"First","Last","Age","Major"});
////    sheet.add_row({"","","",""}); //empty row, row = 0
////    sheet.add_row({"Brian","Becker","21","computer science"});//normal row, row = 1
////    sheet.add_row({"Bri","Beck","2","comp sci"});//normal row abbrev, row = 2
////    sheet.add_row({"CaBrio","CaBecko","Ca2o","Macomp scio"});//normal row appended, row = 3
////    sheet.add_row({"   ","\n   ","\t","\t\n "});//spacing row, row = 4
//
TEST(select_AndTest, Select_AndTF) {
    Spreadsheet sheet;
    Select* selectMock1 = new Select_MockFalse();
    Select* selectMock2 = new Select_MockTrue();
    Select_And* test = new Select_And(selectMock1, selectMock2);
    EXPECT_FALSE(test->select(&sheet, 2));
    delete test;
    delete selectMock1;
    delete selectMock2;
}

TEST(select_AndTest, Select_AndTT) {
    Spreadsheet sheet;
    Select* selectMock1 = new Select_MockTrue();
    Select* selectMock2 = new Select_MockTrue();
    Select_And* test = new Select_And(selectMock1, selectMock2);
    EXPECT_TRUE(test->select(&sheet, 2));
    delete test;
    delete selectMock1;
    delete selectMock2;
}

TEST(select_AndTest, Select_AndFF) {
    Spreadsheet sheet;
    Select* selectMock1 = new Select_MockFalse();
    Select* selectMock2 = new Select_MockFalse();
    Select_And* test = new Select_And(selectMock1, selectMock2);
    EXPECT_FALSE(test->select(&sheet, 2));
    delete test;
    delete selectMock1;
    delete selectMock2;
}


#endif
