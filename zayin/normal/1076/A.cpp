#include<bits/stdc++.h>
#define maxn 200050
using namespace std;

int n,i;
char s[maxn];

int main()
{
    scanf("%d%s",&n,s+1);
    for (i=1;i<n;++i)
    {
        if (s[i]<=s[i+1])
            putchar(s[i]);
        else
        {
            putchar(s[++i]);
            break;
        }
    }

    for (++i;i<=n;++i)
        putchar(s[i]);
    return 0;
}