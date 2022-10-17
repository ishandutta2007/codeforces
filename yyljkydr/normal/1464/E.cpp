#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7,P=998244353;

ll qpow(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%P;
        b>>=1;
        a=a*a%P;
    }
    return ret;
}

int n,m;

vector<int>g[N];

int cnt[530],sg[N],vis[N];

int dfs(int x)
{
    if(vis[x])
        return sg[x];
    vis[x]=1;
    unordered_set<int>s;
    for(auto v:g[x])
        s.insert(dfs(v));
    for(int i=0;i<=511;i++)
        if(s.find(i)==s.end())
        {
            sg[x]=i;
            break;
        }
    return sg[x];
}

ll a[531][531];

void gauss()
{
    int n=511;
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ll f=a[j][i]*qpow(a[i][i],P-2)%P;
            for(int k=i;k<=n+1;k++)
                a[j][k]=(a[j][k]-a[i][k]*f%P+P)%P;
        }
    }
    for(int i=n-1;i>=0;i--)
        for(int j=n;j>i;j--)
            a[i][n+1]=(a[i][n+1]-a[i][j]*qpow(a[j][j],P-2)%P*a[j][n+1]%P+P)%P;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
    int mx=0;
    for(int i=1;i<=n;i++)
        cnt[dfs(i)]++;
    ll ivn=qpow(n+1,P-2);
    for(int i=0;i<512;i++)
    {
        a[i][512]=(i!=0)*ivn;
        for(int j=0;j<512;j++)
            a[i][j]=((i==j)-cnt[i^j]*ivn%P+P)%P;
    }
    gauss();
    printf("%lld\n",a[0][512]*qpow(a[0][0],P-2)%P);
}