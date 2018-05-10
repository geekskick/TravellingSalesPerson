#ifndef TSP_TOUR_T_H
#define TSP_TOUR_T_H


#include <vector>
#include "../City/city_t.h"
#include "tour_base_t.h"

class tour_t: public tour_base_t
{
public:
	tour_t(void);
	tour_t(const std::vector<city_t>& tour);
	~tour_t(void);
	void set_city( const size_t idx, const city_t &c ) override;
	void random_fill();
	static void randomize(city_loop_t& tour);
	const double &get_fitness(void);
	const double &get_fitness(void) const;
	const double& get_distance(void);
	const double& get_distance(void) const;
	std::string to_string(void) const override;
	bool operator==(const tour_t& rhs);
	bool operator<=(const tour_t& rhs);
	bool operator>(const tour_t& rhs);
	bool operator<(const tour_t& rhs);
	bool operator>=(const tour_t& rhs);
	bool is_empty(void) const;
private:
	mutable double _fitness;  // must be mutable to be used in to_string()
	mutable double _distance; // must be mutable to be used in to_string()
};



#endif //TSP_TOUR_T_H
