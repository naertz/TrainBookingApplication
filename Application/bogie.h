#ifndef BOGIE_H
#define BOGIE_H

#include <string>

class Bogie {
	public:
		Bogie(std::string const &name, unsigned int const max_capacity);
		void add_members(unsigned int const members);
		std::string get_name(void) const;
		unsigned int get_occupied_seats(void) const;
		unsigned int get_max_capacity(void) const;
	private:
		std::string name;
		unsigned int occupied_seats;
		unsigned int max_capacity;
};

#endif // BOGIE_H
