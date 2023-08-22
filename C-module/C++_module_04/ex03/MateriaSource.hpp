#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define MAT_SIZE 4

class 							MateriaSource : public IMateriaSource
{
	private:
		AMateria** _knowMat;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& ms);
		~MateriaSource();

		MateriaSource& 			operator=(const MateriaSource& ms);

		void					learnMateria(AMateria* m);
		AMateria*				createMateria(std::string const & type);
};

#endif