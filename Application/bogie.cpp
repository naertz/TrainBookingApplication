#include "bogie.h"

/****************/
/* Constructors */
/****************/

Bogie::Bogie(std::string const &name, int const max_capacity)
  : name(name)
  , occupied_seats(0)
  , max_capacity(max_capacity) { }

/************/
/* Mutators */
/************/

void Bogie::add_members(int const members) {
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

int Bogie::get_occupied_seats(void) const {
	return occupied_seats;
}

int Bogie::get_max_capacity(void) const {
	return max_capacity;
}
