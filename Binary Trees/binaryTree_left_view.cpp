#include<iostream>
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
void leftview(node *head,int &max_level,int current_level)
{
    if(head==NULL)
    {
        return;
    }
    if(current_level>max_level)
    {
        cout<<head->data<<" ";
        max_level=current_level;
    }
    leftview(head->left,max_level,current_level+1);
    leftview(head->right,max_level,current_level+1);
    return;
}
void preorder(node *head)
{
    if(head==NULL)
    {
        return;
    }
    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
}
int main()
{
    node *h1=build_tree();
    int max_level=-1;
    leftview(h1,max_level,0);
}