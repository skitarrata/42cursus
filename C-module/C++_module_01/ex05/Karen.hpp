#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>

class			karen
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		void	complain(std::string level);
		karen(){};
		~karen(){};
};

#endif