#include <iostream>
#include<stack>
using namespace std;
//elimination approach
int main() {
    int n;
    cin>>n;
    int c[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>c[i][j];
        }
    }
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        s.push(i);
    }
    while(s.size()!=1)
    {
        int a,b;
        a=s.top();
        s.pop();
        b=s.top();
        s.pop();
        if(c[a][b])
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    if(s.empty())
    {
        cout<<"No Celebrity"<<endl;
    }
    else
    {
        int flag=1;
        int fr=s.top();
        for(int i=0;i<n;i++)
        {
            if(c[i][fr]!=1 and i!=fr)
            {
                flag=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(c[fr][i])
            {
                flag=0;
            }
        }
        if(flag)
        {
            cout<<fr<<endl;
        }
        else
        {
            cout<<"No celebrity"<<endl;
        }
    }
}
