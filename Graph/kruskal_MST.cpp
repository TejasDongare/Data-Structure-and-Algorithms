#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
class DUS
{
    int *parent;
    int *rank;
public:
    DUS(int v)
    {
        parent=new int[v];
        rank=new int[v];
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find(int i)
    {
        if(parent[i]==-1)
        {
            return i;
        }
        return parent[i]=find(parent[i]);
    }
    void union_set(int u,int v )
    {
        int s1=find(u);
        int s2=find(v);
        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
};
class Graph
{
    vector<vector<int>> edgelist;
    int v;
public:
    Graph(int v)
    {
        this->v=v;
    }
    void addEdge(int x,int y,int w)
    {
        edgelist.push_back({w,x,y});
    }
    int krushkal()
    {
        //sort
        sort(edgelist.begin(),edgelist.end());
        int ans=0;
        DUS s(v);
        for(auto edge:edgelist)
        {
            int s1=s.find(edge[1]);
            int s2=s.find(edge[2]);
            if(s1!=s2)
            {
                s.union_set(s1,s2);
                ans+=edge[0];
            }
        }
        return ans;
    }

};
int main() 
{
    Graph G(4);
    G.addEdge(0,1,1);
    G.addEdge(1,3,3);
    G.addEdge(3,2,5);
    G.addEdge(2,0,2);
    G.addEdge(0,3,2);
    G.addEdge(1,2,2);
    cout<<G.krushkal()<<endl;
}
