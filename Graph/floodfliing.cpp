#include<iostream>
using namespace std;
//here ch is the element to be replaced and i and j is the position where the color iniitiates
void floodfilling(char mat[][50],int i,int j,char ch,int r,int c)
{
    //Base Case Matrix Bound
    if(i<0 or j<0 or i>=r or j>=c)
    {
        return;
    }
    //figure boundary condition
    if(mat[i][j]!=ch)
    {
        return;
    }
    floodfilling(mat,i-1,j,ch,r,c);
    floodfilling(mat,i,j-1,ch,r,c);
    floodfilling(mat,i+1,j,ch,r,c);
    floodfilling(mat,i,j+1,ch,r,c);
    return;
}
int main()
{
    
}