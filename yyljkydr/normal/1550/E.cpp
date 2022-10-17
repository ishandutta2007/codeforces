#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,K=18;

int n,k,c[N][K],nx[N][K],f[1<<K];

char s[N];

bool ok(int t,int l,int r)
{
    return (c[r][t]-c[l-1][t])==r-l+1;
}

bool chk(int w)
{
    for(int i=n-w+2;i<=n+1;i++)
        for(int j=0;j<k;j++)
            nx[i][j]=1e9;
    for(int i=n-w+1;i>=1;i--)
        for(int j=0;j<k;j++)
            nx[i][j]=(ok(j,i,i+w-1)?i+w:nx[i+1][j]);
    for(int S=0;S<(1<<k);S++)
        f[S]=1e9;
    f[0]=1;
    for(int S=1;S<(1<<k);S++)
        for(int i=0;i<k;i++)
            if(S&(1<<i))
            {
                if(f[S^(1<<i)]<=n)
                    f[S]=min(f[S],nx[f[S^(1<<i)]][i]);
            }
    return f[(1<<k)-1]!=1e9;
}

int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<k;j++)
            c[i][j]=(c[i-1][j]+(s[i]==j+'a'||s[i]=='?'));
    int l=0,r=n+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(chk(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%d\n",l);
}