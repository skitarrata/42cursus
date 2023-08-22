#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class						Fixed
{
	private:
		int					val;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const int a);
		Fixed(const float a);
		Fixed(const Fixed& fix);
		Fixed& operator=(const Fixed& fix);
		~Fixed();
		int					getRawBits(void) const;
		float				toFloat(void) const;
		int					toInt(void) const;
		void				setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif