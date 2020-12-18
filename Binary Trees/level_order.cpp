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
//finding height Take O(n)
int height(node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    int left_height=height(head->left);
    int right_height=height(head->right);
    return max(left_height,right_height)+1;
}
//printing Kth Level Takes O(n)
void PrintKthLevel(node *head,int k)
{
    if(head==NULL)
    {
        return;
    }
    if(k==1)
    {
        cout<<head->data<<" ";
        return;
    }
    PrintKthLevel(head->left,k-1);
    PrintKthLevel(head->right,k-1);
    return;
}
//printing Level_order takes O(n*n)
void level_order(node *head)
{
    int h=height(head);
    for(int i=1;i<=h;i++)
    {
        cout<<"Level "<<i<<" :- ";
        PrintKthLevel(head,i);
        cout<<endl;
    }
}
int main() 
{
    node *head=build_tree();
    preorder(head);
    cout<<endl<<"Height="<<height(head)<<endl;
    cout<<"Printing 3rd level of tree:-";
    PrintKthLevel(head,3);
    cout<<endl<<" *****Level Order*****"<<endl;
    level_order(head);
}
