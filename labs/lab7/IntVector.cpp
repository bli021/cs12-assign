
#include "IntVector.h"
#include <cstdlib>

IntVector::IntVector()
:sz(0),cap(0)
{

}
IntVector::IntVector(unsigned size):sz(size),cap(size)
{
    data = new int[size];
    for(unsigned i=0; i < size; i++)
        data[i] = 0;

}

IntVector::IntVector(unsigned size, int value):sz(size),cap(size)
{
    data = new int[size];
    for(unsigned i=0; i < size; i++)
        data[i] = value;
}

const int & IntVector::at( unsigned index ) const
{
    if(index < sz)
        return data[index];
    else
        exit(1);
}