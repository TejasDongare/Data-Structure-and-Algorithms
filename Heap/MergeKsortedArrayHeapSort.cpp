#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,pair<int,int>> node;
vector<int> mergeKsorted(vector<vector<int>> arr)
{
    priority_queue<node,vector<node>,greater<node>> pq;//this will be default creat an heap on the basis of first value
    vector<int> output;
    for(int i=0;i<arr.size();i++)
    {
        pq.push({arr[i][0],{i,0}});
    }
    while(!pq.empty())
    {
        node temp=pq.top();
        pq.pop();
        output.push_back(temp.first);
        if(temp.second.second+1<arr[temp.second.first].size())
        {
            pq.push({arr[temp.second.first][temp.second.second+1],{temp.second.first,temp.second.second+1}});
        }
    }
    return output;
}
int main()
{
    vector<vector<int>> arr{{1,2,3,5},
                            {2,3,5,9},
                            {7,10,64,78}};
    vector<int> output=mergeKsorted(arr);
    int i=0;
    while(i<output.size())
    {
        cout<<output[i]<<" ";
        i++;
    }
}