#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <typeinfo>

Base * generate(void) {
	srand(time(NULL));

	int r = rand() % 3;

	switch (r)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			break;
	}
	return (NULL);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Type: Unknown" << std::endl;
}

void identify(Base& p) {
	try {
		A& test = dynamic_cast<A&>(p);
		(void) test;
		std::cout << "Type: A" << std::endl;
	} catch (std::bad_cast &e){}

	try {
		B& test = dynamic_cast<B&>(p);
		(void) test;
		std::cout << "Type: B" << std::endl;
	} catch (const std::bad_cast &e){}

	try {
		C& test = dynamic_cast<C&>(p);
		(void) test;
		std::cout << "Type: C" << std::endl;
	} catch (const std::bad_cast &e){}
}

int main(void)
{
	Base *test = generate();

	std::cout << "Identification with pointer: ";
	identify(test);
	std::cout << "Identification with reference: ";
	identify(*test);

	delete test;

	return 0;
}