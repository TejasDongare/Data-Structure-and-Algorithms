#include <iostream>
#include<queue>
using namespace std;
int main() 
{
    string s="aabccbcd";
    int a[27]={0};
    queue<char> q;
    int i=0;
    while(s[i]!='\0')
    {
        q.push(s[i]);
        a[s[i]-'a']+=1;
        while(a[q.front()-'a']>1 and !q.empty())
        {
           // cout<<"a[q.front-65] "<<a[q.front()-'a']<<" q.size="<<q.size()<<endl;
            q.pop();
        }
        if(q.empty())
        {
            cout<<"-1"<<" ";
        }
        else
        {
            cout<<q.front()<<" ";
        }
        i++;
    }
}
