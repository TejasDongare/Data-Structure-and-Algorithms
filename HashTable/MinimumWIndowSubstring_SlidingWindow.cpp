#include <iostream>
#include<climits>
using namespace std;
bool checker(int *s,int *p,int ss,int ps)
{
    for(int i=0;i<ps;i++)
    {
        if(s[i]>=p[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
string findtheminLengthsequence(string s,string pattern,int ss,int ps)
{
    int fs[256]={0};
    int fp[256]={0};
    for(int i=0;i<ps;i++)
    {
        fp[pattern[i]]++;
    }
    int count=0;
    int start=0;
    int start_index=-1;
    int len=INT_MAX;
    for(int i=0;i<ss;i++)
    {
        fs[s[i]]++;
        if(fp[s[i]]!=0 and fp[s[i]]>=fs[s[i]])
        {
            count++;
        }
        if(count==ps)
        {
            //expand and reduce the size
            while(fp[s[start]]==0 or fp[s[start]]<fs[s[start]])
            {
                fs[s[start]]--;
                start++;
            }
            int window_length=i-start+1;
            if(len>window_length)
            {
                len=window_length;
                start_index=start;
            }
        }
    }
    if(start_index==-1)
    {
        return "None";
    }
    return s.substr(start_index,len);
}
int main() 
{
    string s1="Hellloworld";
    string pattern="ello";
    cout<<findtheminLengthsequence(s1,pattern,s1.length(),pattern.length())<<endl;
}
