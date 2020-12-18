#include <iostream>
using namespace std;
//Given a sorted array find the pair such that it is equal to key
int main() {
    int array_size,a[50];
    cout<<"ENter the Number of elements in array"<<endl;
    cin>>array_size;
    cout<<"ENter the value of key"<<endl;
    int key;
    cin>>key;
    for(int i=0;i<array_size;i++)
    {
        cin>>a[i];
    }
    int i=0;
    int j=array_size-1;
    int temp=key-a[j];
    while(i<j)
    {
        if(a[i]<temp)
        {
            i++;
        }
        else if(a[i]==temp)
        {
            cout<<a[i]<<"+"<<a[j]<<"="<<key<<endl;
            i++;
            j--;
            temp=key-a[j];
        }
        else
        {
            j--;
            temp=key-a[j];
        }
      }
}
