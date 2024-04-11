#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    scanf("%d",&n);
    if (n < 6)
    {
        puts("-1");
    }
    else
    {
        puts("1 2");
        puts("1 5");
        puts("1 6");
        puts("2 3");
        puts("2 4");
        for (int i=7;n>=i;i++)
        {
            printf("2 %d\n",i);
        }
    }
    for (int i=2;n>=i;i++)
    {
        printf("1 %d\n",i);
    }
}