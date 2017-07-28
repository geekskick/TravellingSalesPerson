#include "location_t.h"

location_t::location_t(const int x, const int y)
		: std::pair<int,int>(x,y){}

const std::pair<int,int>& location_t::get_pair( void )const {
	return *this;
}

double location_t::distance_to(const location_t& dest) const {
	//pythagoras
	const int dx = abs( dest.get_x() - first);
	const int dy = abs( dest.get_y() - second);
	return sqrt((dx*dx) + (dy*dy));
}

int location_t::get_x( void ) const {
	return first;
}

int location_t::get_y( void ) const {
	return second;
}

std::string location_t::to_string(void) const {
	std::stringstream ss;
	ss << "(" << first << ", " << second << ")";
	return ss.str();
}

void location_t::set_y( const int y ) {
	second = y;

}

void location_t::set_x( const int x ) {
	first = x;
}

void location_t::set_pair( const std::pair<int, int> &p ) {
	first = p.first;
	second = p.second;
}

location_t::location_t( void ) {
	first = second = 0;
}
