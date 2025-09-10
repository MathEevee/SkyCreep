#ifndef ITEMTYPE_HPP
# define ITEMTYPE_HPP

# include "item.hpp"

#include <iostream>


class ItemType
{
	private :
		std::string			_name_type;
		std::vector<Item>	_item;
	public :
		ItemType();
		ItemType(std::string name_type);
		~ItemType();

		void	setName(std::string item_type);

		std::string			getName(void);
		std::vector<Item>&	getItemType(void);
};

#endif