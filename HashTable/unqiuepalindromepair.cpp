#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void uniquewordpair(vector<string> s)
{
    unordered_map<string,int> m;
    bool ans=false;
    for(string temp:s)
    {
        m[temp]=1;
    }
    int y;
    for(string temp:s)
    {
        ans=false;
        string t=temp;
        string reverse="";
        for(int i=0;t[i]!='\0';i++)
        {
            reverse=t[i]+reverse;
            //condition t.length>1 because if the length is only 1 that is one character example a than its reverse is a and it will say it is present that is itself which will result in aa thats wrong excluding itself
            if(m.count(reverse) and t.length()>1)
            {
                int end=temp.length()-1;
                for(y=i+1;y<end;y++)
                {
                    if(temp[y]==temp[end])
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                    end--;
                }
                if(y>=end)
                {
                    ans=true;
                }
            }
            if(ans)
           {
                break;
           }
        }
        if(ans)
        {
            cout<<temp+reverse<<endl;
        }
    }
}
int main() 
{
    vector<string> v;
    v.push_back("abcd");
    v.push_back("dcba");
    v.push_back("abbb");
    v.push_back("a");
    uniquewordpair(v);
}
