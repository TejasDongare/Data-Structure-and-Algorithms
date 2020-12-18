#include<iostream>
#include<unordered_map>
using namespace std;
class node
{
public:
    char data;
    bool terminal;
    unordered_map<char,node*> children;
    node(char d)
    {
        data=d;
        terminal=false;
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
            if(temp->children.count(w[i])==0)
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
};
int main()
{
    Trie t;
    t.insert("Not");
    t.insert("No");
    if(t.find("No"))
    {
        cout<<"No is present"<<endl;
    }
    else
    {
        cout<<"Not present"<<endl;
    }
}