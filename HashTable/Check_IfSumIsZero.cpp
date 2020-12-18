#include <iostream>
#include<unordered_map>
using namespace std;
bool checksum(int *arr,int n)
{
    unordered_map<int,int> p;
    int pre=0;
    for(int i=0;i<n;i++)
    {
        pre+=arr[i];
        if(p.find(pre)!=p.end() or arr[i]==0)
        {
            return true;
        }
    }
return false;
}
int main() 
{
    int arr[]={1,2,3,-2,0,8};
    int size=sizeof(arr)/sizeof(int);
    if(checksum(arr,size))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
}
