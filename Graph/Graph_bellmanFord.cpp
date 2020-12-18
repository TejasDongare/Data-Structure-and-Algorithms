#include <iostream>
#include<climits>
#include<vector>
using namespace std;
class Graph
{
    int v;
    vector<vector<int>> l;
public:
    Graph(int v)
    {
        this->v=v;
    }
    void addEdge(int x,int y,int wt)
    {
        l.push_back({x,y,wt});
    }
    void relax(int u,int v,vector<int> &distance,int wt)
    {
        if(distance[u]!=INT_MAX and distance[u]+wt<distance[v])
        {
            distance[v]=distance[u]+wt;
        }
    }
    vector<int> bellman_ford(int src)
    {
        vector<int> distance(v,INT_MAX);
        distance[src]=0;
        for(int i=0;i<v-1;i++)
        {
            for(auto edge:l)
            {
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                relax(u,v,distance,wt);
            }
        }
        //for negative edge
        for(auto edge:l)
        {
            if(distance[edge[0]]!=INT_MAX and distance[edge[0]]+edge[2]<distance[edge[1]])
            {
                cout<<"Negative Cycle"<<endl;
                exit(0);
            }
        }
        return distance;
    }
    
};
int main() 
{
    Graph g(3);
    vector<int> i=g.bellman_ford(0);
    for(int t=0;t<i.size();t++)
    {
        cout<<t<<" "<<i[t]<<endl;
    }
}