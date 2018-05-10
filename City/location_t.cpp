#include "location_t.h"

location_t::location_t(const int x, const int y)
		: _pair(x,y){}

const std::pair<int,int>& location_t::get_pair( void )const {
	return *this;
}

double location_t::distance_to(const location_t& dest) const {
	//pythagoras
	const int dx = abs( dest.get_x() - _pair.first);
	const int dy = abs( dest.get_y() - _pair.second);
	return sqrt((dx*dx) + (dy*dy));
}

int location_t::get_x( void ) const {
	return _pair.first;
}

int location_t::get_y( void ) const {
	return _pair.second;
}

std::string location_t::to_string(void) const {
	std::stringstream ss;
	ss << "(" << _pair.first << ", " << _pair.second << ")";
	return ss.str();
}

void location_t::set_y( const int y ) {
	_pair.second = y;

}

void location_t::set_x( const int x ) {
	_pair.first = x;
}

void location_t::set_pair( const std::pair<int, int> &p ) {
	_pair.first = p.first;
	_pair.second = p.second;
}

location_t::location_t( void ) {
	_pair.first = _pair.second = 0;
}
