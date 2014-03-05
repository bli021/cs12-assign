int search( const vectoy<int>&v, int val, int i = 0)
{
    if(i > v.size() || v.size()==0)
        return -1;
    else if(v.at(i) == val)
        return i;
    else
        search(v, val, i+1);
}