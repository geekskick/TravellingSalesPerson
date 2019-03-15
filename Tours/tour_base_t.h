//
// Created by Patrick Mintram on 28/07/2017.
//

#ifndef TSP_TOUR_BASE_T_H
#define TSP_TOUR_BASE_T_H

#include "../City/city_t.h"
#include <vector>
typedef std::vector<city_t> city_loop_t;

class tour_base_t : public describable_t {
public:
    virtual unsigned long get_city_count(void) const;
    virtual const city_t &get_city(const size_t idx) const;
    virtual city_loop_t &get_cities(void);
    virtual void add_city(const city_t &c);
    virtual void set_city(const size_t idx, const city_t &c);
    virtual bool contains_city(const city_t &c) const;

protected:
    tour_base_t(void) {}
    city_loop_t _cities;
};

#endif // TSP_TOUR_BASE_T_H
