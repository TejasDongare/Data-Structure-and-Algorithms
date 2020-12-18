#include<iostream>
using namespace std;
void acode(char *input,char *output,int i,int j)
{
	if(input[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<endl;
		return;
	}
	int digit=input[i]-'0';
	output[j]=digit+'A'-1;	
	//cout<<output[j]<<endl;
	acode(input,output,i+1,j+1);
	if(input[i+1]!='\0')
	{
		int d=input[i+1]-'0';
		int temp=digit*10+d;
		if(temp<=26)
		{
		output[j]=temp-1+'A';
		acode(input,output,i+2,j+1);
		}
		
	}
}
int main()
{
	char input[100];
	cin>>input;
	char output[100];
	acode(input,output,0,0);
}