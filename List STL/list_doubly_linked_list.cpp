#include <iostream>
#include<list>
using namespace std;
int main() 
{
    //list is like doubly linked list
    list<int> l1{1,2,3,4,5};
    list<string> l2{"apple","Banana","kiwi","cat"};
    
    //delete from front
    l1.pop_front();

    //delete from end
    l1.pop_back();

    //sort
    l2.sort();

    //front and last element in list
    cout<<"Front element from l1="<<l1.front()<<endl;
    cout<<"Last element from l2="<<l2.back()<<endl;

    //iterate over the strings
    for(auto s:l1)
    {
        cout<<s<<" ";
    }
    cout<<endl;
    
    //print using iterator
    for(auto s=l2.begin();s!=l2.end();s++)
    {
        cout<<(*s)<<" ";
    }

}