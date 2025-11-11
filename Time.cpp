#include <iostream>
using namespace std;
struct Time
{
    int hour;
    int min;
    int sec;
};
int main()
{
    struct Time T1={10,55,67};
    struct Time T2={10,55,67};
    struct Time T3;
    T3.sec=T1.sec+T2.sec;
    T3.min=T1.min+T2.min+T3.sec/60;
    T3.hour=T1.hour+T2.hour+T3.min/60;
    T3.sec=(T3.sec)%60;
    T3.min=(T3.min)%60;
    cout<<T3.hour<<" "<<T3.min<<" "<<T3.sec;
    return 0;
}