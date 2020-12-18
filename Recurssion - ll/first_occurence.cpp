#include <iostream>
using namespace std;
int first_occurence(int *ptr,int size,int key)
{
  //  cout<<"ptr[0]="<<ptr[0]<<" key="<<key<<endl;
    if(size==0)
    {
        return -1;
    }
    else if(ptr[0]==key)
    {
        return 0;
    }
    int i=first_occurence(ptr+1,size-1,key);
    if(i==-1)
    {
        return -1;
    }
    return i+1;
}

//different style
int first_occurence1(int *ptr,int size,int key,int i)
{
    if(i==size)
    {
        return -1;
    }
    else if(ptr[0]==key)
    {
        return i;
    }
    int x=first_occurence1(ptr+1,size,key,i+1);
    if(x==(~0))
    {
        return -1;
    }
    return x;
}
int main() {
    int size,a[1000],key;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cin>>key;
    int index=first_occurence(a,size,key);
    cout<<"Method - 1"<<endl;
    if(index==-1)
    {
        cout<<"Element Not found"<<endl;
    }
    else
    {
        cout<<"Element found at index="<<index<<endl;
    }
    int in=first_occurence1(a,size,key,0);
    cout<<endl<<"Method - 2"<<endl;
    if(in==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Element found at="<<in<<endl;
    }
}
