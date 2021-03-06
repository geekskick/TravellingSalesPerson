#ifndef TSP_LOCATION_T_H
#define TSP_LOCATION_T_H

#include "../Utils/describable_t.h"

#include <cmath>
#include <cstdlib>
#include <sstream>
#include <utility>

class location_t : public describable_t {
public:
    location_t(void);
    location_t(const int x, const int y);
    const std::pair<int, int> &get_pair(void) const;
    double distance_to(const location_t &dest) const;
    int get_x(void) const;
    int get_y(void) const;
    void set_y(const int y);
    void set_x(const int x);
    void set_pair(const std::pair<int, int> &p);
    std::string to_string(void) const;

private:
    std::pair<int, int> _pair;
};

#endif // TSP_LOCATION_T_H
