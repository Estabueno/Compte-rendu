#pragma once
#include <string>
#include <iostream>
#include <algorithm>

class Product
{
private:
    std::string _title;
    std::string _description;
    int _quantity;
    float _price;
public:
    Product(std::string title,std::string description,int quantity,float price);
    std::string getTitle();
    std::string getDescription();
    int getQuantity();
    float getPrice();
    void setQuantity(int quantity);
    bool operator==(const Product& p) const;
    friend std::ostream& operator<<(std::ostream& os, Product& p);
};