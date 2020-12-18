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
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Updated matrix"<<endl;
    int temp=1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            a[i][j]=temp++;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
