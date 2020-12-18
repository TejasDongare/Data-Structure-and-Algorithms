#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int row,column,a[50][50],cum_sum[50][50];
    cin>>row>>column;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cin>>a[i][j];
        }
    }
    //prefix sum
    //column wise addition
    for(int i=row-1;i>=0;i--)
    {
        for(int j=column-2;j>=0;j--)
        {
            cum_sum[i][j]=a[i][j]+cum_sum[i][j+1];
        }
    }
    //row wise addition
    for(int j=column-1;j>=0;j--)
    {
        for(int i=row-2;i>=0;i--)
        {
            a[i][j]=a[i+1][j]+a[i][j];
        }
    }
    cout<<"Following is prefix matrix"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<cum_sum[i][j]<<" ";
        }
        cout<<endl;
    }
    int sum=INT_MIN;
    int start_x,start_y;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(cum_sum[i][j]>sum)
            {
                sum=cum_sum[i][j];
                start_x=i;
                start_y=j;
            }
        }
    }
    cout<<"Maximum submatrix"<<endl;
    for(int i=start_x;i<row;i++)
    {
        for(int j=start_y;j<column;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Maximum sum="<<sum<<endl;
}