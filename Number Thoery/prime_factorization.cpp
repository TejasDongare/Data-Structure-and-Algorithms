#include <iostream>
#include<math.h>
using namespace std;
int prime_factorization(int a[],int x,int temp[])
{
    int j=-1,i=2;
    int p=2;
    while(p<=sqrt(x))
    {
        if(x%p==0)
        {
            j=j+1;
            temp[j]=p;
            while(x%p==0)
            {
                x=x/p;
            }
        }
        i++;
        while(a[i]!=1)
        {
            i++;
        }
        p=i;
    }
    if(x!=1)
    {
        j++;
        temp[j]=x;
    }
    return j;
}
int main() {
    int a[1000000]={0};
    for(int i=3;i<1000000;i+=2)
    {
        a[i]=1;
    }
    for(int i=3;i<1000000;i+=2)
    {
        if(a[i])
        {
            for(int j=(2*i);j<1000000;j+=i)
            {
                a[j]=0;
            }
        }
    }
    a[0]=a[1]=0;
    a[2]=1;
    int x;
    cin>>x;
    int temp[100000];
    int index=prime_factorization(a,x,temp);

    for(int i=0;i<=index;i++)
    {
        cout<<temp[i]<<" ";
    }
}
