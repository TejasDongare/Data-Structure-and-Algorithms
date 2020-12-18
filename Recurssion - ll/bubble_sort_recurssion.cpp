#include <iostream>
using namespace std;
//partially recurssion + iteration
void bubble_sort(int *a,int n)
{
    if(n==1)
    {
        return;
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            swap(a[i],a[i+1]);
        }
    }
    bubble_sort(a,n-1);
}

//complete recurssiom
void bubble_sort1(int a[],int n,int i)
{   
    if(n==1)
    {
        return;
    }
    if(i+1==n)
    {
        return bubble_sort1(a,n-1,0);
    }
    if(a[i]>a[i+1])
    {
        swap(a[i],a[i+1]);
    }
    bubble_sort1(a,n,i+1);
}

int main() {
    int a[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubble_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    bubble_sort1(a,n,0);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
