#ifndef __SELECT_NOT_HPP__
#define __SELECT_NOT_HPP__

#include <cstring>
#include "select.hpp"

class Select_Not: public Select {
public:
	Select_Not(Select* selection) : Inv(selection) {}
	bool select(const Spreadsheet* sheet, int row) const{ return !(Inv->select(sheet, row)); }
private: 
	Select* Inv;
};

#endif //__SELECT_NOT_HPP__
