#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <vector>

//* ################# DEFINES #################

# define DEL "\n"
# define DELSIZE 1
# define USERLEN 16
# define CHANLIMIT 2

//* ################# Message #################

int _ft_atoi(std::string text);
int _ft_set_element(std::string _text, int start, std::string *element);
std::vector<std::string> ft_split(std::string _text, char delimiter);


#endif