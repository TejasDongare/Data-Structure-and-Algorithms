#include <iostream>
#include<queue>
#include<list>
using namespace std;
class Graph
{
    int v;
    list<int> *l;
public:
    Graph(int v)
    {
        this->v=v;
        l=new list<int> [v];
    }
    void addEdge(int a,int b)
    {
        l[a].push_back(b);
    }
    void topological_sort()
    {
        int *indegree=new int[v];
        for(int i=0;i<v;i++)
        {
            indegree[i]=0;
        }
        //updating the indegree
        for(int i=0;i<v;i++)
        {
            for(auto t:l[i])
            {
                indegree[t]++;
            }
        }
        queue<int> q;
        //finding indegree with 0
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(int temp:l[t])
            {
                indegree[temp]--;
                if(indegree[temp]==0)
                {
                    q.push(temp);
                }
            }
            cout<<t<<" ";
        }
    }
};
int main() 
{
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.addEdge(3,5);
    g.topological_sort();
}