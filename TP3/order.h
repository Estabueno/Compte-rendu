#pragma once
#include "client.h"
#include "product.h"

class Order
{
private:
    Client _client;
    std::vector<std::pair<Product,int>> _boughtProducts;
    int _status;

public:
    Order(Client& c);
    void displayBoughtProducts();
    std::vector<std::pair<Product,int>> getBoughtProducts();
    Client& getClient();
    int getStatus();
    void setStatus(int s);
    bool operator==(const Order& p) const;
    friend std::ostream& operator<<(std::ostream& os, Order& o);
};
