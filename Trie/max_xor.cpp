#include <iostream>
using namespace std;
class node
{
public:
    node *left;//left means zero
    node *right;//right means one
};
class Trie
{
node *root;
public:
    Trie()
    {
        root=new node();
    }
    void insert(int d)
    {
        node *temp=root;
        for(int i=31;i>=0;i--)
        {
            if((d>>i)&1)
            {
                if(temp->right==NULL)
                {
                    temp->right=new node();
                }
                temp=temp->right;
            }
            else
            {
                if(temp->left==NULL)
                {
                    temp->left=new node();
                }
                temp=temp->left;
            }
        }
    }
    int find_max_xor(int d)
    {
        node *temp=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            if((d>>i)&1)
            {
                if(temp->left!=NULL)
                {
                    ans+=(1<<i);
                    temp=temp->left;
                }
                else{
                    temp=temp->right;
                }
            }
            else
            {
                if(temp->right!=NULL)
                {
                    ans+=(1<<i);
                    temp=temp->right;
                }
                else
                {
                    temp=temp->left;
                }
            }
        }
        return ans;
    }
    int max_xor(int *arr,int size)
    {
        int max_xor=0;
        for(int i=0;i<size;i++)
        {
            insert(arr[i]);
            int current_max_xor=find_max_xor(arr[i]);
            max_xor=max(max_xor,current_max_xor);
        }
        return max_xor;
    }

};
int main() {
    Trie t;
    int arr[]={3,10,5,25};
    cout<<t.max_xor(arr,4);
}
