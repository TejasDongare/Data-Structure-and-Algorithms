#include <iostream>
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
    node *root=new node(d);
    root->left=build_tree();
    root->right=build_tree();
    return root;
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
    return;
}
void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
void postorder(node *head)
{
    if(head==NULL)
    {
        return;
    }
    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
    return;
}
int main() 
{
    node *head=build_tree();
    cout<<"Preoder Traversal:- ";
    preorder(head);
    cout<<endl;
    cout<<"Post Order Traversal:- ";
    postorder(head);
    cout<<endl;
    cout<<"Inorder Traversal:- ";
    inorder(head);
    cout<<endl;
}
