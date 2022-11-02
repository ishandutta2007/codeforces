#include<bits/stdc++.h>
#define maxn 200050
#define modu 998244353
using namespace std;
typedef long long LL;

int n;
vector<int> G[maxn];

LL F[maxn]={1};

void init() {
    scanf("%d",&n);
    for (int k=1;k<n;++k)   {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

LL dp[maxn];

void dfs(int i,int fa=0) {
    dp[i]=1;
    int part=2;
    for (int j:G[i])    {
        if (fa==j)  continue;
        dfs(j,i);
        dp[i]=dp[i]*part%modu*dp[j]%modu;
        ++part;
    }
    // if (G[i].size()==1)
    //     dp[i]=dp[i]*(G[G[i].front()].size()+1);

    // cout<<i<<" "<<dp[i]<<endl;
}

void solve()    {
    for (int i=1;i<=n;++i)  F[i]=F[i-1]*i%modu;
    int rt;
    for (rt=1;rt<=n;++rt)
        if (G[rt].size()==1)
            break;
    int k=G[rt].front();
    dfs(k,rt);
    printf("%lld\n",dp[k]*n%modu);
}

int main()  {
    init();
    solve();
    return 0;
}