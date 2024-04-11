#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int arr[] = {4,7,44,47,74,77,444,447,474,744,747,774,477,777};
    for (int i:arr)
    {
        if (n%i==0)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}