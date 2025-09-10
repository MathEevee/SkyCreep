#ifndef REPLACEYML_HPP
# define REPLACEYML_HPP
# include "item.hpp"
# include "itemType.hpp"
# include "file.hpp"
# include "parsDictionary.hpp"

std::string	select_defis_link(std::string name_rank);
void	    create_all_link(std::vector<ItemType> all_class, std::string rank_name);
void	    overwrite(File file, std::string link);
bool	    parsing_line_for_item(std::string line, Item curr_item, int &nbr, bool change_line);
std::string new_line(std::string line, int &nbr, Item item);
std::string new_line_laine(std::string line, int &nbr, Item item, int &nbr_rewards);
void	    file_laine(std::vector<Item> all_item, std::string link);
void	    file_overwrite(std::vector<Item> all_item, std::string link);
void	    change_file(std::vector<Item> all_item, std::string link);
void	    parse_link_file(std::vector<Item> all_item, std::string class_name, std::string rank_name);


#endif