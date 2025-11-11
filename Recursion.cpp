#include <iostream>
using namespace std;
int Fibonacci(int n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else
        return Fibonacci(n-1)+Fibonacci(n-2);
}
int power(int x,int n)
{
    int a;
    if(n==0)
        return 1;
    else
        a=power(x,n/2);
        if(n%2==0)
            return a*a;
        else
            return x*a*a;
}
int factorial(int n)
{
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int digitsum(int n)
{
    if(n==0)
        return 0;
    else
        return (n%10)+digitsum(n/10);
}
int NaturalSum(int n)
{
    if(n==0)
        return 0;
    else
        return n+NaturalSum(n-1);
}
char palindrome (char str[],int i,int j)
{
    if(i>=j)
        return true;
    if(str[i]!=str[j])
        return false;
    if(str[i]==str[j])
        return palindrome(str,i+1,j-1);
}

int main()
{
    cout<<"Menu\n1.Fibonacci\n2.Power\n3.Factorial\n4.GCD\n5.Digit Sum\n6.Natural Sum\n7.Palindrome\n";
    int ch;
    cout<<"Enter your choice:";
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            int n;
            cout<<"Enter number of terms:";
            cin>>n;
            cout<<"Fibonacci series is:"<<endl;
            for(int i=1;i<=n;i++)
            {
                cout<<Fibonacci(i)<<" ";
            }
            break;
        }
        case 2:
        {
            int x,n;
            cout<<"Enter base and exponent:";
            cin>>x>>n;
            cout<<x<<" raised to "<<n<<" is "<<power(x,n);
            break;
        }
        case 3:
        {
            int n;
            cout<<"Enter number:";
            cin>>n;
            cout<<"Factorial of "<<n<<" is "<<factorial(n);
            break;
        }
        case 4:
        {
            int a,b;
            cout<<"Enter two numbers:";
            cin>>a>>b;
            cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a,b);
            break;
        }
        case 5:
        {
            int n;
            cout<<"Enter number:";
            cin>>n;
            cout<<"Digit sum of "<<n<<" is "<<digitsum(n);
            break;
        }
        case 6:
        {
            int n;
            cout<<"Enter number:";
            cin>>n;
            cout<<"Natural sum up to "<<n<<" is "<<NaturalSum(n);
            break;
        }
        case 7:
        {
            char str[20];
            cout<<"Enter string:";
            cin>>str;
            int len=0;
            while(str[len]!='\0')
                len++;
            if(palindrome(str,0,len-1))
                cout<<"String is palindrome";
            else
                cout<<"String is not palindrome";
            break;
        }
    }
    
    return 0;
}
