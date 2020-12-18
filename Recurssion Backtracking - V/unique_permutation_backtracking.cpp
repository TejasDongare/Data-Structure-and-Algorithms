#include <iostream>
#include<set>
#include<string>
using namespace std;
void permutation(char *ch,int i,set<string> &s)
{
    if(ch[i]=='\0')
    {
        //cout<<ch<<endl;
        s.insert(ch);
    }
    for(int j=i;ch[j]!='\0';j++)
    {
        swap(ch[i],ch[j]);
        permutation(ch,i+1,s);
        //This is most important step called as backtracking - it means resotring the array as it was to backtrack
        swap(ch[i],ch[j]);
    }
}
int main() {
    set<string> s;
    char ch[100];
    cin>>ch;
    permutation(ch,0,s);
    for(auto str:s)
    {
        cout<<str<<endl;
    }
}
