#include "spreadsheet.hpp"

#include "gtest/gtest.h"
#include "Select_Not_Test.hpp"
#include "spreadsheet_test.hpp"
#include "Select_Or_Test.hpp"
#include "select_contains_test.hpp"
#include "select_and_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
