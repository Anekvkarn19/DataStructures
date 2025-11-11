#include <iostream>
using namespace std;
struct Distance
{
    int km;
    int m;
};

int main()
{
   Distance D1= {25,490};
   Distance D2= {50,567};
   Distance D3;
   D3.m=D1.m+D2.m;
   D3.km=D1.km+D2.km+D3.m/1000;
   D3.m=(D3.m)%1000;
   cout<<D3.km<<" "<<D3.m;
   return 0;
}