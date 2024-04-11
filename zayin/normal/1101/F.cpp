#include<bits/stdc++.h>
#define maxn 405
#define maxm 250005
using namespace std;
typedef long long LL;

int n,m;

int a[maxn];

struct node
{
    int c,r;
    node(int _c,int _r) {
        c=_c,r=_r;
    }
};
vector<node> Q[maxn][maxn];
int dp[maxn][maxn];

void init()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    for (int i=1;i<=m;++i)
    {
        int s,f,c,r;
        scanf("%d%d%d%d",&s,&f,&c,&r);
        Q[s][f].push_back(node(c,r));
    }

    // cout<<"???"<<endl;
}

void solve()
{
    LL ans=0;
    for (int k=1;k<=n;++k)
    {
        memset(dp,0x3f,sizeof(dp));
        for (int j=0;j<=n;++j)
            dp[k][j]=0;
        for (int i=k+1;i<=n;++i)
        {
            dp[i][0]=a[i]-a[k];
            for (int j=1;j<=n;++j)
            {
                if (dp[k][j-1]>=a[i]-a[k])
                    dp[i][j]=dp[k][j-1];
                else
                if (dp[i-1][j-1]<=a[i]-a[i-1]) 
                    dp[i][j]=a[i]-a[i-1];
                else
                {
                    int l=k,r=i-1;
                    while (l<r)
                    {
                        int mid=(l+r+1)>>1;
                        if (a[i]-a[mid]>=dp[mid][j-1])
                            l=mid;
                        else
                            r=mid-1;
                    }

                    // cout<<k<<" "<<i<<" "<<j<<" ~ "<<l<<" "<<min(a[i]-a[l],dp[l+1][j-1])<<endl;
                    dp[i][j]=min(a[i]-a[l],dp[l+1][j-1]);
                }
            }
        }

        // for (int i=k;i<=n;++i)
        //     for (int j=0;j<=n;++j)
        //         printf("dp[%d][%d][%d]=%d\n",k,i,j,dp[i][j]);

        for (int j=k;j<=n;++j)
            for (auto p:Q[k][j])
                ans=max(ans,1LL*dp[j][p.r]*p.c);
    }
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}