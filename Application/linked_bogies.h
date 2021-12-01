#ifndef LINKEDBOGIES_H
#define LINKEDBOGIES_H

#include <queue>
#include <string>

#include "bogie.h"
#include "customer.h"
#include "node.h"

class LinkedBogies {
	public:
		LinkedBogies(void);
		void insert(Bogie const &new_bogie);
		void insert_at(Bogie const &bogie, int const index);
		void replace(std::string const &old_bogie_name, Bogie const &new_bogie);
		void remove(std::string const &bogie_name);
		void remove_at(int const index);
		Bogie get(int const index) const;
		int get_size(void) const;
		bool is_empty(void) const;
		int get_available_seats(void) const;
		void dequeue_customers(std::priority_queue<Customer> &customers);
		void send_train(void);
		std::string get_bogies_list(void) const;
	private:
		Node *front;
		int size;
};

#endif // LINKEDBOGIES_H
