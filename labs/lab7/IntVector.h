#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_

class IntVector
{
    private:
        unsigned sz;
        unsigned cap;
        int* data;

    public:
        IntVector();//:sz(0),cap(0){delete data;}
        IntVector(unsigned size);
        IntVector(unsigned size, int value);
        unsigned size() const{return sz;};
        unsigned capacity() const{return cap;};
        bool empty() const{return !sz;};
        const int & at( unsigned index ) const;
};

#endif //INTVECTOR