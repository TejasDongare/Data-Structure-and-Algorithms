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
    int start_x,start_y,end_x,end_y;
    cout<<"ENter the start of submatrix";
    cin>>start_x>>start_y;
    cout<<"Enter the end of the submatrix";
    cin>>end_x>>end_y;
    for(int i=start_x;i<=end_y;i++)
    {
        for(int j=start_y;j<=end_y;j++)
        {
            sum=a[i][j]*((j-start_y+1)*(i-start_x+1)*(column-j-(column-end_y)+1)*(row-i-(row-end_x)+1))+sum;
        }
    }
    cout<<"SUM="<<sum<<endl;
}
