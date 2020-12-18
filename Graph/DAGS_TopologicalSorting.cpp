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
    }
    void dfs_helper(T src,map<T,bool> &v,list<T> &ordering)
    {
        v[src]=1;
        for(T temp:l[src])
        {
            if(!v[temp])
            {
                dfs_helper(temp,v,ordering);
            }
        }
        ordering.push_front(src);
    }
    //this is nothing but dfs
    void topologicalsort()
    {
        map<T,bool> visited;
        for(pair<T,list<T>> x:l)
        {
            visited[x.first]=0;
        }
        list<T> ordering;
        for(auto p:l)
        {
            if(!visited[p.first])
            {
                dfs_helper(p.first,visited,ordering);
            }
        }
        for(auto temp:ordering)
        {
            cout<<temp<<" ";
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(4,2);
    g.addEdge(0,4);
    //this is nothing but dfs
    g.topologicalsort();
}