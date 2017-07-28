//
// Created by Patrick Mintram on 22/07/2017.
//

#ifndef TSP_TOUR_MANAGER_T_H
#define TSP_TOUR_MANAGER_T_H


#include <vector>
#include "city_t.h"

typedef  std::vector<city_t> city_loop_t;

class tour_manager_t
{
public:
	static tour_manager_t& get(void);
	void destroy(void);
	long get_city_count(void) const;
	const city_t& get_city(const int idx) const;
	const city_loop_t& get_cities(void) const;
	void add_city(const city_t& c);

private:

	static tour_manager_t* p;

	typedef std::vector<city_t> city_loop_t;
	city_loop_t _cities;

	tour_manager_t(void){}



};


#endif //TSP_TOUR_MANAGER_T_H
