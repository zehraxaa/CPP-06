#include "ScalarConverter.hpp"

LiteralType detectType(const std::string &s)
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

double parseLiteral(const std::string &s, LiteralType type)
{
	switch (type) {
		case CHAR:
			return static_cast<double>(s[0]); // şurayı bi silip strtod ile charı dönüştürmeyi dene
		case INT:
		case FLOAT:
		case DOUBLE:
		case PSEUDO:
			return std::strtod(s.c_str(), NULL);
		default:
			throw ScalarConverter::InvalidLiteralException();
	}
}

void convertChar(double value)
{
	std::cout << "char: ";

	if (std::isnan(value) || value < 0 || value > 127) {
		std::cout << "impossible" << std::endl;
	return;
	}

	char c = static_cast<char>(value);

	if (!std::isprint(c)) {
		std::cout << " Non displayable" << std::endl;
		return;
	}
	std::cout << "'" << c << "'" << std::endl;
}

void convertInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) 
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	int i = static_cast<int>(value);

	std::cout << i << std::endl;
}

void convertFloat(double value)
{
	std::cout << "float: ";

	float f = static_cast<float>(value);
	std::cout << f;

	if (f == static_cast<int>(f)) // f eğer 42 ise 42.0f şeklinde yazdırılmalı o yüzden bu kontrol yapılıyor
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void convertDouble(double value)
{
	std::cout << "double: " << value;

	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}
