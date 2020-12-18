#include <iostream>
#include<algorithm>
using namespace std;
int main() 
{
    int a[100],size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    int key;
    cout<<"ENter the elements to be searched"<<endl;
    cin>>key;
    //this returns the address
    auto it=find(a,a+size,key);
    cout<<"IT="<<it<<endl;
    int index=it-a;//hexa decimal substractions gives the number of buckets between them
    if(index==size)
    {
        cout<<"element not found"<<endl;
    }
    else
    { 
        cout<<"Element find at index="<<it<<"-"<<a<<"="<<index;
    }
}
