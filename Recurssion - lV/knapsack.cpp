#include<iostream>
using namespace std;
int knapsack(int *weights,int *profits,int n,int c)
{
	if(n==0 or c==0)
	{
	return 0;
	}
	//including last element
	int inc,exc;
	inc=exc=0;
	if(weights[n-1]<=c)
	{
		inc=profits[n-1]+knapsack(weights,profits,n-1,c-weights[n-1]);
	}
	//excluding last elemnt
	exc=knapsack(weights,profits,n-1,c);
//	cout<<max(inc,exc)<<endl;
	return max(inc,exc);
}
int main()
{
	int weights[]={1,2,3,4,5};
	int profits[]={10,20,40,40,50};
	int n=5;
	int c=5;	
	cout<<knapsack(weights,profits,n,c);
}