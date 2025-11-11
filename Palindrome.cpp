#include <iostream>
using namespace std;
#define SS 100;
struct stk
{
    int item [100];
    int TOP;
};
struct stk S;
void Initialize()
{
    S.TOP=-1;
}
/********************************/
bool IsEmpty()
{
    if(S.TOP==-1)
        return true;
    else
        return false;
}
/********************************/
int Pop()
{
    if(IsEmpty())
    {
        cout<<"Stack Underflows";
        exit(1);
    }
    else
    {
        int x=S.item[S.TOP];
        S.TOP--;
        return x;
    }
}
/********************************/
void Push(int x)
{
    if(S.TOP==(99))
    {
        cout<<"Stack Overflows";
        exit(1);
    }
    else
    {
        S.TOP=S.TOP+1;
        S.item[S.TOP]=x;
    }
}
/********************************/
int StackTop()
{
    return S.item[S.TOP];
}
/********************************/
bool isPalindrome(int n)
{
    int m=n;
    while(n>0)
    {
        int d=n%10;
        Push(d);
        n=n/10;
    }
    while(m>0)
    {
        int d=m%10;
        
        if(StackTop()!=d)
        {
           return false;
        }
        int s=Pop();
        m=m/10;
    }
    return true;
}
int main()
{
    Initialize();
    int n;
    cout<<"Enter the number";
    cin>>n;
    if(isPalindrome(n))
    {
        cout<<"The number is palindrome";
    }
    else
    {
        cout<<"The number is not palindrome";
    }
    return 0;
}