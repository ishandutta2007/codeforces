#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

struct E{
    int u,v,w;
    E(int _u=0,int _v=0,int _w=0){u=_u,v=_v,w=_w;}
};

bool cmp(E a,E b)
{
    if(a.w!=b.w)
        return a.w<b.w;
    return a.u<b.u;
}

int n;

vector<E>v;

int tot,fa[N],c[N],id[N],ansc[N],son[N];

vector<pair<int,int> >ans;

int find(int x)
{
    return x==fa[x]?x:find(fa[x]);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            E x;
            x.u=i;
            x.v=j;
            scanf("%d",&x.w);
            if(i<=j)
                v.push_back(x);
        }
    sort(v.begin(),v.end(),cmp);
    tot=n;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(auto x:v)
    {
        int fx=find(x.u),fy=find(x.v);
        if(fx==fy)
        {
            c[fx]=x.w;
            continue;
        }
        if(c[fx]<c[fy])
            swap(fx,fy);
        if(c[fx]==x.w)
        {
            if(c[fy]!=x.w)
                fa[fy]=fx;
        }
        else 
        {
            tot++;
            fa[tot]=tot;
            fa[fx]=tot,fa[fy]=tot;
            c[tot]=x.w;
        }
    }
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++)
        printf("%d ",c[i]);
    puts("");
    for(int i=1;i<=tot;i++)
        if(i==fa[i])
            printf("%d\n",i);
    for(int i=1;i<=tot;i++)
        if(i!=fa[i])
            ans.push_back(make_pair(i,fa[i]));
    for(auto [x,y]:ans)
        printf("%d %d\n",x,y);
}