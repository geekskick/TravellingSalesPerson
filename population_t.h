//
// Created by Patrick Mintram on 22/07/2017.
//

#ifndef TSP_POPULATION_T_H
#define TSP_POPULATION_T_H


#include <vector>
#include "describable_t.h"
#include "tour_t.h"

class population_t: public describable_t{
public:
	population_t(const size_t pop_size, const bool initialise)
	:_tours(pop_size, tour_t() )
	{
		std::vector<tour_t>::iterator it;
		if( initialise )
		{
			for( it = _tours.begin(); it != _tours.end(); it++ )
			{
				it->random_fill();
			}
		}
	}

	~population_t( ){	}

	void set_tour(const int idx, tour_t t){
		_tours[idx] = t;
	}

	tour_t& get_tour(const int idx){
		return _tours[idx];
	}

	tour_t get_fittest(void){
		return *std::max_element(_tours.begin(), _tours.end(), myfn);
	}

	size_t get_size(void) const { return _tours.size(); }

	std::string to_string(void) const{
		std::stringstream ss;
		int i = 1;
		ss << "Tours: " << std::endl;
		std::vector<tour_t>::const_iterator it;
		for( it = _tours.begin(); it != _tours.end(); it++){
				ss << i++ << ": " << it->to_string() << std::endl;

		}
		return ss.str();
	}


protected:

	std::vector<tour_t> _tours;
	static bool myfn(tour_t& i, tour_t& j) {
		if(i.is_empty() && j.is_empty()) { return false; }
		if(i.is_empty()) { return true; }
		if(j.is_empty()) { return false; }
		return i<j;
	}




};



#endif //TSP_POPULATION_T_H
