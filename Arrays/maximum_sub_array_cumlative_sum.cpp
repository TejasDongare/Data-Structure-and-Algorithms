#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[100];
    int cumsum[100]={0};
    int currentsum=0;
    int maxsum=0;
    int left=-1;
    int right=-1;
    cin>>a[0];
    cumsum[0]=a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        cumsum[i]=cumsum[i-1]+a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            currentsum=0;
            (i==0)?maxsum=a[j]:maxsum=cumsum[j]-cumsum[i-1];
            if(currentsum>maxsum)
            {
                maxsum=currentsum;
                left=i;
                right=j;
            }
        }       
    }
    cout<<"maximum sum is "<<maxsum<<endl;
    for(int k=left;k<=right;k++)
    {
        cout<<a[k]<<",";
    }
    return 0;
}
