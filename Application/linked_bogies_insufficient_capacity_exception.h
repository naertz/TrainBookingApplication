#ifndef LINKEDBOGIESINSUFFICIENTCAPACITYEXCEPTION_H
#define LINKEDBOGIESINSUFFICIENTCAPACITYEXCEPTION_H

#include <exception>
#include <string>

class LinkedBogiesInsufficientCapacityException : public std::exception {
	public:
		LinkedBogiesInsufficientCapacityException(void);
		LinkedBogiesInsufficientCapacityException(std::string const &message);
		virtual const char *what(void) const noexcept override;
	private:
		std::string message;
};

#endif // LINKEDBOGIESINSUFFICIENTCAPACITYEXCEPTION_H
