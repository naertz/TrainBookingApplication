#include "linked_bogies.h"

#include "linked_bogies_empty_exception.h"
#include "linked_bogies_invalid_argument_exception.h"
#include "linked_bogies_out_of_range_exception.h"

/****************/
/* Constructors */
/****************/

LinkedBogies::LinkedBogies(void)
  : front(nullptr)
  , size(0) { }

/************/
/* Mutators */
/************/

void LinkedBogies::insert(Bogie new_bogie) {
	// Allocate a new node pointer.
	Node *new_node = new Node(new_bogie);

	// Set the front node pointer to the new node pointer if the linked bogies list is empty.
	if (front == nullptr) {
		front = new_node;
		// Increment the size.
		++size;
	// Add new node pointer to the end of the linked bogies list.
	} else {
		// Initialize the iterator node pointer as the front node pointer.
		Node *iterator = front;

		// Traverse to the end of the linked bogies list.
		while (iterator->get_next_node() != nullptr) iterator = iterator->get_next_node();

		// Set the last node pointer to the new node pointer.
		iterator->set_next_node(new_node);
		// Increment the size.
		++size;
	}
}

void LinkedBogies::insert_at(Bogie new_bogie, int index) {
	// Throw exception if the index is invalid.
	if (index < 0) throw LinkedBogiesOutOfRangeException();

	// Allocate a new node pointer.
	Node *new_node = new Node(new_bogie);

	// Determine if the linked bogies list is empty.
	if (front == nullptr) {
		// Determine if the index is zero.
		if (index == 0) {
			// Set the front node pointer to the new node pointer.
			front = new_node;
			// Increment the size.
			++size;
			// The given index is out of range.
		} else {
			delete new_node;
			// Throw out of range index exception.
			throw LinkedBogiesOutOfRangeException();
		}
	// Add a new node pointer to end of the linked bogies list if the index is valid.
	} else {
		// Determine if the index is zero.
		if (index == 0) {
			// Allocate a node pointer for the old front node pointer.
			Node *old_front = front;
			// Assign the front node pointer to the new node pointer.
			front = new_node;
			// Set the next node pointer of the new front node pointer to the old front node pointer.
			front->set_next_node(old_front);
			// Increment the size.
			++size;
		} else {
			// Initialize iterator node pointer as the front node pointer.
			Node *iterator = front;

			// Attempt to traverse to the end of the index.
			for (int i = 0; i < index; ++i) {
				// Determine if the next node pointer is null.
				if (iterator->get_next_node() == nullptr) {
					// Determine if the index is the end of the current linked bogies list.
					if (i + 1 == index) {
						// Set the last node pointer to the new node pointer.
						iterator->set_next_node(new_node);
						// Increment the size.
						++size;
						// Exit loop.
						break;
					// The given index is out of range.
					} else {
						delete new_node;
						// Throw out of range index exception.
						throw LinkedBogiesOutOfRangeException();
					}
				// Determine if the next index is the given index.
				} else if (i + 1 == index) {
					// Allocate a node pointer for the old next node pointer.
					Node *old_next = iterator->get_next_node();
					// Assign the next node pointer of the current node pointer to the new node pointer.
					iterator->set_next_node(new_node);
					// Assign the next node pointer of the new node pointer to the old next node pointer.
					new_node->set_next_node(old_next);
					// Increment the size.
					++size;
					// Exit loop.
					break;
				// Iterate to the next node pointer.
				} else iterator = iterator->get_next_node();
			}
		}
	}
}

void LinkedBogies::replace(Bogie old_bogie, Bogie new_bogie) {
	// Throw exception if the linked bogies list is empty.
	if (front == nullptr) throw LinkedBogiesEmptyException();
	else {
		// Initialize iterator node pointer as the front node pointer.
		Node* iterator = front;

		// Boolean to signal if old bogie is found
		bool is_old_bogie_found = false;

		// Traverse to the end of the linked bogies list.
		while (iterator->get_next_node() != nullptr) {
			// Determine if the current node pointer contains the old bogie.
			if (iterator->get_bogie().get_name() == old_bogie.get_name()) {
				is_old_bogie_found = true;
				// Replace bogie.
				iterator->set_bogie(new_bogie);
				// Exit loop.
				break;
			}

			iterator = iterator->get_next_node();
		}

		// Determine if the old bogie is not found yet.
		if (!is_old_bogie_found) {
			// Determine if the current node pointer contains the old bogie.
			if (iterator->get_bogie().get_name() == old_bogie.get_name()) iterator->set_bogie(new_bogie);
			// Throw exception for non-existing old bogie.
			else throw LinkedBogiesInvalidArgumentException();
		}
	}
}

void LinkedBogies::remove(Bogie bogie) {
	// Throw exception if the linked bogies list is empty.
	if (front == nullptr) throw LinkedBogiesEmptyException();
	// Determine if the front node pointer contains the given bogie name.
	else if (front->get_bogie().get_name() == bogie.get_name()) {
		// Set the front node pointer to the next node pointer.
		front = front->get_next_node();
		// Decrement the size.
		--size;
	} else {
		// Initialize iterator node pointer as the front node pointer.
		Node *iterator = front;

		// Boolean to signal if the given bogie is found
		bool is_bogie_found = false;

		// Traverse to the end of the linked bogies list.
		while (iterator->get_next_node() != nullptr) {
			// Determine if the next node pointer contains the given bogie name.
			if (iterator->get_next_node()->get_bogie().get_name() == bogie.get_name()) {
				is_bogie_found = true;
				// Set the next node of the current node pointer to the next node pointer of the next node pointer.
				iterator->set_next_node(iterator->get_next_node()->get_next_node());
				// Decrement the size.
				--size;
				// Exit loop.
				break;
			}

			iterator = iterator->get_next_node();
		}

		// Determine if the old bogie is not found.
		if (!is_bogie_found) throw LinkedBogiesInvalidArgumentException();
	}
}

void LinkedBogies::remove_at(int index) {
	// Throw exception if the index is invalid.
	if (index < 0) throw LinkedBogiesOutOfRangeException();

	// Throw exception if the linked bogies list is empty.
	if (front == nullptr) throw LinkedBogiesEmptyException();
	// Determine if the index is zero.
	else if (index == 0) {
		// Set the front node pointer to the next node pointer.
		front = front->get_next_node();
		// Decrement the size.
		--size;
	} else {
		// Initialize iterator node pointer as the front node pointer.
		Node *iterator = front;

		// Attempt to traverse to the end of the index.
		for (int i = 0; i < index; ++i) {
			// Determine if the next node pointer is null.
			if (iterator->get_next_node()->get_next_node() == nullptr) {
				// Determine if the index is the end of the current linked bogies list.
				if (i + 1 == index) {
					// Set the current node pointer to the null pointer of the next node pointer.
					iterator->set_next_node(iterator->get_next_node()->get_next_node());
					// Decrement the size.
					--size;
					// Exit loop.
					break;
				// The given index is out of range.
				} else throw LinkedBogiesOutOfRangeException();
			// Determine if the next index is the given index.
			} else if (i + 1 == index) {
				// Set the current node pointer to the next node pointer of the next node pointer.
				iterator->set_next_node(iterator->get_next_node()->get_next_node());
				// Decrement the size.
				--size;
				// Exit loop.
				break;
			// Iterate to the next node pointer.
			} else iterator = iterator->get_next_node();
		}
	}
}

/*************/
/* Accessors */
/*************/

Bogie LinkedBogies::get(int index) const {
	// Return if the linked bogies list is empty.
	if (front == nullptr) throw LinkedBogiesEmptyException();
	// Determine if the index is zero.
	else if (index == 0) return front->get_bogie();
	else {
		// Initialize iterator node pointer as the front node pointer.
		Node *iterator = front;

		// Attempt to traverse to the end of the index.
		for (int i = 0; i < index; ++i) {
			// Determine if the next node pointer is null.
			if (iterator->get_next_node()->get_next_node() == nullptr) {
				// Determine if the index is the end of the current linked bogies list.
				if (i + 1 == index) return iterator->get_next_node()->get_bogie();
				// The given index is out of range.
				else throw LinkedBogiesOutOfRangeException();
			// Determine if the next index is the given index.
			} else if (i + 1 == index) break;
			// Iterate to the next node pointer.
			else iterator = iterator->get_next_node();
		}

		// Return the next node pointer.
		return iterator->get_next_node()->get_bogie();
	}
}

int LinkedBogies::get_size() const {
	return size;
}

bool LinkedBogies::is_empty() const {
	return front == nullptr;
}