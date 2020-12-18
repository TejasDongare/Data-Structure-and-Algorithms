#include <iostream>
//clear bit
int clearbit(int number,int bit)
{
    int mask=1<<bit;
    return number&(~mask);
}
using namespace std;
int main() {
    int number,bit;
    cin>>number>>bit;
    cout<<clearbit(number,bit);
}
