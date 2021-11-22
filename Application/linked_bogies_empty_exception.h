#ifndef LINKEDBOGIESEMPTYEXCEPTION_H
#define LINKEDBOGIESEMPTYEXCEPTION_H

#include <exception>
#include <string>

class LinkedBogiesEmptyException : public std::exception {
	public:
		LinkedBogiesEmptyException(void);
		LinkedBogiesEmptyException(std::string const &message);
		virtual const char *what(void) const noexcept override;
	private:
		std::string message;
};

#endif // LINKEDBOGIESEMPTYEXCEPTION_H
