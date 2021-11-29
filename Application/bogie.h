#ifndef BOGIE_H
#define BOGIE_H

#include <string>

class Bogie {
	public:
		Bogie(std::string const &name, int const max_capacity);
		void add_members(int const members);
		std::string get_name(void) const;
		int get_occupied_seats(void) const;
		int get_max_capacity(void) const;
	private:
		std::string name;
		int occupied_seats;
		int max_capacity;
};

#endif // BOGIE_H
