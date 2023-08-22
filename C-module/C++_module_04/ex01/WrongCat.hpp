#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class						WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& wc);
		~WrongCat();
		WrongCat&			operator=(const WrongCat& wc);

		void				makeSound() const;
};

#endif