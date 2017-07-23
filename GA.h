//
// Created by Patrick Mintram on 22/07/2017.
//

#ifndef TSP_GA_H
#define TSP_GA_H


#include "population_t.h"

class GA
{
public:

	static void mutate( tour_t *t );

	static population_t evolve_population( const population_t& input_pop){
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

protected:
	static const double _mutation_rate;
	static const int _tournament_size;
	static const bool _elitist;

	static tour_t *crossover( tour_t *pTour, tour_t *p2 );
	static tour_t *tournament_selection( const population_t &population );



};


#endif //TSP_GA_H
