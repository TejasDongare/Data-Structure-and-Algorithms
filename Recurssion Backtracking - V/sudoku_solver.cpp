#include <iostream>
#include<cmath>
using namespace std;
bool is_possible(int mat[][10],int i,int j,int n,int t)
{
    for(int temp=0;temp<n;temp++)
    {
        if(mat[temp][j]==t)
        {
            return false;
        }
    }
    for(int temp=0;temp<n;temp++)
    {
        if(mat[i][temp]==t)
        {
            return false;
        }
    }
    int sqrtn=sqrt(n);
    int x=(i/sqrtn)*sqrtn;
    int y=(j/sqrtn)*sqrtn;
    for(int tt=x;tt<x+sqrtn;tt++)
    {
        for(int ty=y;ty<y+sqrtn;ty++)
        {
            if(mat[tt][ty]==t)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudoku_solver(int mat[][10],int i,int j,int n)
{
    if(i==n)
    {
        for(int ttt=0;ttt<n;ttt++)
        {
            for(int yyy=0;yyy<n;yyy++)
            {
                cout<<mat[ttt][yyy]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //if j==column goto next line
    if(j==n)
    {
        return sudoku_solver(mat,i+1,0,n);
    }
    if(mat[i][j]!=0)
    {
        return sudoku_solver(mat,i,j+1,n);
    }
    //recursive case
    for(int t=1;t<=n;t++)
    {
        if(is_possible(mat,i,j,n,t)) 
        {
            mat[i][j]=t;
            if(sudoku_solver(mat,i,j+1,n))
            {
                return true;
            }
        }
    }
    //Backtracking
    mat[i][j]=0;
    return false;
}
int main() {
    int mat[10][10]= { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };
         bool ans=sudoku_solver(mat,0,0,9);
         if(ans);
         {
             cout<<"not possible";
         }
}
