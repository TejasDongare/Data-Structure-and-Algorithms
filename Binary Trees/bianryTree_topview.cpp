#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int max_temp=100000;
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
        if(temp.second<0 and negative[max_temp+temp.second]==-1)
        {
            negative[max_temp+temp.second]=temp.first->data;
        }
        if(temp.second>=0 and positive[temp.second]==-1)
        {
            positive[temp.second]=temp.first->data;
        }
    }
}
void topView(node *head,vector<int> &positive,vector<int> &negative,int d)
{
    if(head==NULL)
    {
        return;
    }
    topView(head->left,positive,negative,d-1);
    if(d<0)
    {
        if(negative[max_temp+d]==head->data)
        {
            cout<<head->data<<" ";
        }
    }
    else if(d>=0)
    {
        if(positive[d]==head->data)
        {
            cout<<head->data<<" ";
        }
    }
    topView(head->right,positive,negative,d+1);
    return;
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
        vector<int> positive(100000,-1);
        vector<int> negative(100000,-1);
        node *h1=level_order_build();
        travel(h1,positive,negative,0);
      //  cout<<"positive[1]="<<positive[1]<<endl;
        topView(h1,positive,negative,0);
}