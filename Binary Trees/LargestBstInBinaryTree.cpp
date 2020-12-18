#include<iostream>
#include<climits>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};
class isbstproperty
{
public:
	int size,min,max;
	bool ans;
};
node *build_tree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node *root=new node(d);
    root->left=build_tree();
    root->right=build_tree();
    return root;
}
isbstproperty checker(node *head)
{
	isbstproperty temp;
	if(head==NULL)
	{
		temp.ans=true;
		temp.size=0;
		temp.min=INT_MAX;
		temp.max=INT_MIN;
		return temp;
	}
	isbstproperty left=checker(head->left);
	isbstproperty right =checker(head->right);
	//cout<<"head->data:-"<<head->data<<" left.min "<<left.min<<" left.min "<<left.min<<" right.min "<<right.min<<" right.max "<<right.max<<e 
	temp.min=min(left.min,min(right.min,head->data));
	temp.max=max(left.max,max(right.max,head->data));
	if(left.ans==true and right.ans==true and (left.max<=head->data and right.min>head->data))
	{
		temp.ans=true;
		temp.size=left.size+right.size+1;
	}
	else
	{
	    //cout<<"head->data="<<head->data<<endl;
		temp.ans=false;
		temp.size=max(left.size,right.size);
	}
	return temp;
}
void createinorderarray(node *head,int *in,int &in_ptr)
{
	if(head==NULL)
	{
		return;
	}
	createinorderarray(head->left,in,in_ptr);
	in[in_ptr]=head->data;
	in_ptr++;
	createinorderarray(head->right,in,in_ptr);
}
int main() 
{
	node *h=build_tree();
	isbstproperty x=checker(h);
	cout<<x.size<<endl;
}