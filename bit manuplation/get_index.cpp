#include <iostream>
using namespace std;
//get bit by ith index
bool getbit(int number,int bit)
{
    return (number&(1<<bit))>0;
}
int main() {
    int number,bit;
    cin>>number>>bit;
    (getbit(number,bit))?cout<<"1":cout<<"0";
}
