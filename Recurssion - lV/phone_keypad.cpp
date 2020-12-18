#include <iostream>
using namespace std;
void keypad1(char *input,char *output,int i,int o)
{
    char keypad[][100]={"","","ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX"};
    //Base Case
    if(input[i]=='\0')
    {
        output[o]='\0';
        cout<<output<<endl;
        return;
    }

    //Recurssive Call
    int digit=input[i]-'0';
    if(digit==0 or digit==1)
    {
        keypad1(input,output,i+1,o);
    }
    for(int k=0;keypad[digit][k]!='\0';k++)
    {
        output[o]=keypad[digit][k];
        keypad1(input,output,i+1,o+1);
    }
    return;
}
int main() {
    char input[100];
    cin>>input;
    char output[100];
    keypad1(input,output,0,0);
}
