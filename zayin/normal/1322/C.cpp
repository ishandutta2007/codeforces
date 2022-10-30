#include<bits/stdc++.h>
#define maxn 500050
#define modu 998244353
using namespace std;
typedef long long LL;

map<LL,LL> sum;

int n;

bool vis[maxn];
LL a[maxn],h[maxn];

LL pw[maxn];

LL gcd(LL a,LL b)   {
    return !b?a:gcd(b,a%b);
}

int main()  {
    for (int i=pw[0]=1;i<maxn;++i) pw[i]=pw[i-1]*2%modu;
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;++i) scanf("%lld",a+i),h[i]=0,vis[i]=0;
        while (m--) {
            int u,v;
            scanf("%d%d",&u,&v);
            --u,--v;
            vis[v]=1;
            h[v]=(h[v]+pw[u])%modu;
        }
        sum.clear();
        for (int i=0;i<n;++i)
            if (vis[i])
                // cout<<i<<":"<<h[i]<<" "<<a[i]<<endl,
                sum[h[i]]+=a[i];
        
        LL ans=0;
        for (pair<LL,LL> p:sum)
            ans=gcd(ans,p.second);
        printf("%lld\n",ans);
    }
    return 0;
}