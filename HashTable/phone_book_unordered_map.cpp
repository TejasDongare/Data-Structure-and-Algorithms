#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main() 
{
    unordered_map<string,vector<string>> phonebook;
    phonebook["Tejas"].push_back("9892457087");
    phonebook["Tejas"].push_back("99999999999");
    phonebook["papa"].push_back("97022030542");
    phonebook["Mummy"].push_back("8108735732");
    for(pair<string,vector<string>> t:phonebook)
    {
        cout<<t.first<<" :- ";
        for(string s:t.second)
        {
            cout<<s<<" -> ";
        }
        cout<<endl;
    }
    cout<<"Enter the Name to find the Number"<<endl;
    string temp;
    cin>>temp;
    if(phonebook.count(temp))
    {
        cout<<"Number of "<<temp<<" :- ";
        for(string s:(*phonebook.find(temp)).second)
        {
            cout<<s<<"->";
        }
    }
    else
    {
        cout<<"Number of "<<temp<<" not found "<<endl;
    }
}
