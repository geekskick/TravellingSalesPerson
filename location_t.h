#ifndef TSP_LOCATION_T_H
#define TSP_LOCATION_T_H

#include "describable_t.h"

#include <utility>
#include <cstdlib>
#include <sstream>
#include <cmath>

class location_t: protected std::pair<int, int>, public describable_t{
public:
	location_t(const int x, const int y);
	const std::pair<int,int>& get_pair( void )const;
	double distance_to(const location_t& dest) const;
	int getX(void) const;
	int getY(void) const;
	std::string to_string(void) const;
};


#endif //TSP_LOCATION_T_H
