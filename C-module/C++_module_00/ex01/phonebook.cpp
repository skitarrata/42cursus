#include "phonebook.hpp"

void	ph_book::ft_add()
{
	int err;

	if (ind == 8)
		ind = 0;
	do
	{
		err = 0;
		std::cout << "enter name " << ind + 1 <<":";
		std::getline(std::cin, this->contact[ind].f_name);
		err = ph_book::ft_err(this->contact[ind].f_name, err);
		std::cout << "enter lastname "<< ind + 1 <<":";
		std::getline(std::cin, this->contact[ind].l_name);
		err = ph_book::ft_err(this->contact[ind].l_name, err);
		std::cout << "enter nikname "<< ind + 1 <<":";
		std::getline(std::cin, this->contact[ind].nik);
		err = ph_book::ft_err(this->contact[ind].nik, err);
		std::cout << "enter phonenumber "<< ind + 1 <<":";
		std::getline(std::cin, this->contact[ind].number);
		err = ph_book::ft_err(this->contact[ind].number, err);
		std::cout << "enter secret "<< ind + 1 <<":";
		std::getline(std::cin, this->contact[ind].secret);
		err = ph_book::ft_err(this->contact[ind].secret, err);
		if (err == 1)
			std::cout << "one of the fields is empty, try again\n";
	} while(err);
	if (ind == 7)
		std::cout << "the phonebook is full, the contacts will be replaced\n";
	ind++;
}

void	ph_book::ft_stamp(int n)
{
	std::string	str;
	int			i;

	do
	{
		std::cout << "which index are you looking for ? ";
		std::getline(std::cin, str);
		i = str[0] - 48 - 1;
		if (str.empty() || i >= n || i < 0)
			std::cout << "index does not exist" << std::endl;
	} while (str.empty() || i >= n || i < 0);

	std::cout << "name: " << contact[i].f_name << std::endl;
	std::cout << "lastname: "<< contact[i].l_name << std::endl;
	std::cout << "nikname: "<< contact[i].nik << std::endl;
	std::cout << "phonenumber: "<< contact[i].number << std::endl;
	std::cout << "secret: "<< contact[i].secret << std::endl;
}

void	ph_book::ft_search()
{
	static int max = 0;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	if (!ind)
		return ;
	if (ind > max)
		max = ind;
	for (int i = 0; i < max; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		ph_book::ft_tab(i, this->contact[i].f_name);
		ph_book::ft_tab(i, contact[i].l_name);
		ph_book::ft_tab(i, contact[i].nik);
		std::cout << "|" << std::endl;
	}
	ph_book::ft_stamp(max);
}

void	ph_book::ft_exit()
{
	std::cout << "OK, BYE!" << std::endl;
	exit (0);
}

ph_book::ph_book(){ind = 0;}
ph_book::~ph_book(){}

int	main (void)
{
	std::string	command;
	ph_book		ph_book;

	std::cout << "WELCOME TO YOUR PHONEBOOK!" << std::endl;
	while (1)
	{
		std::cout << "choose the command between: ADD, SEARCH, EXIT ---> ";
		std::getline(std::cin, command);
		if (command == "ADD")
			ph_book.ft_add();
		else if (command == "SEARCH")
			ph_book.ft_search();
		else if (command == "EXIT")
			ph_book.ft_exit();
		else
			std::cout << "bad command" << std::endl;
	}
	return (0);
} 