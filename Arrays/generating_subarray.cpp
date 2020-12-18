/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int a[50],size;
    cout<<"Enter the size of array=";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cout<<"Follwing is subarrays"<<endl;
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<a[k];
            }
            cout<<", ";
        }
        cout<<endl;
    }

    return 0;
}
