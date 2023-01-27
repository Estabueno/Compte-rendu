#include "product.h"

Product::Product(std::string title,std::string description,int quantity,float price)
:_title(title), _description(description), _quantity(quantity), _price(price)
{
}

std::string Product::getTitle()
{
    return _title;
}

std::string Product::getDescription()
{
    return _description;
}

int Product::getQuantity()
{
    return _quantity;
}

float Product::getPrice()
{
    return _price;
}

void Product::setQuantity(int quantity)
{
    _quantity = quantity;
}

bool Product::operator==(const Product& p) const
{
	if((_title == p._title) && (_description == p._description) && (_price == p._price))
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, Product& p) 
{
	os << "Titre du produit : " << p._title << std::endl << "Description : " << p._description << std::endl
    << "Quantité : " << p._quantity << std::endl << "Prix unitaire : " << p._price << std::endl << std::endl;
    return os;
}