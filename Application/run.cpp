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
#include <sstream>
#include <vector>

#include "validation.h"

int get_longest_string_length(std::vector<std::string> const &column_strings);

int main() {
	// Print the title of the program.
	std::cout << "Train Booking Application\n";

	// Option selections initialized for while loops
	int main_option_selection = -1;
	int passengers_option_selection = -1;
	int bogies_option_selection = -1;

	// Vector of strings for main options to use to determine dynamic padding
	std::vector<std::string> main_number_column = { "#", "0", "1", "2" };
	std::vector<std::string> main_option_column = { "Option", "Passengers", "Bogies", "Quit" };

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
				// Vectors of strings for passenger options to use to determine dynamic padding
				std::vector<std::string> passengers_number_column = { "#", "0", "1" };
				exit_value = std::stoi(passengers_number_column.back());
				std::vector<std::string> passengers_customer_column = { "Customer", "John Doe" };
				std::vector<std::string> passengers_option_column = { "Option", "Passenger", "Return" };

				// Length of longest string of each passengers menu column
				const int longest_passengers_number_length   = get_longest_string_length(passengers_number_column);
				const int longest_passengers_customer_length = get_longest_string_length(passengers_customer_column);
				const int longest_passengers_option_length   = get_longest_string_length(passengers_option_column);

				// Lengths of each width for padding
				const int passengers_number_width   = longest_passengers_number_length;
				const int passengers_customer_width = longest_passengers_customer_length + 4;
				const int passengers_option_width   = longest_passengers_option_length + 4;

				// Print formatted table.
				std::stringstream passengers_menu;
				passengers_menu << "\n";
				for (unsigned int i = 0; i < passengers_number_column.size() - 1; ++i) {
					passengers_menu << std::left << std::setw(passengers_number_width) << passengers_number_column[i] << std::right << std::setw(passengers_option_width) << passengers_option_column[i] << std::setw(passengers_customer_width) << passengers_customer_column[i] << "\n";
				}
				passengers_menu << std::left << std::setw(passengers_number_width) << passengers_number_column.back() << std::right << std::setw(passengers_option_width) << passengers_option_column.back() << "\n\n";
				std::cout << passengers_menu.str();

				// Execute until a valid integer is parsed.
				do {
					// Prompt the user for the passenger option selection.
					std::cout << "Enter passenger: " << std::flush;

					// Get the string input.
					std::getline(std::cin, string_input);

					// Validate the input.
					passengers_option_selection = get_valid_integer(string_input, std::stoi(passengers_number_column.back()));
				} while (passengers_option_selection == -1);
			} while (passengers_option_selection != exit_value);
		} else if (main_option_selection == std::stoi(main_number_column[2])) {
			do {
				// Vectors of strings for bogies options to use to determine dynamic padding
				std::vector<std::string> bogies_number_column = { "#", "0", "1" };
				exit_value = std::stoi(bogies_number_column.back());
				std::vector<std::string> bogies_bogie_column = { "Bogie", "Bogie 9500001" };
				std::vector<std::string> bogies_option_column = { "Option", "Bogie", "Return" };

				// Length of longest string of each bogies menu column
				const int longest_bogies_number_length = get_longest_string_length(bogies_number_column);
				const int longest_bogies_bogie_length  = get_longest_string_length(bogies_bogie_column);
				const int longest_bogies_option_length = get_longest_string_length(bogies_option_column);

				// Lengths of each width for padding
				const int bogies_number_width = longest_bogies_number_length;
				const int bogies_bogie_width  = longest_bogies_bogie_length + 4;
				const int bogies_option_width = longest_bogies_option_length + 4;

				// Print formatted table.
				std::stringstream bogies_menu;
				bogies_menu << "\n";
				for (unsigned int i = 0; i < bogies_number_column.size() - 1; ++i) {
					bogies_menu << std::left << std::setw(bogies_number_width) << bogies_number_column[i] << std::right << std::setw(bogies_option_width) << bogies_option_column[i] << std::setw(bogies_bogie_width) << bogies_bogie_column[i] << "\n";
				}
				bogies_menu << std::left << std::setw(bogies_number_width) << bogies_number_column.back() << std::right << std::setw(bogies_option_width) << bogies_option_column.back() << "\n\n";
				std::cout << bogies_menu.str();

				// Execute until a valid integer is parsed.
				do {
					// Prompt the user for the passenger option selection.
					std::cout << "Enter passenger: " << std::flush;

					// Get the string input.
					std::getline(std::cin, string_input);

					// Validate the input.
					bogies_option_selection = get_valid_integer(string_input, std::stoi(bogies_number_column.back()));
				} while (bogies_option_selection == -1);
			} while (bogies_option_selection != exit_value);
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
