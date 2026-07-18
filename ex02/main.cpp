#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	int num = rand() % 3;
	if (num == 0)
		return new A();
	else if (num == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout<<"A"<<std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout<<"B"<<std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout<<"C"<<std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout<<"A"<<std::endl;
		return;
	}
	catch (...) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout<<"B"<<std::endl;
		return;
	}
	catch (...) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout<<"C"<<std::endl;
		return;
	}
	catch (...) {}
}

int main()
{
	std::srand(std::time(NULL));

	Base* ptr = generate();

	std::cout<<"Pointer version: ";
	identify(ptr);

	std::cout<<"Reference version: ";
	identify(*ptr);

	delete ptr;
	return 0;
}