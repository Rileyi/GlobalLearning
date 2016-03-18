#include "Exception.h"

Exception::Exception(Type type, const std::string &message) : std::exception(), _type(type), _message(message)
{
	//ctor
}

Exception::Exception(const Exception& other) : std::exception(other), _type(other._type), _message(other._message)
{
}

Exception::~Exception()
{
	//dtor
}

const char* Exception::what() const throw()
{
	std::string message = _message + "(Type" + std::to_string(static_cast<int>(_type)) + ")";
	return message.c_str();
}
