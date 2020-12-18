#include<iostream>
#include<climits>
#include<queue>
#include<list>
#include<map>
using namespace std;
template<typename T>
//if we do bfs and if the node is discovered first then it will the shortest path for unweighted graph
//undirected graph and unweighted graph
class graph
{
    map<T,list<T>> l;
public:
    void addEdge(T a,T b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }
    //this works only for unweighted graph here we are going to BFS traversal
    void SingleSourceShortestPath(T source)
    {
        queue<T> q;
        map<T,int> distance;
        for(pair<T,list<T>> x:l)
        {
            distance[x.first]=INT_MAX;
        }
        distance[source]=0;
        q.push(source);
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(T temp:l[node])
            {
                if(distance[temp]==INT_MAX)
                {
                    distance[temp]=distance[node]+1;
                    q.push(temp);
                }
            }
        }
        for(pair<T,list<T>> temp:l)
        {
            cout<<" Node "<<temp.first<<" Distance From Source "<<distance[temp.first]<<endl;
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
    g.SingleSourceShortestPath(0);
}