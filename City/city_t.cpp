#include "city_t.h"

const std::string empty_city_t::EMPTY = "EMPTY";

//--------------
std::string city_t::to_string(void) const {
    std::stringstream ss;
    ss << "Name: " << _name << ", \tLocation: " << _location.to_string();
    return ss.str();
}

//--------------
const std::string &city_t::get_name(void) const { return _name; }

//--------------
const location_t &city_t::get_location(void) const { return _location; }
