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

/* tek bir exception olacak o da "invalid literal type" exceptionu. çünkü diğer
int: impossible gibi olanlar bir hata değil, beklenen bir davranış. dolayısıyla da
convert fonksiyonu içinde tek bir try-catch olacak, exception orda yakalanıp main
fonksiyonunda dümdüz convert fonksiyonu çağrıldığında zaten hata yazdırılmış olacak */