#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,m,f[N][5],vis[2][N];

struct B{
    int r,c;
}a[N];

bool cmp(B a,B b)
{
    return a.c<b.c;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<2;i++)
            for(int j=1;j<=n;j++)
                vis[i][j]=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
            scanf("%d%d",&a[i].r,&a[i].c);
        int dlt=0;
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;i++)
        {
            dlt+=(a[i].c-dlt-a[i-1].c-1)/2*2;
            a[i].c-=dlt;
            vis[a[i].r-1][a[i].c]=1;
        }
        dlt+=(n-dlt-a[m].c-1)/2*2;
        n-=dlt;
        for(int i=0;i<=n;i++)
            for(int S=0;S<4;S++)
                f[i][S]=0;
        f[0][3]=1;
        for(int i=0;i<n;i++)
            for(int S=0;S<4;S++)
                if(f[i][S])
                {
                    for(int T=0;T<4;T++)
                    {
                        bool ok=1;
                        for(int j=0;j<2;j++)
                            if(vis[j][i+1]&&!((T>>j)&1))
                                ok=0;
                        if(!ok)
                            continue;
                        for(int j=0;j<2;j++)
                            if(vis[j][i+1])
                                ok&=(S>>j)&1;
                            else
                                ok&=((S>>j)&1)^((T>>j)&1);
                        if(S==3&&T==3)
                            ok=!(vis[0][i+1]^vis[1][i+1]);
                        if(!ok)
                            continue;
                        f[i+1][T]=1;
                    }
                }
        puts(f[n][3]?"YES":"NO");
    }
}