#include <iostream>
#include<climits>
using namespace std;
int main()
{
    int cumlative_sum,max_sum,a[50];
    cout<<"Enter the number of elelemnts in array="<<endl;
    int array_size;
    cin>>array_size;
    for(int i=0;i<array_size;i++)
    {
        cin>>a[i];
    }
    cumlative_sum=a[0];
    max_sum=INT_MIN;
    for(int i=1;i<array_size;i++)
    {
        if(max_sum<cumlative_sum)
        {
            max_sum=cumlative_sum;
        }
        if(a[i]<0 and cumlative_sum<0)
        {
            cumlative_sum=a[i];
        }
        else if(cumlative_sum<0 and a[i]>=0)
        {
            cumlative_sum=a[i];
        }
        else
        {
            cumlative_sum=cumlative_sum+a[i];
        }
    }
    if(max_sum<cumlative_sum)
    {
        max_sum=cumlative_sum;
    }
    cout<<"Max sum="<<max_sum;
    
    return 0;
}
