#include <iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> t;
    t.push_back(10);
    t.push_back(20);
    t.push_back(50);
    t.push_back(80);
    t.push_back(90);
    vector<int> x{1,2,3,4,5};
    cout<<"Details of vector T:-"<<endl;
    cout<<"Size="<<t.size()<<endl;
    cout<<"Capacity="<<t.capacity()<<endl;
    cout<<"Max Size="<<t.max_size()<<endl;
    cout<<endl<<"Details of vector x:-"<<endl;
    cout<<"Size="<<x.size()<<endl;
    cout<<"Capacity="<<x.capacity()<<endl;
    cout<<"Max Size="<<x.max_size()<<endl;
    for(auto s:t)
    {
        cout<<s<<" ";
    }
    cout<<endl;
    for(vector<int>::iterator it=x.begin();it!=x.end();it++)
    {
        cout<<*it<<" ";
    }
}
