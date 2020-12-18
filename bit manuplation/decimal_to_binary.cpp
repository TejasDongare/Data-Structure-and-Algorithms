#include <iostream>
using namespace std;
int decimal_to_binary(int number)
{
    int ans=0,power=1;
    while(number>0)
    {
        int last_digit=number&1;
        ans=(last_digit*power)+ans;
        number= number>>1;
        power*=10;
    }
    return ans;
}
int main() {
    int number;
    cin>>number;
    cout<<decimal_to_binary(number)<<endl;
}
