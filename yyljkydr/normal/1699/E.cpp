#include<bits/stdc++.h>
using namespace std;

const int N=5e6+1e3+7;

int T;

int n,m,a[N];

int cnt[N],dp[N],vis[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
            dp[i]=i;
        int mn=m;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),cnt[a[i]]++,vis[a[i]]++,mn=min(mn,a[i]);
        int mx=m;
        int ans=1e9;
        for(int i=m;i>=1;i--)
        {
            for(long long j=1ll*i*i;j<=m;j+=i)
            {
                cnt[dp[j]]-=vis[j];
                dp[j]=min(dp[j],dp[j/i]);
                cnt[dp[j]]+=vis[j];
            }
            while(!cnt[mx])
                mx--;
            if(i<=mn)
                ans=min(ans,mx-i);
        }
        printf("%d\n",ans);
        for(int i=1;i<=m;i++)
            cnt[i]=0,vis[i]=0;
    }
}