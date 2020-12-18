#include <iostream>
using namespace std;
//given 4*N wall find the total ways in which bricks can be placed with bricks height = 3 and width=4
int tile(int n)
{
    if(n<=3)
    {
        return 1;
    }
    return tile(n-1)+tile(n-4);
}
int main() {
    int n;
    cin>>n;
    cout<<tile(n);
}
