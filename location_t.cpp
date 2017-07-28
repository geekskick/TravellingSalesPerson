#include "location_t.h"

location_t::location_t(const int x, const int y)
		: std::pair<int,int>(x,y){}

const std::pair<int,int>& location_t::get_pair( void )const {
	return *this;
}

double location_t::distance_to(const location_t& dest) const {
	//pythagoras
	const int dx = abs(dest.getX() - first);
	const int dy = abs(dest.getY() - second);
	return sqrt((dx*dx) + (dy*dy));
}

int location_t::getX(void) const {
	return first;
}

int location_t::getY(void) const {
	return second;
}

std::string location_t::to_string(void) const {
	std::stringstream ss;
	ss << "(" << first << ", " << second << ")";
	return ss.str();
}