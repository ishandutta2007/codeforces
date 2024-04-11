#include<bits/stdc++.h>
#define maxc 26
#define maxn 200050
using namespace std;
typedef long long LL;

int n,m,len;

char s[maxn];

int a[maxc];

int dp[maxn];

void init()
{
    memset(a,0,sizeof(a));
    scanf("%d%d%d%s",&n,&m,&len,s);
    for (int i=0;i<len;++i)
        ++a[s[i]-'A'];
    if (n>m)    swap(n,m);
}

LL ans;

void calc(int vn,int vm,int c)
{
    if (vn+c<n) return ;
    //cout<<vn<<" "<<vm<<" "<<c<<endl;
    if (vm>=m)
        ans=0;
    else
        ans=min(ans,1LL*(n-vn)*(m-vm));
}

void solve()
{
    ans=1LL<<60;
    for (int k=0;k<maxc;++k)
    {
//        memset(dp,0,sizeof(dp));
        for (int j=0;j<=n;++j)
            dp[j]=0;
        for (int i=0;i<maxc;++i)
            if (i!=k)
                for (int j=n;j>=a[i];--j)
                    dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
                    
        for (int j=0;j<=n;++j)
            calc(dp[j],len-a[k]-dp[j],a[k]);
    }
    printf("%lld\n",ans);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        init();
        solve();
    }
    return 0;
}