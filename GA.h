//
// Created by Patrick Mintram on 22/07/2017.
//

#ifndef TSP_GA_H
#define TSP_GA_H


#include "population_t.h"

class GA: describable_t
{
public:

	void mutate( tour_t &t );
	population_t evolve_population( population_t& input_pop);


	std::string to_string(void) const;

	double get_mutation_rate(void);
	int get_tournament_size(void);
	bool is_elitist(void);
	void set_tournament_size(const int s);
	void set_mutation_rate(const double m);
	void set_elitism(const bool e);

	GA(): _mutation_rate(RAND_MAX * 0.015), _tournament_size(3), _elitist(true)
	{ }
protected:
	double _mutation_rate;
	int _tournament_size;
	bool _elitist;

	tour_t &crossover( tour_t &pTour, tour_t &p2, tour_t &child );
	tour_t tournament_selection( population_t &population );
	void duplicate_check( tour_t &t ) const;
};


#endif //TSP_GA_H
