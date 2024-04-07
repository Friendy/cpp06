#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <unistd.h>

Base *generate(void)
{
	srand(time(NULL));
	int r = rand() % 100;
	if (r <= 33)
		return(new A);
	else if (r > 33 && r < 67)
		return(new B);
	else
		return(new C);
}

void identify(Base* p)
{
	A *a = dynamic_cast <A*> (p);
	if (a!= NULL)
		std::cout << "A\n";
	else
	{
		B *b = dynamic_cast <B*> (p);
		if (b!= NULL)
			 std::cout << "B\n";
		else
		{
			C *c = dynamic_cast <C*> (p);
			if (c!= NULL)
				std::cout << "C\n";
		}
	}
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast <A&> (p);
		std::cout << "A\n";
	}
	catch(std::exception &e){};
	try
	{
		B &b = dynamic_cast <B&> (p);
		std::cout << "B\n";
	}
	catch(std::exception &e){};
	try
	{
		C &c = dynamic_cast <C&> (p);
		std::cout << "C\n";
	}
	catch(std::exception &e){};
}


int main()
{
	std::cout << "********pointer test************\n";
	Base *b = generate();
	identify(b);
	std::cout << "********reference test************\n";
	Base &ref = *b;
	identify(ref);
	delete(b);
	std::cout << "********multiple test************\n";
	for (int i = 0; i < 10; i++)
	{
		b = generate();
		identify(b);
		identify(*b);
		delete(b);
		sleep(2);
		std::cout << "------------\n";
	}
	return(0);
}
