#include <iostream>
#include<list>
#include<map>
using namespace std;
template<typename T>
class Graph
{
    map<T,list<T>> l;
public:
    void addEdge(T a,T b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }
    void dfs_helper(T src,map<T,bool> &v)
    {
        cout<<src<<" ";
        v[src]=1;
        for(T temp:l[src])
        {
            if(!v[temp])
            {
                dfs_helper(temp,v);
            }
        }
    }
    void dfs(T src)
    {
        map<T,bool> visited;
        for(pair<T,list<T>> x:l)
        {
            visited[x.first]=0;
        }
        dfs_helper(src,visited);
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs(0);
}