#include<iostream>
using namespace std;
bool rat_maze(char maze[][10],int r ,int c,int row,int column,int solution[][10])
{
	if(row==r and column==c)
	{
        //solution[row][column]=1;
		for(int i=0;i<=row;i++)
        {
            for(int j=0;j<=column;j++)
            {
                if(solution[i][j])
                {
                    cout<<i<<j<<"->";
                }
            }
        }
        cout<<endl;
		return true;
	}
    if(row>r or column>c)
    {
        return false;
    }
	if(maze[row][column]=='x')
	{
		return false;
	}
	solution[row][column]=1;
	int right_success=rat_maze(maze,r,c,row,column+1,solution);
	int left_succes=rat_maze(maze,r,c,row+1,column,solution);
	solution[row][column]=0;
    if(right_success==true or left_succes==true)
    {
        return true;
    }
    return false;
}
int main()
{
	char maze[][10]={"0000","00x0","000x","0x00"};
	int r,c;
	r=4;
	c=4;
	int solution[10][10];
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
		 solution[i][j]=0;
		}
	}
	if(rat_maze(maze,r-1,c-1,0,0,solution)==false)
    {
        cout<<"Path Doesnt exist"<<endl;
    }
	
}