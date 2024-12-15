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
		Item();
		~Item();


		void	addPrice(std::string unit, std::string prix);
		void	addPrice(price new_price);



		std::vector<price>&	getType(void);
		std::string	getName(void);

		const std::vector<price>& getType() const;

};

// std::ostream	&operator<<(std::ostream& os, std::vector<price>& obj);

#endif