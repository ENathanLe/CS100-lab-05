#ifndef __SELECT_ALL_MOCKS_HPP__
#define __SELECT_ALL_MOCKS_HPP__

#include "select.hpp"



class Select_MockTrue : public Select {
	public:
		Select_MockTrue() {}
		bool select(const Spreadsheet* sheet, int row) const {return true;}
};

class Select_MockFalse : public Select {
        public:
                Select_MockFalse() {}
                bool select(const Spreadsheet* sheet, int row) const {return false;}
};




#endif
