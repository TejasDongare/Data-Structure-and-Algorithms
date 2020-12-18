#include <iostream>
#include<queue>
using namespace std;
int main() 
{
    priority_queue<int> left;//max heap
    priority_queue<int,vector<int>, greater<int>> right;//min heap
    int d;
    cin>>d;
    left.push(d);
    float median=d;
    cout<<"med:-"<<median<<" "<<endl;
    cin>>d;
    while(d!=-1)
    {
        if(left.size()>right.size())
        {
            if(d>median)
            {
                right.push(d);
            }
            else
            {
                right.push(left.top());
                left.pop();
                left.push(d);
            }
            median=(left.top()+right.top())/2.0;
        }
        else if(left.size()==right.size())
        {
            if(d>median)
            {
                right.push(d);
                median=right.top();
            }
            else
            {
                left.push(d);
                median=left.top();
            }
        }
        else
        {
            if(d>median)
            {
                left.push(right.top());
                right.pop();
                right.push(d);
            }
            else
            {
                left.push(d);
            }
            median=(left.top()+right.top())/2.0;
        }
        cout<<"med:-"<<median<<endl;
        cin>>d;
    }

}
