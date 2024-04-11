#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7,P=998244353;

int n,m;

int f[51][N],g[N],l[51],r[51];

int get(int i,int j)
{
    return j<0?0:f[i][j];
}

signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&l[i],&r[i]);
    for(int d=m;d>=1;d--)
    {
        int t=m/d;
        for(int j=0;j<=t;j++)
            f[0][j]=1;
        for(int j=1;j<=n;j++)
        {
            int L=(l[j]+d-1)/d,R=r[j]/d;
            for(int k=0;k<=t;k++)
                f[j][k]=(f[j][k-1]+get(j-1,k-L)-get(j-1,k-R-1)+P)%P;
        }
        g[d]=f[n][t];
        for(int j=2;j<=t;j++)
            g[d]=(g[d]-g[j*d]+P)%P;
    }
    printf("%lld\n",g[1]);
}