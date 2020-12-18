#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class graph
{
    map<T,list<T>> l;
public:
    void addEdge(T a,T b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }
    void bfs(T d)
    {
        map<T,bool> visited;
        queue<T> q;
        q.push(d);
        visited[d]=1;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(T temp:l[node])
            {
                if(!visited[temp])
                {
                    q.push(temp);
                    visited[temp]=1;
                }
            }
            cout<<node<<" ";
        }
    }
};
int main()
{
    graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);
}