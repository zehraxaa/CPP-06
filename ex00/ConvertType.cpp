#include "ScalarConverter.hpp"

LiteralType ScalarConverter::detectType(const std::string& s)
{
	if (isPseudoLiteral(s))
		return PSEUDO;
	if (isCharLiteral(s))
		return CHAR;
	if (isIntLiteral(s))
		return INT;
	if (isFloatLiteral(s))
		return FLOAT;
	if (isDoubleLiteral(s))
		return DOUBLE;
	
	return INVALID;
}

double ScalarConverter::parseLiteral(const std::string &s, LiteralType type)
{
	switch (type)
	{
		case CHAR:
			return static_cast<double>(s[0]); //şurayı bi silip strtod ile charı dönüştürmeyi dene
		case INT:
		case FLOAT:
		case DOUBLE:
		case PSEUDO:
			return std::strtod(s.c_str(), NULL);
		default:
			throw ScalarConverter::InvalidLiteralException();
	}
}

void ScalarConverter::convertChar(double value)
{
	std::cout<<"char: ";

	if (std::isnan(value) || value < 0 || value > 127 )
	{
		std::cout<<"impossible"<<std::endl;
		return;
	}

	char c = static_cast<char>(value);

	if (!std::isprint(c))
	{
		std::cout<<" Non displayable"<<std::endl;
		return;
	}
	std::cout<<"'"<<c<<"'"<<std::endl;
}

void ScalarConverter::convertInt(double value)
{
	
}