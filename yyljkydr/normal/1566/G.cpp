#include<bits/stdc++.h>
using namespace std;

const int N=4e6+1e3+7;

int n,m,q;

multiset<long long>tri;

set<pair<int,int> >e[N];

map<pair<int,int>, int>W;

struct E{
    int u,v,w;
};

bool operator <(const E &a,const E &b)
{
    if(a.w!=b.w)
        return a.w<b.w;
    if(a.u!=b.u)
        return a.u<b.u;
    return a.v<b.v;
}

set<E>edge;

void ct(int x,int v)
{
    auto it=e[x].begin();
    for(int i=0;i<3&&it!=e[x].end();i++)
    {
        int u=x,y=it->second;
        auto itj=e[y].begin();
        bool ok=v==-1||e[y].size()<3||next(e[y].begin(),2)->first>=it->first;
        if(!ok)
        {
            it++;
            continue;
        }
        if(u>y)
            swap(u,y);
        if(v==1)
            edge.insert({u,y,it->first});
        else
            edge.erase({u,y,it->first});
        it++;
    }
}

void ins(int u,int v,int w)
{
    ct(u,-1);
    ct(v,-1);
    e[u].insert({w,v});
    e[v].insert({w,u});
    ct(u,1);
    ct(v,1);
    W[{u,v}]=w;
}

void del(int u,int v,int w)
{
    ct(u,-1);
    ct(v,-1);
    e[u].erase({w,v});
    e[v].erase({w,u});
    ct(u,1);
    ct(v,1);
    W.erase({u,v});
}

long long calc()
{
    long long ret=1e18;
    ret=min(ret,1ll*edge.begin()->w+next(edge.begin(),1)->w+next(edge.begin(),2)->w);
    auto it=edge.begin();
    int t=10;
    for(int i=0;i<t&&it!=edge.end();i++,it++)
    {
        auto itj=it;
        itj++;
        for(int j=0;j<t&&itj!=edge.end();j++,itj++)
        {
            if(it->u==itj->u||it->v==itj->v||it->u==itj->v||it->v==itj->u)
                continue;
            ret=min(ret,1ll*it->w+itj->w);
        }
    }
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u>v)
            swap(u,v);
        ins(u,v,w);
    }
    printf("%lld\n",calc());
    scanf("%d",&q);
    while(q--)
    {
        int op,u,v,w;
        scanf("%d",&op);
        if(!op)
        {
            scanf("%d%d",&u,&v);
            if(u>v)
                swap(u,v);
            int w=W[{u,v}];
            del(u,v,w);
        }
        else
        {
            scanf("%d%d%d",&u,&v,&w);
            if(u>v)
                swap(u,v);
            ins(u,v,w);
        }
        printf("%lld\n",calc());
    }
}