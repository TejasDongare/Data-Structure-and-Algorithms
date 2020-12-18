#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
bool compare(pair<int,int> p,pair<int,int> p1)
{
    return p.first>p1.first;
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        int flag=0;
        int numberofstations;
        vector<pair<int,int>> v;
        cin>>numberofstations;
        for(int i=0;i<numberofstations;i++)
        {
            int d,f;
            cin>>d>>f;
            v.push_back({d,f});
        }
        sort(v.begin(),v.end(),compare);
        int current_fuel,Distance;
        cin>>Distance>>current_fuel;
        for(int i=0;i<numberofstations;i++)
        {
            v[i].first=Distance-v[i].first;
        }
        int current=0;
        int next=0;
        priority_queue<int> pq;
        while(next<numberofstations)
        {
            if(((v[next].first)-current)<=current_fuel)
            {
                current_fuel=current_fuel-(v[next].first-current);
                //curremt contains the current distance covered while next contains the index of the next station
                current=v[next].first;
                pq.push(v[next].second);
            }
            else
            {
                if(pq.empty())
                {
                    flag=1;
                    break;
                }
                int t=pq.top();
                current_fuel+=t;
                pq.pop();
                ans++;
                continue;//this will redirect to line number 34 to check condition
            }
            next++;
        }
        //traversed all the stations
        if(flag)
        {
            cout<<-1<<endl;
            continue;
        }
        Distance=Distance-v[numberofstations-1].first;
        if(Distance<=current_fuel)
        {
            cout<<ans<<endl;
            continue;
        }
        while(current_fuel<Distance)
        {
            if(pq.empty())
            {
                flag=1;
                break;
            }
            int t=pq.top();
            current_fuel+=t;
            pq.pop();
            ans++;
        }
        if(flag)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
}