#ifndef __ENATHANLE_TESTS_HPP__
#define __ENATHANLE_TESTS_HPP__

#include "select.hpp"
#include "select_contains.hpp"
#include "Select_Not.hpp"
#include "select_and.hpp"
#include "Select_Or.hpp"
#include "spreadsheet.hpp"

TEST(ENathanLe_integrated, normal_sheet) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"","","",""}); //empty row, row = 0
    sheet.add_row({"Brian","Becker","21","computer science"});//normal row, row = 1
    sheet.add_row({"Bri","Beck","2","comp sci"});//normal row abbrev, row = 2
    sheet.add_row({"CaBrio","CaBecko","Ca2o","Macomp scio"});//normal row appended, row = 3
    sheet.add_row({"   ","\n   ","\t","\t\n "});//spacing row, row = 4
    Select* selectAnd = new Select_And(new Select_Not(new Select_Contains(&sheet, "Age", "21")), new Select_Contains(&sheet, "Major", "comp sci")); //(NOT(age 21)) AND (major comp sci)
    sheet.set_selection(selectAnd);
    std::ostringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Bri Beck 2 comp sci \nCaBrio CaBecko Ca2o Macomp scio \n");
    out.str(std::string());
    sheet.clear();

}

TEST(ENathanLe_integrated, multiple_OrAnd) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"John","Meyer","20","mathematics"}); //empty row, row = 0
    sheet.add_row({"Brian","Becker","21","computer science"});//normal row, row = 1
    sheet.add_row({"Brienne","Andrews","22","physics"});//normal row abbrev, row = 2
    sheet.add_row({"Carol","Dole","19","computer science"});//normal row appended, row = 3
    sheet.add_row({"Jack","Daniels","24","business"});//spacing row, row = 4
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    Select* selectAnd = new Select_And(new Select_Or(new Select_Contains(&sheet, "Age", "21"), new Select_Contains(&sheet, "Major", "comp sci")), new Select_Contains(&sheet, "First", "Carol")); //((Age 21) OR (major comp sci)) AND (First Carol)
    sheet.set_selection(selectAnd);
    std::ostringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Carol Conners 21 computer science \n");
    out.str(std::string());
    sheet.clear();
}

TEST(ENathanLe_integrated, OrNot) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"John","Meyer","20","mathematics"}); //empty row, row = 0
    sheet.add_row({"Brian","Becker","21","computer science"});//normal row, row = 1
    sheet.add_row({"Brienne","Andrews","22","physics"});//normal row abbrev, row = 2
    sheet.add_row({"Carol","Dole","19","computer science"});//normal row appended, row = 3
    sheet.add_row({"Jack","Daniels","24","business"});//spacing row, row = 4
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    Select* selectOr = new Select_Or(new Select_Not(new Select_Contains(&sheet, "First", "")), new Select_Not(new Select_Contains(&sheet, "Major", "comp sci"))); //(NOT(Age ) OR NOT(major comp sci))
    sheet.set_selection(selectOr);
    std::ostringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "John Meyer 20 mathematics \nBrian Becker 21 computer science \nBrienne Andrews 22 physics \nCarol Dole 19 computer science \nJack Daniels 24 business \nCarol Conners 21 computer science \nJoe Jackson 21 mathematics \nSarah Summers 21 computer science \nDiane Dole 20 computer engineering \n");
    out.str(std::string());
    sheet.clear();
}


#endif
