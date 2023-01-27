#include "reader.h"

Reader::Reader(std::string Id, std::string name, std::string lastName)
:_Id(Id),_name(name),_lastName(lastName)
{
}

std::string Reader::getId() const
{
	return _Id;
}

std::string Reader::getName() const
{
	return _name;
}

std::string Reader::getlastName() const
{
	return _lastName;
}

void Reader::setId(std::string a)
{
	_Id = a;
}

void Reader::setName(std::string a)
{
	_name = a;
}

void Reader::setlastName(std::string a)
{
	_lastName = a;
}

std::ostream& operator<<(std::ostream& os, const Reader& r) {
	os << "Lecteur:" << std::endl << "Prénom : " << r.getName() << std::endl << "Nom de Famille : " << r.getlastName()
    << std::endl << "Id : " << r.getId() << std::endl;
	return os;
}

void Reader::displayLoan()
{
	std::cout << "Liste des ISBN des livres empruntés par " << _name << " " << _lastName << ":" << std::endl;
	for(unsigned i = 0; i < _listBookLoan.size(); ++i)
    {
        std::cout << _listBookLoan.at(i) << std::endl;
    }
	std::cout << std::endl;
}

std::vector<std::string>& getBookLoan(Reader& r)
{
	return r._listBookLoan;
}

bool Reader::operator==(const Reader& r) const
{
	if((_Id == r._Id) && (_name == r._name) && (_lastName == r._lastName))
		return true;
	return false;
}
