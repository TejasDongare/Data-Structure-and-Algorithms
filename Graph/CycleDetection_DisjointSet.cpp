#include <iostream>
#include<list>
using namespace std;
class Graph
{
    list<pair<int,int>> l;
    int v;
public:
    Graph(int v)
    {
        this->v=v;
    }
    void addEdge(int u,int v)
    {
        l.push_back({u,v});
    }
    int findset(int i,int parent[])
    {
        if(parent[i]==-1)
        {
            return i;
        }
        return findset(parent[i],parent);
    }
    void union_set(int x,int y,int parent[])
    {
        int s1=findset(x,parent);
        int s2=findset(y,parent);
        if(s1!=s2)
        {
            parent[s2]=s1;
        }
    }
    //cycle detection using disjoint set
    bool contains_cycle()
    {
        //disjoint union set to check if graph conatians cycle or not
        int *parent=new int[v];
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
        }
        //iterate over the edge list
        for(auto edge:l)
        {
            int i=edge.first;
            int j=edge.second;
            int s1=findset(i,parent);
            int s2=findset(j,parent);
            if(s1!=s2)
            {
                union_set(s1,s2,parent);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
int main() 
{
    Graph G(4);
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(0,3);
    if(G.contains_cycle())
    {
        cout<<"Cycle is presnet"<<endl;
    }
    else
    {
        cout<<"Cycle is not present"<<endl;
    }
}