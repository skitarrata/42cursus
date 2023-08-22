#ifndef CONVERT_HPP
# define CONVERT_HPP

# define ZERO 1
# define CHAR 2
# define INT 3
# define FLOAT 4
# define DOUBLE 5

# include <iostream>
# include <string>
# include <limits>
# include <cmath>

class					Convert
{
	private:
		std::string		str;
		int				flag;
		char			ch;
		double			nb;
		size_t			countOccurrences(std::string _str, char ch);
		Convert();
	public:
		Convert(std::string	_str);
		Convert(const Convert& cv);
		Convert&		operator=(const Convert& cv);
		~Convert();

		int				err;
		void			toChar() const;
		void			toInt() const;
		void			toFloat() const;
		void			toDouble() const;
		int				toParse();
};

std::ostream&			operator<<(std::ostream& out, Convert const& cv);

#endif