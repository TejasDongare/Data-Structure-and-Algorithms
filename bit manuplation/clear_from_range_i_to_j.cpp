#include <iostream>
using namespace std;
void clearRangeofbits(int &number,int j,int i)
{
    int mask=(~0)<<(j+1);
    int m=(1<<i)-1;
    int final_mask=mask|m;
    number=number&final_mask;
}
int main() {
    int number,i,j;
    cin>>number>>j>>i;
    clearRangeofbits(number,j,i);
    cout<<number;
}
