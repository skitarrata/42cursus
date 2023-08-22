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

		bool				operator>(const Fixed& fix) const;
		bool				operator<(const Fixed& fix) const;
		bool				operator>=(const Fixed& fix) const;
		bool				operator<=(const Fixed& fix) const;
		bool				operator==(const Fixed& fix) const;
		bool				operator!=(const Fixed& fix) const;

		Fixed				operator+(const Fixed& fix) const;
		Fixed				operator-(const Fixed& fix) const;
		Fixed				operator*(const Fixed& fix) const;
		Fixed				operator/(const Fixed& fix) const;

		Fixed&				operator++();
		Fixed				operator++(int);
		Fixed&				operator--();
		Fixed				operator--(int);

		static Fixed&		min(Fixed& x, Fixed& y);
		static const Fixed&	min(const Fixed& x, const Fixed& y);
		static Fixed&		max(Fixed& x, Fixed& y);
		static const Fixed&	max(const Fixed& x, const Fixed& y);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif