//
// Created by Patrick Mintram on 22/07/2017.
//

#include "GA.h"


tour_t GA::tournament_selection( population_t &population )
{
	population_t pop(_tournament_size, false);
	for(int i = 0; i < _tournament_size; i++){
		int random = std::rand() % population.get_size();
		pop.set_tour(i, population.get_tour(random));
	}

	//std::cout << "tournament selection chose: " << pop.to_string();
	return pop.get_fittest();
}

tour_t &GA::crossover( tour_t &p1, tour_t &p2, tour_t &child)
{
	int start = int(rand() % p1.get_city_count());
	int end = int((rand() % (p1.get_city_count() - start)) + start);

	//std::cout << "xover chosen " << start << " to " << end << std::endl;

	for(int i = start; i < end; i++){
		child.set_city(i, p1.get_city(i));
	}

	for( int i = 0; i < p2.get_city_count(); i++){
		if(!child.contains_city(p2.get_city(i))){
			for(int ii = 0; ii < child.get_city_count(); ii++){
				if(child.get_city(ii).get_name() == empty_city_t::EMPTY){
					child.set_city(ii, p2.get_city(i));
					break;
				}
			}
		}
	}

	return child;
}

population_t GA::evolve_population(population_t& input_pop){
	population_t next_pop(input_pop.get_size(), false);
	int elitism_offset = 0;
	if(_elitist){
		elitism_offset++;
		next_pop.set_tour(0, input_pop.get_tour(0));
	}

	for(int i = elitism_offset; i < input_pop.get_size(); i++){
		tour_t child;
		tour_t p1 = tournament_selection(input_pop);
		tour_t p2 = tournament_selection(input_pop);
		crossover(p1, p2, child);
		mutate(&child);
		next_pop.set_tour(i, child);
	}

	return next_pop;

}

void GA::mutate( tour_t *t )
{
	for(int i = 0; i < t->get_city_count(); i++){
		int random = std::rand();
		if(random < _mutation_rate){
			int rand_idx = int(std::rand() % t->get_city_count());
			const city_t& c1 = t->get_city(i);
			const city_t& c2 = t->get_city(rand_idx);

			t->set_city(i, c2);
			t->set_city(rand_idx, c1);
		}
	}

}
