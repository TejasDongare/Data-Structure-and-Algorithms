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
    cout<<endl;
}
void deleteAtTail(node*&head)
{
    if(head->next==NULL)
    {
        delete head;
        head=NULL;
        return;
    }
    if(head!=NULL)
    {
        node *temp=head;
        node *prev=NULL;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=(*temp).next;
        }
        prev->next=NULL;
        delete temp;
    }
    return;


}
void deleteAtPosition(node*&head,int p)
{
    node *current=head;
    node*prev;
    if(p==1)
    {
        node*temp=head->next;
        delete head;
        head=temp;
        return;
    }
    while(p>1)
    {
        prev=current;
        current=current->next;
        p--;
    }
    prev->next=current->next;
    delete current;
}
void deleteAtHead(node*&head)
{
    if(head!=NULL)
    {
        node*temp=head->next;
        delete head;
        head=temp;
    }
    return ;
}
int linear_search(node*head,int key)
{
    int pos=0;
    while(head!=NULL)
    {
        if(head->data==key)
        {
            return pos;
        }
        pos++;
        head=head->next;
    }
    return -1;
}
int recursive_linear_search(node*head,int key,int index)
{
    if(head==NULL)
    {
        return -1;
    }
    else if(head->data==key)
    {
        return index;
    }
    return recursive_linear_search(head->next,key,index+1);
}
node* take_input()
{
    int d;
    cin>>d;
    node*head=NULL;
    while(d!=-1)
    {
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}
int main() {
    /*
    node *head=NULL;
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,50);
    insertAtHead(head,108);
    insertAtHead(head,53);
    insertAtPosition(head,99,3);
    inserAtTail(head,0);
    deleteAtHead(head);
    deleteAtTail(head);
    deleteAtTail(head);
    deleteAtTail(head);
    deleteAtTail(head);
    deleteAtTail(head);
    deleteAtTail(head);
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,50);
    insertAtHead(head,108);
    insertAtHead(head,53);
    insertAtPosition(head,99,3);
    print(head);
    deleteAtPosition(head,1);
    print(head);
    int index=linear_search(head,99);
    if(index==-1)
    {
        cout<<"Element "<<99<<" not found in Linked List Using Linear Search"<<endl;
    }
    else
    {
        cout<<"Element  "<<99<<" found at index="<<index<<" Using Linear Search "<<endl;
    }
    index=recursive_linear_search(head,99,0);
    if(index==-1)
    {
        cout<<"Element  "<<99<<" not found in Linked List Using recursive search"<<endl;
    }
    else
    {
        cout<<"Element  "<<99<<" Found at Index="<<index<<" Using Recursive Search"<<endl;
    }*/
    
    //taking input method
    node*head=take_input();
    print(head);
}
