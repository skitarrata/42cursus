#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : n(N) {}

Span::Span(const Span& src) { this->operator=(src); }

Span::~Span() {}

Span& Span::operator=(const Span& src)
{
	n = src.n;
	arr = src.arr;

	return (*this);
}

void	Span::addNumber(int x)
{
	if (n <= 1)
		throw Span::BadArgArray();
	else if (arr.size() < n)
		arr.push_back(x);
	else
		throw Span::OverflowArray();
}

void	Span::addNumber(int begin, int end)
{
	if (n <= 1)
		throw Span::BadArgArray();
	else if ((begin > end) || (arr.size() + (end - begin) > n))
		throw Span::OverflowArray();
	else
		for (int i = begin; i <= end; i++)
			arr.push_back(i);
}

int		Span::shortestSpan()
{
	if (arr.size() < 2 || n <= 1)
	{
		Span::BadArgArray();
		return 0;
	}
	int ret = std::abs(arr[1] - arr[0]);
	int min = 0;
	std::sort(arr.begin(), arr.end());
	for (std::size_t i = 1; i < arr.size(); i++)
	{
		min = std::abs(arr[i - 1] - arr[i]);
		ret = (min > ret) ? ret : min;
	}
	return ret;
}

int		Span::longestSpan()
{
	if (arr.size() < 2 || n <= 1)
	{
		Span::BadArgArray();
		return 0;
	}
	int min = *std::min_element(arr.begin(), arr.end());
	int max = *std::max_element(arr.begin(), arr.end());
	return (max - min);
}