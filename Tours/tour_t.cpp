#include "tour_t.h"
#include "tour_manager_t.h"
//------------
tour_t::tour_t(void) : _fitness(0.0), _distance(0.0) { _cities = city_loop_t(tour_manager_t::get().get_city_count(), empty_city_t()); }

//------------
tour_t::tour_t(const std::vector<city_t> &tour) : _fitness(0.0), _distance(0.0) { _cities = tour; }

//------------
tour_t::~tour_t(void) {
    // std::cout << "Deleting tour" << std::endl;
}

//------------
void tour_t::random_fill() {
    _cities = tour_manager_t::get().get_cities();
    std::random_shuffle(_cities.begin(), _cities.end());
}

//------------
void tour_t::randomize(city_loop_t &tour) { std::random_shuffle(tour.begin(), tour.end()); }

//------------
const double &tour_t::get_fitness(void) {
    if (_fitness == 0.0) {
        _fitness = 1 / get_distance();
    }
    return _fitness;
}

//------------
const double &tour_t::get_fitness(void) const {
    if (_fitness == 0.0) {
        _fitness = 1 / get_distance();
    }
    return _fitness;
}

//------------
const double &tour_t::get_distance(void) { return get_distance(); }

//------------
const double &tour_t::get_distance(void) const {
    if (_distance == 0.0) {
        double cumulative_distance = 0.0;
        std::vector<city_t>::const_iterator it;
        // all but the final city
        for (it = _cities.begin(); it < _cities.end() - 1; it++) {
            cumulative_distance += it->get_location().distance_to((*(it + 1)).get_location());
        }

        // final city goes back to the first one
        cumulative_distance += (*(_cities.end() - 1)).get_location().distance_to((*_cities.begin()).get_location());
        _distance = cumulative_distance;
    }
    return _distance;
}

//------------
std::string tour_t::to_string(void) const {
    std::stringstream ss;
    // ss << "Tour: " << std::endl;
    city_loop_t::const_iterator it;
    for (it = _cities.begin(); it != (_cities.end() - 1); it++) {
        ss << (*it).get_name() << " to ";
    }

    ss << (*(_cities.end() - 1)).get_name() << std::endl;
    ss << "Fitness: " << get_fitness() << std::endl;
    ss << "Distance: " << get_distance();
    return ss.str();
}

//------------
bool tour_t::operator==(const tour_t &rhs) { return this->get_fitness() == rhs.get_fitness(); }

//------------
bool tour_t::operator<=(const tour_t &rhs) { return this->get_fitness() <= rhs.get_fitness(); }

//------------
bool tour_t::operator>(const tour_t &rhs) { return this->get_fitness() > rhs.get_fitness(); }

//------------
bool tour_t::operator<(const tour_t &rhs) { return this->get_fitness() < rhs.get_fitness(); }

//------------
bool tour_t::operator>=(const tour_t &rhs) { return this->get_fitness() >= rhs.get_fitness(); }

//------------
bool tour_t::is_empty(void) const {
    bool rc = true;
    std::vector<city_t>::const_iterator it = _cities.begin();
    for (; it != _cities.end(); it++) {
        if (it->get_name() != empty_city_t::EMPTY) {
            rc = false;
            break;
        }
    }
    return rc;
}

void tour_t::set_city(const size_t idx, const city_t &c) {
    _fitness = 0.0;
    _distance = 0.0;
    tour_base_t::set_city(idx, c);
}
