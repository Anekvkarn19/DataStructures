#include <iostream>
#include <cmath>
using namespace std;
int digit(int n)
 {
    int count=0;
    while(n>0)
    {
        n=n/10;
        count++;
    }
    return count;
}
int divisionHash(int key, int tableSize)
 {
    return key % tableSize;
}
int MidSquareHash(int key, int tableSize)
 {
    int m=digit(tableSize-1);
    double M=pow(10,m);
    double y=key*key;
    int n=digit(key);
    int x=(2*n-m)/2;
    double d=pow(10,x);
    y=y/d;
    double L=y%M;
    return L;
}
int main()
{
    int key, tableSize;
    cout << "Enter the key to be hashed: ";
    cin >> key;
    cout << "Enter the hash table size: ";
    cin >> tableSize;

    int divisionIndex = divisionHash(key, tableSize);
    cout << "Division Method Hash Index: " << divisionIndex << "\n";

    int midSquareIndex = MidSquareHash(key, tableSize);
    cout << "Mid-Square Method Hash Index: " << midSquareIndex << "\n";

    return 0;
}
