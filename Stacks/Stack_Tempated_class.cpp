#include <iostream>
#include<vector>
using namespace std;
template<typename T>
class stack
{
private:
    vector<T> v;
public:
    void push(T d)
    {
        v.push_back(d);
    }
    bool empty()
    {
        return v.size()==0;
    }
    void pop()
    {
        if(!empty())
        {
            v.pop_back();
        }
        else
        {
            cout<<"Stack Is Empty"<<endl;
        }
    }
    T top()
    {
        return v[v.size()-1];
    }
};
int main() {
    stack<char> s;
    s.push('A');
    s.push('B');
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
}
