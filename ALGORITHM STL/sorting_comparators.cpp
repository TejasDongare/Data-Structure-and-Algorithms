#include <iostream>
#include<algorithm>
using namespace std;
bool comparator(int a,int b)
{
    return a>b;
}
int main() {
    int arr[1000],size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+size);
    cout<<"Sorted array in ascending order"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr,arr+size,comparator);
    cout<<"Sorted array in descending order with comparator"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
