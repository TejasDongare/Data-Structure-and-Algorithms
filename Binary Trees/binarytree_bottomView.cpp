#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int max_temp=10000000;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data=d;
        right=NULL;
        left=NULL;
    }
};
node *build_tree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node *temp=new node(d);
    temp->left=build_tree();
    temp->right=build_tree();
    return temp;
}
void travel(node *head,vector<int> &positive,vector<int> &negative,int d)
{
    queue<pair<node*,int>> q;
    pair<node*,int> t;
    t.first=head;
    t.second=0;
    q.push(t);
    while(!q.empty())
    {
        pair<node*,int> temp=q.front();
        q.pop();
       // cout<<"temp.first->data:-"<<temp.first->data<<" "<<"temp.second:-"<<temp.second<<" "<<"negative[max_temp+temp.second]"<<negative[max_temp+temp.second]<<" positive[d] "<<positive[temp.second]<<endl;
        if(temp.first->left!=NULL)
        {
            pair<node*,int> left;
            left.first=temp.first->left;
            left.second=temp.second-1;
            q.push(left);
        }
        if(temp.first->right!=NULL)
        {
            pair<node*,int> right;
            right.first=temp.first->right;
            right.second=temp.second+1;
            q.push(right);
        }
        if(temp.second<0)
        {
            negative[max_temp+temp.second]=temp.first->data;
        }
        if(temp.second>=0)
        {
            positive[temp.second]=temp.first->data;
        }
    }

}
//printing levelorder in bottom view
void BottomView(node *head,vector<int> &positive,vector<int> &negative,int d)
{
	queue<pair<node*,int>> q;
	q.push(make_pair(head,0));
	while(!q.empty())
	{
	    pair<node*,int> temp=q.front();
	    q.pop();
	    if(temp.second<0)
	    {
	        if(temp.first->data==negative[max_temp+temp.second])
	        {
	            cout<<temp.first->data<<" ";
	        }
	    }
	    else
	    {
	        if(temp.first->data==positive[temp.second])
	        {
	            cout<<temp.first->data<<" ";
	        }
	    }
	    if(temp.first->left!=NULL)
	    {
	        q.push(make_pair(temp.first->left,temp.second-1));
	    }
	    if(temp.first->right!=NULL)
	    {
	        q.push(make_pair(temp.first->right,temp.second+1));
	    }
	}
}
node *level_order_build()
{
	queue<node*> q;
	int d;
	cin>>d;
	node *temp;
	if(d!=-1)
	{
		temp=new node(d);
		q.push(temp);
	}
	while(!q.empty())
	{
		node *x=q.front();
		q.pop();
		int t;
		cin>>t;
		if(t==-1)
		{
			x->left=NULL;
		}
		else
		{
			x->left=new node(t);
			q.push(x->left);
		}
		cin>>t;
		if(t==-1)
		{
			x->right=NULL;
		}
		else
		{
			x->right=new node(t);
			q.push(x->right);
		}
	}
	return temp;
}
int main()
{
        vector<int> positive(10000000,-1);
        vector<int> negative(10000000,-1);
        node *h1=level_order_build();
        travel(h1,positive,negative,0);
        BottomView(h1,positive,negative,0);
}
