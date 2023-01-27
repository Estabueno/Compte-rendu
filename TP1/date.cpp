#include "date.h"

Date::Date(int day, int month, int year)
:_day(day),_month(month),_year(year)
{
}

int Date::getDay() const{
    return _day;
}

int Date::getMonth() const{
    return _month;
}

int Date::getYear() const{
    return _year;
}

void Date::setDay(int day){
    _day = day;
}

void Date::setMonth(int month){
    _month = month;
}

void Date::setYear(int year){
    _year = year;
}

bool Date::isDate() {
    if ((_day < 1) || (_day>31)) 
        return false;
    if ((_month <1) || (_month>12)) 
        return false;
    if ((_month == 2) && (_day > 28)) 
        return false;
    if (((_month == 4) || (_month == 6) || (_month == 9) || (_month == 11)) && (_day > 30)) 
        return false;
    if((_year > 2022) || (_year < 0))
        return false; 
return true;
}

std::string toString(Date d)
{
    std::ostringstream buffer;
    if(d.isDate())
    {
        buffer << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
        return buffer.str();
    }
     else
    {
        buffer << "Date non conforme, veuillez resaisir les informations." << std::endl;
        return buffer.str();
    }
}

bool Date::operator==(const Date& d) const
{
    if((_day == d._day) && (_month == d._month) && (_year == d._year))
        return true;
    return false;
}