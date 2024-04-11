#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,m;

int a[N][4],r[N];

char t[N];

int f[N][9],sta[N];

int ok(int A,int B)
{
    return (((A&1)+((A>>1)&1)+(B&1)+((B>>1)&1))&1)&&(m==2||((((A>>2)&1)+((A>>1)&1)+((B>>2)&1)+((B>>1)&1))&1));
}

int dis(int x,int y)
{
    return __builtin_popcount(x^y);
}

signed main()
{
    scanf("%d%d",&n,&m);
    if(n>3&&m>3)
    {
        puts("-1");
        return 0;
    }
    if(n==1||m==1)
    {
        puts("0");
        return 0;
    }
    if(m<=3)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%s",t+1);
            for(int j=1;j<=m;j++)
                a[i][j]=t[j]-'0';
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%s",t+1);
            for(int j=1;j<=m;j++)
                a[j][i]=t[j]-'0';
        }
        swap(n,m);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            r[i]=(r[i]<<1)|a[i][j];
    for(int j=1;j<=n;j++)
        for(int i=0;i<(1<<m);i++)
            f[j][i]=1e9;
    for(int j=0;j<(1<<m);j++)
        f[1][j]=dis(j,r[1]);
    for(int i=2;i<=n;i++)
        for(int S=0;S<(1<<m);S++)
            for(int T=0;T<(1<<m);T++)
                if(ok(T,S))
                    f[i][S]=min(f[i][S],f[i-1][T]+dis(S,r[i]));
    int ans=1e9;
    for(int S=0;S<(1<<m);S++)
        ans=min(ans,f[n][S]);
    printf("%d\n",ans==1e9?-1:ans);
}