#include "bogie.h"

/****************/
/* Constructors */
/****************/

Bogie::Bogie(std::string const &name, int const max_capacity)
  : name(name)
  , available_seats(max_capacity <= 0 ? 1 : max_capacity)
  , max_capacity(max_capacity <= 0 ? 1 : max_capacity) {
	for (int i = 0; i < max_capacity; ++i) {
		members.push_back("Empty");
	}
}

/************/
/* Mutators */
/************/

void Bogie::add_member(Member const &member) {
	if (available_seats - 1 >= 0) {
		members[max_capacity - available_seats] = member.get_first_name() + " " + member.get_last_name();
		available_seats -= 1;
	}
}

/*************/
/* Accessors */
/*************/

std::string Bogie::get_name(void) const {
	return name;
}

int Bogie::get_available_seats(void) const {
	return available_seats;
}

int Bogie::get_max_capacity(void) const {
	return max_capacity;
}

/*************/
/* Functions */
/*************/

std::string Bogie::get_bogie_information(void) const {
	std::string bogie_information = "Bogie: " + name;
	for (unsigned int i = 0; i < members.size(); ++i) {
		bogie_information += "\n" + members[i];
	}
	return bogie_information;
}
