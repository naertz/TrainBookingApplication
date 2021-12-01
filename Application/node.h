#ifndef NODE_H
#define NODE_H

#include "bogie.h"

class Node {
	public:
		Node(Bogie const &bogie);
		void set_bogie(Bogie const &bogie);
		void set_next_node(Node *const next);
		Bogie &get_bogie(void);
		Node *get_next_node(void) const;
	private:
		Bogie bogie;
		Node *next;
};

#endif // NODE_H
