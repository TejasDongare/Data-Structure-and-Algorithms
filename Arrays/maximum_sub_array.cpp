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
        for(int j=i;j<size;j++)
        {
            current_sum=0;
            for(int k=i;k<=j;k++)
            {
                //cout<<a[k];
                //cout<<"Max sum="<<current_sum<<"+"<<a[k]<<endl;
                current_sum=current_sum+a[k];
                if(max_sum<current_sum)
                {
                    max_sum=current_sum;
                    //cout<<"Max sum="<<max_sum<<endl;
                    start=i;
                    end=j;//end=j or end=k both are right
                }
            }
            
            //cout<<", ";
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
