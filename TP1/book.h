#pragma once
#include <string>
#include <vector>
#include "author.h"
#include "reader.h"

enum Language
{
	French,
	English,
	German,
	Spanish,
};

enum Kind
{
	Love,
	SF,
	Detective,
	Historical,
};

class Book
{
private:
	std::string _title;
	Language _language;
	Kind _kind;
	Date _publication;
	std::string _ISBN;
    Author& _author;
	std::vector<std::string> _val = {};
	std::vector<std::string>& _listLoaner = _val;
	bool _init = true;
    bool& _available;
public:
	Book(std::string title,Author& author, Language language,Kind kind,Date publication,std::string ISBN);
	std::string whichLanguage(Language l);
	std::string whatKind(Kind k);
	Date getDate();
	std::string getTitle() const;
	std::string getISBN() const;
	Language getLanguage() const;
	Kind getKind() const;
    Author& getAuthor() const;
	void displayLoaner();
	friend std::vector<std::string>& getListLoaner(Book& b);
	friend void addLoaner(Book& b, Reader& r);
	friend std::ostream& operator<<(std::ostream& os, Book& b);
	bool& getAvailable();
	void setAvailable(bool i);
	bool operator==(const Book& b) const;
};
