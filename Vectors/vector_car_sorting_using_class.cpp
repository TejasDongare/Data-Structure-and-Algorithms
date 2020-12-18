#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class car
{
    public:
    int x;
    int y;
    string name;
    car()
    {

    }
    car(int x1,int y1,string s1)
    {
        x=x1;
        y=y1;
        name=s1;
    }
    int distance()
    {
        int xy=x*x+y*y;
        return xy; 
    }
};
bool comparator(car a,car b)
{
    int x1=a.distance();
    int y1=b.distance();
    if(x1==y1)
    {
        return a.x<b.x;
    }
    return x1<y1;
}
int main() {
    int size;
    cin>>size;
    vector<car> v;
    for(int i=0;i<size;i++)
    {
        int x,y;
        string s;
        cin>>x>>y>>s;
        car temp(x,y,s);
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),comparator);
    for(auto t:v)
    {
        cout<<t.name<<" "<<t.x<<" "<<t.y<<endl;
    }
}
