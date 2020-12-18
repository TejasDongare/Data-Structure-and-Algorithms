#include <iostream>
using namespace std;
void toweer_hanoi(int n,char src,char helper,char destination)
{
    if(n==0)
    {
        return ;
    }
    toweer_hanoi(n-1,src,destination,helper);
    cout<<"shifting "<<n<<" from "<<src<<" Destination "<<destination<<endl;
    toweer_hanoi(n-1,helper,src,destination);
}
int main() {
    int n;
    cin>>n;
   toweer_hanoi(n,'A','B','C');
}
