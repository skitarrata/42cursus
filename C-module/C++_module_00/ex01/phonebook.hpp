#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class				Contact
{
	public:
		std::string	f_name;
		std::string	l_name;
		std::string	nik;
		std::string	number;
		std::string	secret;
};

class				ph_book
{
	public:
		int	ind;
		ph_book();
		~ph_book();
		void		ft_add();
		void		ft_search();
		void		ft_exit();
	private:
		Contact		contact[8];
		void			ft_stamp(int n);
		void			ft_tab(int i, std::string str)
		{
			std::cout << "|";
			if (str.length() > 10)
				std::cout << str.substr(0, 9) << ".";
			else
				std::cout << std::setw(10) << str;
		}
		int				ft_err(std::string str, int n)
		{
			if (n)
				return (n);
			if (str.empty())
				return (1);
			return (0);
		}
};

#endif