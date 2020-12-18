#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
    vector<pair<int,int>> *l;
    int v;
public:
    Graph(int v)
    {
        this->v=v;
        l=new vector<pair<int,int>> [v];
    }
    void addEdge(int x,int y,int w)
    {
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }
    int prims()
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//here int the pair pq.first contains weight because to sort it on that basis and second contains the node
        bool *visited=new bool[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=0;
        }
        int ans=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            pair<int,int> temp=pq.top();
            pq.pop();
            if(visited[temp.second])
            {
                continue;
            }
            visited[temp.second]=1;
            ans+=temp.first;
            for(pair<int,int> t:l[temp.second])
            {
                if(!visited[t.first])
                {
                    pq.push({t.second,t.first});
                }
            }
        }
        return ans;
    }
};
int main() 
{
    Graph g(9);
    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,7,11);
    g.addEdge(7,8,7);
    g.addEdge(7,6,1);
    g.addEdge(8,6,6);
    
    g.addEdge(2,8,2);
    g.addEdge(1,2,8);
    
    
    g.addEdge(2,5,4);
    g.addEdge(6,5,2);
    g.addEdge(2,3,7);
    g.addEdge(3,5,14);
    g.addEdge(3,4,9);
    g.addEdge(5,4,10);
    cout<<g.prims()<<endl;
}