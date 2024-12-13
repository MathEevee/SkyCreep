#ifndef PRICE_HPP
# define PRICE_HPP

# include <iostream>

class price
{
	private:
		std::string 		_prix;
		std::string 		_unit;

	public:
		price(std::string unit, std::string  prix);
		price(std::string unit);
		~price();

		void		addPrice(std::string  prix);

		std::string 		getPrice(void);
		std::string getUnit(void);

		void		setPrice(std::string  prix);
};

// std::ostream	&operator<<(std::ostream& os, std::vector<price>& obj);


#endif