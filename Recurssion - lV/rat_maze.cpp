#include<iostream>
using namespace std;
bool rat_maze(char *maze,int r ,int c,int row,int column,int *solution)
{
	if(row==r and column==c)
	{
		//print solution 
		return true;
	}
	if(maze[row][column]=='x')
	{
		return false;
	}
	solution[row][column]=1;
	rat_maze(maze,r,c,row,column+1,solution);
	rat_maze(maze,r,c,row+1,column,solution);
	solution[row][column]={0};
}
int main()
{
	char maze[][10]={"0000","000x","0000","x000"};
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
	rat_maze(maze,r-1,c-1,0,0,solution);
	
}