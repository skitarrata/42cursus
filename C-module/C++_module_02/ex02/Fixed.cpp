#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->val = 0;
}

Fixed::Fixed(const int a)
{
	//std::cout << "Int constructor called" << std::endl;
	val = a << bits;
}

Fixed::Fixed(const float a)
{
	//std::cout << "Float constructor called" << std::endl;
	val = (int)roundf(a * (1 << bits));
}

Fixed::Fixed(const Fixed& fix)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed&	Fixed::operator=(const Fixed& fix)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
		this->val = fix.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int					Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->val;
}

void				Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->val = raw;
}

float				Fixed::toFloat(void) const
{
	return ((float)val / (float)(1 << bits));
}

int					Fixed::toInt(void) const
{
	return ((int)(val >> bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return (os);
}

bool				Fixed::operator>(const Fixed& fix) const
{
	return (getRawBits() > fix.getRawBits());
}
bool				Fixed::operator<(const Fixed& fix) const
{
	return (getRawBits() < fix.getRawBits());	
}
bool				Fixed::operator>=(const Fixed& fix) const
{
	return (getRawBits() >= fix.getRawBits());
}
bool				Fixed::operator<=(const Fixed& fix) const
{
	return (getRawBits() <= fix.getRawBits());
}
bool				Fixed::operator==(const Fixed& fix) const
{
	return (getRawBits() == fix.getRawBits());
}
bool				Fixed::operator!=(const Fixed& fix) const
{
	return (getRawBits() != fix.getRawBits());
}

Fixed				Fixed::operator+(const Fixed& fix) const
{
	Fixed	res;
	res.setRawBits((getRawBits() + fix.getRawBits()));
	return (res);
}
Fixed				Fixed::operator-(const Fixed& fix) const
{
	Fixed	res;
	res.setRawBits((getRawBits() - fix.getRawBits()));
	return (res);
}
Fixed				Fixed::operator*(const Fixed& fix) const
{
	Fixed	res;
	res.setRawBits((getRawBits() * fix.getRawBits()) >> bits);
	return (res);
}
Fixed				Fixed::operator/(const Fixed& fix) const
{
	Fixed	res(this->toFloat() / fix.toFloat());
	return (res);
}

Fixed&				Fixed::operator++()
{
	++val;
	return (*this);
}
Fixed				Fixed::operator++(int)
{
	Fixed	old(*this);

	++val;
	return (old);
}
Fixed&				Fixed::operator--()
{
	--val;
	return (*this);
}
Fixed				Fixed::operator--(int)
{
	Fixed	old(*this);

	--val;
	return (old);
}

Fixed&		Fixed::min(Fixed& x, Fixed& y)
{
	if (x < y)
		return (x);
	return (y);
}
const Fixed&	Fixed::min(const Fixed& x, const Fixed& y)
{
	if (x < y)
		return (x);
	return (y);	
}
Fixed&		Fixed::max(Fixed& x, Fixed& y)
{
	if (x > y)
		return (x);
	return (y);	
}
const Fixed&	Fixed::max(const Fixed& x, const Fixed& y)
{
	if (x > y)
		return (x);
	return (y);	
}
