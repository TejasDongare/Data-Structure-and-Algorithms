#include <iostream>
using namespace std;
int main()
{
    int row,column,a[50][50];
    cin>>row>>column;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cin>>a[i][j];
        }
    }
    int cum_sum[50][50];
    cum_sum[0][0]=a[0][0];
    int j=1;
    int sum=a[0][0];
    sum=0;
    //column wise addition
    for(int i=0;i<row;i++)
    {
        for(int j=1;j<column;j++)
        {
            a[i][j]=a[i][j]+a[i][j-1];
        }
    }
    //row wise addition
    for(int j=0;j<column;j++)
    {
        for(int i=1;i<row;i++)
        {
            a[i][j]=a[i-1][j]+a[i][j];
        }
    }
    cout<<"Cumlative sum"<<endl;
    for(int i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    sum=0;
    
    for(int li=0;li<row;li++)
    {
        for(int lj=0;lj<column;lj++)
        {
            for(int i=li;i<row;i++)
            {
                for(int j=lj;j<column;j++)
                {
                    if(li!=0 and lj!=0)
                    {
                        sum=sum+cum_sum[i][j]-cum_sum[i][lj-1]-cum_sum[li-1][j]+cum_sum[li-1][lj-1];
                    }
                    else if(li==i and lj==j)
                    {
                        sum=sum+a[i][j];
                    }
                    else if(li==0)
                    {
                       sum=sum+cum_sum[i][j]-cum_sum[i][lj-1];
                    }
                    else
                    {
                        sum=sum+cum_sum[i][j]-cum_sum[li-1][j];
                    }
                    
                   // cout<<"start="<<li<<","<<lj<<" end="<<i<<","<<j<<" Sum="<<sum<<endl;
                }
            }
        }
    }
    cout<<sum<<endl;
}
