#ifndef RANK_HPP
# define RANK_HPP

# include <iostream>
# include <vector>
# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <fstream>

# include "itemType.hpp"

class ItemType;

class rank
{
	private :
		std::string				_name_rank;
		std::vector<ItemType>	_item_type;
	public :
		rank();
		rank(std::string name);
		~rank();

		void			setName(std::string name_rank);

		void			addClassItem(std::string name_class);
		void			addItem(std::string name_class, std::string name_item);
		void			addOtherItem(std::string name_item);
		void			addOtherPrice(std::string name_item, std::string prix, std::string unit);


		void			addOtherUnit(std::string prix, std::string unit);

		void			addPrice(std::string name_class, std::string name_item, std::string prix, std::string unit);


		std::string		getName(void);
		std::vector<ItemType>&	getType(void);
};


// std::ostream	&operator<<(std::ostream& os, std::vector<rank>& obj);

#endif