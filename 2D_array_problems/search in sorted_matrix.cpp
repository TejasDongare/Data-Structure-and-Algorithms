#include<iostream>
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
    int key;
    cin>>key;
    int i=row-1;
    int j=column-1;
    while(a[i][j]!=key)
    {
        if(a[i][j]>key)
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    cout<<"Key found at index="<<i<<","<<j;
    
    
}
