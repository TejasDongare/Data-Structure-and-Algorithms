#include <iostream>
using namespace std;
int count_set_bitss(int number)
{
    int count=0;
    while(number>0)
    {
        number&=(number-1);
        count++;
    }
    return count;
}
int count_set_bits(int number)
{
    int count=0,mask=1;
    while(number>0)
    {
        if(number&mask)
        {
            count++;
        }
        number=number>>1;
    }
    return count;
}
int main() {
    int number;
    cin>>number;
    //method-1
    cout<<count_set_bits(number)<<endl;
    //method-2
    //method-3
    cout<<count_set_bitss(number)<<endl;
    cout<<__builtin_popcount(number)<<endl;
}
