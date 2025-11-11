//Repeated odd number of times
#include <iostream>
#include <vector> 
using namespace std;
int main()
{
    int n,max=0;
    cout<<"Enter the number of elements";
    cin>>n;
    vector<int>A(n);
    cout<<"Enter the elements";
    for(int i=0;i<n;i++)
    {
       cin>>A[i];
       if(A[i]>max)
        max=A[i];
    }
    
    vector<int>DAT(max+1);
    
    for(int k=0;k<n;k++)
    {
        DAT[A[k]]++;
    }
    
    for(int k=1;k<=max;k++)
    {
        if(DAT[k]%2!=0)
         cout<<(k);
    }
    return 0;
}