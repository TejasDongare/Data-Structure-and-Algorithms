#include <iostream>

using namespace std;

int main()
{
    int a[50],size,current_sum,max_sum,start,end,prev_sum;
    cout<<"Enter the size of array=";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    max_sum=0;
    current_sum=0;
    
    for(int i=0;i<size;i++)
    {
        current_sum=0;
        for(int j=i;j<size;j++)
        {
            current_sum=current_sum+a[j];
            if(current_sum>max_sum)
            {
                max_sum=current_sum;
                start=i;
                end=j;
            }
            
        }
        cout<<endl;
    }
    cout<<"Max sum="<<max_sum<<endl;
    for(int i=start;i<=end;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
