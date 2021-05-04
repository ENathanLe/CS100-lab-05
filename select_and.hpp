#ifndef __SELECT_AND_HPP__
#define __SELECT_AND_HPP__

#include "select.hpp"


class Select_And : public Select {
	public:
		Select_And(Select* select1, Select* select2) : select1(select1), select2(select2) {}
		bool select(const Spreadsheet* sheet, int row) const { select1->select(sheet, row) && select2->select(sheet, row);}
		~Select_And() {
			delete select1;
			delete select2;
		}

	private:
		Select* select1; 
		Select* select2;

};

#endif
