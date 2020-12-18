#include <iostream>
using namespace std;
int find_set_bit(int number)
{
    int count=0;
    while(number>0)
    {
        int x=number&1;
        if(x)
        {
            return count;
        }
        count++;
        number=number>>1;
    }
    return 0;
}
int main() 
{
    int sum,a[1000],temp,size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    temp=a[0];
    sum=a[0];
    for(int i=1;i<size;i++)
    {
        temp=temp^a[i];
    }
   // cout<<"Temp="<<temp<<endl;
    int s;
    int set_bit=find_set_bit(temp);
    //cout<<"Set_bit="<<set_bit<<endl;
    int arr[1000];
    s=-1;
    for(int i=0;i<size;i++)
    {
      //  cout<<"(a[i])="<<a[i]<<" a[i]>>set_bit "<<(a[i]>>set_bit)<<" ((a[i]>>set_bit)&1) "<<((a[i]>>set_bit)&1)<<endl;
        if((a[i]>>set_bit)&1)
        {
            s++;
            arr[s]=a[i];
            //cout<<a[i]<<" ";
        }
    }
//cout<<endl;
//cout<<"S="<<s<<endl;
    int x=arr[0];
    for(int i=1;i<=s;i++)
    {
        x=arr[i]^x;
       
    }
    int v1=x;
    int v2=temp^x;
    cout<<v1<<endl;
    cout<<v2<<endl;
    
}
