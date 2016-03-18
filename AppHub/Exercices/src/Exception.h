#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <ostream>
#include <string>

class Exception : public std::exception
{
	public:
		enum Type
		{
			Parser
		};

	public:
		Exception(Type type, const std::string &message);
		virtual ~Exception();
		Exception(const Exception& other);
		Exception& operator=(const Exception& other) = delete;

		virtual const char* what() const throw();

	protected:
		Type _type;
		std::string _message;
};

#endif // EXCEPTION_H
