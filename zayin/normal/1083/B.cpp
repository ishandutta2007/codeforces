#include<bits/stdc++.h>
#define maxn 500050
using namespace std;
typedef long long LL;

int n,len;
char s[maxn],t[maxn];

void init()
{
    scanf("%d%d%s%s",&len,&n,s+1,t+1);
}

LL dp[maxn]={1};

void solve()
{
    bool flag=0;
    LL ans=0;
    for (int i=1;i<=len;++i)
    {
        LL c=dp[i-1]<<1;
        if (s[i]=='b')  --c;
        if (t[i]=='a')  --c;
        if (flag||c>=n)
            flag=1,dp[i]=n;
        else
            dp[i]=c;
        
        ans+=dp[i];
    }
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}