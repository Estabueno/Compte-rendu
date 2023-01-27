#include "shop.h"

Shop::Shop()
{
}

void Shop::addProduct(Product& p)
{
    if(!IsProduct(p))
        _products.push_back(p);
    else
        std::cout << "Le produit a déjà été ajouté" << std::endl << std::endl;
}

void Shop::displayProduct()
{
    for(unsigned i = 0; i < _products.size(); ++i)
    {
        std::cout << _products.at(i) << std::endl;
    }
    std::cout << std::endl;
}

void Shop::displayProduct(std::string title)
{
    bool ok = true;
    for(unsigned i = 0; i < _products.size();  ++i)
    {
        if(title == _products.at(i).getTitle())
        {
            std::cout << _products.at(i) << std::endl;
            ok = false;
        }
    }
    if(ok)
        std::cout << "Le nom du produit n'est pas correct ou le produit n'est pas dans le magasin" << std::endl << std::endl;
}

void Shop::updateQuantity(std::string title, int quantity)
{
    bool ok = true;
    for(unsigned i = 0; i < _products.size();  ++i)
    {
        if(title == _products.at(i).getTitle())
        {
            if(quantity == 0)
            {
                _products.erase(_products.begin()+i);
                std::cout << "Quantité mise à jour, le produit n'est plus disponible dans le magasin." << std::endl;
            }
            else
            {
                _products.at(i).setQuantity(quantity);
                std::cout << "Quantité mise à jour." << std::endl;
            }
            ok = false;
        }
    }
    if(ok)
        std::cout << "Le nom du produit n'est pas correct ou le produit n'est pas dans le magasin" << std::endl << std::endl;
}

void Shop::addClient(Client& c)
{
    if(!IsClient(c))
        _clients.push_back(c);
    else
        std::cout << "Le Client a déjà été ajouté" << std::endl << std::endl;
}

void Shop::displayClient()
{
    for(unsigned i = 0; i < _clients.size(); ++i)
    {
        std::cout << _clients.at(i) << std::endl;
    }
}

void Shop::displayClient(std::string choice)
{
    bool ok = true;
    for(unsigned i = 0; i < _clients.size();  ++i)
    {
        if((choice == _clients.at(i).getId()) || (choice == _clients.at(i).getName()))
        {
            std::cout << _clients.at(i) << std::endl; 
            ok = false;
        }
    }
    if(ok)
        std::cout << "Le prénom ou l'identifiant du Client n'est pas correct ou le Client n'est pas dans le magasin" << std::endl << std::endl;
}

void Shop::addShoppingCart(Client& c, Product p, int number)
{
    if(p.getQuantity() >= number && number != 0)
    {
        bool ok = true;
        for(unsigned i = 0; i < c.getShoppingCart().size();  ++i)
        {
            if((c.getShoppingCart().at(i).second += number) > p.getQuantity() && c.getShoppingCart().at(i).first == p)
            {
                ok = false;
            }
        }
        if(ok)
        {
            getShopClient(c).addProduct(p,number); // Affecte le client ajouté au magasin (copie de l'objet)
            c.addProduct(p,number); // Affecte l'objet
            std::cout << std::endl << "Produit ajouté " << number << " fois au panier de " << c.getName() << "." << std::endl;
        }
        else 
        {
            std::cout << std::endl << "Vous ne pouvez pas ajouter autant de fois ce produit" << std::endl;
        }
    }
    else
        std::cout << std::endl << "Ce produit n'est pas disponible dans les quantités demandées." << std::endl;
    std::cout << std::endl;
    
}

void Shop::eraseShoppingCart(Client& c, Product& p)
{
    getShopClient(c).eraseProduct(p);
}

void Shop::updateQuantityShoppingCart(Client& c, Product& p, int quantity)
{
    if(p.getQuantity() >= quantity)
    {
        getShopClient(c).updateQuantity(p,quantity);
        c.updateQuantity(p,quantity);
        std::cout << std::endl << "Quantité mise à jour" << std::endl;
    }
    else 
        std::cout << std::endl << "Ce produit n'est pas disponible dans les quantités demandées." << std::endl;
    std::cout << std::endl;
}

void Shop::displayShoppingCart()
{
    for(unsigned i = 0; i < _clients.size(); ++i)
    {
        std::cout << _clients.at(i).getName() << std::endl;
        _clients.at(i).displayShoppingCart();
    }
}

void Shop::addOrder(Order& o)
{
    bool ok = true;
    for(unsigned i = 0; i < _orders.size(); ++i)
    {
        if(_orders.at(i) == o)
            ok = false;
    }
    if(ok)
    {
        _orders.push_back(o);
    }
    else
        std::cout << "Cette commande a déjà été ajoutée." << std::endl << std::endl;
}

void Shop::displayOrder()
{
    bool ok = true;
    for(unsigned i = 0; i < _orders.size(); ++i)
    {
        if(_orders.at(i).getStatus() == 1)
        {
            std::cout << _orders.at(i) << std::endl;
            ok = false;
        }
    }
    if(ok)
        std::cout << "Aucune commande n'a été validé pour le moment" << std::endl;
}

void Shop::orderValidate(Order& o)
{
    bool ok = true;
    if(o.getStatus() == 0)
    {
        //Modifier quantités stock et vider panier
        for(unsigned i = 0; i < o.getBoughtProducts().size(); i++)
        {
            for(unsigned j = 0; j < _products.size(); j++)
            {
                if(o.getBoughtProducts().at(i).first == _products.at(j) && (_products.at(j).getQuantity() - o.getBoughtProducts().at(i).second) >= 0)
                {
                    std::cout << "Commande validée." << std::endl;
                    getShopOrder(o).setStatus(1);
                    _products.at(j).setQuantity(_products.at(j).getQuantity() - o.getBoughtProducts().at(i).second);
                    ok = false;
                }
            }
        }
        if(!ok)
        {
            getShopClient(o.getClient()).clearShoppingCart();
            o.getClient().clearShoppingCart();
        }
        else
            std::cout << "La commande ne peut pas être validée, il faut modifier la quantité d'un produit" << std::endl << std::endl;
    }
}

void Shop::orderByClient(Client& c)
{
    for(unsigned i = 0; i < _orders.size(); ++i)
    {
        if(_orders.at(i).getClient() == c && _orders.at(i).getStatus() == 1)
            std::cout << _orders.at(i) << std::endl;
    }
}

bool Shop::IsProduct(Product& p)
{
    for(unsigned i = 0; i < _products.size();  ++i)
    {
        if(p == _products.at(i))
            return true;
    }
    return false;
}

bool Shop::IsClient(Client& c)
{
    for(unsigned i = 0; i < _clients.size();  ++i)
    {
        if(c == _clients.at(i))
            return true;
    }
    return false;
}

std::vector<Product> Shop::getProduct()
{
    return _products;
}

std::vector<Client> Shop::getClient()
{
    return _clients;
}

std::vector<Order> Shop::getOrder()
{
    return _orders;
}

Client& Shop::getShopClient(Client c)
{
  for(unsigned i = 0; i < _clients.size(); i++)
  {
    if(c == _clients.at(i))
    {
      return _clients.at(i);
    }
  }
}

Order& Shop::getShopOrder(Order o)
{
  for(unsigned i = 0; i < _orders.size(); i++)
  {
    if(o == _orders.at(i))
    {
      return _orders.at(i);
    }
  }
}

