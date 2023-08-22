#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class							Dog : public Animal
{
	private:
		Brain* brd;
	public:
		Dog();
		Dog(const Dog& d);
		Dog&					operator=(const Dog& d);
		~Dog();
		Brain*					getBrain() const;
		void					makeSound() const;
};

#endif