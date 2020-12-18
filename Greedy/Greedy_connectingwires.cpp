#include<iostream>
#include<algorithm>
using namespace std;
int mod(int d)
{
    if(d<0)
    {
        return (-1*d);
    }
    return d;
}
int main()
{
    int size;
    cin>>size;
    int whitedots[size];
    int blackdots[size];
    cout<<"Enter the co-ordinates of White Dot"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>whitedots[i];
    }
    cout<<"Enter the co-ordinates of Black Dots"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>blackdots[i];
    }
    sort(whitedots,whitedots+size);
    sort(blackdots,blackdots+size);
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans+=(whitedots[i]-blackdots[i]);
    }
    cout<<ans<<endl;
}