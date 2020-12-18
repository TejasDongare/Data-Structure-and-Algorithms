#include <iostream>
#include<algorithm>
using namespace std;
bool comparator(int a,int b)
{
    return a<=b;
}
int main() {
    int change[]={1,2,5,10,20,50,100,200,500,1000,2000};
    cout<<"Enter the amount to find change which is less than than or equal to 3888"<<endl;
    int money;
    cin>>money;
    int size=(sizeof(change))/sizeof(int);
    while(money>0)
    {
        int *ptr=lower_bound(change,change+size,money,comparator);
        money=money-change[ptr-change-1];
        cout<<change[ptr-change-1]<<" ";
    }
}
