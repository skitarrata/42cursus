#include "Convert.hpp"

Convert::Convert() { }
Convert::~Convert() { }
Convert::Convert(std::string _str) : str(_str) 
{
	err = toParse();
	if (flag == CHAR)
		ch = _str[0];
	else
	{
		nb = strtod(_str.c_str(), 0);
		if (nb == 0)
			flag = ZERO;
	}
}
Convert::Convert(const Convert& cv) : str(cv.str) { *this = cv; }
Convert&		Convert::operator=(const Convert& cv)
{
	if (this != &cv)
	{
		str = cv.str;
		flag = cv.flag;
		ch = cv.ch;
		nb = cv.nb;
	}
	return *this;
}

int				Convert::toParse()
{
	size_t i = 0;
	size_t n = 0;
	size_t dim = str.length();

	if (str.empty())
		return 1;
	else if (dim == 1 && (str[i] >= 32 && str[i] <= 126))
	{
		flag = CHAR;
		if (str[i] == 48)
			flag = ZERO;
		return 0;
	}
	else if (str == "nanf" || str == "+inff" || str == "inff" || str == "-inff")
		return 0;
	else if (str == "nan" || str == "+inf" || str == "inf" || str == "-inf")
		return 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[dim - 1] == 'f')
		dim--;
	for (size_t j = i; j < dim; j++)
		if (!(str[j] >= 48 && str[j] <= 57) && str[j] != '.')
			return 1;

	if ((i = str.find(".")) == dim - 1)
		return 1;

	i = countOccurrences(str, '.');
	n = countOccurrences(str, 'f');
	if (!i && !n)
		flag = INT;
	else if (i == 1 && n == 1) //  || (!i && n == 1)  ??
		flag = FLOAT;
	else if (i == 1 && !n)
		flag = DOUBLE;
	else
		return 1;

	if (flag == FLOAT || flag == DOUBLE)
	{
		size_t count = 0;
		i = str.find(".");
		std::string sub = str.substr(i);
		size_t d = sub.length();

		if (flag == FLOAT)
			d--;
		for (size_t j = 0; j < d; j++)
			if (sub[j] == '0')
					count++;
		if (count == d - 1)
			flag = INT;
	}

	return 0;
}

size_t			Convert::countOccurrences(std::string _str, char ch)
{
	size_t n = 0;

	for (size_t i = 0; i < _str.length(); i++)
		if (_str[i] == ch)
			n++;
	return n;
}

void    Convert::toChar() const
{
    std::cout << "char: ";

    if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
        std::cout << "impossible" << std::endl;
    else if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
        std::cout << "impossible" << std::endl;
	else if (flag == CHAR)
		std::cout << "'" << ch << "'" << std::endl;
    else if (nb > 127 || nb < -128)
        std::cout << "overflow" << std::endl;
	else if ((nb >= 0 && nb < ' ') || nb == 127)
		std::cout << "Non displayable" << std::endl;
	else if (nb >= -128 && nb <= 126)
		std::cout << "'" << static_cast<char>(nb) << "'" << std::endl;
}

void    Convert::toInt() const
{
    std::cout << "int: ";

    if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
        std::cout << "impossible" << std::endl;
    else if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
        std::cout << "impossible" << std::endl;
	else if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
		std::cout << "overflow" << std::endl;
	else if (flag == CHAR)
		std::cout << static_cast<int>(ch) << std::endl;
	else
		std::cout << static_cast<int>(nb) << std::endl;
}

void    Convert::toFloat() const
{
    std::cout << "float: ";

    if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
        std::cout << str << "f" << std::endl;
    else if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
        std::cout << str << std::endl;
	else if (flag == CHAR)
		std::cout << static_cast<int>(ch) << ".0f" << std::endl;
	else if (flag == INT || flag == ZERO)
		std::cout << static_cast<float>(nb) << ".0f" << std::endl;
	else
		std::cout << static_cast<float>(nb) << "f" << std::endl;
}

void    Convert::toDouble() const
{
    std::cout << "double: ";

    if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
        std::cout << str << std::endl;
    else if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
        std::cout << str.substr(0, str.size() - 1) << std::endl;
	else if (flag == INT || flag == ZERO)
		std::cout << static_cast<double>(nb) << ".0" << std::endl;
	else if (flag == CHAR)
		std::cout << static_cast<int>(ch) << ".0" << std::endl;
	else
		std::cout << static_cast<double>(nb) << std::endl;
}

std::ostream&			operator<<(std::ostream& out, Convert const& cv)
{
	cv.toChar();
	cv.toInt();
	cv.toFloat();
	cv.toDouble();

	return out;
}