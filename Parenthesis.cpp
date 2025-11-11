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
int main()
{
    char a[100];
    int n;
    cout<<"Enter the length of expression";
    cin>>n;
    cout<<"Enter the expression";
    for(int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    Initialize();
    int i=0,flag=0;
    while(a[i]!='\0')
    {
        if(a[i]=='(')
          Push(a[i]);
        else
           if(!IsEmpty())
              int b= Pop();
           else
            {
               flag=1;
               break;
            }
        i=i+1;
    }
    if(IsEmpty())
    {
        if (flag==1)
          cout<<"Invalid Expression";
        else
          cout<<"Valid Expresssion";
    }
    else
       cout<<"Invalid Expression";
    return 0;
}