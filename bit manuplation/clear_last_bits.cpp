#include <iostream>
using namespace std;
//clear range of bits
void clearlastbits(int &number,int bits)
{
    int  mask=(~0)<<(bits+1);//~0=1 1 1 1 or take -1=1 1 1 1  1
   // cout<<"Mask="<<mask<<endl;
    number=number&mask;
}
int main() {
    int number,bits;
    cin>>number>>bits;
    clearlastbits(number,bits);
    cout<<number;
}
