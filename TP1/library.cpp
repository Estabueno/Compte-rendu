#include "library.h"

Library::Library(Author& a, Book& b, Reader& r)
:_a(a),_b(b),_r(r)
{
    _listAuthor.push_back(_a);
    _listBook.push_back(_b);
    _listReader.push_back(_r);
    _bestReader[_r.getName()] = getBookLoan(_r).size();
}

void Library::addAuthor(Author a)
{
    bool ok = true;
    for(unsigned i = 0; i < _listAuthor.size(); ++i)
    {
        if(_listAuthor.at(i) == a || !a.getBirthDate().isDate())
        {
            ok = false;
        }
    }
    if(ok)
    {
        _listAuthor.push_back(a);
    }
}

void Library::addBook(Book b)
{
    bool ok = true;
    for(unsigned i = 0; i < _listBook.size(); ++i)
    {
        if(_listBook.at(i) == b || !b.getDate().isDate())
        {
            ok = false;
        }
    }
    if(ok)
    {
        _listBook.push_back(b);
    }
}

void Library::addReader(Reader r)
{
    bool ok = true;
    for(unsigned i = 0; i < _listReader.size(); ++i)
    {
        if(_listReader.at(i) == r)
        {
            ok = false;
        }
    }
    if(ok)
    {
        _listReader.push_back(r);
        _bestReader[r.getName()] = getBookLoan(r).size();
    }

}

void Library::displayAuthor()
{
    std::cout << "Liste des Auteurs:" << std::endl;
    for(unsigned i = 0; i < _listAuthor.size(); ++i)
    {
        std::cout << _listAuthor.at(i) << std::endl;
    }
    std::cout << std::endl;
}

void Library::displayBook()
{
    std::cout << "Liste des Livres:" << std::endl;
    for(unsigned i = 0; i < _listBook.size(); ++i)
    {
        std::cout << _listBook.at(i) << std::endl;
    }
    std::cout << std::endl;
}

void Library::displayReader()
{
    std::cout << "Liste des Lecteurs:" << std::endl;
    for(unsigned i = 0; i < _listReader.size(); ++i)
    {
        std::cout << _listReader.at(i) << std::endl;
    }
    std::cout << std::endl;
}

bool Library::loan(Loan& l)
{
    bool ok = false;
    if(l.getDate().isDate())
    {
        if(l.getBook().getAvailable() && l.getIsLoaned())
        {
            for(unsigned i = 0; i < _listBook.size(); ++i)
            {
                if(_listBook.at(i) == l.getBook())
                {
                    _listBookLoan.push_back(l.getBook().getTitle());
                    std::cout << l.getReader().getName() <<  " a emprunté " << l.getBook().getTitle() << std::endl << std::endl;
                    for(unsigned j = 0; j < getListLoaner(l.getBook()).size(); ++j)
                    {
                        if(getListLoaner(l.getBook()).at(j) == l.getReader().getId())
                        {
                            ok = true;
                        }
                    }
                    if(!ok)
                    {
                        addLoaner(l.getBook(),l.getReader());
                    }
                    addBookLoan(l.getReader(), l.getBook());
                    _bestReader[l.getReader().getName()] = getBookLoan(l.getReader()).size();
                    l.setIsLoaned(false);
                    return true;
                }
            }
            return false;
        }
        else if(l.getIsLoaned() && !l.getBook().getAvailable())
        {
            std::cout << l.getBook().getTitle() << " n'est pas disponible, il a déjà été emprunté" << std::endl << std::endl;
            return false;
        }
    }
    else
        std::cout << "La date d'emprunt de ce livre n'est pas conforme, vous ne pouvez pas l'emprunter." << std::endl << std::endl;
    return false;
}

bool Library::restore(Loan& l)
{
    if(l.getDate().isDate())
    {
        if(!l.getIsLoaned())
        {
            std::vector<std::string>::iterator it;
            it = std::find(_listBookLoan.begin(), _listBookLoan.end(), l.getBook().getTitle());
            _listBookLoan.erase(it);
            std::vector<std::string>::iterator it1;
            it1 = std::find(getBookLoan(l.getReader()).begin(), getBookLoan(l.getReader()).end(), l.getBook().getISBN());
            getBookLoan(l.getReader()).erase(it1);
            std::cout << l.getReader().getName() <<  " a restitué " << l.getBook().getTitle() << std::endl << std::endl;
            l.setIsLoaned(true);
            _bestReader[l.getReader().getName()] = getBookLoan(l.getReader()).size();
            return true;
        }
        else if(l.getIsLoaned())
        {
            std::cout << l.getReader().getName() << " ne peut pas restituer " << l.getBook().getTitle() << std::endl << std::endl;
            return true;
        }
        else
            std::cout << "La date d'emprunt de ce livre n'est pas conforme, vous ne pouvez pas le restituer." << std::endl << std::endl;
    }
    return false;
}

void Library::displayLoan()
{
    std::cout << "Liste des livres empruntés:" << std::endl;
    for(unsigned i = 0; i < _listBookLoan.size(); ++i)
    {
        std::cout << _listBookLoan.at(i) << std::endl;
    }
    std::cout << std::endl;
}

float Library::percentageBook()
{
    return ((float)_listBookLoan.size()/(float)_listBook.size())*100;
}

void addBookLoan(Reader& r, Book& b)
{
	getBookLoan(r).push_back(b.getISBN());
}

void Library::bestReader()
{
    int _numbers[_listReader.size()];
    std::string _names[_listReader.size()];
    int _a;
    std::string _b;

    for(unsigned i =0; i != _listReader.size(); i++)
    {
        _numbers[i] = getBookLoan(_listReader[i]).size();
        _names[i] = _listReader[i].getName();
    }

    std::cout << std::endl;

    for(unsigned i =0; i != _listReader.size(); i++)
    {
        for(unsigned j =0; j != _listReader.size() -1 ; j++)
        {
            if( _numbers[j] < _numbers[j+1] )
            {
                _a = _numbers[j];
                _b = _names[j];

                _numbers[j] = _numbers[j+1];
                _names[j] = _names[j+1];

                _numbers[j+1] = _a;
                _names[j+1] = _b;
            }
        }
    }

    std::cout << "Classement des lecteurs selon leurs nombres de livres empruntés:" << std::endl;
    for(unsigned i =0; i != _listReader.size(); i++)
    {
        std::cout << _names[i] << "/" << _numbers[i] << std::endl;
    }
}
