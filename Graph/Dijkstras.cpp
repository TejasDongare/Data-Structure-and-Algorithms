#include <iostream>
#include<climits>
#include<list>
#include<unordered_map>
#include<set>
using namespace std;
template<typename T>
class Graph
{   
    unordered_map<T,list<pair<T,int>> > m;
public:
    void addEdge(T a,T b,int d)
    {
        m[a].push_back({b,d});
        m[b].push_back({a,d});
    }
    void printadjlist()
    {
        for(pair<T,list<pair<T,int>>> x:m)
        {
            cout<<x.first<<" : - ";
            for(pair<T,int> temp:x.second)
            {
                cout<<"("<<temp.first<<","<<temp.second<<"),";
            }
            cout<<endl;
        }
    }
    void dijkstras(T src)
    {
        unordered_map<T,int> distance;
        //set all distance to infinity
        for(pair<T,list<pair<T,int>>> d:m)
        {
            distance[d.first]=INT_MAX;
        }
        
        //set is sorted
        //we are creating set and not min heap because in min heap we cant update a specific value but in set we can find that element and than delete that element and again reinsert ew new value
        //but in heap that is priority queueu we have to only the first element that is max or min but we cant udpate it
        set<pair<int,T>> s;//first paramter is distance because set is sorted on the basis of the first parameter
        distance[src]=0;
        s.insert({0,src});
        while(!s.empty())
        {
            pair<int,T> source=*(s.begin());
            s.erase(s.begin());
            for(pair<T,int> neighbour:m[source.second])
            {
                //cout<<"Distance of neighbout:-"<<distance[neighbour.first]<<endl;
                if(distance[neighbour.first]>(source.first+neighbour.second))
                {
                    auto add=s.find({distance[neighbour.first],neighbour.first});
                    if(add!=s.end())
                    {
                        s.erase(add);
                    }
                  //  cout<<"Distance:-"<<source.first+neighbour.second<<" for "<<neighbour.first<<endl;
                    distance[neighbour.first]=source.first+neighbour.second;
                    s.insert({source.first+neighbour.second,neighbour.first});
                }
            }
        }
        for(pair<T,int> d: distance)
        {
            cout<<d.first<<" is located at distance "<<d.second<<endl;
        }
    }
};
int main() 
{
    Graph<string> g;
    g.addEdge("Mumbai","Delhi",1500);
    g.addEdge("Mumbai","gujrat",200);
    g.addEdge("gujrat","Delhi",30);
    g.addEdge("gujrat","kashmir",800);
    g.addEdge("Delhi","kashmir",70);
    g.dijkstras("Mumbai");
}