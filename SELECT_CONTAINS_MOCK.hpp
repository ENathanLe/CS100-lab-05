#ifndef __SELECT_CONTAINS_MOCK__
#define __SELECT_CONTAINS_MOCK__

#include "select.hpp"
#include <string>

class Select_Contains_Mock_True : public Select {
	public: 
		Select_Contains_Mock_True() {};
		bool select(const Spreadsheet* sheet, int row) const {return true;}
		~Select_Contains_Mock_True() = default;		
};

class Select_Contains_Mock_False : public Select {
	public: 
		Select_Contains_Mock_False() {};
		bool select(const Spreadsheet* sheet, int row) const {return false;}
		~Select_Contains_Mock_False() = default;
};


#endif //__SELECT_CONTAINS_MOCK__
