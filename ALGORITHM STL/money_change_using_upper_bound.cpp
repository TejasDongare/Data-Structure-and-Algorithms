#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    int change[]={1,2,5,10,20,50,100,200,500,1000,2000};
    int money;
    cin>>money;
    int copy=money;
    int *ptr=upper_bound(change,(sizeof(change)/sizeof(int)+change),money);
    int index=ptr-change-1;
    int sum=change[index];
    cout<<change[index]<<" ";
    for(int i=index-1;i>=0;i--)
    {
        if(sum==copy)
        {
            break;
        }
        else
        {
            if(sum+change[i]<=copy)
            {
                cout<<change[i]<<" ";
                sum=sum+change[i];
            }
        }
    }
}
