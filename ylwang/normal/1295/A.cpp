#include<bits/stdc++.h>
using namespace std;
int n,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n&1)
        {
            putchar('7');
            n-=3;
        }
        while(n)
        {
            putchar('1');
            n-=2;
        }
        putchar(10);
    }
    return 0;
}