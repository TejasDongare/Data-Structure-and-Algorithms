#include <iostream>
#include<stack>
using namespace std;
bool paranthesis_check(stack<char> &x,string s)
{
    int ans=true;
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]=='(')
        {
            x.push('(');
        }
        else if(s[i]==')')
        {
            if(x.empty() or x.top()!='(')
            {
                return false;
            }
            x.pop();
        }
        i++;
    }
    x.top();
    if(x.empty())
    {
        return true;
    }
    return false;
}

int main() 
{
    stack<char> s;
    string t="()())";
    if(paranthesis_check(s,t))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}
