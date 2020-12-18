#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class person
{
public:
    int age;
    string name;
    person()
    {

    }
    person(string n,int a)
    {
        name=n;
        age=a;
    }
};
class comparator
{
public:
    bool operator()(person A,person B)
    {
        return A.age>B.age;
    }
};
int main() 
{
    priority_queue<person,vector<person>,comparator> pq;
    int size;
    cin>>size;
    for(int i=1;i<=size;i++)
    {
        int a;
        string n;
        cin>>n>>a;
        person p(n,a);
        pq.push(p);
    }
    while(!pq.empty())
    {
        person top=pq.top();
        cout<<top.name<<" "<<top.age<<endl;
        pq.pop();
    }
}
