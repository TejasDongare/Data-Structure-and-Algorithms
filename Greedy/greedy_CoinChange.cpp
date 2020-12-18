#include <iostream>
#include<algorithm>
using namespace std;
int make_change(int *arr,int size,int coin)
{
    int count=0;
    while(coin>0)
    {
        int index=upper_bound(arr,arr+size,coin)-arr;
        if(coin==arr[index])
        {
            count++;
            return count;
        }
        index--;
        coin=coin-arr[index];
        count++;
    }
    return count;
}
int main() 
{
    int arr[]={1,2,5,10,20,50,100,500};
    int size=sizeof(arr)/sizeof(int);
    int coin;
    cin>>coin;
    cout<<make_change(arr,size,coin)<<endl;
}