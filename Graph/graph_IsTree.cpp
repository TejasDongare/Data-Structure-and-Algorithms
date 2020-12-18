#include <iostream>
#include<list>
#include<queue>
using namespace std;
class graph
{
    int v;
    list<int> *l;
public:
    graph(int v)
    {
        this->v=v;
        l=new list<int>[v];
    }
    void addEdges(int a,int b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }
    bool is_tree()
    {
        queue<int> q;
        bool *visited=new bool[v];
        int *parent=new int[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=0;
            parent[i]=i;
        }
        int src=0;
        visited[src]=1;
        q.push(src);
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(int t:l[temp])
            {
                if(visited[t] and parent[temp]!=t)
                {
                    return false;
                }
                else if(!visited[t])
        
                {
                    visited[t]=1;
                    q.push(t);
                    parent[t]=temp;
                }
            }
        }
        return true;
    }
};
int main() 
{
    graph g(4);
    g.addEdges(0,1);
    g.addEdges(0,3);
    g.addEdges(3,2);
    g.addEdges(1,2);
    if(g.is_tree())
    {
        cout<<"Is Tree"<<endl;
    }
    else
    {
        cout<<"Not Tree"<<endl;
    }
    
}