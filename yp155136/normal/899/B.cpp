#include <iostream>
#include <cstdio>
using namespace std;

int _[84] = {31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,
31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,
31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,
31,28,31,30,31,30,31,31,30,31,30,31
};

int a[24];

int main ()
{
    int n;
    cin >> n;
    for (int i=0;n>i;i++)
    {
        cin >> a[i];
    }
    for (int i=0;84>i;i++)
    {
        if (i+n > 84) break;
        bool can=true;
        for (int j=0;n>j;j++)
        {
            if (a[j] != _[i+j]) can=false;
        }
        if (can)
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}