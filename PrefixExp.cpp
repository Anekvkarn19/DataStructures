#include <iostream>
#include <math.h>
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
        char x=S.item[S.TOP];
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
/****************************/
int Evaluate(char ch,int x,int y)
{
    switch(ch)
    {
        case '+':
             return x+y;
        case '-':
             return x-y;
        case '*':
             return x*y;
        case '/':
             return x/y;
        case '^':
             return pow(x,y);
             
    }
    return 0;
}
    void PreFixEvaluation(char Prefix[])
    {
        int i=0;
        Initialize();
        while(Prefix[i]!='\0')
        i++;
        i=i-1;
        while(i>=0)
        {
            char symbol=Prefix[i];
            if(symbol>='0'&& symbol<='9')
              Push(symbol-'0');
            else
            {
                int x=Pop();
                int y=Pop();
                int value=Evaluate(symbol,x,y);
                Push(value);
            }
            i++;
        }
        cout<<"The answer is "<< Pop();
    }
    int main()
    {
        char Expression[40];
        cout<<"Enter prefix exp:"<<endl;
        cin>>Expression;
        PreFixEvaluation(Expression);
        return 0;


    }
