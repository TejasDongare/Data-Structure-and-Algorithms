#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    int data;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
node *insert(node *head,int d)
{
    if(head==NULL)
    {
        return new node(d);
    }
    if(head->data<=d)
    {
        head->right=insert(head->right,d);
    }
    else
    {
        head->left=insert(head->left,d);
    }
    return head;
}
node *buildtree()
{
    int d;
    cin>>d;
    node *head=NULL;
    while(d!=-1)
    {
        head=insert(head,d);
        cin>>d;
    }
    return head;
}
void bfs(node *head)
{
    queue<node*> q;
    q.push(head);
    q.push(NULL);
    while(!q.empty())
    {
        //cout<<"q.size()"<<q.size()<<"q.front() "<<q.front()<<endl;
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
int main()
{
    node *head=buildtree();
    bfs(head);
}