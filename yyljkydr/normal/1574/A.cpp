#include<bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
                putchar('(');
            for(int j=1;j<=i;j++)
                putchar(')');
            for(int j=1;j<=(n-i);j++)
                putchar('(');
            for(int j=1;j<=(n-i);j++)
                putchar(')');
            puts("");
        }
    }
}