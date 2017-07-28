#ifndef TSP_POPULATION_T_H
#define TSP_POPULATION_T_H


#include <vector>
#include "describable_t.h"
#include "tour_t.h"

class population_t: public describable_t{
public:
	population_t(const size_t pop_size, const bool initialise);
	~population_t( ){	}
	void set_tour(const size_t idx, tour_t t);
	tour_t& get_tour(const size_t idx);
	tour_t get_fittest(void);
	size_t get_size(void) const;
	std::string to_string(void) const;

protected:

	std::vector<tour_t> _tours;
	static bool comparison_function(tour_t& i, tour_t& j);

};



#endif //TSP_POPULATION_T_H
