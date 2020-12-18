#include <iostream>
using namespace std;
int last_occurence(int *ptr,int size,int key)
{
    if(size<0)
    {
        return -1;
    }
    else if(ptr[size]==key)
    {
        return size;
    }
    return last_occurence(ptr,size-1,key);
}
int main() {
    int size,a[1000];
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<last_occurence(a,size-1,key)<<endl;
}
