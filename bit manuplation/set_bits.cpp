#include <iostream>
using namespace std;
int setbit(int number,int bit)
{
    int mask=1<<bit;
    //cout<<mask<<" ";
    return number|mask;
}
int main() {
    int number,bit;
    cin>>number>>bit;
    cout<<setbit(number,bit);
}
