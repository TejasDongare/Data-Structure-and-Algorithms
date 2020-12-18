//Number of set bits
#include <iostream>
int find_set_bits(int number)
{
    int mask=1,count=0;
    while(number>0){
        if(number&mask)
        {
            count++;
        }
        number=number>>1;
    }
    return count;
}
using namespace std;
int main() {
    int number;
    cin>>number;
    cout<<find_set_bits(number);
}
