#include<iostream>
#include<set>
using namespace std;
class comparator
{
    public:
    bool operator()(pair<string,int> p1,pair<string,int> p2)
    {
        return p1.second>p2.second;
    }
};
int main()
{
    multiset<pair<string,int>> m;
    pair<string,int> p1=make_pair("B",100);
    pair<string,int> p2=make_pair("C",20);
    pair<string,int> p3=make_pair("A",99);
    pair<string,int> p4=make_pair("D",10);
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);
    //here the sorting is done on the basis of String defualt
    for(auto p:m)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    
    //we can pass do custom sorting now sorting will be done on the basis of custom
    multiset<pair<string,int>,comparator> t;
    t.insert(p1);
    t.insert(p2);
    t.insert(p3);
    t.insert(p4);
    for(auto p:m)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    
}
