#include<iostream>
#include<typeinfo>
#include<climits>
#include<set>
using namespace std;
int main()
{
    set<pair<int,int>> s;
    s.insert(make_pair(50,60));
    s.insert(make_pair(10,5));
    s.insert(make_pair(50,7));
    s.insert(make_pair(50,8));
    s.insert(make_pair(60,60));
    s.insert(make_pair(60,7));
    s.insert(make_pair(70,60));
    s.erase(make_pair(50,60));
    set<pair<int,int>>::iterator it=s.lower_bound(make_pair(50,8));
    cout<<"Lower_bound="<<it->first<<" "<<it->second<<endl;
    it=s.upper_bound(make_pair(50,INT_MAX));
    cout<<"Upper Bound="<<it->first<<" "<<it->second<<endl;
}