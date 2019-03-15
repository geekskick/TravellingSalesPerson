#ifndef TSP_TOUR_MANAGER_T_H
#define TSP_TOUR_MANAGER_T_H

#include "../City/city_t.h"
#include "tour_base_t.h"
#include <vector>

typedef std::vector<city_t> city_loop_t;

class tour_manager_t : public tour_base_t {
public:
    static tour_manager_t &get(void);
    void destroy(void);
    std::string to_string(void) const override;

private:
    static tour_manager_t *p;
};

#endif // TSP_TOUR_MANAGER_T_H
