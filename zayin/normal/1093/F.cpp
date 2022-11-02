#include<bits/stdc++.h>
#define maxm 105
#define maxn 100050
#define modu 998244353
using namespace std;
typedef long long LL;

int n,m,len;
int a[maxn];

LL Fk[maxn]={1};

int neg[maxn],L[maxn][maxm];

LL f[maxn],h[maxn];
LL g[maxn][maxm],sg[maxn][maxm];

void init()
{
    scanf("%d%d%d",&n,&m,&len);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        neg[i]=neg[i-1];
        if (!~a[i])
        {
            ++neg[i];
            memcpy(L[i],L[i-1],sizeof(L[i]));
        }
        else
        {
            fill(L[i]+1,L[i]+m+1,i);
            L[i][a[i]]=L[i-1][a[i]];
        }
    }
}

void solve()
{
    for (int i=1;i<=n;++i)
        Fk[i]=Fk[i-1]*m%modu;
    f[0]=1;
    for (int i=1;i<=n;++i)
    {
        // cout<<i<<" "<<L[i]<<endl;
        h[i]=h[i-1]*(~a[i]?1:m);
        for (int j=1;j<=m;++j)
        {
            if (i<len||L[i][j]>i-len)
                g[i][j]=0;
            else
            {
                g[i][j]=f[i-len];

                int k=max(i-len+1,L[i][j]+len);
                g[i][j]-=sg[i-1][j]-sg[k-1][j];
                g[i][j]=(g[i][j]+modu)%modu;
                // g[i]=g[i]*Fk[cnt[n]-cnt[i]];
                // cout<<"g :["<<i<<","<<j<<"] "<<f[i-len]<<" "<<sg[i-1][j]-sg[k-1][j]<<endl;
            }
            h[i]+=g[i][j];
            sg[i][j]=(sg[i-1][j]+g[i][j])%modu;
        }
        h[i]%=modu;
        f[i]=(Fk[neg[i]]-h[i]+modu)%modu;
        // printf("f[%d]=%lld\n",i,f[i]);
        // printf("h[%d]=%lld\n",i,h[i]);
        // for (int j=1;j<=m;++j)
        //     printf("g[%d][%d]=%lld\n",i,j,g[i][j]);
        // cout<<endl;
        // cout<<i<<" "<<f[i]<<" "<<h[i]<<" "<<endl<<endl;
    }
    printf("%lld\n",f[n]);
}

int main()
{
    init();
    solve();
    return 0;
}