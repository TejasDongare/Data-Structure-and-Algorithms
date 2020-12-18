#include <iostream>
#include<cstring>
using namespace std;
//string to integer
int stringToInteger(string s,int size,int ans)
{
    if(size==-1)
    {
        return 0;
    }
    int temp=(s[size])-'0';
   // cout<<(stringToInteger(s,size-1,ans)*10+temp)<<endl;
    return stringToInteger(s,size-1,ans)*10+temp;
}
int main() {
    string s;
    cin>>s;
    int x=stringToInteger(s,(s.length()-1),0);
    cout<<x<<endl;
}
