#ifndef __SELECT_CONTAINS_HPP__
#define __SELECT_CONTAINS_HPP__


#include "select.hpp"
#include "spreadsheet.hpp"
#include <string>

class Select_Contains : public Select_Contains{
        public:
                Select_Contains(const Spreadsheet* sheet, string column, const string& search);
                bool Select(const string& str);
        private:
                string search;

}

#endif
