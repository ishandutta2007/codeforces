#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,m;

struct EDG{
    int u,v,w;
}e[N];

int fa[N];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

void merge(int u,int v,int p)
{
    int iu=u*2-2,iv=v*2-2;
    fa[find(iu)]=find(iv^p);
    fa[find(iu^1)]=find(iv^p^1);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<n;i++)
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        for(int i=0;i<n*2;i++)
            fa[i]=i;
        for(int i=1;i<n;i++)
            if(e[i].w!=-1)
                merge(e[i].u,e[i].v,__builtin_popcount(e[i].w)&1);
        for(int i=1;i<=m;i++)
        {
            int u,v,w; 
            scanf("%d%d%d",&u,&v,&w);
            merge(u,v,w);
        }
        bool ok=1;
        for(int i=1;i<=n;i++)
            if(find(i*2-2)==find(i*2-1))
                ok=0;
        if(!ok)
            puts("NO");
        else
        {
            puts("YES");
            for(int i=1;i<n;i++)
                if(e[i].w!=-1)
                    printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
                else
                {
                    int iu=find(e[i].u*2-2),iv=find(e[i].v*2-2);
                    int ae=-1;
                    if(find(iu)==find(iv))
                        ae=0;
                    else if(find(iu)==find(iv^1))
                        ae=1;
                    else
                        ae=0,merge(e[i].u,e[i].v,0);
                    printf("%d %d %d\n",e[i].u,e[i].v,ae);
                }
        }
    }
}