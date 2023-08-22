#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class						WrongAnimal
{
	protected:
		std::string			type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& wa);
		virtual ~WrongAnimal();
		virtual WrongAnimal&		operator=(const WrongAnimal& wa);

		std::string			getType() const;
		void				setType(std::string name);
		void				makeSound() const;
};

#endif