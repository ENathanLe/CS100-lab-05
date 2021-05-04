#ifndef __SELECT_SPREADSHEET_TEST_HPP__
#define __SELECT_SPREADSHEET_TEST_HPP__

#include "gtest/gtest.h"
#include "spreadsheet.hpp"
#include <string>
#include "select_all_mocks.hpp"
#include <sstream>
#include <string>
#include <iostream>

//Spreadsheet sheet;
////    sheet.set_column_names({"First","Last","Age","Major"});
////    sheet.add_row({"","","",""}); //empty row, row = 0
////    sheet.add_row({"Brian","Becker","21","computer science"});//normal row, row = 1
////    sheet.add_row({"Bri","Beck","2","comp sci"});//normal row abbrev, row = 2
////    sheet.add_row({"CaBrio","CaBecko","Ca2o","Macomp scio"});//normal row appended, row = 3
////    sheet.add_row({"   ","\n   ","\t","\t\n "});//spacing row, row = 4



TEST(spreadsheet_test, spreadsheet_full) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"","","",""}); //empty row, row = 0
    sheet.add_row({"Brian","Becker","21","computer science"});//normal row, row = 1
    sheet.add_row({"Bri","Beck","2","comp sci"});//normal row abbrev, row = 2
    sheet.add_row({"CaBrio","CaBecko","Ca2o","Macomp scio"});//normal row appended, row = 3
    sheet.add_row({"   ","\n   ","\t","\t\n "});//spacing row, row = 4
    Select* trueMock = new Select_MockTrue();
    std::ostringstream out;
    sheet.print_selection(out);
    std::string text = out.str();
    EXPECT_EQ(text, "    \nBrian Becker 21 computer science \nBri Beck 2 comp sci \nCaBrio CaBecko Ca2o Macomp scio \n     \n    \t \t\n  \n");
    out.str(std::string());
    delete trueMock;
    sheet.clear();

}



#endif
