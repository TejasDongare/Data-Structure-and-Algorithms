#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node(int n)
    {
        data=n;
        next=NULL;
    }
};

void insertAtHead(node*&head,int data)//passing head by reference
{
    node*new_node=new node(data);
    if(head==NULL)
    {
        head=new_node;
        return;
    }
    (*new_node).next=head;//here we are deferencing thats why (*new_node) or we can also use new_node->
    head=new_node;
}
void inserAtTail(node*&head,int d)
{
    //if head is at null
    if(head==NULL)
    {
        head=new node(d);
        return;
    }
    node*tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(d);
    return;
}
void insertAtPosition(node*&head,int d,int p)
{
    node*h=head;
    
    if(p==0 or head==NULL)
    {
        insertAtHead(head,d);
        return;
    }
    node *new_node=new node(d);
    while(h->next!=NULL and p>1)//we will take p-1 jumps
    {
        p--;
        h=h->next;
    }
    //cout<<"current node="<<h->data<<endl;
    new_node->next=h->next;
    h->next=new_node;
    return;
}
void print(node*head)
{
    while(head!=NULL)
    {
        cout<<(*head).data<<"->";
        head=(*head).next;
    }
}
int main() {
    node *head=NULL;
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,50);
    insertAtHead(head,108);
    insertAtHead(head,53);
    insertAtPosition(head,99,3);
    inserAtTail(head,0);
    print(head);
}
