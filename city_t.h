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

	~city_t(void){
		std::cout << "destroying "<<_name << std::endl;
	}

	const location_t& get_location(void) const { return _location; }
	const std::string& get_name(void) const { return _name; }
	std::string to_string(void) const{
		std::stringstream ss;
		ss << "Name: " << _name << ", \tLocation: " << _location.to_string();
		return ss.str();
	}
protected:
	const std::string _name;
	const location_t _location;
};


#endif //TSP_CITY_T_H
