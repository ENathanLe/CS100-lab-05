#ifndef __SELECT_OR_HPP__
#define __SELECT_OR_HPP__

#include <cstring>
#include "select.hpp"

class Select_Or: public Select {
private:
	Select* One;
	Select* Two;
public:
	Select_Or(Select* selectionOne, Select* selectionTwo) : One(selectionOne), Two(selectionTwo) {}
	bool select(const Spreadsheet* sheet, int row) const{ return One->select(sheet, row) || Two->select(sheet, row); }
};

#endif //__SELECT_OR_HPP__
