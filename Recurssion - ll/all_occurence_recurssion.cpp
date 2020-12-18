#include <iostream>
using namespace std;
void all_occurence(int *ptr,int size,int key,int index)
{
    if(ptr[0]==key)
    {
        cout<<index<<" ";
    }
    else if(size==0)
    {
        return ;
    }
    all_occurence(ptr+1,size-1,key,index+1);
}
//FInd The occurence and store it in array;
int creat_array_of_all_occurence(int *ptr,int size,int key,int *output,int in,int index)
{
    if(ptr[0]==key)
    {
        output[in]=index;
        in++;
    }
    else if(size==0)
    {
        return in;
    }
    return creat_array_of_all_occurence(ptr+1,size-1,key,output,in,index+1);
}
int main() 
{
    int size,key;
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cin>>key;
    int output[size];
    cout<<"Method - 1"<<endl;
    all_occurence(a,size,key,0);
    int index = creat_array_of_all_occurence(a,size,key,output,0,0);
    cout<<endl<<"Method - 2"<<endl;
    for(int i=0;i<index;i++)
    {
        cout<<output[i]<<" ";
    }
}
