#ifndef LINKEDBOGIESOUTOFRANGEEXCEPTION_H
#define LINKEDBOGIESOUTOFRANGEEXCEPTION_H

#include <exception>
#include <string>

class LinkedBogiesOutOfRangeException : public std::exception {
	public:
		LinkedBogiesOutOfRangeException(void);
		LinkedBogiesOutOfRangeException(std::string const &message);
		virtual const char *what(void) const noexcept override;
	private:
		std::string message;
};

#endif // LINKEDBOGIESOUTOFRANGEEXCEPTION_H
