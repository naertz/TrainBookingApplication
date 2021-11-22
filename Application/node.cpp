#include "node.h"

/****************/
/* Constructors */
/****************/

Node::Node(Bogie bogie)
  : bogie(bogie)
  , next(nullptr) { }

/************/
/* Mutators */
/************/

void Node::set_bogie(Bogie bogie) {
	this->bogie = bogie;
}

void Node::set_next_node(Node *next) {
	this->next = next;
}

/*************/
/* Accessors */
/*************/

Bogie Node::get_bogie(void) const {
	return bogie;
}

Node *Node::get_next_node(void) const {
	return next;
}
