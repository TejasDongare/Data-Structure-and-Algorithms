#include <iostream>
using namespace std;
//given ladder having step and max step size 1,2,3...max_step_size
int ladder(int n,int max_step_size)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    int ans=0;
    for(int i=1;i<=max_step_size;i++)
    {
        ans+=ladder(n-i,max_step_size);
    }
    return ans;
}
int main() {
    int step;
    int max_step_size;
    cin>>step>>max_step_size;
    cout<<ladder(step,max_step_size);
}
