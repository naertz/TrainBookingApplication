#ifndef LINKEDBOGIES_H
#define LINKEDBOGIES_H

#include <string>

#include "bogie.h"
#include "node.h"

class LinkedBogies {
	public:
		LinkedBogies(void);
		void insert(Bogie new_bogie);
		void insert_at(Bogie bogie, int index);
		void replace(Bogie old_bogie, Bogie new_bogie);
		void remove(Bogie bogie);
		void remove_at(int index);
		Bogie get(int index) const;
		int get_size(void) const;
		bool is_empty(void) const;
	private:
		Node *front;
		int size;
};

#endif // LINKEDBOGIES_H
