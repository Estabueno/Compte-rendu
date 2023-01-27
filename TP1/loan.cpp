#include "loan.h"

Loan::Loan(Date d, Book& b, Reader r)
:_d(d),_b(b), _r(r),_isLoaned(ok)
{
    if(!d.isDate())
    {
        toString(_d);
    }
}

Date Loan::getDate()
{
    return _d;
}

Reader& Loan::getReader()
{
    return _r;
}

Book &Loan::getBook()
{
    return _b;
}

bool& Loan::getIsLoaned()
{   
	return _isLoaned;
}

void Loan::setIsLoaned(bool i)
{
    if(i)
    {
        _b.setAvailable(true);
    }        
    else
    {
        _b.setAvailable(false);
    }
    _isLoaned = i;
}

std::string toString(Loan l)
{
    std::ostringstream buffer;
    if(l.getDate().isDate())
    {
        buffer << "Date d'emprunt : " << toString(l.getDate()) << std::endl << "ISBN : " << l.getBook().getISBN() << std::endl
        << "Id du lecteur : " << l.getReader().getId() << std::endl;
        return buffer.str();
    }
    else
    {
        buffer << "Emprunt : date d'emprunt non conforme, veuillez resaisir les informations." << std::endl;
        return buffer.str();
    }
}
