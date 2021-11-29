#include "validation.h"

#include <cerrno>
#include <climits>
#include <iostream>

bool validate_string_to_integer(int &parsed_integer, const char *string_input_pointer, int const base = 0) {
	// Pointer to the pointer of the character past the last character interpreted
	char *end;
	// Long to parse from the string and to be cast to an integer after validation
	long long_to_parse;
	// A preprocesor macro initialized to 0 for the upcoming validation. In this case, it is used to determine if the long receives a value that is out of range.
	errno = 0;
	// Interpret integer value from the byte string pointed to by the string_input_pointer.
	long_to_parse = std::strtol(string_input_pointer, &end, base);

	// Determine if errno is out of range AND long returns LONG_MAX (the maximum value of a long) OR long exceeds INT_MAX (the maximum value of an integer). Upon error, long returns 0.
	if ((errno == ERANGE && long_to_parse == LONG_MAX) || long_to_parse > INT_MAX) {
		return false;
	// Determine if errno is out of range AND long returns LONG_MIN (the minimum value of a long) OR long exceeds INT_MIN (the minimum value of an integer). Upon error, long returns 0.
	} else if ((errno == ERANGE && long_to_parse == LONG_MIN) || long_to_parse < INT_MIN) {
		return false;
	// Determine if the byte string or the character pointer of the last pointer returns null. Prevents input such as "5g".
	} else if (*string_input_pointer == '\0' || *end != '\0') {
		return false;
	// Input is a valid integer.
	} else {
		// Cast valid long to an integer.
		parsed_integer = static_cast<int>(long_to_parse);
	}

	// Return validation result.
	return true;
}

int get_valid_integer(std::string const string_input, int const max) {
	// Convert the string to a c-string and then convert to a constant byte string to pass to validation function.
	const char *string_input_pointer = string_input.c_str();

	// Declare an integer to pass by reference and to store the parsed result from the input string.
	int integer_from_string = -1;

	// Validate the string to an integer and determine if the input is invalid.
	if (!validate_string_to_integer(integer_from_string, string_input_pointer)) {
		// Print a message informing the user that the input is not a valid integer.
		std::cout << "Invalid input. Please enter a non-negative integer.\n";
	// Determine if the input is too low.
	} else if (integer_from_string < 0) {
		// Print a message informing the user that the input is too low.
		std::cout << "Input is too low. Please enter a non-negative integer.\n";
		// Reset integer to invalid state.
		integer_from_string = -1;
	// Determine if the input is too high.
	} else if (integer_from_string > max) {
		// Print a message informing the user that the input is too high.
		std::cout << "Input is too high. Please enter an integer less than or equal to " << max << ".\n";
		// Reset integer to invalid state.
		integer_from_string = -1;
	}

	// Returns parsed integer.
	return integer_from_string;
}

int get_valid_positive_integer(std::string const string_input, int const max) {
	// Convert the string to a c-string and then convert to a constant byte string to pass to validation function.
	const char *string_input_pointer = string_input.c_str();

	// Declare an integer to pass by reference and to store the parsed result from the input string.
	int integer_from_string = -1;

	// Validate the string to an integer and determine if the input is invalid.
	if (!validate_string_to_integer(integer_from_string, string_input_pointer)) {
		// Print a message informing the user that the input is not a valid integer.
		std::cout << "Invalid input. Please enter a positive integer.\n";
	// Determine if the input is too low.
	} else if (integer_from_string < 1) {
		// Print a message informing the user that the input is too low.
		std::cout << "Input is too low. Please enter a positive integer.\n";
		// Reset integer to invalid state.
		integer_from_string = -1;
	// Determine if the input is too high.
	} else if (integer_from_string > max) {
		// Print a message informing the user that the input is too high.
		std::cout << "Input is too high. Please enter an integer less than or equal to " << max << ".\n";
		// Reset integer to invalid state.
		integer_from_string = -1;
	}

	// Returns parsed integer.
	return integer_from_string;
}
