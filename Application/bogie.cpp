#include "bogie.h"

/****************/
/* Constructors */
/****************/

Bogie::Bogie(unsigned int const max_capacity)
  : occupied_seats(0)
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

unsigned int Bogie::get_occupied_seats(void) const {
	return occupied_seats;
}

unsigned int Bogie::get_max_capacity(void) const {
	return max_capacity;
}
