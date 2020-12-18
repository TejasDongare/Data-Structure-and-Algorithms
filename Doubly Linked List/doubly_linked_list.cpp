#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};
void insertAtbegin(node*&head,int d)
{
    if(head==NULL)
    {
        head=new node(d);
        return;
    }
    node *temp=new node(d);
    temp->next=head;
    head=temp;
    temp->next->prev=temp;
}
void inserAtend(node*&head,int d)
{
    if(head==NULL)
    {
        insertAtbegin(head,d);
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new node(d);
    temp->next->prev=temp;
    return;
}
void deleteAtStart(node*&head)
{
    if(head!=NULL)
    {
        node*temp=head->next;
        head->next->prev=NULL;
        delete head;
        head=temp;
    }
    return ;
}
void deleteAtEnd(node*&head)
{
    if(head->next==NULL)
    {
        delete head;
        head=NULL;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node *node_to_delete=temp;
    temp->prev->next=NULL;
    delete node_to_delete;
}
ostream& operator<<(ostream&x,node *temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return x;
}
int main() {
    node *head=NULL;
    insertAtbegin(head,10);
    insertAtbegin(head,50);
    inserAtend(head,70);
    cout<<head<<endl;
    deleteAtEnd(head);
    deleteAtEnd(head);
   // deleteAtEnd(head);
   // deleteAtEnd(head);
  //  cout<<head<<endl;
}
