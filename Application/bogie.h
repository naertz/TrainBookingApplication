#ifndef BOGIE_H
#define BOGIE_H

class Bogie {
	public:
		Bogie(unsigned int const max_capacity);
		void add_members(unsigned int const members);
		unsigned int get_occupied_seats(void) const;
		unsigned int get_max_capacity(void) const;
	private:
		unsigned int occupied_seats;
		unsigned int max_capacity;
};

#endif // BOGIE_H
