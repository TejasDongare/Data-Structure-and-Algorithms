#include<iostream>
#include<climits>
#include<queue>
#include<list>
#include<map>
using namespace std;
template<typename T>
class graph
{
    map<T,list<T>> l;
public:
    void addEdge(T a,T b)
    {
        l[a].push_back(b);
    }
    //this works only for unweighted graph here we are going to BFS traversal
    T SingleSourceShortestPath(T source,T destination)
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
                   // cout<<"node "<<node<<" temp "<<temp<<" distance node to temp="<<distance[node]+1<<endl;
                    q.push(temp);
                }
            }
        }
        return distance[destination];
    }
};
int main()
{
    int board[37];
    graph<int> g;
    for(int i=0;i<37;i++)
    {
        board[i]=i;
    }
    board[2]=15;
    board[5]=7;
    board[9]=27;
    board[17]=4;
    board[18]=29;
    board[20]=6;
    board[24]=16;
    board[25]=35;
    board[32]=30;
    board[34]=12;
    for(int i=0;i<=36;i++)
    {
        for(int j=1;j<=6;j++)
        {
            int temp=i+j;
            if(temp<=36)
            {
                g.addEdge(i,board[temp]);
            }
        }
    }
    //this we have to add else it in map there will be no node of 36
    g.addEdge(36,36);
    cout<<g.SingleSourceShortestPath(0,36);
}
