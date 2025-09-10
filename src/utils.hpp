#ifndef UTILS_HPP
# define UTILS_HPP
# include "define.hpp"
# include "replaceYml.hpp"

# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>

void        reverse(char s[]);
void        itoa(int n, char s[]);
std::string change_class_name(std::string class_name);
std::string select_defis_link(std::string name_rank);
void        create_all_link(std::vector<ItemType> all_class, std::string rank_name);
std::string ft_replace(std::string str);

#endif