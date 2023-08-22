#include "Base.hpp"

int main()
{
	srand(time(0));
	Base *ptr = nullptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;

	return 0;
}