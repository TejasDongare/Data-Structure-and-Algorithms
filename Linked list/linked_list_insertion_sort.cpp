#include <iostream>
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
void insertAtTail(node *&head,int d)
{
    if(head==NULL)
    {
        head=new node(d);
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new node(d);
    return;
}
ostream& operator<<(ostream &x,node *y)
{
    while(y!=NULL)
    {
        cout<<y->data<<" ";
        y=y->next;
    }
    return x;
}
void swap(node *t1,node *t2)
{
    int temp=t1->data;
    t1->data=t2->data;
    t2->data=temp;
}
void insertion_sort(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        node *t1=head;
        while(t1!=temp)
        {
            if(t1->data>temp->data)
            {
                swap(t1,temp);
            }
            t1=t1->next;
        }
        temp=temp->next;
    }
}
int main() 
{
    node *head=NULL;
    int size;
    cin>>size;
    while(size--)
    {
        int d;
        cin>>d;
        insertAtTail(head,d);
    }
    insertion_sort(head);
    cout<<head;
}
