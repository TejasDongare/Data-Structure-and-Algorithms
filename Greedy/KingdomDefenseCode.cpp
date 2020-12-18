#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int w,h,nooftowers;
    cin>>w>>h>>nooftowers;
    int x[nooftowers];
    int y[nooftowers];
    for(int i=0;i<nooftowers;i++)
    {
        cin>>x[i]>>y[i];
    }
    sort(x,x+nooftowers);
    sort(y,y+nooftowers);
    int dx=x[0]-1;
    int dy=y[0]-1;
    for(int i=1;i<nooftowers;i++)
    {
        dx=max(dx,x[i]-x[i-1]-1);
        dy=max(dy,y[i]-y[i-1]-1);
    }
    //corner case
    dx=max(dx,w-x[nooftowers-1]);
    dy=max(dy,h-y[nooftowers-1]);
    cout<<dx*dy<<endl;
}