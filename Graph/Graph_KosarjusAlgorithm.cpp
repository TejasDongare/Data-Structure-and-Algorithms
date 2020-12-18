#include <iostream>
#include<string.h>
#include<vector>
using namespace std;
void dfs(vector<int> g[],int i,bool *visited,vector<int> &stack)
{
    visited[i]=1;
    for(auto x:g[i])
    {
        if(!visited[x])
        {
            dfs(g,x,visited,stack);
        }
    }
    stack.push_back(i);
    return;
}
void dfs1(vector<int> g[],int i,bool *visited)
{
    visited[i]=1;
    for(auto x:g[i])
    {
        if(!visited[x])
        {
            dfs1(g,x,visited);
        }
    }
    cout<<i<<" ";
    return;
}
void kosarjus(vector<int> g[],vector<int> r[],int N)
{
    bool visited[N]={0};
    memset(visited,0,N);
    //Step 1:-create ordering
    vector<int> stack;
    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            dfs(g,i,visited,stack);
        }
    }
    
    //Step 2 :- reversing already done
    
    //Step 3 :-travers and find the component
    for(int i=0;i<N;i++)
    {
        visited[i]=0;
    }
    char component_name='A';
    for(int i=stack.size()-1;i>=0;i--)
    {
        if(visited[stack[i]]==0)
        {
            cout<<"Component "<<component_name<<" --> ";
            dfs1(r,stack[i],visited);
            cout<<endl;
            component_name++;
        }
    }
}
int main() 
{
    int Vertex;
    cin>>Vertex;
    vector<int> graph[Vertex];
    //reverse graph
    vector<int> rev_graph[Vertex];
    int edges;
    cin>>edges;
    while(edges--)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }
    kosarjus(graph,rev_graph,Vertex);
}