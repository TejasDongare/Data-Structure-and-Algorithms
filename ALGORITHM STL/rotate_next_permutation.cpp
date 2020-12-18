#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    int x[]={1,2,3};
    //permutation
    for(int i=0;i<8;i++)
    {
        next_permutation(x,x+3);
        for(int j=0;j<3;j++)
        {
            cout<<x[j]<<" ";
        }
        cout<<endl;
    }

    //rotate
    int y[]={1,2,3,4,5};
    rotate(y,y+1,y+3);
    cout<<"After rotating array at index 1"<<endl;
    for(int j=0;j<3;j++)
    {
        cout<<y[j]<<" ";
    }

    //rotating and reversing
    int z[]={1,2,3};
    rotate(z,z+2,z+3);
    cout<<endl<<"After rotating at last index resulting reversed array"<<endl;
    for(int j=0;j<3;j++)
    {
        cout<<z[j]<<" ";
    }
}
