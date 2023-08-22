#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <iomanip>

int main()
{
	std::cout << "********Subject Test********" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "********USavoia Test********" << std::endl;
	MutantStack<int> a;
	std::list<int> b;

	for (int i = 0; i < 10; i++)
	{
		a.push(i + 1);
		b.push_back(i + 1);
	}
	
	MutantStack<int>::iterator itStack = a.begin();
	MutantStack<int>::iterator itendStack = a.end();
	std::list<int>::iterator itList = b.begin();
	std::list<int>::iterator itendList = b.end();

	std::cout << "\033[34m" << "Size Stack:   " << a.size() << "    |   Size List:   " << b.size() << std::endl;
	while ((itStack != itendStack) && (itList != itendList))
	{
		std::cout << std::setw(19) << *itStack << " | " << *itList << std::endl;
		itStack++;
		itList++;
	}
	std::cout << "\033[0m" << std::endl;
	return 0;
}