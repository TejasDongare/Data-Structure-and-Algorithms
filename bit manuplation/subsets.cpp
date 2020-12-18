#include <iostream>
#include<cstring>
using namespace std;
void filter_and_print(char a[],int i)
{
    int j=0;
    while(i>0)
    {
        if(i&1)
        {
            cout<<a[j]<<"";
        }
        j++;
        i=i>>1;
    }
    cout<<endl;
}
int main() {
    char a[1000];
    cin>>a;
    int length=strlen(a);
    int len=1<<(length);
   // cout<<len<<endl;
    //cout<<length<<endl;
    for(int i=0;i<len;i++)
    {
        filter_and_print(a,i);
    }
}
