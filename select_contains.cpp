#include "select_contains.hpp"

#include "select.hpp"
#include <string>


Select_Contains::Select_Contains(const Spreadsheet* sheet, std::string name, const std::string& contain) : Select_Column(sheet, name) {
    search = contain;

}

bool Select_Contains::select(const std::string& s) const {
    return s.find(search) != std::string::npos;

}


