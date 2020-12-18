#include<iostream>
bool even_odd(int number)
{
    return number&1;
}
using namespace std;
int main()
{
    //if number is even or odd
    int number;
    cin>>number;
    if(even_odd(number))
    {
        cout<<"Even"<<endl;
    }
    else
    {
        cout<<"ODD"<<endl;
    }
}