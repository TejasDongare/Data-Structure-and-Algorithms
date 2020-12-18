#include <iostream>
#include<list>
using namespace std;
class graph
{
    list<int> *l;
    int v;
public:
    graph(int v)
    {
        this->v=v;
        l=new list<int> [v];
    }
    void addEdge(int a,int b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }
    //cycle detection for undirected graph using dfs
    bool cycle_helper(int node,bool *visited,int parent)
    {
        visited[node]=true;
        for(int temp:l[node])
        {
            if(!visited[temp])
            {
                if(cycle_helper(temp,visited,node))
                {
                    return true;
                }
            }
            else if(parent!=temp)
            {
                return true;
            }
        }
        return false;
    }
    bool undirected_graph_cycle_detection_DFS()
    {
        bool *visited=new bool[v];
        int parent=-1;
        for(int i=0;i<v;i++)
        {
            visited[i]=0;
        }
        return cycle_helper(0,visited,-1);
    }
};
int main() 
{
    graph g(3);
    g.addEdge(0,1);
    g.addEdge(0,2);
    //g.addEdge(2,1);
    if(g.undirected_graph_cycle_detection_DFS())
    {
        cout<<"Cycle is Present"<<endl;
    }
    else
    {
        cout<<"Cycle is not present"<<endl;
    }
}