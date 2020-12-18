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
        inserAtTail(head,d);
        cin>>d;
    }
    return head;
}
//operator overloading
ostream& operator<<(ostream &x,node*head)
{
    while(head!=NULL)
    {
        x<<head->data<<" ";
        head=head->next;
    }
    return x;
}
istream& operator>>(istream&x,node*&head)
{
    head=take_input();
    return x;
}
void reversed_linked_list(node *&head)
{
    node*prev=NULL;
    node*current=head;
    while(current!=NULL)
    {
        node *next_node=current->next;
        current->next=prev;
        prev=current;
        current=next_node;
    }
    head=prev;
}
node* recursive_reversed_linked_list(node *head)
{
    if(head->next==NULL or head==NULL)
    {
        return head;
    }
    node* small_head=recursive_reversed_linked_list(head->next);
    node *temp=small_head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    head->next=NULL;
    temp->next=head;
    return small_head;
}
//Another method reverse of linked list
/*void recurssive_linked_list(node *&head,node *prev,node*current)
{
    if(current==NULL)
    {
        head=prev;
        return;
    }
    node *next_node=current->next;
    current->next=prev;
    prev=current;
    current=next_node;
    recurssive_linked_list(head,prev,current);
    return ;
}*/
//Runner up
node *mid_point(node *head)
{
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
int kth_node_from_left(node*head,int k)
{
    node*slow=head;
    node*fast=head;
    while(k--)
    {
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow->data;
}
node *merge(node*head1,node*head2)
{
    node*sorted_list=NULL;
    while(head1!=NULL and head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            inserAtTail(sorted_list,head1->data);
            head1=head1->next;
        }
        else
        {
            inserAtTail(sorted_list,head2->data);
            head2=head2->next;
        }
    }
    while(head1!=NULL)
    {
        inserAtTail(sorted_list,head2->data);
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        inserAtTail(sorted_list,head2->data);
        head2=head2->next;
    }
    return sorted_list;
}
node*recursive_merge(node*a,node *b)
{
    //base case
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    node *c;
    if(a->data<b->data)
    {
        c=a;
        c->next=recursive_merge(a->next,b);
    }
    else
    {
        c=b;
        c->next=recursive_merge(a,b->next);
    }
    return c;
}
node *merge_sort(node *head)
{
    //Base case
    if(head==NULL or head->next==NULL)
    {
        return head;
    }
    //break
    node *mid=mid_point(head);
    node*a=head;
    node*b=mid->next;
    mid->next=NULL;
    //recursivelt merge
    a=merge_sort(a);
    b=merge_sort(b);
    node *c=merge(a,b);
    return c;
}
int main() 
{
    node *head;
    cout<<"enter the linked list terminating with -1"<<endl;
    cin>>head;
    cout<<"Entered Linked List"<<endl;
    cout<<head<<endl;
    head=merge_sort(head);
    cout<<head<<endl;
}

