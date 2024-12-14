#ifndef PRICE_HPP
# define PRICE_HPP

# include <iostream>

class price
{
	private:
		std::string 		_prix;
		std::string 		_unit;

	public:
		price(std::string unit, std::string prix);
		price(std::string unit);
		price();
		~price();

		std::string	getPrice(void);
		std::string	getUnit(void);
};

// std::ostream	&operator<<(std::ostream& os, std::vector<price>& obj);


#endif