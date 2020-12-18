#include <iostream>
using namespace std;
template<typename T>
class node
{
public:
    string key;
    T value;
    node<T>* next;
    node(string key,T value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }
    //DESTRUCTOR
    ~node()
    {
        if(next!=NULL)
        {
            delete next;
        }
    }
};
template<typename T>
class HashTable
{
    node<T>**table;//pointer to an array of pointers
    int current_size;
    int table_size;
    int hashfunction(string key)
    {
        int index=0;
        int p=1;
        for(int j=0;j<key.length();j++)
        {
            index=index+(key[j]*p)%table_size;
            index=index%table_size;
            p=(p*27)%table_size;
        }
        return index;
    }
    void rehash()
    {
        node<T> **old_table=table;
        table_size=table_size*2;
        table=new node<T>*[table_size];
        for(int i=0;i<table_size;i++)
        {
            table[i]=NULL;
        }
        current_size=0;
        for(int i=0;i<(table_size/2);i++)
        {
            node<T> *temp=old_table[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            if(old_table[i]!=NULL)
            {
                delete old_table[i];
            }
        }
        delete [] old_table;
    }
public:
    HashTable(int ts=7)
    {
        table=new node<T>*[table_size]; 
        table_size=ts;
        current_size=0;
        for(int i=0;i<table_size;i++)
        {
            table[i]=NULL;
        }
    }
    void insert(string key,T value)
    {
         int index=hashfunction(key);
         node<T> *n=new node<T>(key,value);
         n->next=table[index];
         table[index]=n;
         current_size++;
        float load_factor=(current_size)/(1.0*table_size);
         //that is 60% data is filled or load factor=0.6
         if(load_factor>0.6)
         {
             rehash();
         }
    }

    void print()
    {
        for(int i=0;i<table_size;i++)
        {
            node<T> *temp=table[i];
            cout<<i<<" :- ";
            while(temp!=NULL)
            {
                cout<<temp->key<<","<<temp->value<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

};
int main() 
{
    HashTable<int> h;
    h.insert("Burger",75);
    h.insert("Noodles",40);
    h.insert("Chinese Bhel",10);
    h.insert("Manchurian",15);
    h.insert("pizza",175);
   // h.insert("pia",175);
    h.print();
}
