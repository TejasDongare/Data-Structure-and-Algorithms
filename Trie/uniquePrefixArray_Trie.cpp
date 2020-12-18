#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;
class node
{
public:
    char data;
    bool terminal;
    int freq;
    unordered_map<char,node*> children;
    node(char d)
    {
        data=d;
        terminal=false;
        freq=1;
    }
};
class Trie
{
    node *root;
    int cnt;
public:
    Trie()
    {
        root=new node('\0');
        cnt=0;
    }
    void insert(string w)
    {
        node *temp=root;
        for(int i=0;w[i]!='\0';i++)
        {
            if((temp->children.count(w[i])))
            {
                (temp->children[w[i]])->freq=(temp->children[w[i]])->freq+1;
            }
            else
            {
                temp->children[w[i]]=new node(w[i]);
            }
            temp=temp->children[w[i]];
        }
        temp->terminal=true;
    }
    bool find(string w)
    {
        node* temp=root;
        for(int i=0;w[i]!='\0';i++)
        {
            if(temp->children.count(w[i])==0)
            {
                return false;
            }
            else
            {
                temp=temp->children[w[i]];
            }
        }
        return temp->terminal;
    }
    void printuniqueprefixarray(string arr[],int size)
    {
        int i;
        for(int j=0;j<size;j++)
        {
            string x=arr[j];
            node* temp=root;
            for(i=0;x[i]!='\0';i++)
            {
                if((temp->children[x[i]])->freq==1)
                {
                    cout<<x.substr(0,i+1)<<" ";
                    break;
                }
                temp=temp->children[x[i]];
            }
            if(x[i]=='\0')
            {
                cout<<"-1"<<" ";
            }
        }
    }
};
int main()
{
    Trie t;
    t.insert("cobra");
    t.insert("dove");
    t.insert("duck");
    t.insert("dog");
    string ch[]={"cobra","dove","duck","dog"};
    t.printuniqueprefixarray(ch,4);
    
}