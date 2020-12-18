#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    cout<<"Array should be sorted "<<endl;
    int a[7]={0,1,2,30,30,60,70};
    bool present=binary_search(a,a+7,30);
    cout<<"Following is array"<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<" ";
    }
    if(present)
    {
        int *lower_bound1=lower_bound(a,a+7,30);
        cout<<endl<<"lower bound="<<lower_bound1-a<<endl;
        int *upper_bound1=upper_bound(a,a+7,30);
        cout<<"Upper_boun="<<upper_bound1-a<<endl;//ipper bound returns one index extra than the index
        cout<<"Total count of 30="<<upper_bound1-lower_bound1<<endl;
    }
    else
    {
        cout<<"Element not present"<<endl;  
    }
}
