//
// Created by Patrick Mintram on 22/07/2017.
//

#ifndef TSP_TOUR_T_H
#define TSP_TOUR_T_H


#include <vector>
#include "city_t.h"
#include "tour_manager_t.h"

class tour_t: public describable_t
{
public:
	tour_t(void);
	tour_t(const std::vector<city_t>& tour);
	~tour_t(void);
	long get_city_count(void);
	void set_city( const int idx, const city_t& c);
	void random_fill();
	static void randomize(city_loop_t& tour);
	const city_t get_city(const int idx);
	const double &get_fitness(void);
	const double &get_fitness(void) const;
	const double& get_distance(void);
	const double& get_distance(void) const;
	bool contains_city(const city_t& c);
	std::string to_string(void) const;
	bool operator==(const tour_t& rhs);
	bool operator<=(const tour_t& rhs);
	bool operator>(const tour_t& rhs);
	bool operator<(const tour_t& rhs);
	bool operator>=(const tour_t& rhs);
	bool is_empty(void) const;
	std::vector<city_t>& get_cities(void);
private:
	std::vector<city_t> _cities;
	mutable double _fitness;  // must be mutable to be used in to_string()
	mutable double _distance; // must be mutable to be used in to_string()
};



#endif //TSP_TOUR_T_H
