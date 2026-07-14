#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iostream>
#include <cctype>

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
		static bool isValidLiteral(const std::string& s);
		static bool isPseudoLiteral(const std::string& s);
		static bool isCharLiteral(const std::string& s);
		static bool isIntLiteral(const std::string& s);
		static bool isDoubleLiteral(const std::string& s);
		static bool isFloatLiteral(const std::string& s);
	public:
		static void convert(const std::string& literal);
	
	class InvalidLiteralException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#endif

/* her skaler veri tipini kontrol eden fonksiyonun içerisinde cout<<"int: "; diye başlayacak mesela. 
 stdendl yapmayacak, eğer geçiyorsa karşılığını yazdıracak, geçmiyorsa da exception fırlatacak. sonra tüm bu
 fonksiyonları convert fonksiyonu içerisinde try-catch bloğu içerisinde çağırınca hata varsa yazdıracak.
 ya da converter fonksiyonunda hata tiplerine göre integer bir değer döndürüp maindeki try-catchde de bu 
 exceptionı yakalayabilir. */