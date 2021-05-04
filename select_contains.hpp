#ifndef __SELECT_CONTAINS_HPP__1234
#define __SELECT_CONTAINS_HPP__1234


#include "select.hpp"
#include "spreadsheet.hpp"
#include <string>

class Select_Contains : public Select_Column{
        public:
                Select_Contains(const Spreadsheet* sheet, std::string column, const std::string& search);
                bool select(const std::string& str) const;
       private:
                std::string search;

};

#endif
