#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void insertAthead(node*&head,int d)
{
    node *new_node=new node(d);
    new_node->next=head;
    node *temp=head;
    if(temp!=NULL)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
    //this is for self loop if insert is called for the first time
    else
    {
        new_node->next=new_node;
    }
    head=new_node;
}
ostream& operator<<(ostream&x,node*head)
{
    node *temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    return x;
}
node *search(node *head,int d)
{
    while(head!=NULL)
    {
        if(head->data=d)
        {
            return head;
        }
        head=head->next;
    }
    return NULL;
}
void delete_node(node*&head,int d)
{
    node *del=search(head,d);
    if(del!=NULL)
    {
        if(head==del)
        {
            head=head->next;
        }
        node*temp=head;
        while(temp->next!=del)
        {
            temp=temp->next;
        }
        temp->next=del->next;
        delete del;
    }
}
int main()
{
    node*head=NULL;
    insertAthead(head,10);
    insertAthead(head,20);
    insertAthead(head,30);
    insertAthead(head,40);
    insertAthead(head,50);
    //cout<<"head->data="<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<" "<<head->next->next->next->data<<" "<<head->next->next->next->next->data<<endl;
    cout<<head<<endl; 
    delete_node(head,50);
    cout<<head<<endl;
    delete_node(head,40);
    cout<<head<<endl;

}