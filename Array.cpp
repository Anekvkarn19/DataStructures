#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements";
    cin>>n;
    vector<int>A(n);
    cout<<"Enter the elements";
    for(int i=0;i<n;i++)
    {
       cin>>A[i];
    }
    cout<<"Array elements are:";
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
    return 0;
}
