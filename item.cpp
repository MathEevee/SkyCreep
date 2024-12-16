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
		return ("PatateEmpoisonee");
	if (old_name == "Andésite")
		return ("Andesite");
	if (old_name == "Chêne")
		return ("Chene");
	if (old_name == "Block de Paille")
		return ("Paille");
	if (old_name == "Verrue nether")
		return ("Verrues");
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
	if (old_name == "Mossy Cobble")
		return ("CobbleMoussue");
	if (old_name == "Oeufs")
		return ("Oeuf");
	if (old_name == "Bloc purpur")
		return ("PurpurBlock");
	if (old_name == "Liane")
		return ("Lianes");
	if (old_name == "SlimeBall")
		return ("Slime");
	if (old_name == "Brique")
		return ("EndstoneBrick");
	if (old_name == "Minerai Charbon")
		return ("MineraisCharbon");
	if (old_name == "Minerai Fer")
		return ("MineraisFer");
	if (old_name == "Minerai Or")
		return ("MineraisOr");
	if (old_name == "Minerai Diamant")
		return ("MineraisDiamant");
	if (old_name == "Minerai Quartz")
		return ("Minerai Quartz");
	if (old_name == "Minerai Redstone")
		return ("MineraisRedstone");
	if (old_name == "Minerai Lapis Lazuli")
		return ("MineraisLapisLazuli");
	if (old_name == "Minerai Emeraude")
		return ("MineraisEmeraude");
	if (old_name == "Boule de neige")
		return ("Boule");
	if (old_name == "Bloc de neige")
		return ("Bloc");
	if (old_name == "Blazerod")
		return ("BlazeRod");
	if (old_name == "Endrod")
		return ("EndRod");
	if (old_name == "Block Magma")
		return ("MagmaBloc");
	if (old_name == "Brique du Nether")
		return ("NetherBrick");
	if (old_name == "Brique rouge du Nether")
		return ("RedNetherBrick");
	if (old_name == "Normale")
		return ("Ice");
	if (old_name == "Normale")
		return ("Ice");
	if (old_name == "Enderpearl")
		return ("EnderPearl");
	if (old_name == "Block Verrue Nether")
		return ("BlocVerrues");
	if (old_name == "Monolithe de Verrues")
		return ("MonolitheVerrues");
	return (old_name);
}

std::string change_name(std::string old_name)
{
	std::string new_name = old_name;
	new_name = select_pars_item(old_name);
	if (new_name != old_name)
		return (new_name);

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