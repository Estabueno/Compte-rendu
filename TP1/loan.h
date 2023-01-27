#pragma once
#include "book.h"

class Loan  
{
private:
    Date _d;
    Book& _b;
    Reader _r;
    bool ok = true;
    bool& _isLoaned;
public:
    Loan(Date d,Book& b,Reader r);
    Date getDate();
    Reader& getReader();
    Book& getBook();
    bool& getIsLoaned();
	void setIsLoaned(bool i);
};

std::string toString(Loan l);
