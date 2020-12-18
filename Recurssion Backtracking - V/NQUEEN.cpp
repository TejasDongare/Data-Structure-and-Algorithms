#include <iostream>
using namespace std;
bool CheckToPlaceAQueen(int grid[][10],int i,int j,int n)
{
    //check for column
    for(int k=0;k<i;k++)
    {
        if(grid[k][j])
        {
            return false;
        }
    }
    //left diagonal
    int start_row=i;
    int start_column=j;
     while(start_row>=0 and start_column>=0)
     {
         if(grid[start_row][start_column])
         {
             return false;
         }
         start_row--;
         start_column--;
     }

     //right Diagonal
    start_row=i;
    start_column=j;
    while(start_column<n and start_row>=0)
    {
        if(grid[start_row][start_column])
        {
            return false;
        }
        start_row--;
        start_column++;
    }
    return true;
}
bool NQUEEN(int grid[][10],int i,int n)
{
    if(i==n)
    {
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                if(grid[r][c])
                {
                    cout<<"Q"<<" ";
                }
                else
                {
                    cout<<"_"<<" ";
                }
            }
            cout<<endl;
        }
        return true;
    }
    for(int j=0;j<n;j++)
    {
        if(CheckToPlaceAQueen(grid,i,j,n))
        {
            grid[i][j]=1;
            if(NQUEEN(grid,i+1,n))
            {
                return true;
            }
            grid[i][j]=0;
        }
    }
    return false;
}
int main() {
    int n;
    cin>>n;
    int grid[10][10]={0};
    if(NQUEEN(grid,0,n)!=1)
    {
        cout<<"Placing queen is not possible"<<endl;
    }
}
