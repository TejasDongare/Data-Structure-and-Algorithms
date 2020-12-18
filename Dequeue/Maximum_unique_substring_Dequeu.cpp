#include <iostream>
#include<cstring>
using namespace std;
int main() 
{
    char a[]="abcdeabcdefghifg";
    int n=strlen(a);
    int current_length=1;
    int max_length=1;
    int visited[27];
    for(int i=0;i<27;i++)
    {
        visited[i]=-1;
    }
    visited[a[0]-'a']=0;
    for(int i=1;i<n;i++)
    {
        int last_occurence=visited[a[i]-'a'];
        //expansion
        if(last_occurence==-1 or last_occurence<i-current_length)
        {
            current_length+=1;
        //    cout<<"Current_length="<<current_length<<endl;
        }
        //expansion + contraction
        else
        {
            max_length=max(max_length,current_length);
            current_length=i-last_occurence;
        }
        visited[a[i]-'a']=i;
    }
    max_length=max(max_length,current_length);
    cout<<max_length<<endl;
}
