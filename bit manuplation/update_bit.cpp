#include <iostream>
/*int update_bit(int number,int bit,int change)
{
    if(change==1)
    {
        int mask=1<<bit;
        return number|mask;
    }
    else
    {
        int mask=~(1<<bit);
        return number&mask;
    }
}*/


//OR
void clearbit(int &number,int bit)
{
    int mask=~(1<<bit);
    number=number&mask;
}
void update_bit(int &number,int bit,int change)
{
    int mask=change<<bit;
    number=number|mask;
}
using namespace std;
int main() {
    int number,bit,change;
    cin>>number>>bit>>change;
   // cout<<update_bit(number,bit,change);
   clearbit(number,bit);
   update_bit(number,bit,change);
   cout<<number;
}
