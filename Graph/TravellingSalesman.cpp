#include<iostream>
#include<climits>
using namespace std;
//time complexity is O(n!)
int n=4;
int a[10][10]={{0,20,42,25},
                      {20,0,30,34},
                      {42,30,0,10},
                      {25,34,10,0}};
int VISITED_ALL=(1<<n)-1;
int tsp(int mask,int pos)
{
    if(mask==VISITED_ALL)
    {
        return a[pos][0];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(((mask>>i)&1)==0)
        {
            int newAns=a[pos][i]+tsp(mask|(1<<i),i);
            ans=min(newAns,ans);
        }
    }
    return ans;
}
int main()
{
    cout<<tsp(1,0);
    return 0;
}