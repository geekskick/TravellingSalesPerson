//
// Created by Patrick Mintram on 22/07/2017.
//

#ifndef TSP_TOUR_MANAGER_T_H
#define TSP_TOUR_MANAGER_T_H


#include <vector>
#include "city_t.h"

typedef  std::vector<city_t*> city_loop_t;

class tour_manager_t
{
public:
	static tour_manager_t& get(void) {
		if( nullptr == p ){ p = new tour_manager_t(); }
		return *p;
	}

	void destroy(void){
		delete p;
		p = nullptr;
	}

	long get_city_count(void) const { return _cities.size(); }
	const city_t& get_city(const int idx) const { return *_cities[idx]; }
	const city_loop_t& get_cities(void) const { return _cities; }
	void add_city(city_t* c) { _cities.push_back(c); }
private:
	static tour_manager_t* p;
	city_loop_t _cities;
	tour_manager_t(void){
	}



};


#endif //TSP_TOUR_MANAGER_T_H
