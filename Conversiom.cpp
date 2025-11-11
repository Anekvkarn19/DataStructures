#include <iostream>
#include <vector>
using namespace std;
struct stk
{
    char item[100];
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
void Push(char x)
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
/*********************************/
bool prcd(char op1,char op2)
{
    if(op1=='^'||op1=='*'||op1=='/'||op1=='%')
    {
       if(op2=='^')
        return false;
        else
        return true;
    }
    else if(op1=='+'||op2=='-')
      {
        if(op2=='+'||op2=='-')
          return true;
        else
          return false;
      }
}
int main()
{
    char Infix[30];
    vector<char>postfix;
    cin>>Infix;
    Initialize();
    int i=0;
    while(Infix[i]!='\0')
    {
        i++;
        char symb=Infix[i];
        if(symb>='a'&& symb<='z')
        {
            postfix.push_back(symb);
        }
        else
        {
            while(!IsEmpty()&&prcd(StackTop(),symb))
            {
              char x=Pop();
              postfix.push_back(x);
            }
            Push(symb);
        }
    }
         while(!IsEmpty())
         {
            char x=Pop();
            postfix.push_back(x);

         }
         
    
    for(int i=0;i<postfix.size();i++)
         {
            cout<<postfix[i];
            
         }
         return 0;
}