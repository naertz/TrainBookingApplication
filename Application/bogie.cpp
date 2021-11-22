#include "bogie.h"

/****************/
/* Constructors */
/****************/

Bogie::Bogie(std::string const &name, unsigned int const max_capacity)
  : name(name)
  , occupied_seats(0)
  , max_capacity(max_capacity) { }

/************/
/* Mutators */
/************/

void Bogie::add_members(unsigned int const members) {
	if (occupied_seats + members <= max_capacity) {
		occupied_seats += members;
	}
}

/*************/
/* Accessors */
/*************/

std::string Bogie::get_name(void) const {
	return name;
}

unsigned int Bogie::get_occupied_seats(void) const {
	return occupied_seats;
}

unsigned int Bogie::get_max_capacity(void) const {
	return max_capacity;
}
