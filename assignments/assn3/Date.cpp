#include <string>
#include <iostream>

using namespace std;

#include "Date.h"


/// PUBLIC ///

Date::Date() : day(1), month(1), MonthName("January"), year(2000) {};

Date::Date(unsigned m, unsigned d, unsigned y )
{
    if ((m <= 12) && (m >= 1))
        month = m;
    else
        month = 1;
    if (d <= daysPerMonth(m, y))
        day = d;
    else
        day = 1;
    MonthName = name(m);
    year = y;
};

Date::Date(const string &mn, unsigned d, unsigned y )
{
    month = number(mn);
    MonthName = name(month);
    if (d <= daysPerMonth(month, y))
        day = d;
    else
        day = 1;
    year = y;
};

void Date::printNumeric() const
{
    cout << month << '/' << day << '/' << year;
}

void Date::printAlpha() const
{
    cout << MonthName << ' ' << day << ", " << year;
}


/// PRIVATE ///
bool Date::isLeap( unsigned year) const
{
    return ( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

unsigned Date::daysPerMonth( unsigned m, unsigned y ) const
{
    switch(m)
    {
        case 1: //january
            return 31;
            break;
        case 2: //febuary
            if(isLeap(y))
                return 29;
            else
                return 28;
            break;
        case 3: //march
            return 31;
            break;
        case 4: //april
            return 30;
            break;
        case 5: //may
            return 31;
            break;
        case 6: //june
            return 30;
            break;
        case 7: //july
            return 31;
            break;
        case 8: //august
            return 31;
            break;
        case 9: //september
            return 30;
            break;
        case 10: //october
            return 31;
            break;
        case 11: //november
            return 30;
            break;
        case 12: //december
            return 31;
            break;
    }
    return 1;
}

string Date::name(unsigned m ) const
{
    switch(m)
    {
        case 1:
            return "January";
            break;
        case 2:
            return "February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "October";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
            break;
    }
    return "January";
}

unsigned Date::number(const string &month )
{
    if (month == "January")
        return 1;
    else if (month == "February")
        return 2;
    else if (month == "March")
        return 3;
    else if (month == "April")
        return 4;
    else if (month == "May")
        return 5;
    else if (month == "June")
        return 6;
    else if (month == "July")
        return 7;
    else if (month == "August")
        return 8;
    else if (month == "September")
        return 9;
    else if (month == "October")
        return 10;
    else if (month == "November")
        return 11;
    else if (month == "December")
        return 12;
    else
        return 1;
}

