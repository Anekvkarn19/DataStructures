#include <iostream>
using namespace std;
struct stk
{
    int item[100];
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
    if(S.TOP==99)
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
void DecimalToBinary(int N)
{
    Initialize();
    while(N!=0)
    {
        int r=N%2;
        Push(r);
        N=N/2;
     }
     while(!IsEmpty())
     {
        int x=Pop();
        cout<<x;
     }
}
/********************************/
void DecimalToOctal(int N)
{
    Initialize();
    while(N!=0)
    {
        int r=N%8;
        Push(r);
        N=N/8;
     }
     while(!IsEmpty())
     {
        int x=Pop();
        cout<<x;
     }
}
/********************************/
void DecimalToHexaDecimal(int N)
{
    char DAT[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    Initialize();
    while(N!=0)
    {
        int r=N%16;
        Push(r);
        N=N/16;
     }
     while(!IsEmpty())
     {
        int x=Pop();
        cout<<DAT[x];
     }
}
/********************************/
void DecimalToAnyBase(int N,int x)
{
    char DAT[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    Initialize();
    while(N!=0)
    {
        int r=N%x;
        Push(r);
        N=N/x;
     }
     while(!IsEmpty())
     {
        int y=Pop();
        cout<<DAT[y];
     }
}
/********************************/
int main()
{
   int N;
   cout<<"Enter the Decimal Number";
   cin>>N;
   DecimalToBinary(N);
   cout<<"\n";
   DecimalToAnyBase(N,8);
   cout<<"\n";
   DecimalToAnyBase(N,2);
   cout<<"\n";
   DecimalToAnyBase(N,16);
   cout<<"\n";
    return 0;
}