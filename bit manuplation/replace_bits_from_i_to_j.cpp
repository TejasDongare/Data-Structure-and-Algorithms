#include <iostream>
void replace_bits(int &number,int j,int i,int rep)
{
    int mask=rep<<i;
    number=number|mask;

}
void clearbAits(int &number,int j,int i)
{
    int m1=(~0)<<(j+1);
    int m2=(1<<i)-1;
    int mask=m1|m2;
    number=number&mask;
}
using namespace std;
int main() {
   int number,j,i,rep;
   cin>>number>>j>>i>>rep;
    clearbits(number,j,i);
    replace_bits(number,j,i,rep);
    cout<<number;
}
