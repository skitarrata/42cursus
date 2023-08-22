#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class							Animal
{
	protected:
		std::string				type;
	public:
		Animal();
		Animal(const Animal& ani);
		virtual Animal&			operator=(const Animal& ani);
		virtual ~Animal();

		std::string				getType() const;
		void					setType(std::string name);
		virtual void			makeSound() const = 0;
};

#endif