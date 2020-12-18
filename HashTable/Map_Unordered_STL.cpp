#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string,int> m;
    //1.insert
    m.insert({"Mango",200});
    
	//2.insert
    m["Banana"]=20;
    
    //Search
    string fruit;
    cin>>fruit;
    unordered_map<string,int>::iterator it=m.find(fruit);
    if(it!=m.end())
    {
        cout<<"Price of "<<fruit<<" is "<< m[fruit]<<endl;
    }

    //erase
    m.erase(fruit);
    
    //update the price
    m[fruit]+=21;
    
    
    //another wau to find a particular map
    //it stores unqiue value
    if(m.count(fruit))
    {
        cout<<"Price of "<<fruit<<" is "<<m[fruit]<<endl;
    }
    else
    {
        cout<<"Fruit does not found"<<endl;
    }
    m["Apple"]=120;
    m["Peru"]=50;
    m["pomogranate"]=125;
    
    cout<<endl<<"Iterators using for loop"<<endl;
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    //for each loop
    cout<<endl<<"Iterators using for each loop "<<endl;
    for(auto p:m)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
}