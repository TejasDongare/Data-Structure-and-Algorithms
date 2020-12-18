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

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            sum=a[i][j]*((i+1)*(j+1)*(row-i)*(row-j))+sum;
        }
    }
    cout<<"SUM="<<sum<<endl;
}
