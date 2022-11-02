#include<bits/stdc++.h>
#define maxm 205
#define maxn 100050
#define modu 1000000007
using namespace std;
typedef long long LL;

int n,m;
vector<int> G[maxn];

void init()
{
    scanf("%d%d",&n,&m);
    for (int k=1;k<n;++k)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int sz[maxn];

LL F[maxn]={1},pw[maxn]={1};
LL dp[maxn][maxm],S[maxm][maxm];

LL res[maxm];

LL add(LL &x,LL y)  {
    x=(x+y)%modu;
}

void dfs(int i,int fa=0)
{
    dp[i][0]=2,sz[i]=1;
    for (int j:G[i])
    {
        if (fa==j)  continue;
        dfs(j,i);
        for (int c=min(sz[i],m);~c;--c)
        {
            for (int k=1;k<=min(sz[j],m)&&c+k<=m;++k)
            {
                LL t=dp[i][c]*dp[j][k]%modu;
                if (c) //cout<<"1_add:"<<c+k<<"("<<j<<") "<<t<<endl,
                    add(res[c+k],t*pw[n-sz[i]-sz[j]]);
                // cout<<"change:"<<i<<" "<<c<<"+"<<k<<" "<<dp[i][c]<<"*"<<dp[j][k]<<"="<<t<<endl;
                add(dp[i][c+k],t);
            }
            dp[i][c]=dp[i][c]*pw[sz[j]]%modu;
        }
        sz[i]+=sz[j];
    // cout<<"pro:"<<i<<"("<<j<<"):";
    // for (int k=0;k<=m;++k)  cout<<dp[i][k]<<" "; cout<<endl;
    }

    // cout<<"pre:"<<i<<":";
    // for (int k=0;k<=m;++k)  cout<<dp[i][k]<<" "; cout<<endl;
    for (int k=min(sz[i],m)-1;~k;--k)
    {
        LL t=k?dp[i][k]:(pw[sz[i]]-1);
        // cout<<"2_add:"<<k+1<<" "<<t*(pw[n-sz[i]]-1)<<endl;
        add(dp[i][k+1],t);
        if (fa)
            add(res[k+1],t*(pw[n-sz[i]]-1));
    }
    // cout<<"lst:"<<i<<":";
    // for (int k=0;k<=m;++k)  cout<<dp[i][k]<<" "; cout<<endl;
    // cout<<endl;
}

void solve()
{
    for (int i=1;i<=n;++i)  F[i]=F[i-1]*i%modu,pw[i]=pw[i-1]*2LL%modu;
    dfs(1);
    for (int i=0;i<=m;++i)  {
        S[i][0]=(i==0);
        for (int j=1;j<=i;++j)
            S[i][j]=(S[i-1][j-1]+S[i-1][j]*j)%modu;
        // for (int j=0;j<=i;++j)
        //     cout<<S[i][j]<<" ";
        // cout<<endl;
    }

    LL ans=0;
    // for (int i=0;i<=m;++i)  cout<<res[i]<<" "; cout<<endl;
    for (int i=0;i<=m;++i)
        add(ans,S[m][i]*F[i]%modu*res[i]);
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}