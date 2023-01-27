#include "author.h"

Author::Author(std::string Id, std::string name, std::string lastName, Date birthDate)
:_Id(Id),_name(name),_lastName(lastName),_birthDate(birthDate)
{
    if(!birthDate.isDate())
    {
        _Id = " ";
        _name = " ";
        _lastName = " ";
    }
}

Date Author::getBirthDate()
{
	return _birthDate;
}

std::string Author::getId(){
    return _Id;
}

std::string Author::getName(){
    return _name;
}
std::string Author::getLastName(){
    return _lastName;
}

std::string Author::getAuthor()
{
	return _name + " " + _lastName;
}

void Author::displayBookAuthor()
{
    std::cout << "Liste des livres écrit par " << _name << " " << _lastName << std::endl;
    for(unsigned i = 0; i < _listBook.size(); ++i)
    {
        std::cout << _listBook.at(i) << std::endl;
    }
	std::cout << std::endl;
}

std::vector<std::string>& getListBook(Author& a)
{
    return a._listBook;
}

std::ostream& operator<<(std::ostream& os, Author& a) {
    if(a.getBirthDate().isDate())
    {
	    os << "Identifiant de l'auteur : " << a.getId() << std::endl << "Nom : " << a.getAuthor() << std::endl
        << "Date de naissance : " << toString(a.getBirthDate()) << std::endl;
    }
    else
        os << "La date de naissance n'est pas conforme, veuillez resaisir les informations" << std::endl;
    return os;
} 

bool Author::operator==(const Author& a) const
{
    if((_Id == a._Id) && (_name == a._name) && (_lastName == a._lastName) && (_birthDate == a._birthDate))
        return true;
    return false;
}