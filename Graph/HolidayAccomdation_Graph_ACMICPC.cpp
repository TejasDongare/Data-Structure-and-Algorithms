#include <iostream>
#include<list>
using namespace std;
class graph
{
    list<pair<int,int>> *l;
    int v;
public:
    graph(int v)
    {
        this->v=v;
        l=new list<pair<int,int>> [v];
    }
    void addEdge(int u,int v,int d)
    {
        l[u].push_back({v,d});
        l[v].push_back({u,d});
    }
    int dfs_helper(int node,bool *visited,int *count,int &ans)
    {
        visited[node]=1;
        count[node]=1;
        for(auto nbr_pair:l[node])
        {
            if(!visited[nbr_pair.first])
            {
                count[node]+=dfs_helper(nbr_pair.first,visited,count,ans);
                ans+=(2*(min(count[nbr_pair.first],v-(count[nbr_pair.first]))))*nbr_pair.second;
            }
        }
        return count[node];
    }
    int dfs()
    {
        bool *visited=new bool[v]{0};
        int *count=new int[v]{0};
        int ans=0;
        dfs_helper(0,visited,count,ans);
        return ans;
    }
};

int main() 
{
    graph g(4);
    g.addEdge(0,1,3);
    g.addEdge(1,2,2);
    g.addEdge(2,3,2);
    cout<<g.dfs()<<endl;
}