#include <iostream>
#include<vector>
using namespace std;
class stack
{
private:
    vector<int> v;
public:
    void push(int d)
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
    int top()
    {

        return v[v.size()-1];
    
    }
};
int main() {
    stack s;
    s.push(6);
    s.push(7);
    s.pop();
    s.pop();
    s.pop();
}
