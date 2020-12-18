#include <iostream>
using namespace std;
void twozerofoureight(int number)
{
    char words[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    if(number==0)
    {
        return;
    }
    int rem=number%10;
    twozerofoureight(number/10);
    cout<<words[rem]<<" ";
}
int main() {
    int n;
    cin>>n;
    twozerofoureight(n);
}
