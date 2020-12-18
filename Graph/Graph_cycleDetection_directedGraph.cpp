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
    bool cycle_helper(int node,bool *visited,bool *stack)
    {
        visited[node]=1;
        stack[node]=1;
        for(int temp:l[node])
        {
            if(stack[temp])
            {
                return true;
            }
            else if(!visited[temp])
            {
                if(cycle_helper(temp,visited,stack))
                {
                    return true;
                }
            }
        }
        stack[node]=0;
        return 0;
    }
    bool cycle_checker()
    {
        bool *visited=new bool[v];
        bool *stack=new bool[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=0;
            stack[i]=0;
        }
        return cycle_helper(0,visited,stack);
    }
};
int main() 
{
    graph g(7);
    g.addEdges(0,1);
    g.addEdges(1,5);
    g.addEdges(5,6);
    g.addEdges(1,2);
    g.addEdges(2,3);
    g.addEdges(3,4);
    g.addEdges(4,2);
    g.addEdges(4,5);
    if(g.cycle_checker())
    {
        cout<<"Cycle is present"<<endl;
    }
    else
    {
        cout<<"Cycle Is Not present"<<endl;
    }
    
}#include <iostream>
using namespace std;
int main() {
    cout<<"Hello World!";
}
