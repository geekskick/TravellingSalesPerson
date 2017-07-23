//
// Created by Patrick Mintram on 22/07/2017.
//

#include "GA.h"

const double GA::_mutation_rate = RAND_MAX * 0.015;
const int GA::_tournament_size = 8;
const bool GA::_elitist = true;

tour_t *GA::tournament_selection( const population_t &population )
{
	population_t pop(_tournament_size, false);
	for(int i = 0; i < _tournament_size; i++){
		int random = std::rand() % population.get_size();
		pop.set_tour(i, population.get_tour(random));
	}

	//std::cout << "tournament selection chose: " << pop.to_string();
	return pop.get_fittest();
}

tour_t *GA::crossover( tour_t *p1, tour_t *p2 )
{
	tour_t *child = new tour_t();
	int start = int(rand() % p1->get_city_count());
	int end = int((rand() % (p1->get_city_count() - start)) + start);

	//std::cout << "xover chosen " << start << " to " << end << std::endl;

	for(int i = start; i < end; i++){
		child->set_city(i, p1->get_city(i));
	}

	for( int i = 0; i < p2->get_city_count(); i++){
		if(!child->contains_city(p2->get_city(i))){
			for(int ii = 0; ii < child->get_city_count(); ii++){
				if(child->get_city(ii) == nullptr){
					child->set_city(ii, p2->get_city(i));
					break;
				}
			}
		}
	}

	return child;
}

void GA::mutate( tour_t *t )
{
	for(int i = 0; i < t->get_city_count(); i++){
		int random = std::rand();
		if(random < _mutation_rate){
			int rand_idx = int(std::rand() % t->get_city_count());
			city_t* c1 = t->get_city(i);
			city_t* c2 = t->get_city(rand_idx);

			t->set_city(i, c2);
			t->set_city(rand_idx, c1);
		}
	}

}
