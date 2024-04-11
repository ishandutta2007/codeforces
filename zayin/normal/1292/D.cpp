#include<bits/stdc++.h>
#define maxn 5050
using namespace std;
typedef long long LL;

int n,a[maxn];

int cnt[maxn];

bool noprime[maxn];
int val[maxn][maxn],sval[maxn][maxn];

int dis[maxn][maxn];

int mxp[maxn][maxn];

int main()  {
    scanf("%d",&n);
    for (int a,i=1;i<=n;++i)
        scanf("%d",&a),++cnt[max(a,1)];
    for (int i=2;i<maxn;++i)  
        for (int j=2;j<i;++j)
            if (i%j==0)
                noprime[i]=1;
    for (int i=2;i<maxn;++i)  {
        for (int j=2;j<=i;++j)  {
            if (noprime[j]) continue;
            for (int t=i;t;t/=j)
                val[i][j]+=t/j;
        }
        for (int j=1;j<maxn;++j)
            sval[i][j]=sval[i][j-1]+val[i][j];
        for (int j=2;j<=i;++j)
            if (!noprime[j]&&i%j==0)
                mxp[i][i]=j;
    }

    for (int i=1;i<maxn;++i)
        for (int j=i+1;j<maxn;++j)
            mxp[i][j]=max(mxp[i][j-1],mxp[j][j]);

    for (int i=1;i<maxn;++i)
        for (int j=1;j<i;++j)    {
            LL p=mxp[j+1][i];
            dis[i][j]=sval[i][p-1]+sval[j][p-1]+val[i][p]-val[j][p];
            dis[j][i]=dis[i][j];
        }

    LL ans=1LL<<60;
    for (int i=1;i<maxn;++i)    {
        LL res=0;
        for (int j=1;j<maxn;++j)    
            res+=(LL)dis[i][j]*cnt[j];
        ans=min(ans,res);    
    }

    printf("%lld\n",ans);
    
    return 0;
}