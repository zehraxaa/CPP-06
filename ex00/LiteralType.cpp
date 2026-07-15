#include "ScalarConverter.hpp"

bool ScalarConverter::isValidLiteral(const std::string &s)
{
	if (isPseudoLiteral(s))
		return true;
	if (isCharLiteral(s))
		return true;
	if (isIntLiteral(s))
		return true;
	if (isFloatLiteral(s))
		return true;
	if (isDoubleLiteral(s))
		return true;
	return false;
}

bool ScalarConverter::isPseudoLiteral(const std::string &s)
{
	if (s == "nan" || s == "nanf" || s == "+inf" ||
		s == "-inf" || s == "+inff" || s == "-inff")
		{
			std::cout<<"pseudo variable"<<std::endl;
			return true;
		}
	return false;
}

bool ScalarConverter::isCharLiteral(const std::string& s)
{
	if (s.length() == 1 && !std::isdigit(s[0]))
	{
		std::cout<<"char variable"<<std::endl;
		return true;
	}
	return false;
}

bool ScalarConverter::isIntLiteral(const std::string &s)
{
	size_t i = 0;

	if (s.empty())
		return false;
	if (s[0] == '+' || s[0] == '-')
		i++;
	if ( i == s.length()) //sadece + ya da - den oluşuyorsa
		return false;
	while (i < s.length())
	{
		if (!std::isdigit(s[i]))
			return false;
		i++;
	}
	std::cout<<"int variable"<<std::endl;
	return true;
}

bool ScalarConverter::isDoubleLiteral(const std::string& s)
{
	int countDot = 0;
	bool hasDigit = false;
	size_t i = 0;

	if (s.empty())
		return false;
	if (s[0] == '+' || s[0] == '-')
		i++;
	if (i == s.length())
		return false;

	while (i < s.length())
	{
		if (std::isdigit(s[i]))
			hasDigit = true;
		else if (s[i] == '.')
			countDot++;
		else
			return false;
		i++;
	}

	size_t dotPos = s.find('.');

	if (countDot != 1 || dotPos == i-1 || !std::isdigit(s[dotPos - 1]))
		return false;

	std::cout<<"double variable"<<std::endl;
	return hasDigit;
}

bool ScalarConverter::isFloatLiteral(const std::string &s)
{
	int countDot = 0;
	bool hasDigit = false;
	size_t i = 0;

	if (s.empty())
		return false;
	if (s[0] == '+' || s[0] == '-')
		i++;
	if (i >= s.length() - 1)
		return false;
	while (i < s.length() - 1)
	{
		if (std::isdigit(s[i]))
			hasDigit = true;
		else if (s[i] == '.')
			countDot++;
		else
		 	return false;
		i++;
	}

	size_t dotPos = s.find('.');

	if ((countDot != 1 || s[dotPos + 1] == 'f' || !std::isdigit(s[dotPos-1])) || (s[i] != 'f'))
		return false;

	std::cout<<"float variable"<<std::endl;
	return hasDigit;
}