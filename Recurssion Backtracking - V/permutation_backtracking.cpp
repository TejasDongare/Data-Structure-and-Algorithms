\\#include <iostream>
using namespace std;
void permutation(char *ch,int i)
{
    if(ch[i]=='\0')
    {
        cout<<ch<<endl;
    }
    for(int j=i;ch[j]!='\0';j++)
    {
        swap(ch[i],ch[j]);
        permutation(ch,i+1);
        //This is most important step called as backtracking - it means resotring the array as it was to backtrack
        swap(ch[i],ch[j]);
    }
}
int main() {
    char ch[100];
    cin>>ch;
    permutation(ch,0);
}
