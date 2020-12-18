#include <iostream>
#include<vector>
#include<algorithm>
#include <typeinfo>
using namespace std;
bool comparator(pair<int,int> c1,pair<int,int>c2)
{
    int d1=c1.first*c1.first+c1.second*c2.second;
    int d2=c2.first*c2.first+c2.second*c2.second;
    if(d1==d2)
    {
        return c1.first<c2.first;
    }
    return d1<d2;
}
int main() {
    vector<pair<int,int>> cars;
    int total_cars;
    cin>>total_cars;
    for(int i=0;i<total_cars;i++)
    {
        int x,y;
        cin>>x>>y;
        cars.push_back(make_pair(x,y));
    }
    sort(cars.begin(),cars.end(),comparator);
    for(pair<int,int> temp:cars)//or we can also write for(auto temp:cars)
    {
        //cout << typeid(temp).name() << endl;
        cout<<temp.first<<" "<<temp.second<<endl;
    }
    
}
