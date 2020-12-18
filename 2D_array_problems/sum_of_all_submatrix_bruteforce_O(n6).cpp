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
    int sum=0;
    for(int li=0;li<row;li++)
    {
        for(int lj=0;lj<column;lj++)
        {
            for(int bi=li;bi<row;bi++)
            {
                for(int bj=lj;bj<column;bj++)
                {
                    for(int i=li;i<=bi;i++)
                    {
                        for(int j=lj;j<=bj;j++)
                        {
                            sum=sum+a[i][j];
                        }
                    }
                }
            }
        }
    }
    cout<<sum<<endl;
}
