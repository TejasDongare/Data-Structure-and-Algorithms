#include <iostream>
using namespace std;
int main() 
{
    int a[1000][1000]={0};
    cout<<"Enter the size of the Matrix"<<endl;
    int row,column;
    cin>>row>>column;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cin>>a[i][j];
        }
        cout<<endl;
    }
    cout<<"Following is the matrix"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Wave Pattern Matrix"<<endl;
    for(int i=0;i<row;i++)
    {
        int col=column-1;
        for(int j=0;j<column;j++)
        {
            if(i%2==0)
            {
                //top down
                cout<<a[j][i]<<" ";
            }
            else
            {
                //bottom Up
                cout<<a[col--][i]<<" ";
            }
        }
    }
    cout<<endl;
    //OR
   for(int col1=0;col1<row;col1++)
    {
        //cout<<"col1="<<col1<<endl;
        if(col1%2==0)
        {
            for(int row1=0;row1<column;row1++)
            {
                //top bottom
                cout<<a[row1][col1]<<" ";
            }
        }
        else
        {
            for(int row1=column-1;row1>=0;row1--)
            {
                //bottom up
                cout<<a[row1][col1]<<" ";
            }
        }
    }
}
