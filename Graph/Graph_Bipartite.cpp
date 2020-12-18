#include <iostream>
#include<vector>
using namespace std;
void addEdge(int u,int v,vector<vector<int>> &l)
{
    l[u].push_back(v);
    l[v].push_back(u);
}
//we can use dfs or bfs both
bool dfs_helper(int node,int *visited,int parent,int color,vector<vector<int>> &l)
{
    visited[node]=color;
    for(auto neighbour:l[node])
    {
        if(visited[neighbour]==0)
        {
            if(!dfs_helper(neighbour,visited,node,3-color,l))
            {
                return false;
            }
        }
        else if(visited[neighbour]==color and neighbour!=parent)
        {
            return false;
        }
    }
    return true;
}
bool dfs(vector<vector<int>> &l,int v)
{
    int visited[v]={0};//if visited=0 than not visited and if visited=1 than color 1 and if visited=2 than color 2
    int color=1;
    return dfs_helper(0,visited,0,1,l);
}

int main()
{
    int n=5;
    vector<vector<int>> l(n);
    addEdge(0,1,l);
    addEdge(1,2,l);
    addEdge(0,3,l);
    //addEdge(2,4,l);
    addEdge(4,3,l);
    if(dfs(l,v))
    {
        cout<<"Bipartite"<<endl;
    }
    else
    {
        cout<<"Not Bipartite"<<endl;
    }
}
