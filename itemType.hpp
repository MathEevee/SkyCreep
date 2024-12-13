#ifndef ITEMTYPE_HPP
# define ITEMTYPE_HPP

# include "item.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>


class ItemType
{
	private :
		std::string			_name_type;
		std::vector<Item>	_item;
	public :
		ItemType(std::string name_type);
		~ItemType();

		void	setName(std::string item_type);

		// void	addItem(price new_price, Item new_item);

		std::string			getName(void);
		std::vector<Item>&	getItemType(void);
};

// std::ostream	&operator<<(std::ostream& os, std::vector<Item>& obj);

#endif