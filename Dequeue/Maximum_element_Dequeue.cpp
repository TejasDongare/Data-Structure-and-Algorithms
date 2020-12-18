#include <iostream>
#include<deque>
using namespace std;
int main() 
{
    int size,k;
    cin>>size>>k;
    int a[size];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    int i=0;
    deque<int> Q;
    for(;i<k;i++)
    {
        while(!Q.empty() and a[i]>a[Q.back()])
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    for(;i<size;i++)
    {
        cout<<a[Q.front()]<<" ";
        //Remove the elements not a part of the window
        while(!Q.empty() and Q.front()<=i-k)
        {
            Q.pop_front();
        }
        //Remove the elements which are not useful and are in window
        while(!Q.empty() and a[i]>a[Q.back()])
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    cout<<a[Q.front()]<<endl;
}
