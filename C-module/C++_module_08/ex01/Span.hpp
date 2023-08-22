#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class						Span
{
	private:
		Span();
		unsigned int		n;
		std::vector<int>	arr;
	public:
		Span(unsigned int N);
		Span(const Span& src);
		Span& operator=(const Span& src);
		~Span();

		void				addNumber(int x);
		void				addNumber(int begin, int end);
		int					shortestSpan();
		int					longestSpan();

		class OverflowArray : public std::exception
		{
			public:
				virtual const char* what() const throw() { return "Error: Bad access"; };
		};
		class BadArgArray : public std::exception
		{
			public:
				virtual const char* what() const throw() { return "Error: Bad arguments"; }
		};
};

#endif