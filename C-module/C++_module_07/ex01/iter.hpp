#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T>
void		iter(T* array, int dim, void (*f)(const T& elem))
{
	for (int i = 0; i < dim; i++)
		(*f)(array[i]);
}

template<typename T>
void		printable(const T& elem)
{
	std::cout << elem << " ";
}

#endif