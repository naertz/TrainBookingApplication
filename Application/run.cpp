/*****************************************************************************************************************************
* Name             : Train Booking Application
* Author           : Noah Allan Ertz
* Created          : 11/04/2021
* Course           : CIS 152 - Data Structures
* Version          : 1.0
* OS               : Windows 10
* IDE              : Qt 5.12.5
* Copyright        : This is my own original work based on specifications issued by our instructor.
* Description      : Runs train booking application.
*                    Input:  Menu options
*                    Output: Customer priority queue, bogie linked list with list of customers, and prompts for customer entry
* Academic Honesty : I attest that this is my original work. I have not used unauthorized source code, either modified or
*                    unmodified. I have not given other fellow students access to my program.
*****************************************************************************************************************************/

#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

#include "customer.h"
#include "linked_bogies.h"
#include "party_member.h"
#include "validation.h"

int get_longest_string_length(std::vector<std::string> const &column_strings);

int main() {
	// Create customer priority queue.
	std::priority_queue<Customer> customer_queue;

	// Create bogie linked list.
	LinkedBogies linked_bogie_list;

	// Print the title of the program.
	std::cout << "Train Booking Application\n";

	// Option selections initialized for while loops
	int main_option_selection = -1;
	int customers_option_selection = -1;
	int trains_option_selection = -1;

	// Vector of strings for main options to use to determine dynamic padding
	std::vector<std::string> main_number_column = { "#", "0", "1", "2" };
	std::vector<std::string> main_option_column = { "Option", "Customers", "Trains", "Quit" };

	// Length of longest string of each main menu column
	const int longest_main_number_length = get_longest_string_length(main_number_column);
	const int longest_main_option_length = get_longest_string_length(main_option_column);

	// Lengths of each width for padding
	const int main_number_width = longest_main_number_length;
	const int main_option_width = longest_main_option_length + 4;

	// String input
	std::string string_input = "";

	while (main_option_selection != 2) {
		int exit_value;

		// Print formatted table.
		std::stringstream main_option_menu;
		main_option_menu << "\n";
		for (unsigned int i = 0; i < main_number_column.size(); ++i) {
			main_option_menu << std::left << std::setw(main_number_width) << main_number_column[i] << std::right << std::setw(main_option_width) << main_option_column[i] << "\n";
		}
		main_option_menu << "\n";
		std::cout << main_option_menu.str();

		// Execute until a valid integer is parsed.
		do {
			// Prompt the user for the main option selection.
			std::cout << "Enter option: " << std::flush;

			// Get the string input.
			std::getline(std::cin, string_input);

			// Validate the input.
			main_option_selection = get_valid_integer(string_input, std::stoi(main_number_column.back()));
		} while (main_option_selection == -1);

		// Determine main option selected.
		if (main_option_selection == std::stoi(main_number_column[1])) {
			do {
				// Vectors of strings for customer options to use to determine dynamic padding
				std::vector<std::string> customers_number_column = { "#", "0", "1" };
				exit_value = std::stoi(customers_number_column.back());
				std::vector<std::string> customers_option_column = { "Option", "Enter New Customer", "Return" };

				// Length of longest string of each customers menu column
				const int longest_customers_number_length = get_longest_string_length(customers_number_column);
				const int longest_customers_option_length = get_longest_string_length(customers_option_column);

				// Lengths of each width for padding
				const int customers_number_width   = longest_customers_number_length;
				const int customers_option_width   = longest_customers_option_length + 4;

				// Print formatted table.
				std::stringstream customers_menu;
				customers_menu << "\n";
				for (unsigned int i = 0; i < customers_number_column.size(); ++i) {
					customers_menu << std::left << std::setw(customers_number_width) << customers_number_column[i] << std::right << std::setw(customers_option_width) << customers_option_column[i] << "\n";
				}
				std::cout << customers_menu.str() << "\n";

				// Execute until a valid integer is parsed.
				do {
					// Prompt the user for the customer option selection.
					std::cout << "Enter option: " << std::flush;

					// Get the string input.
					std::getline(std::cin, string_input);

					// Validate the input.
					customers_option_selection = get_valid_integer(string_input, std::stoi(customers_number_column.back()));
				} while (customers_option_selection == -1);

				if (customers_option_selection == std::stoi(customers_number_column[1])) {
					// Prompt for the customer's first name.
					std::cout << "Enter the customer's first name: " << std::flush;
					std::string customer_first_name;
					// Get the customer's first name.
					std::getline(std::cin, customer_first_name);

					// Prompt for the customer's last name.
					std::cout << "Enter the customer's last name: " << std::flush;
					std::string customer_last_name;
					// Get the customer's last name.
					std::getline(std::cin, customer_last_name);

					// Prompt for the customer's party members.
					std::cout << "Does the customer have any party members? " << std::flush;
					// Get the string input.
					std::getline(std::cin, string_input);

					if (std::tolower(string_input[0]) == 'y') {
						int party_members_amount;
						// Execute until a valid integer is parsed.
						do {
							// Prompt for the number of the customer's party members.
							std::cout << "Enter the number of party members: " << std::flush;

							// Get the string input.
							std::getline(std::cin, string_input);

							// Validate the input.
							party_members_amount = get_valid_integer(string_input, 19);
						} while (party_members_amount == -1);

						std::vector<PartyMember> party_members;
						for (int i = 0; i < party_members_amount; ++i) {
							// Prompt for the party member's first name.
							std::cout << "Enter party member " << i << "'s first name: " << std::flush;
							std::string party_member_first_name;
							// Get the party member's first name.
							std::getline(std::cin, party_member_first_name);

							// Prompt for the party member's last name.
							std::cout << "Enter party member " << i << "'s last name: " << std::flush;
							std::string party_member_last_name;
							// Get the party member's last name.
							std::getline(std::cin, party_member_last_name);

							int party_member_age;
							// Execute until a valid integer is parsed.
							do {
								// Prompt for the party member's age.
								std::cout << "Enter party member " << i << "'s age: " << std::flush;

								// Get the string input.
								std::getline(std::cin, string_input);

								// Validate the input.
								party_member_age = get_valid_integer(string_input, 150);
							} while (party_member_age == -1);

							// Add party member.
							party_members.push_back(PartyMember(party_member_first_name, party_member_last_name, party_member_age));
						}

						// Prompt for the customer's destination.
						std::cout << "Enter the customer's destination: " << std::flush;
						std::string customer_destination;
						// Get the customer's last name.
						std::getline(std::cin, customer_destination);

						// Prompt for the customer's ticket type.
						std::cout << "Does the customer want a fast lane ticket? " << std::flush;
						// Get the string input.
						std::getline(std::cin, string_input);
						bool is_fast_lane_ticket = std::tolower(string_input[0]) == 'y' ? true : false;

						// Add customer with party members to customer queue.
						customer_queue.push(Customer(customer_first_name, customer_last_name, party_members, customer_destination, is_fast_lane_ticket));
					}
				}
			} while (customers_option_selection != exit_value);
		} else if (main_option_selection == std::stoi(main_number_column[2])) {
			do {
				int submenu_exit_value;

				// Option selections initialized for bogie submenu while loops
				int add_bogie_option_selection    = -1;
				int remove_bogie_option_selection = -1;

				// Vectors of strings for trains options to use to determine dynamic padding
				std::vector<std::string> trains_number_column = { "#", "0", "1", "2", "3", "4", "5", "6" };
				exit_value = std::stoi(trains_number_column.back());
				std::vector<std::string> trains_option_column = { "Option", "View Bogies", "Add Bogie", "Replace Bogie", "Remove Bogie", "Dequeue Passengers", "Send Train", "Return" };

				// Length of longest string of each trains menu column
				const int longest_trains_number_length = get_longest_string_length(trains_number_column);
				const int longest_trains_option_length = get_longest_string_length(trains_option_column);

				// Lengths of each width for padding
				const int trains_number_width = longest_trains_number_length;
				const int trains_option_width = longest_trains_option_length + 4;

				// Print formatted table.
				std::stringstream trains_menu;
				trains_menu << "\n";
				for (unsigned int i = 0; i < trains_number_column.size(); ++i) {
					trains_menu << std::left << std::setw(trains_number_width) << trains_number_column[i] << std::right << std::setw(trains_option_width) << trains_option_column[i] << "\n";
				}
				std::cout << trains_menu.str() << "\n";

				// Execute until a valid integer is parsed.
				do {
					// Prompt the user for the train option selection.
					std::cout << "Enter option: " << std::flush;

					// Get the string input.
					std::getline(std::cin, string_input);

					// Validate the input.
					trains_option_selection = get_valid_integer(string_input, std::stoi(trains_number_column.back()));
				} while (trains_option_selection == -1);

				if (trains_option_selection == std::stoi(trains_number_column[1])) {
					std::cout << "\n" << linked_bogie_list.get_bogies_list() << "\n";
				} else if (trains_option_selection == std::stoi(trains_number_column[2])) {
					do {
						// Vectors of strings for add bogie options to use to determine dynamic padding
						std::vector<std::string> add_bogie_number_column = { "#", "0", "1", "2" };
						submenu_exit_value = std::stoi(add_bogie_number_column.back());
						std::vector<std::string> add_bogie_option_column = { "Option", "Insert New Bogie At The End", "Insert New Bogie At Location", "Return" };

						// Length of longest string of each add bogie menu column
						const int longest_add_bogie_number_length = get_longest_string_length(add_bogie_number_column);
						const int longest_add_bogie_option_length = get_longest_string_length(add_bogie_option_column);

						// Lengths of each width for padding
						const int add_bogie_number_width = longest_add_bogie_number_length;
						const int add_bogie_option_width = longest_add_bogie_option_length + 4;

						// Print formatted table.
						std::stringstream add_bogie_menu;
						add_bogie_menu << "\n";
						for (unsigned int i = 0; i < add_bogie_number_column.size(); ++i) {
							add_bogie_menu << std::left << std::setw(add_bogie_number_width) << add_bogie_number_column[i] << std::right << std::setw(add_bogie_option_width) << add_bogie_option_column[i] << "\n";
						}
						std::cout << add_bogie_menu.str() << "\n";

						// Execute until a valid integer is parsed.
						do {
							// Prompt the user for the add bogie option selection.
							std::cout << "Enter option: " << std::flush;

							// Get the string input.
							std::getline(std::cin, string_input);

							// Validate the input.
							add_bogie_option_selection = get_valid_integer(string_input, std::stoi(add_bogie_number_column.back()));
						} while (add_bogie_option_selection == -1);

						if (add_bogie_option_selection == std::stoi(add_bogie_number_column[1])) break;
						else if (add_bogie_option_selection == std::stoi(add_bogie_number_column[2])) break;
					} while (add_bogie_option_selection != submenu_exit_value);
				} else if (trains_option_selection == std::stoi(trains_number_column[3])) break;
				else if (trains_option_selection == std::stoi(trains_number_column[4])) {
					do {
						// Vectors of strings for remove bogie options to use to determine dynamic padding
						std::vector<std::string> remove_bogie_number_column = { "#", "0", "1", "2" };
						submenu_exit_value = std::stoi(remove_bogie_number_column.back());
						std::vector<std::string> remove_bogie_option_column = { "Option", "Remove Bogie With Name", "Remove Bogie With Location", "Return" };

						// Length of longest string of each remove bogie menu column
						const int longest_remove_bogie_number_length = get_longest_string_length(remove_bogie_number_column);
						const int longest_remove_bogie_option_length = get_longest_string_length(remove_bogie_option_column);

						// Lengths of each width for padding
						const int remove_bogie_number_width = longest_remove_bogie_number_length;
						const int remove_bogie_option_width = longest_remove_bogie_option_length + 4;

						// Print formatted table.
						std::stringstream remove_bogie_menu;
						remove_bogie_menu << "\n";
						for (unsigned int i = 0; i < remove_bogie_number_column.size(); ++i) {
							remove_bogie_menu << std::left << std::setw(remove_bogie_number_width) << remove_bogie_number_column[i] << std::right << std::setw(remove_bogie_option_width) << remove_bogie_option_column[i] << "\n";
						}
						std::cout << remove_bogie_menu.str() << "\n";

						// Execute until a valid integer is parsed.
						do {
							// Prompt the user for the remove bogie option selection.
							std::cout << "Enter option: " << std::flush;

							// Get the string input.
							std::getline(std::cin, string_input);

							// Validate the input.
							remove_bogie_option_selection = get_valid_integer(string_input, std::stoi(remove_bogie_number_column.back()));
						} while (remove_bogie_option_selection == -1);

						if (remove_bogie_option_selection == std::stoi(remove_bogie_number_column[1])) break;
						else if (remove_bogie_option_selection == std::stoi(remove_bogie_number_column[2])) break;
					} while (remove_bogie_option_selection != submenu_exit_value);
				} else if (trains_option_selection == std::stoi(trains_number_column[5])) break;
				else if (trains_option_selection == std::stoi(trains_number_column[6])) break;
				else if (trains_option_selection == std::stoi(trains_number_column[7])) break;
			} while (trains_option_selection != exit_value);
		} else if (main_option_selection == std::stoi(main_number_column[3])) {
			break;
		}
	}

	return 0;
}

int get_longest_string_length(std::vector<std::string> const &column_strings) {
	// Stores the first string.
	std::string current_column_string = column_strings[0];

	// Initializes the current string length integer for the upcoming for loop.
	int current_column_string_length = 0;
	// Stores the first string length to the longest string length integer.
	int longest_column_string_length = current_column_string.length();

	// Loops through the rest of the strings to determine longest string length.
	for (unsigned int i = 1; i < column_strings.size(); ++i) {
		current_column_string = column_strings[i];
		current_column_string_length = current_column_string.length();

		if (current_column_string_length > longest_column_string_length) {
			longest_column_string_length = current_column_string_length;
		}
	}

	return longest_column_string_length;
}
