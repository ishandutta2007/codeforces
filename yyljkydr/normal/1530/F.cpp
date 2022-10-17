#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=23,P=31607;

int n,p[N][N],iv[N][N];

int f[1<<N],g[4][1<<N];

int r[1<<21],to[1<<21];

namespace FWT{
    int n;
    void fwt(int *a,int n)
    {
        for(int i=1;i<n;i<<=1)
            for(int p=i<<1,j=0;j<n;j+=p)
                for(int k=0;k<i;++k)
                    a[i+j+k]+=a[j+k];
        //for(int i=0;i<n;i++)
        //    a[i]=(a[i]%P+P)%P;
    }

    void ifwt(int *a)
    {
        for(int i=1;i<n;i<<=1)
            for(int p=i<<1,j=0;j<n;j+=p)
                for(int k=0;k<i;++k)
                    a[i+j+k]-=a[j+k];
        //for(int i=0;i<n;i++)
        //    a[i]=(a[i]%P+P)%P;
    }

    void conv(int m)
    {
        //fwt(f,1);
        fwt(g[0],m);
        fwt(g[1],m);
        fwt(g[2],m);
        fwt(g[3],m);
        for(int i=0;i<n;i++)
        {
            int t=g[0][i>>2];
            if(i&1)
                t+=g[1][i>>2];
            if(i&2)
                t+=g[2][i>>2];
            if((i&3)==3)
                t+=g[3][i>>2];
            t%=P;
            f[i]=f[i]*t%P;
        }
        //fwt(f,-1);
    }
}

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%P;
        b>>=1;
        a=a*a%P;
    }
    return ret;
}

int tmp[4];

signed main()
{
    scanf("%lld",&n);
    //n=21;
    FWT::n=(1<<(n+2));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lld",&p[i][j]),iv[i][j]=qpow(p[i][j],P-2);
            
    for(int i=0;i<n;i++)
        to[1<<i]=i;
    //f[0]=1;
    //FWT::fwt(f,1);
    for(int i=0;i<FWT::n;i++)
        f[i]=1;
    for(int i=0;i<n;i++)
    {
        for(int S=0;S<1<<n;S++)
            g[0][S]=g[1][S]=g[2][S]=g[3][S]=0;
        r[0]=1;
        for(int j=0;j<n;j++)
            r[0]=r[0]*p[i][j]%P;
        for(int S=1;S<(1<<n);S++)
        {
            r[S]=r[S^(S&-S)]*(10000-p[i][to[S&-S]])*iv[i][to[S&-S]]%P;
            //for(int j=0;j<n;j++)
            //    r=r*((S&(1<<j))?10000-p[i][j]:p[i][j]);
            //printf("%d %d\n",S,(S<<2)+(S>>i&1)+(S>>(n-i-1)&1)*2);
            int id=(S>>i&1)+(S>>(n-i-1)&1)*2;
            g[id][S]=r[S];
        }
        FWT::conv(1<<n);
        //FWT::ifwt(f);
    }
    FWT::ifwt(f);
    printf("%lld\n",(1-f[FWT::n-1]*qpow(qpow(10000,P-2),n*n)%P+P)%P);
}