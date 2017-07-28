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

std::string tour_manager_t::to_string( void ) const {
	std::stringstream ss;
	for( int i = 0; i < get_city_count(); i++){
		ss << get_city(i).to_string() << std::endl;
	}
	return ss.str();
}
