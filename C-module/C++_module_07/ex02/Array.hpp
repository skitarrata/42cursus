#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <exception>
# include <iostream>
# include <cstdlib>

template<typename T>
class							Array
{
	private:
		unsigned int			dim;
		T*						arr;
	public:
		Array() : dim(0), arr(new T[0]) { };
		Array(unsigned int n) : dim(n), arr(new T[n]) { };
		Array(const Array& a)
		{
			dim = a.dim;
			arr = new T[a.dim];
			if (dim)
				for (unsigned int i = 0; i < dim; i++)
					arr[i] = a.arr[i];
		}
		Array&					operator=(const Array& a)
		{
			delete[] arr;
			dim = a.dim;
			arr = new T[a.dim];
			if (dim)
				for (unsigned int i = 0; i < dim; i++)
					arr[i] = a.arr[i];
			return *this;
		}
		~Array() { delete[] arr; };

		unsigned int			size() const { return dim; };

		T&						operator[](unsigned int i)
		{
			if (i < 0 || i > dim - 1)
				throw	Array::accessDenied();
			else
				return (arr[i]);
		}

		class 					accessDenied : public std::exception
		{
			public:
				virtual const char* what() const throw() {return "Error: Bad access"; };
		};
};

#endif