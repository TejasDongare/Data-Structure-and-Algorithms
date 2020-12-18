#include<iostream>
#include<climits>
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
node *search(node *head,int key)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->data==key)
    {
        return head;
    }
    if(head->data<key)
    {
        return search(head->right,key);
    }
    return search(head->left,key);
}
node *deleteINBST(node *head,int key)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->data==key)
    {
        //case 1:- if the node to be deleted is leaf node(node with 0 child)
        if(head->left==NULL and head->right==NULL)
        {
            delete head;
            return NULL;
        }
        //Case 2:- if the node has only one child(node with 1 child)
        else if(head->left!=NULL and head->right==NULL)
        {
            //if head has only one child in the left subtree
            node *temp=head->left;
            delete head;
            return temp;
        }
        else if(head->right!=NULL and head->left==NULL)
        {
            //if the head node has only one child and that is in right child
            node *temp=head->right;
            delete head;
            return temp;
        }
        //Case 3:-node with 2 child
        node *right_smallest=head->right;
        while(right_smallest->left!=NULL)
        {
            right_smallest=right_smallest->left;
        }
        head->data=right_smallest->data;
        //now deleting the node which has the right smallest element it can have zero or one child so we can recursive do the same thing
        head->right=deleteINBST(head->right,head->data);
        return head;
    }
    else if(head->data<key)
    {
        head->right=deleteINBST(head->right,key);
        return head;
    }
    head->left=deleteINBST(head->left,key);
    return head;
}
bool isBST(node *head,int min=INT_MIN,int max=INT_MAX)
{
    if(head==NULL)
    {
        return true;
    }
    if(head->data>=min and head->data<=max and isBST(head->left,min,head->data) and isBST(head->right,head->data,max))
    {
        return true;
    }
    return false;
}
class LinkedList
{
public:
    node *head;
    node *tail;
};
LinkedList createlinkedlist(node *head)
{
    LinkedList p;
    if(head->right==NULL and head->left==NULL)
    {
        p.head=p.tail=head;
        return p;
    }
    if(head->left!=NULL and head->right==NULL)
    {
        LinkedList l=createlinkedlist(head->left);
        l.tail->right=head;
        p.head=l.head;
        p.tail=head;
        return p;
    }
    if(head->right!=NULL and head->left==NULL)
    {
        LinkedList r=createlinkedlist(head->right);
        head->right=r.head;
        p.head=head;
        p.tail=r.tail;
        return p;
    }
    LinkedList left=createlinkedlist(head->left);
    LinkedList right=createlinkedlist(head->right);
    p.head=left.head;
    left.tail->right=head;
    head->right=right.head;
    p.tail=right.tail;
    return p;
}
int main()
{
    node *head=buildtree();
    LinkedList h=createlinkedlist(head);
    head=h.head;
    while(head->right!=NULL)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
    
}