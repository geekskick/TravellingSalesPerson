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
	tour_t(void): _cities(tour_manager_t::get().get_city_count(), empty_city_t()),_fitness(0.0),_distance(0.0)
	{}

	tour_t(const std::vector<city_t>& tour):
	_cities(tour), _fitness(0.0), _distance(0.0)
	{

	}

	~tour_t( ){
		//std::cout << "Deleting tour" << std::endl;
	}

	long get_city_count(void) { return _cities.size(); }
	void set_city( const int idx, const city_t& c) {
		_fitness = 0.0;
		_distance = 0.0;
		_cities[idx] = c;
	}

	void random_fill(){
		_cities = tour_manager_t::get().get_cities();
		std::random_shuffle(_cities.begin(), _cities.end());
	}

	static void randomize(city_loop_t& tour){
		std::random_shuffle(tour.begin(), tour.end());
	}

	const city_t& get_city(const int idx){
		return _cities[idx];
	}

	const double &get_fitness(void){
		if(_fitness == 0.0){
			_fitness = 1/get_distance();
		}
		return _fitness;
	}

	const double &get_fitness(void) const{
		if(_fitness == 0.0){
			_fitness = 1/get_distance();
		}
		return _fitness;
	}

	const double& get_distance(void){
		if(_distance == 0.0){
			double cumulative_distance = 0.0;
			std::vector<city_t>::const_iterator it;
			//all but the final city
			for( it = _cities.begin(); it < _cities.end() - 1; it++){
				cumulative_distance += it->get_location().distance_to((*(it+1)).get_location());
			}

			// final city goes back to the first one
			cumulative_distance += (*(_cities.end()-1)).get_location().distance_to((*_cities.begin()).get_location());
			_distance = cumulative_distance;


		}
		return _distance;

	}

	const double& get_distance(void) const {
		if(_distance == 0.0){
			double cumulative_distance = 0.0;
			std::vector<city_t>::const_iterator it;
			//all but the final city
			for( it = _cities.begin(); it < _cities.end() - 1; it++){
				cumulative_distance += it->get_location().distance_to((*(it+1)).get_location());
			}

			// final city goes back to the first one
			cumulative_distance += (*(_cities.end()-1)).get_location().distance_to((*_cities.begin()).get_location());
			_distance = cumulative_distance;


		}
		return _distance;

	}

	bool contains_city(const city_t& c){
		bool rc = false;
		std::vector<city_t>::iterator it = _cities.begin();
		while(it != _cities.end()){
			if(c.to_string() == (*it).to_string()) { rc = true; break; }
			it++;
		}
		return rc;
	}

	std::string to_string(void) const {
		std::stringstream ss;
		//ss << "Tour: " << std::endl;
		city_loop_t::const_iterator it;
		for(it = _cities.begin(); it != (_cities.end() - 1); it++){
				ss << ( *it ).get_name() << ",";
		}

		ss << (*(_cities.end()-1)).get_name() <<std::endl;
		ss << "Fitness: " << get_fitness() << std::endl;
		ss << "Distance: " << get_distance();
		return ss.str();

	}

	bool operator==(const tour_t& rhs){
		return this->get_fitness() == rhs.get_fitness();
	}
	bool operator<=(const tour_t& rhs){
		return this->get_fitness() <= rhs.get_fitness();
	}
	bool operator>(const tour_t& rhs){
		return this->get_fitness() > rhs.get_fitness();
	}
	bool operator<(const tour_t& rhs){
		return this->get_fitness() < rhs.get_fitness();
	}
	bool operator>=(const tour_t& rhs){
		return this->get_fitness() >= rhs.get_fitness();
	}

	bool is_empty() const
	{
		bool rc = true;
		std::vector<city_t>::const_iterator it = _cities.begin();
		for(; it != _cities.end(); it++){
			if(it->get_name() != empty_city_t::EMPTY)
			{
				rc = false;
				break;
			}
		}
		return rc;
	}

private:
	std::vector<city_t> _cities;
	mutable double _fitness;  // must be mutable to be used in to_string()
	mutable double _distance; // must be mutable to be used in to_string()
};



#endif //TSP_TOUR_T_H
