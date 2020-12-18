#include <iostream>
#include<vector>
#include<climits>
using namespace std;
void floyd_warshall(vector<vector<int>> &v)
{   
    for(int k=0;k<v.size();k++)
    {
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v.size();j++)
            {
                if(v[i][j]>v[i][k]+v[k][j] and v[i][k]!=INT_MAX and v[k][j]!=INT_MAX)
                {
                    v[i][j]=v[i][k]+v[k][j];
                }
            }
        }
    }
    return;
}
int main() 
{
    vector<vector<int>> v={{0,INT_MAX,-2,INT_MAX},
                            {4,0,3,INT_MAX},
                            {INT_MAX,INT_MAX,0,2},
                            {INT_MAX,-1,INT_MAX,0}};
    floyd_warshall(v);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}