#include "item.hpp"

std::string select_pars_item(std::string old_name)
{
	if (old_name == "Pomme dorée")
		return ("PommeOr");
	if (old_name == "Canne à sucre")
		return ("CanneASucre");
	if (old_name == "Carotte dorée")
		return ("CarotteOr");
	if (old_name == "Chêne Noir")
		return ("CheneNoir");
	if (old_name == "Feuillage Chêne Noir" || old_name == "Feuillage Chene noir")
		return ("FeuillageCheneNoir");
	if (old_name == "Patate empoisonnée")
		return ("PatateEmpoisonnee");
	if (old_name == "Andésite")
		return ("Andesite");
	if (old_name == "Chêne")
		return ("Chene");
	if (old_name == "Block de Paille")
		return ("Paille");
	if (old_name == "Verrue nether")
		return ("Verrues");
	if (old_name == "Block Verrue Nether")
		return ("BlocVerrues");
	if (old_name == "Bloc")
		return ("Endstone");
	if (old_name == "Bloc d'Os")
		return ("BlocOs");
	if (old_name == "fruit")
		return ("ChorusFruit");
	if (old_name == "éclaté")
		return ("ChorusEclate");
	if (old_name == "Oeil Araignée")
		return ("OeilAraignee");
	if (old_name == "Graine")
		return ("GraineBle");
	if (old_name == "Epi")
		return ("Ble");
	if (old_name == "Rouge")
		return ("ChampignonRouge");
	if (old_name == "Brun")
		return ("ChampignonBrun");
	if (old_name == "Poisson Clown")
		return ("PoissonTropical");
	if (old_name == "Compactée")
		return ("PackedIce");
	if (old_name == "Compactée")
		return ("PackedIce");
	if (old_name == "CobbleStone")
		return ("Cobble");
	if (old_name == "Poisson globe")
		return ("Pufferfish");
	return (old_name);
}

std::string change_name(std::string old_name)
{
	std::string new_name = old_name;
	// std::cout << "before = " << old_name << std::endl;
	new_name = select_pars_item(old_name);
	if (new_name != old_name)
	{
		// std::cout << "after = " << new_name << std::endl;
		return (new_name);
	}

	if (old_name.find(' ') == std::string::npos)
		return (old_name);

	new_name = "";

	while (old_name.find(' ') != std::string::npos)
	{
		new_name = old_name.substr(0, old_name.find(' '));
		old_name = old_name.substr(old_name.find(' ') + 1);
		if (old_name[0])
		{
			if (old_name[0] >= 'a' && old_name[0] <= 'z')
				old_name[0] = old_name[0] - 32;
		}
		new_name = new_name + old_name;
	}
	// std::cout << "after = " << new_name << std::endl;
	return (new_name);
}

Item::Item()
{}

Item::Item(std::string name)
{
	std::string new_name;

	new_name = change_name(name);

	this->_name_item = new_name;
}

void	Item::addPrice(price new_price)
{
	this->getType().push_back(new_price);
}

void	Item::addPrice(std::string unit, std::string prix)
{
	price new_price(unit, prix);

	this->getType().push_back(new_price);
}

Item::~Item()
{}

std::string	Item::getName(void)
{
	return (this->_name_item);
}


std::vector<price>&	Item::getType(void)
{
	return (this->_price);
}

const std::vector<price>& Item::getType() const {
    return this->_price;
}

// std::ostream	&operator<<(std::ostream& os, std::vector<price>& obj)
// {
// 	for (std::vector<price>::iterator it = obj.begin(); it != obj.end(); it++)
// 	{
// 		os << (*it).getType() << std::endl;
// 	}
// 	return (os);
// }