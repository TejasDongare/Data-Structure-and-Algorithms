#include <iostream>
using namespace std;
//Generate Subsequence
void generate(char *input,char *output,int i,int o)
{
    if(input[i]=='\0')
    {
        output[o]='\0';
        cout<<output<<endl;
        return ;
    }
    //including the current character
    output[o]=input[i];
    generate(input,output,i+1,o+1);
    //excluding the current character
    generate(input , output ,i+1,o);
}
int main() {
    char input[]="abc";
    char output[100];
    generate(input,output,0,0);
}
