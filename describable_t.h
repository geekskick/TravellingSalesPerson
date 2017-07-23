//
// Created by Patrick Mintram on 22/07/2017.
//

#ifndef TSP_DESCRIBABLE_T_H
#define TSP_DESCRIBABLE_T_H


#include <string>

class describable_t{
public:
	virtual std::string to_string(void) const = 0;
};


#endif //TSP_DESCRIBABLE_T_H
