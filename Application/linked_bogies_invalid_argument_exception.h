#ifndef LINKEDBOGIESINVALIDARGUMENTEXCEPTION_H
#define LINKEDBOGIESINVALIDARGUMENTEXCEPTION_H

#include <exception>
#include <string>

class LinkedBogiesInvalidArgumentException : public std::exception {
	public:
		LinkedBogiesInvalidArgumentException(void);
		LinkedBogiesInvalidArgumentException(std::string const &message);
		virtual const char *what(void) const noexcept override;
	private:
		std::string message;
};

#endif // LINKEDBOGIESINVALIDARGUMENTEXCEPTION_H
