#include <iostream>
using namespace std;
int fibonacci(int number)
{
    if(number==0 or number==1)
    {
        return number;
    }
    int f=fibonacci(number-1)+fibonacci(number-2);
    return f;
}
int main() {
    int number;
    cin>>number;
    int x=fibonacci(number);
    cout<<x<<endl;
}
