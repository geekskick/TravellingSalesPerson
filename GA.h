//
// Created by Patrick Mintram on 22/07/2017.
//

#ifndef TSP_GA_H
#define TSP_GA_H


#include "population_t.h"

class GA: describable_t
{
public:

	void mutate( tour_t *t );

	population_t evolve_population( const population_t& input_pop){
		population_t next_pop(input_pop.get_size(), false);
		int elitism_offset = 0;
		if(_elitist){
			elitism_offset++;
			next_pop.set_tour(0, input_pop.get_tour(0));
		}

		for(int i = elitism_offset; i < input_pop.get_size(); i++){
			tour_t* p1 = tournament_selection(input_pop);
			tour_t* p2 = tournament_selection(input_pop);
			tour_t* child = crossover(p1, p2);
			mutate(child);
			next_pop.set_tour(i, child);
		}

		return next_pop;

	}

	std::string to_string(void) const {
		std::stringstream ss;
		ss << "Mutation Rate," << _mutation_rate << "," << std::endl;
		ss << "Tournament Size," << _tournament_size << "," << std::endl;
		ss << "Elitism," << _elitist << "," << std::endl;
		return ss.str();
	}


	double get_mutation_rate(void) { return _mutation_rate; }
	int get_tournament_size(void) { return _tournament_size; }
	bool is_elitist(void){ return _elitist; }
	void set_tournament_size(const int s) { _tournament_size = s; }
	void set_mutation_rate(const double m) { _mutation_rate = m; }
	void set_elitism(const bool e){ _elitist = e; }

	GA()
			: _mutation_rate(RAND_MAX * 0.015), _tournament_size(3), _elitist(true)
	{ }
protected:
	double _mutation_rate;
	int _tournament_size;
	bool _elitist;

	tour_t *crossover( tour_t *pTour, tour_t *p2 );
	tour_t *tournament_selection( const population_t &population );



};


#endif //TSP_GA_H
