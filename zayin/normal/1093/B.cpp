#include<bits/stdc++.h>
#define maxn 1050
using namespace std;
typedef long long LL;

char s[maxn];

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        n=strlen(s);
        sort(s,s+n);
        if (s[0]==s[n-1])
            printf("-1\n");
        else
            printf("%s\n",s);
    }
    return 0;
}