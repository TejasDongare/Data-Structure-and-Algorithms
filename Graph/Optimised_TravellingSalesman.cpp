#include<iostream>
#include<climits>
using namespace std;
int n=4;
//Optimised DP having time complexity
int dp[16][4]={-1};
int a[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};
int VISITED_ALL=(1<<n)-1;
int tsp(int mask,int pos)
{
    if(mask==VISITED_ALL)
    {
        return a[pos][0];
    }
    if(dp[mask][pos]!=-1)
    {
        return dp[mask][pos];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(!((mask&(1<<i))))
        {
            int newAns=a[pos][i]+tsp(mask|(1<<i),i);
            ans=min(newAns,ans);
        }
    }
    return dp[mask][pos]=ans;
}
int main()
{
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<4;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<tsp(1,0);
    return 0;
}