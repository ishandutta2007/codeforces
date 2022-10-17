#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n,m;

int u[N],v[N],w[N];

int fa[31][N],key[31][N];

int find(int *fa,int x)
{
    return x==fa[x]?x:fa[x]=find(fa,fa[x]);
}

int main()
{
    // scanf("%d",&T);
    T=1;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<30;i++)
            for(int j=1;j<=n;j++)
                fa[i][j]=j,key[i][j]=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
            for(int j=0;j<30;j++)
                key[j][u[i]]|=(w[i]%2==0),key[j][v[i]]|=(w[i]%2==0);
        }
        for(int i=0;i<30;i++)
            for(int j=1;j<=m;j++)
            {
                if(!((w[j]>>i)&1))
                    continue;
                int fu=find(fa[i],u[j]),fv=find(fa[i],v[j]);
                fa[i][fv]=fu;
                key[i][fu]|=key[i][fv];
            }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            int ans=2;
            for(int i=1;i<30;i++)
            {
                int fu=find(fa[i],u);
                if(key[i][fu])
                    ans=1;
            }
            for(int i=0;i<30;i++)
            {
                int fu=find(fa[i],u),fv=find(fa[i],v);
                if(fu==fv)
                    ans=0;
            }
            printf("%d\n",ans);
        }
    }
}