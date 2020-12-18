#include <iostream>
#include<set>
using namespace std;
//set is ordered
//set is sorted
//set stores unqiue vale
 //set is like BST internally it takes O(logn) for insertion and deletion
 //set can add or delete but it doesnot support update opertation
int main() 
{
    int arr[]={10,2,99,-10,77,3,9};
    int n=sizeof(arr)/sizeof(int);
    set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<(*it)<<" ";
    }
}
