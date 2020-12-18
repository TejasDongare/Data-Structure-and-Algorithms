#include <iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> d{1,2,3,4,5};
    d.push_back(18);
    d.pop_back();
    d.insert(d.begin()+3,100);
    for(int x:d)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    d.insert(d.begin()+4,4,69);
    for(int x:d)
    {
        cout<<x<<" ";
    }
    d.erase(d.begin()+3);
    cout<<endl;
    for(int x:d)
    {
        cout<<x<<" ";
    }
    d.erase(d.begin()+3,d.begin()+5);
    cout<<endl;
    for(int x:d)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Size="<<d.size()<<endl;
    cout<<"capacity="<<d.capacity()<<endl;
    //RESIZE
    d.resize(15);
    cout<<"After resizing the array"<<endl;
    cout<<"Capacity="<<d.capacity()<<endl;
    //resize remove all elements but doesnt delete the memory occupied by the array
    d.clear();
    cout<<"Size after clearing="<<d.size()<<endl;
    //empty
    if(d.empty())
    {
        cout<<"This is empty Vector"<<endl;
    }
    //TO get front and last element
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    cout<<endl;
    for(int x:d)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Front element="<<d.front()<<endl;
    cout<<"End element="<<d.back()<<endl;
    cout<<endl;
    //to avoid doubling we will reverse function suppose input size is big it is expensive to double everytime so we can reserve once example 1000 elements 
    vector<int> x;
    x.reserve(1000);
    for(int i=0;i<800;i++)
    {
        x.push_back(i);
    }
    cout<<"size="<<x.size()<<endl;
    cout<<"Capacity="<<x.capacity()<<endl;
}
