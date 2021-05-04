#include "select_contains.hpp"

#include <string>

Select_Contains::Select_Contains(const Spreadsheet* sheet, std::string name, const std::string& contain) {
    search = contain;

}

bool Select_Contains::select(const string& s) const {
    return s.find(search) != std::string::npos;

}


