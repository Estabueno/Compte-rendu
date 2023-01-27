#pragma once
#include "product.h"
#include <vector>
#include <algorithm>


class Client
{
private:
    std::string _Id;
    std::string _name;
    std::string _lastName;
    std::vector<std::pair<Product,int>> _shoppingCart;
public:
    Client(std::string Id, std::string name, std::string lastName);
    std::string getId() const;
    std::string getName();
    std::string getLastName();
    std::vector<std::pair<Product,int>> getShoppingCart();
    void addProduct(Product& p,int number);
    void clearShoppingCart();
    void updateQuantity(Product& p, int quantity);
    void eraseProduct(Product& p);
    void displayShoppingCart();
    friend std::ostream& operator<<(std::ostream& os, Client& c);
    bool operator==(const Client& c) const;
};
