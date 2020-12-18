#include <iostream>
using namespace std;
bool is_sorted(int *a,int n)
{
   if(n==0 or n==1)
   {
       return true;
   }
   if(a[0]<=a[1] and is_sorted(a+1,n-1))
   {
       return true;
   }
   return false;
}
int main()
{
    int size;
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    if(is_sorted(a,size))
    {
        cout<<"Sorted";
    }
    else
    {
        cout<<"Not sorted";
    }
}
