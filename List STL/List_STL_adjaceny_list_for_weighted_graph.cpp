#include <iostream>
#include<list>
using namespace std;
int main() 
{
    int vertex;
    cin>>vertex;
    list<pair<int,int>> l[vertex];
    int edges;
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        l[x].push_back(make_pair(y,wt));
        l[y].push_back(make_pair(x,wt));
    }
    //Printing the adjancency list
    
   /* for(list<pair<int,int>> s:l)
    {
        for(pair<int,int> t:s)
        {
            cout<<"("<<t.first<<","<<t.second<<"),";
        }
        cout<<endl;
    }*/
    for(int i=0;i<vertex;i++)
    {
        cout<<"list for index "<<i<<":-";
        for(auto s:l[i])
        {
            cout<<"("<<s.first<<","<<s.second<<"),";
        }
        cout<<endl;
    }
}
