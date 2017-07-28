#ifndef TSP_FILE_READER_T_H
#define TSP_FILE_READER_T_H


#include "../City/location_t.h"
#include <fstream>

class file_reader_t
{
public:
	file_reader_t(const std::string& file);
	~file_reader_t( void );
	void close(void);
	bool get_city( std::string &name, location_t &co_ords );
	bool get_city( std::string &name, int &x, int &y );
protected:
	std::ifstream _input;
	const std::string _name;

	void ensure_open(void);


};


#endif //TSP_FILE_READER_T_H
