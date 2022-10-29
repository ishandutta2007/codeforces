#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    int n,m;
    cin >> n>>m;
    int a[n],b[n];
    int now=0;
    for(int i=0;n>i;i++)
    {
        cin >>a[i] >> b[i];
        if (a[i]>now)
        {
            puts("NO");
            return 0;
        }
        now = max(now,b[i]);
    }
    if (now == m) puts("YES");
    else puts("NO");
}