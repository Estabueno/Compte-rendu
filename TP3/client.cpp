#include "client.h"

Client::Client(std::string Id, std::string name, std::string lastName)
:_Id(Id), _name(name), _lastName(lastName)
{
}

std::string Client::getId() const
{
    return _Id;
}

std::string Client::getName()
{
    return _name;
}

std::string Client::getLastName()
{
    return _lastName;
}

std::vector<std::pair<Product, int>> Client::getShoppingCart()
{
    return _shoppingCart;
}

void Client::addProduct(Product& p, int number)
{
    bool ok = true;
    for(unsigned i = 0; i < _shoppingCart.size();  ++i)
    {
        if(_shoppingCart.at(i).first == p)
        {
            _shoppingCart.at(i).second += number;
            ok = false;
        }
    }
    if(ok)
    {
        auto s = std::make_pair(p,number);
        _shoppingCart.push_back(s);
    }
}

void Client::clearShoppingCart()
{
    _shoppingCart.clear();
}

void Client::updateQuantity(Product& p, int quantity)
{
    bool ok = true;
    for(unsigned i = 0; i < _shoppingCart.size();  ++i)
    {
        if(_shoppingCart.at(i).first == p)
        {
            _shoppingCart.at(i).second = quantity;
            ok = false;
        }
    }
    if(ok)
        std::cout << "Le produit n'est pas dans le panier d'achat" << std::endl << std::endl;
}

void Client::eraseProduct(Product& p)
{
    bool ok = true;
    for(unsigned i = 0; i < _shoppingCart.size();  ++i)
    {
        if(_shoppingCart.at(i).first == p)
        {
            _shoppingCart.erase(_shoppingCart.begin() + i);
            std::cout << std::endl << "Le produit a été supprimé du panier d'achat" << std::endl;
            ok = false;
        }
    }
    if(ok)
        std::cout << "Le nom du produit n'est pas correct" << std::endl;
}

void Client::displayShoppingCart()
{
    std::cout << "Panier d'achat :" << std::endl;
    for(unsigned i = 0; i < _shoppingCart.size(); ++i)
    {
        std::cout << _shoppingCart.at(i).first.getTitle() << " / Quantité : " << _shoppingCart.at(i).second << std::endl;
    }
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, Client& c)
{
	os << "Identifiant du client : " << c._Id << std::endl << "Prénom : " << c._name << std::endl
    << "Nom de famille : " << c._lastName << std::endl << "Panier d'achat :" << std::endl;
    for(unsigned i = 0; i < c.getShoppingCart().size(); ++i)
    {
        os << c.getShoppingCart().at(i).first.getTitle() << " / Quantité : " << c.getShoppingCart().at(i).second << std::endl;
    }
    os << std::endl;
    return os;
}

bool Client::operator==(const Client& c) const
{
	if((_Id == c._Id) && (_name == c._name) && (_lastName == c._lastName))
		return true;
	return false;
}
