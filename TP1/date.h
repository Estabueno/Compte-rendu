#pragma once
#include <iostream>
#include <sstream>

class Date{
private:
    int _day;
    int _month;
    int _year;
public:
    Date(int day, int month, int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    bool isDate();
    bool operator==(const Date& d) const;
};

std::string toString(Date d);
