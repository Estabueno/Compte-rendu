#pragma once
#include <iostream>
#include "date.h"
#include <string>
#include <sstream>
#include <vector>

class Author {
private:
    std::string _Id;
    std::string _name;
    std::string _lastName;
    Date _birthDate;
    std::vector<std::string> _val = {};
    std::vector<std::string>& _listBook = _val;
public:
    Author(std::string Id, std::string name, std::string lastName, Date birthDate);
    Date getBirthDate();
    std::string getId();
    std::string getName();
    std::string getLastName();
    std::string getAuthor();
    void displayBookAuthor();
    friend std::vector<std::string>& getListBook(Author& a);
    friend std::ostream& operator<<(std::ostream& os, Author& a);
    bool operator==(const Author& a) const;
};
