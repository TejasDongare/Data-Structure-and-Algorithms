#include <iostream>
using namespace std;
int binary_decimal(int number)
{
    int count=1,power=1,ans=0;
    while(number>0)
    {
      //  cout<<"ans="<<ans<<" Number="<<number<<endl;
        int last_digit=number%10;
        ans+=(power*last_digit);
        power=power<<1;
        number=number/10;
        
    }
    return ans;
}
int main()
{
    int a[10000],size,arr[64],j=63;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    int count=0;
    while(count<64)
    {
        int temp=0;
        for(int i=0;i<size;i++)
        {
            int x=(a[i]&1);
            if(x)
            {
                temp=temp+x;
            }
            a[i]=a[i]>>1;
        }
        arr[j]=temp;
        j--;
        count++;
    }
   
    int ans=0;
    for(int i=j+1;i<64;i++)
    {
        ans=((ans)*10)+(arr[i]%3);
    }
    cout<<binary_decimal(ans);
    
    /*
    int ans=0,power=10;
    for(int i=j+1;i<64;i--)
    {
        a
    }
    cout<<ans<<endl;*/
}
