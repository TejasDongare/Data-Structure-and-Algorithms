#include<iostream>
#include<set>
using namespace std;
int main()
{
    //internally stored as BST
    //multiset
    int arr[]={10,10,30,30,30,10,50,60};
    int size=sizeof(arr)/sizeof(int);
    multiset<int> m(arr,arr+size);
    
    //iterate
    for(int x:m)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    //this will erase all the occurrence of 20
    m.erase(10);
    for(int x:m)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    //if we want to remove multiple occurence  of 10 and insert only than we can erase all the occurence of 10 and only insert one 10
    m.insert(10);
    for(int x:m)
    {
        cout<<x<<" ";
    }
    //count
    cout<<endl<<"Count:-"<<m.count(30)<<endl;
    
    //find
    auto it=m.find(30);
    cout<<(*it)<<endl;
    
    typedef multiset<int>::iterator t;
    //get range of elements which are equal to 30
    pair<t,t> p=m.equal_range(30);
    for(multiset<int>::iterator temp=p.first;temp!=p.second;temp++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    
    
    //get a number to a range lower bound returns >= and upper bound returns >c++
    p.first=m.lower_bound(20);
    p.second=m.upper_bound(50);
    cout<<"Range between 20 t0 50"<<endl;
    for(auto temp=p.first;temp!=p.second;temp++)
    {
        cout<<*temp<<" ";
    }
}
