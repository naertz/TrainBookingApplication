#include "node.h"

/****************/
/* Constructors */
/****************/

Node::Node(Bogie const &bogie)
  : bogie(bogie)
  , next(nullptr) { }

/************/
/* Mutators */
/************/

void Node::set_bogie(Bogie const &bogie) {
	this->bogie = bogie;
}

void Node::set_next_node(Node *const next) {
	this->next = next;
}

/*************/
/* Accessors */
/*************/

Bogie &Node::get_bogie(void) {
	return bogie;
}

Node *Node::get_next_node(void) const {
	return next;
}
