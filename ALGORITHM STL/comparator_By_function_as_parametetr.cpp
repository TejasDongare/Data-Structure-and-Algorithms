#include <iostream>
using namespace std;
bool comparator(int x,int y)
{
    return x>y;
}
void bubble_sort(int a[],int size,bool (&cmp)(int x,int y))
{
    for(int i=0;i<size;i++)
    {
        for(int j=1;j<size-i;j++)
        {
            if(comparator(a[j-1],a[j]))
            {
                swap(a[j-1],a[j]);
            }
        }
    }

}
int main() {
    int arr[100],size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    bubble_sort(arr,size,comparator);
    cout<<"Sorted array is shown below"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
