#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

class Reader
{
private:
    std::string _Id;
	std::string _name;
	std::string _lastName;
    std::vector<std::string> _val = {};
    std::vector<std::string>& _listBookLoan = _val;
public:
    Reader(std::string Id, std::string name, std::string lastName);
    std::string getId() const;
	std::string getName() const;
    std::string getlastName() const;
    void setId(std::string a);
	void setName(std::string a);
    void setlastName(std::string a);
    friend std::ostream& operator<<(std::ostream& os, const Reader& r);
    void displayLoan();
    friend std::vector<std::string>& getBookLoan(Reader& r);
    bool operator==(const Reader& r) const;
};
