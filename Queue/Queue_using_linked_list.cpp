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
class queue
{
    node *head;
public:
    queue()
    {
        head=NULL;
    }
    void enqueue(int d)
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
    bool empty()
    {
        return head==NULL;
    }
    void dequeue()
    {
        if(!empty())
        {
            node *temp=head;
            head=head->next;
            delete temp;
            return;
        }
        cout<<"Queue is empty"<<endl;
        return;
    }
    int front()
    {
        return head->data;
    }
};
int main() {
    queue c;
    c.enqueue(10);
    c.enqueue(20);
    while(!c.empty())
    {
        cout<<c.front()<<" ";
        c.dequeue();
    }
    c.dequeue();
}
