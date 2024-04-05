#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate(void)
{
	srand(time(NULL));
	int r = rand() % 100;
	if (r < 33)
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
		std::cout << "this is type A\n";
	else
    {
        B *b = dynamic_cast <B*> (p);
        if (b!= NULL)
             std::cout << "this is type B\n";
        else
        {
            C *c = dynamic_cast <C*> (p);
            if (c!= NULL)
                std::cout << "this is type C\n";
        }
    }
}

void identify(Base& p)
{
    try 
	{
		A &a = dynamic_cast <A&> (p);
		std::cout << "this is type A\n";
	}
	catch(std::exception &e){};
	try 
	{
		B &b = dynamic_cast <B&> (p);
		std::cout << "this is type B\n";
	}
	catch(std::exception &e){};
	try 
	{
		C &c = dynamic_cast <C&> (p);
		std::cout << "this is type C\n";
	}
	catch(std::exception &e){};
}


int main()
{
    // A a;
    // std::cout << "ttiuo";
    Base *b = generate();
    identify(b);
    // std::cout << "hhjhjgj";
    delete(b);
    return(0);
}
