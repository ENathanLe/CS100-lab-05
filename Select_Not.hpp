#ifndef __SELECT_NOT_HPP__
#define __SELECT_NOT_HPP__

#include <cstring>
#include "select.hpp"

class Select_Not: public Select_Column {
public:
	Select_Not(Select* selection) : Inv(selection) {}
	bool select(const std::string& s) const{ return !Inv.select(); }
};

#endif //__SELECT_NOT_HPP__
