#ifndef RANK_HPP
# define RANK_HPP

# include "itemType.hpp"
# include "parsDictionary.hpp"

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

		void					setName(std::string name_rank);

		void					addClassItem(std::string name_class);
		void					addItem(std::string name_class, std::string name_item, std::map<std::string, std::string> dictonary);
		void					addOtherItem(std::string name_item, std::map<std::string, std::string> dictionary);
		void					addOtherPrice(std::string name_item, std::string prix, std::string unit);

		void					addOtherUnit(std::string prix, std::string unit);

		void					addPrice(std::string name_class, std::string name_item, std::string prix, std::string unit);


		std::string				getName(void);
		std::vector<ItemType>&	getType(void);
};

#endif