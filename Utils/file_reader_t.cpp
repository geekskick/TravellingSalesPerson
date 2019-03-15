

#include "file_reader_t.h"
#include <iostream>

void file_reader_t::close(void) { _input.close(); }

bool file_reader_t::get_city(std::string &name, location_t &co_ords) {
    int x, y;
    bool rc = get_city(name, x, y);
    co_ords.set_pair({x, y});
    return rc;
}

/// TODO: Add some error checking in here
bool file_reader_t::get_city(std::string &name, int &x, int &y) {
    ensure_open();
    bool rc = false;
    if (!_input.eof()) {
        _input >> name >> x >> y;
        rc = true;
    }
    return rc;
}

void file_reader_t::ensure_open(void) {
    const int attempts_limit = 5;
    static int attempts = 0;
    if (!_input.is_open()) {
        _input.open(_name, std::ios::in);
        if (!_input.is_open()) {
            attempts++;
            if (attempts < attempts_limit) {
                ensure_open();
            } else {
                std::cerr << "Can't open file " << _name << std::endl;
                throw;
            }
        }
        attempts = 0;
    }
}

file_reader_t::file_reader_t(const std::string &file) : _input(), _name(file) {}

file_reader_t::~file_reader_t(void) { close(); }
