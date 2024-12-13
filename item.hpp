#ifndef ITEM_HPP
# define ITEM_HPP

# include <iostream>
# include <vector>
# include <iomanip>

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>

# include "price.hpp"

class Item
{
	private :
		std::string			_name_item;
		std::vector<price>	_price;
	public :
		Item(std::string name);
		~Item();

		void	addPrice(price unit_price_item);


		std::vector<price>&	getType(void);
		std::string	getName(void);

};

// std::ostream	&operator<<(std::ostream& os, std::vector<price>& obj);

#endif