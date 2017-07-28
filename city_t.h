//
// Created by Patrick Mintram on 22/07/2017.
//

#ifndef TSP_CITY_T_H
#define TSP_CITY_T_H


#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include "describable_t.h"
#include "location_t.h"


class city_t: public describable_t
{
public:
	city_t(const std::string& name, const location_t& location)
			: _name(name), _location(location)
	{}

	city_t(const std::string& name, const int x, const int y)
			: _name(name), _location(x,y)
	{}

	~city_t(void){}

	const location_t& get_location(void) const;
	const std::string& get_name(void) const;
	std::string to_string(void) const;
protected:
	std::string _name;
	location_t _location;
};

class empty_city_t :public city_t{
public:
	static const std::string EMPTY;
	empty_city_t(void):city_t(EMPTY,0,0){}
};

#endif //TSP_CITY_T_H
