//
// Created by Patrick Mintram on 28/07/2017.
//

#include "tour_base_t.h"

//------------
const city_t& tour_base_t::get_city( const size_t idx ) const{
	return _cities[idx];
}

//------------
bool tour_base_t::contains_city(const city_t& c) const{
	bool rc = false;
	std::vector<city_t>::const_iterator it = _cities.begin();
	while(it != _cities.end()){
		if(c.to_string() == (*it).to_string()) { rc = true; break; }
		it++;
	}
	return rc;
}

//------------
city_loop_t & tour_base_t::get_cities( void ){
	return _cities;
}

//------------
unsigned long tour_base_t::get_city_count(void) const {
	return _cities.size();
}

//------------
void tour_base_t::set_city( const size_t idx, const city_t &c ) {
	_cities[idx] = c;
}

void tour_base_t::add_city(const city_t& c) {
	_cities.push_back(c);
}