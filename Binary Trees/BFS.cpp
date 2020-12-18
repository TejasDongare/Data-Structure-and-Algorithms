#include <iostream>
#include<queue>
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
//BFS and level order are same but level order does it in O(n) 
void BFS(node *head)
{
    queue<node*> q;
    q.push(head);
    while(!q.empty())
    {
        node *temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}
//BFS If We Need with each level with different level
void BFS_With_New_line(node *head)
{
    queue<node*> q;
    q.push(head);
    q.push(NULL);
    while(!q.empty())
    {
        cout<<"q.size()"<<q.size()<<"q.front() "<<q.front()<<endl;
        node *temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
//**********OR*********
/*
void BFS_With_New_line(node *head)
{
    queue<node*> q;
    q.push(head);
    q.push(NULL);
    while((!q.empty()) and !(q.size()==1 and q.front()==NULL))
    {
       // cout<<"q.size() "<<q.size()<<"q.front() "<<(q.front())<<endl;
        node *temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            q.push(NULL);
        }
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
*/
int main() 
{
    cout<<"Level Order without New Line :- ";
    node *head=build_tree();
    BFS(head);

    cout<<endl<<"Level Order with New Line :- "<<endl;
    BFS_With_New_line(head);
}
