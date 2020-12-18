#include <iostream>
using namespace std;
class queue
{
    int *arr;
    int f,r,cs,ms;
public:
    //constructor
    queue(int default_size=5)
    {
        arr=new int[default_size];
        ms=default_size;
        cs=0;
        f=0;
        r=ms-1;
    }
    bool full()
    {
        return ms==cs;
    }
    void enqueue(int d)
    {
        if(!full())
        {
            r=(r+1)%ms;
            arr[r]=d;
            cs++;
            return;
        }
        cout<<"Queue is Full"<<endl;
        return;
    }
    bool empty()
    {
        return cs==0;
    }
    void dequeue()
    {
        if(!empty())
        {
            f=(f+1)%ms;
            cs--;
            return;
        }
        cout<<"Queue is empty"<<endl;
    }
    int front()
    {
        return arr[f];
    } 
    ~queue()
    {
        if(arr!=NULL)
        {
            delete [] arr;
            arr=NULL;
        }
    }
};
int main() {
    queue x;
    x.enqueue(5);
    x.enqueue(6);
    while(!x.empty())
    {
        cout<<x.front()<<" ";
        x.dequeue();
    }
}
