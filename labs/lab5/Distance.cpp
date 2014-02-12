#include <iostream>
#include <cmath>

using namespace std;

#include "Distance.h"


/// PUBLIC ///

Distance::Distance() : feet(0), inches(0) {};

Distance::Distance(unsigned ft, double inch) : feet(ft), inches(inch)
{
    init();
}

Distance::Distance(double inch) : feet(0), inches(inch)
{
    init();
}

double Distance::convertToInches() const
{
    return inches + (feet * 12);
}

const Distance Distance::operator+(const Distance &x) const
{
    Distance temp;
    temp.inches = inches + x.inches;
    temp.feet = feet + x.feet;
    temp.init();
    return temp;
}

const Distance Distance::operator-(const Distance &x) const
{
    Distance temp;
    if(feet >= x.feet)
        temp.inches = abs(convertToInches() - x.convertToInches());
    else
        temp.inches = abs(x.convertToInches() - convertToInches());
    temp.init();
    return temp;
}

//todo
void Distance::display() const
{
    cout << feet << "\' " << inches << '\"' << endl;
}


/// PRIVATE ///
void Distance::init()
{
    while(inches >= 12)
    {
        inches -= 12;
        feet++;
    }
}