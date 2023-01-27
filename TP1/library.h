#pragma once
#include "loan.h"
#include "reader.h"
#include <algorithm>
#include <map>

class Library
{
private:
    Author& _a;
    Book& _b;
    Reader _r;
    std::vector<Book> _listBook;
    std::vector<Reader> _listReader;
    std::vector<Author> _listAuthor;
    std::vector<std::string> _listBookLoan;
    std::map<std::string,int> _bestReader;

public:
    Library(Author& a, Book& b, Reader& r);
    void addAuthor(Author a);
    void addBook(Book b);
    void addReader(Reader r);
    void displayAuthor();
    void displayBook();
    void displayReader();
    float percentageBook();
    bool loan(Loan& l);
    bool restore(Loan& l);
    void displayLoan();
    void bestReader();
};
void addBookLoan(Reader& r, Book& b);
