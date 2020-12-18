#include <iostream>
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
        l=new list<int>[v];
    }
    void addEdge(int a,int b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }
    void printAdjlist()
    {
        for(int i=0;i<v;i++)
        {
            cout<<"Vertex "<<i<<" :- ";
            for(int neighbour:l[i])
            {
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
    }
};
int main() 
{
    Graph G(3);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,2);
    G.addEdge(2,2);
    G.printAdjlist();
}