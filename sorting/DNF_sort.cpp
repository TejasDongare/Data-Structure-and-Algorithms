#include <iostream>
using namespace std;
void dnf_sort(int *ptr,int n)
{
    int l=0;
    int e=n-1;
    int m=0;
    while(m<e)
    {
        if(ptr[m]==0)
        {
            swap(ptr[l],ptr[m]);
            l++;
            m++;
        }
        else if(ptr[m]==1)
        {
            m++;
        }
        else
        {
            swap(ptr[m],ptr[e]);
            e--;
        }
    }
}
//DNF sort arrays of 0 1 and 2
int main() {
    int a[]={0,1,1,1,2,2,0};
    int n=7;
    dnf_sort(a,7);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
