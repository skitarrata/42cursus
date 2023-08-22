#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class						Cat : public Animal
{
	private:
		Brain* brc;
	public:
		Cat();
		Cat(const Cat& c);
		Cat&				operator=(const Cat& c);
		~Cat();

		Brain*				getBrain() const;
		void				makeSound() const;
};

#endif