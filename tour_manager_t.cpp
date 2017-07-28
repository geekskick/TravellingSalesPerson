#include "tour_manager_t.h"

tour_manager_t* tour_manager_t::p = nullptr;

void tour_manager_t::destroy(void){
	delete p;
	p = nullptr;
}

tour_manager_t& tour_manager_t::get(void) {
	if( nullptr == p ){ p = new tour_manager_t(); }
	return *p;
}

unsigned long tour_manager_t::get_city_count(void) const {
	return _cities.size();
}

const city_t& tour_manager_t::get_city(const int idx) const {
	return _cities[idx];
}

const city_loop_t& tour_manager_t::get_cities(void) const {
	return _cities;
}

void tour_manager_t::add_city(const city_t& c) {
	_cities.push_back(c);
}