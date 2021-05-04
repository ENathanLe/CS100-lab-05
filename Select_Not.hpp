#ifndef __SELECT_NOT_HPP__
#define __SELECT_NOT_HPP__

#include <cstring>
#include "select.hpp"

class Select_Not: public Select_Column {
private: 
	std::string target; 
public:
	Select_Not(const Spreadsheet* sheet, const std::string& name, const std::string& input) : Select_Column(sheet, name), target(input) {}

	bool Select_Not(const std::string& s) const : select() { return target != s; }
};

#endif //__SELECT_NOT_HPP__
