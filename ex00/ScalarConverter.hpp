#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iostream>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <cmath>

enum LiteralType
{
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void convert(const std::string& literal);
	
	class InvalidLiteralException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};
	bool isValidLiteral(const std::string& s);
	bool isPseudoLiteral(const std::string& s);
	bool isCharLiteral(const std::string& s);
	bool isIntLiteral(const std::string& s);
	bool isDoubleLiteral(const std::string& s);
	bool isFloatLiteral(const std::string& s);
	LiteralType detectType(const std::string& s);
	double parseLiteral(const std::string& literal, LiteralType type);
	void convertChar(double value);
	void convertInt(double value);
	void convertFloat(double value);
	void convertDouble(double value);

#endif