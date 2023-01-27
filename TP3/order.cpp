#include "order.h"

Order::Order(Client& c)
:_client(c),_status(0)
{   
    for(unsigned i = 0; i < _client.getShoppingCart().size(); i++)
    {
        _boughtProducts.push_back(_client.getShoppingCart().at(i));
    }
}

void Order::displayBoughtProducts()
{
    std::cout << "Commande de " << _client.getName() << " " << _client.getLastName() << ":" << std::endl;
    for(unsigned i = 0; i < _boughtProducts.size(); i++)
    {
        std::cout << _boughtProducts.at(i).first.getTitle() << "/ Quantité : " << _boughtProducts.at(i).second << std::endl;
    }
    std::cout << std::endl;
}

std::vector<std::pair<Product,int>> Order::getBoughtProducts()
{
    return _boughtProducts;
}

Client& Order::getClient()
{
    return _client;
}

void Order::setStatus(int s)
{
    _status = s;
}

int Order::getStatus()
{
    return _status;
}

bool Order::operator==(const Order& o) const
{
	if((_client.getId() == o._client.getId()) && (_status == o._status))
		return true;
  else
	 return false;
}

std::ostream& operator<<(std::ostream& os, Order& o)
{
	os << "Description de la commande : " << std::endl << "Client:" << o._client.getName() << " " << o._client.getLastName() << std::endl
    << "Statut: " << o._status << std::endl << "Commande de " << o.getClient().getName() << " " << o.getClient().getLastName() << ":" << std::endl;
    for(unsigned i = 0; i < o.getBoughtProducts().size(); i++)
    {
        os << o.getBoughtProducts().at(i).first.getTitle() << "/ Quantité : " << o.getBoughtProducts().at(i).second << std::endl;
    }
    os << std::endl;
  return os;
}
