#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}
int findnumberofjobs(vector<pair<int,int>> v)
{
    int count=0;
    int prev_finish=0;
    for(int i=0;i<v.size();i++)
    {
        pair<int,int> x=v[i];
        if(x.first>=prev_finish)
        {
            count++;
            prev_finish=x.second;
        }
    }
    return count;
}
int main() 
{
    vector<pair<int,int>> v;
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        pair<int,int> a;
        cin>>a.first>>a.second;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),compare);
   cout<<findnumberofjobs(v)<<endl;
}