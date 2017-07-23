//
// Created by Patrick Mintram on 22/07/2017.
//

#ifndef TSP_LOCATION_T_H
#define TSP_LOCATION_T_H

#include "describable_t.h"

#include <utility>
#include <cstdlib>
#include <sstream>
#include <cmath>

class location_t: protected std::pair<int, int>, public describable_t{
public:
	location_t(const int x, const int y)
			: std::pair<int,int>(x,y){}
	const std::pair<int,int>& get_pair( void )const { return *this; }

	const double distance_to(const location_t& dest) const {
		//pythagoras
		const int dx = abs(dest.getX() - first);
		const int dy = abs(dest.getY() - second);
		return sqrt((dx*dx) + (dy*dy));
	}

	const int getX(void) const { return first; }
	const int getY(void) const { return second; }
	std::string to_string(void) const {
		std::stringstream ss;
		ss << "(" << first << ", " << second << ")";
		return ss.str();
	}
};


#endif //TSP_LOCATION_T_H
