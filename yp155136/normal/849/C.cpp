#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100006;

LL dp[N];

int main ()
{
    int k;
    scanf("%d",&k);
    if (k==0)
    {
        puts("abcdefghijklmnopqrstuvwxyz");
        return 0;
    }
    else if (k==1)
    {
        puts("aabcdefghijklmnopqrstuvwxyz");
        return 0;
    }
    dp[0] = dp[1] = 0;
    int i;
    for (i=2;N>i;i++)
    {
        dp[i] = dp[i/2] + dp[i-i/2] + (i/2)*1LL*(i-i/2);
        if (dp[i] > k) break;
    }
    --i;
    char now='a';
    while (k)
    {
        while (k >= dp[i])
        {
            int cnt=i;
            while (cnt--) putchar(now);
            now++;
            k -= dp[i];
        }
        --i;
    }
    puts("");
}