#include "book.h"

Book::Book(std::string title, Author& author, Language language, Kind kind, Date publication, std::string ISBN):_title(title),_language(language),
_kind(kind),_publication(publication),_ISBN(ISBN), _author(author),_available(_init)
{
	if(!_publication.isDate())
	{
		_title = " ";
		_ISBN = " ";
	}
	else
	{
		getListBook(_author).push_back(_title);
	}
}

std::string Book::getTitle() const
{
	return _title;
}

std::string Book::getISBN() const
{
	return _ISBN;
}

Date Book::getDate()
{
	return _publication;
}
Author& Book::getAuthor() const
{
    return _author;
}

Language Book::getLanguage() const
{
	return _language;
}

Kind Book::getKind() const
{
	return _kind;
}

std::string Book::whichLanguage(Language l)
{
	std::ostringstream buffer;
	switch (l)
	{
		case 0:
			buffer << "Français";
			return buffer.str();
			break;
		case 1:
			buffer << "Anglais";
			return buffer.str();
			break;
		case 2:
			buffer << "Allemand";
			return buffer.str();
			break;
		case 3:
			buffer << "Espagnol";
			return buffer.str();
			break;
	}
}

std::string Book::whatKind(Kind k)
{
	std::ostringstream buffer;
	switch (k)
	{
		case 0:
			buffer << "Romance";
			return buffer.str();
			break;
		case 1:
			buffer << "Science Fiction";
			return buffer.str();
			break;
		case 2:
			buffer << "Policier";
			return buffer.str();
			break;
		case 3:
			buffer << "Historique";
			return buffer.str();
			break;
	}
}
void Book::displayLoaner()
{
    std::cout << "Liste des Id des personnes ayant empruntés " << _title << " :" << std::endl;
    for(unsigned i = 0; i < _listLoaner.size(); ++i)
    {
        std::cout << _listLoaner.at(i) << std::endl;
    }
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, Book& b) {
	if(b.getDate().isDate())
	{
		os << "Titre du livre : " << b.getTitle() << std::endl << b.getAuthor() << "Langue : " << b.whichLanguage(b.getLanguage()) << std::endl
		<< "Genre : " << b.whatKind(b.getKind()) << std::endl << "Date de publication : " << toString(b.getDate()) << std::endl
		<< "ISBN : " << b.getISBN() << std::endl;
	}
	else
		os << "La date de publication n'est pas conforme, veuillez resaisir les informations" << std::endl;
	return os;
}

void addLoaner(Book& b, Reader& r)
{
    getListLoaner(b).push_back(r.getId());
}

std::vector<std::string>& getListLoaner(Book &b)
{
		return b._listLoaner;
}

bool Book::operator==(const Book& b) const
{
	if((_title == b._title) && (_language == b._language) && (_kind == b._kind) && (_ISBN == b._ISBN) && (_publication == b._publication) && (_author == b._author))
		return true;
	return false;
}

bool& Book::getAvailable()
{
	return _available;
}

void Book::setAvailable(bool i)
{
	_available = i;
}
