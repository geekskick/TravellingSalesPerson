#include <iostream>
#include <fstream>

#include "city_t.h"
#include "tour_manager_t.h"
#include "tour_t.h"
#include "population_t.h"
#include "GA.h"

#warning MEMORY LEAKS ABOUND!
///TODO: Remove the memory leaks which are all over the shop

void test(void){
	std::cout << "=====Testing TSP=====" << std::endl;
	city_t c0("first", 60, 60);
	city_t c1("second", 60, 70);
	city_t c2("third", 20, 100);
	city_t c3("fourth", 100, 40);
	city_t c4("fifth", 300, 300);

	tour_manager_t::get().add_city(&c1);
	tour_manager_t::get().add_city(&c0);
	tour_manager_t::get().add_city(&c2);
	tour_manager_t::get().add_city(&c3);
	tour_manager_t::get().add_city(&c4);

	auto c_v = tour_manager_t::get().get_cities();
	city_loop_t::const_iterator it = c_v.begin();

	// Print off contents of the tour manager
	for(; it < c_v.end() -1; it++)
	{
		std::cout << (*it)->to_string();
		std::cout << " in " << (*it)->get_location().distance_to((*(it+1))->get_location()) << std::endl;
	}

	std::cout << (*(c_v.end()-1))->to_string() << " is " << (*(c_v.end()-1))->get_location().distance_to((*c_v.begin())->get_location()) << " back to first " << std::endl;

	// Create a tour with the contents of the tour manager
	// all tours must be on heap
	tour_t *dt = new tour_t(c_v);
	tour_t &t1 = *dt;
	std::cout << "Fitness: " << t1.get_fitness() << std::endl << "Distance: " << t1.get_distance() << std::endl;
	std::cout << "EXPCECTING TRUE: " << (t1.contains_city(&c0)? "TRUE":"FALSE") << std::endl;
	std::cout << "EXPCECTING TRUE: " << (t1.contains_city(&c1)? "TRUE":"FALSE") << std::endl;
	std::cout << "EXPCECTING TRUE: " << (t1.contains_city(&c2)? "TRUE":"FALSE") << std::endl;
	std::cout << "EXPCECTING TRUE: " << (t1.contains_city(&c3)? "TRUE":"FALSE") << std::endl;
	std::cout << "EXPCECTING TRUE: " << (t1.contains_city(&c4)? "TRUE":"FALSE") << std::endl;

	// Check the tour doesn't contain an extra city even when it's added to the tour manager
	city_t c5("sixth", 600, 0);
	tour_manager_t::get().add_city(&c5);
	std::cout << "EXPCECTING FALSE: " << (t1.contains_city(&c5)? "TRUE":"FALSE") << std::endl;

	std::cout << t1.to_string() << std::endl;

	//population_t py(3, true);
	population_t py(tour_manager_t::get().get_city_count(), true);

	std::cout << py.to_string() << std::endl;

	/*for(int i = 0; i < py.get_size(); i++){
		py.set_tour(i, &t1);
	}*/

	std::cout << py.to_string() << std::endl;

	population_t pn(3, false);
	std::cout << pn.to_string() << std::endl;

	pn.set_tour(0, &t1);
	std::cout << pn.to_string() << std::endl;

	std::cout << "FITTEST EXPECTED TO BE " << t1.to_string() << " and calculated as " << pn.get_fittest()->to_string() << std::endl;

	//delete dt;
	dt = new tour_t(tour_manager_t::get().get_cities());
	pn.set_tour(2, &t1);
	std::cout << pn.to_string() << std::endl;

	population_t py2(3, true);
	//std::cout << py2.get_tour(0)->to_string() << " X " << py.get_tour(0)->to_string() << std::endl;
	//std::cout << GA::crossover(py.get_tour(0), py2.get_tour(0))->to_string() << std::endl;

	//std::cout << "tournament: " << py.to_string() << std::endl;
	//std::cout << GA::tournament_selection(py)->to_string() << std::endl;
	GA gen;
	 std::cout << "-----evolve gen 1-----" << std::endl;
	std::cout <<  gen.evolve_population(py).to_string()<< std::endl;
	std::cout << "-----evolve gen 2-----" << std::endl;
	std::cout <<  gen.evolve_population(py).to_string()<< std::endl;
	std::cout << "-----evolve gen 3-----" << std::endl;
	std::cout <<  gen.evolve_population(py).to_string()<< std::endl;


	std::cout << "=====Testing TSP Complete=====" << std::endl;
}
int main( )
{
	//test();

	city_t c0("first", std::rand() % 1000, std::rand() % 1000);
	city_t c1("second",std::rand() % 1000, std::rand() % 1000);
	city_t c2("third", std::rand() % 1000, std::rand() % 1000);
	city_t c3("fourth",std::rand() % 1000, std::rand() % 1000);
	city_t c4("fifth", std::rand() % 1000, std::rand() % 1000);
	city_t c5("sixth", std::rand() % 1000, std::rand() % 1000);
	city_t c6("seventh",std::rand() % 1000, std::rand() % 1000);
	city_t c7("eighth",std::rand() % 1000, std::rand() % 1000);
	city_t c8("nine", std::rand() % 1000, std::rand() % 1000);
	city_t c9("ten", std::rand() % 1000, std::rand() % 1000);
	city_t c10("eleven",std::rand() % 1000, std::rand() % 1000);
	city_t c11("twelve",std::rand() % 1000, std::rand() % 1000);
	city_t c12("thriteen",std::rand() % 1000, std::rand() % 1000);
	city_t c13("fourteen", std::rand() % 1000, std::rand() % 1000);
	city_t c14("fifthteen", std::rand() % 1000, std::rand() % 1000);

	tour_manager_t::get().add_city(&c0);
	tour_manager_t::get().add_city(&c1);
	tour_manager_t::get().add_city(&c2);
	tour_manager_t::get().add_city(&c3);
	tour_manager_t::get().add_city(&c4);
	tour_manager_t::get().add_city(&c5);
	tour_manager_t::get().add_city(&c6);
	tour_manager_t::get().add_city(&c7);
	tour_manager_t::get().add_city(&c8);
	tour_manager_t::get().add_city(&c9);
	tour_manager_t::get().add_city(&c10);
	tour_manager_t::get().add_city(&c11);
	tour_manager_t::get().add_city(&c12);
	tour_manager_t::get().add_city(&c13);
	tour_manager_t::get().add_city(&c14);

	std::ofstream ofile;
	ofile.open("results.csv", std::ios::app);
	if(!ofile.is_open()){
		std::cout << "Error opening file" << std::endl;
		return EXIT_FAILURE;
	}

	const int pop_size = 50;

	ofile << "=======New run=======" << std::endl;
	GA gen;
	ofile << gen.to_string();
	//ofile  << "popsize," << pop_size << std::endl;

	// show the locations of the cities
	for( int i = 0; i < tour_manager_t::get().get_city_count(); i++){
		std::cout << tour_manager_t::get().get_city(i).to_string() << std::endl;
		ofile << tour_manager_t::get().get_city(i).to_string() << "," << std::endl;
	}

	// true means to randomly generate a bunch of tours in the population
	// the population size here is the city count value.

	// an indiviual in the population is a route
	// and a population is a bunch of routes to try
	// population_t p(pop_size, true);

//	double fittest = 0.0;
//	for(int i = 0; i < 100; i++){
//		p = GA::get().evolve_population(p);
//		if( p.get_fittest()->get_fitness() > fittest) { fittest = p.get_fittest()->get_fitness(); }
//		std::cout << i << " Fitness: " << p.get_fittest()->get_fitness() << std::endl;
//		//ofile << i << "," << p.get_fittest()->get_fitness() << "," << std::endl;
//
//	}

	for(int po = 1; po < 40; po++){
		ofile << "popsize," << po << std::endl;
		population_t p(po, true);
		for(int i = 1; i <= 100; i++){
			p = gen.evolve_population(p);
			ofile << "gen," << i << ",fitness," << p.get_fittest()->get_fitness() << std::endl;
		}
		ofile << "route," << p.get_fittest()->to_string() << std::endl;
	}

//	std::cout << "Fittest recorded: " << fittest << " and the fittest at end is " << p.get_fittest()->get_fitness() << std::endl;
//	std::cout << "Route: " << p.get_fittest()->to_string() << std::endl;
//	ofile << "Route," <<  p.get_fittest()->to_string() << std::endl;
	tour_manager_t::get().destroy();

	ofile.close();
	return 0;
}