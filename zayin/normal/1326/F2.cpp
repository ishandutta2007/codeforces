#include<bits/stdc++.h>
#define maxn 20
#define maxs (1<<maxn)
using namespace std;
typedef long long LL;

int n;
int mp[maxn][maxn];

LL dp[maxn][maxs],g[maxn][maxs];

vector<int> link;
map<vector<int>,vector<int> > decom;

LL f[maxs],d[maxs];

LL backup[maxn][maxs];

void dfs(int sum,int i)   {
    if (sum==n)   {
        LL ans=0,all=(1<<n)-1;

        for (int s=0;s<(1<<n);++s)
            if (__builtin_popcount(s^all)&1)
                ans-=d[s];
            else
                ans+=d[s];
        
        for (int s:decom[link])
            f[s]+=ans;

    } else  {
        for (int s=0;s<(1<<n);++s)
            backup[sum][s]=d[s];
        for (;sum+i<=n;++i)   {
            if (sum+i!=n&&sum+i+i>n) continue;
            link.push_back(i);

            for (int s=0;s<(1<<n);++s)
                d[s]*=g[i][s];

            dfs(sum+i,i);

            for (int s=0;s<(1<<n);++s)
                d[s]=backup[sum][s];

            link.pop_back();
        }
    }
}

int main()  {
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        for (int x,j=0;j<n;++j)
            scanf("%1d",mp[i]+j);
    
    for (int i=0;i<n;++i)
        dp[i][1<<i]=1;
    for (int s=1;s<(1<<n);++s)  {
        if (__builtin_popcount(s)<=1) continue;
        for (int i=0;i<n;++i)
            if (s>>i&1)
                for (int j=0;j<n;++j)
                    if ((s>>j&1)&&mp[i][j])
                        dp[i][s]+=dp[j][s^1<<i];
    }

    for (int s=0;s<(1<<n);++s)  {
        for (int i=0;i<n;++i)
            g[__builtin_popcount(s)][s]+=dp[i][s];
    }

    for (int d=0;d<n;++d)   {
        for (int i=0;i<n;++i)
            for (int s=0;s<(1<<n);++s)
                if (s>>i&1)
                    g[d][s]+=g[d][s^1<<i];
    }

    for (int s=0;s<(1<<n-1);++s)    {
        vector<int> link;
        for (int i=0,j=0;i<n;i=j+1)   {
            for (j=i;j<n-1&&(s>>j&1);) ++j;
            link.push_back(j-i+1);
        }
        sort(link.begin(),link.end());
        decom[link].push_back(s);
    }

    for (int s=0;s<(1<<n);++s) d[s]=1;
    dfs(0,1);

    for (int i=0;i<(n-1);++i)
        for (int s=0;s<(1<<n-1);++s)
            if (~s>>i&1)
                f[s]-=f[s^1<<i];
    
    for (int s=0;s<(1<<n-1);++s)
        printf("%lld ",f[s]);

    return 0;
}