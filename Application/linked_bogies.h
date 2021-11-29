#ifndef LINKEDBOGIES_H
#define LINKEDBOGIES_H

#include <string>

#include "bogie.h"
#include "node.h"

class LinkedBogies {
	public:
		LinkedBogies(void);
		void insert(Bogie const &new_bogie);
		void insert_at(Bogie const &bogie, int const index);
		void replace(Bogie const &old_bogie, Bogie const &new_bogie);
		void remove(Bogie const &bogie);
		void remove_at(int const index);
		Bogie get(int const index) const;
		int get_size(void) const;
		bool is_empty(void) const;
	private:
		Node *front;
		int size;
};

#endif // LINKEDBOGIES_H
