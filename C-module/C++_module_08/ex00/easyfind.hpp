#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
int		easyfind(T rand, int n)
{
	typename T::iteretor iter = std::find(rand.begin(), rand.end(), n);
	if (iter == rand.end())
		return -1;
	return *iter;
}

#endif