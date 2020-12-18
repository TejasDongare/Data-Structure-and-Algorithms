#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class Graph
{
    unordered_map<string ,list<pair<string,int>>> l;
public:
    void addEdge(string x,string y,int wt,bool bidirectional=0)
    {
        l[x].push_back({y,wt});
        if(bidirectional)
        {
            l[y].push_back({x,wt});
        }
    }
    void printAdjlist()
    {
        for(pair<string,list<pair<string,int>>> t:l)
        {
            cout<<t.first<<" :- ";
            for(pair<string,int> x:t.second)
            {
                cout<<"("<<x.first<<","<<x.second<<")"<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g;
    g.addEdge("A","B",20);
    g.addEdge("A","C",10);
    g.addEdge("A","D",50,0);
    g.addEdge("B","D",40);
    g.addEdge("D","C",30);
    g.printAdjlist();
    return 0;
}