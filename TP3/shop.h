#pragma once
#include "client.h"
#include "order.h"

class Shop
{
private:
    std::vector<Product> _products;
    std::vector<Client> _clients;
    std::vector<Order> _orders;
public:
    Shop();
    void addProduct(Product& p);
    void displayProduct();
    void displayProduct(std::string title);
    void updateQuantity(std::string title, int quantity);
    void addClient(Client& c);
    void displayClient();
    void displayClient(std::string choice);
    void addShoppingCart(Client &c, Product p, int number);
    void eraseShoppingCart(Client& c, Product& p);
    void updateQuantityShoppingCart(Client& c, Product& p, int quantity);
    void displayShoppingCart();
    void addOrder(Order& o);
    void displayOrder();
    void orderValidate(Order& o);
    void orderByClient(Client& c);
    bool IsProduct(Product& p);
    bool IsClient(Client& c);
    std::vector<Product> getProduct();
    std::vector<Client> getClient();
    std::vector<Order> getOrder();
    Client& getShopClient(Client c);
    Order& getShopOrder(Order o);
};
