#ifndef NODE_H
#define NODE_H

#include "bogie.h"

class Node {
	public:
		Node(Bogie bogie);
		void set_bogie(Bogie bogie);
		void set_next_node(Node *next);
		Bogie get_bogie(void) const;
		Node *get_next_node(void) const;
	private:
		Bogie bogie;
		Node *next;
};

#endif // NODE_H
