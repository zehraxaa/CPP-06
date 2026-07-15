#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return(*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
	try 
	{
		if (!isValidLiteral(literal))
			throw InvalidLiteralException();

		LiteralType type = detectType(literal);

		double value = parseLiteral(literal, type);
		convertChar(value);
	}
	catch (const std::exception &e)
	{
		std::cerr<<e.what()<<std::endl;
	}
}

const char* ScalarConverter::InvalidLiteralException::what() const throw()
{
	return "Error: Invalid literal!";
}
 