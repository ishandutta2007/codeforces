#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=4e5+1e3+7;

int n;

struct Frac{
    int a,b;
    void upd()
    {
        int g=__gcd(a,b);
        a/=g,b/=g;
    }
    void adx()
    {
        a+=b;
        upd();
    }
    void ady()
    {
        b+=a;
        upd();
    }
}x[N],y[N];

bool operator ==(Frac a,Frac b)
{
    return a.a==b.a&&a.b==b.b;
}

bool operator <(Frac a,Frac b)
{
    return a.a<b.a||(a.a==b.a&&a.b<b.b);
}

vector<int>g[N],idx[N];

typedef pair<Frac,Frac> pfc;
typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int use[N];

bool operator <(pfc a,pfc b)
{
    return a.fs<b.fs||(a.fs==b.fs&&a.sd<b.sd);
}

map<pfc,int>id;

vector<pii>ans;

int dfn[N],dc;

void dfs(int x,int f)
{
    dfn[x]=++dc;
    int cand=-1;
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(v==f)
            continue;
        if(!dfn[v])
        {
            dfs(v,x);
            if(!use[idx[x][i]])
            {
                if(cand==-1)
                    cand=idx[x][i];
                else
                    ans.push_back(mp(cand,idx[x][i])),use[idx[x][i]]=1,cand=-1;
            }
        }
        else if(dfn[v]>dfn[x])
        {
            if(!use[idx[x][i]])
            {
                if(cand==-1)
                    cand=idx[x][i];
                else
                    ans.push_back(mp(cand,idx[x][i])),use[idx[x][i]]=1,cand=-1;
            }
        }
    }
    if(cand!=-1)
    {
        if(f==0)
            return;
        for(int i=0;i<g[f].size();i++)
            if(g[f][i]==x)
            {
                ans.push_back(mp(cand,idx[f][i]));
                use[idx[f][i]]=1;
                break;
            }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i].a>>x[i].b>>y[i].a>>y[i].b,x[i].upd(),y[i].upd();
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        pfc tmp;
        tmp.fs=x[i];
        tmp.sd=y[i];
        tmp.fs.adx();
        tmp.fs.a*=tmp.sd.b;
        tmp.fs.b*=tmp.sd.a;
        tmp.sd.a=tmp.sd.b=0;
        tmp.fs.upd();
        if(id.find(tmp)==id.end())
            id[tmp]=++cnt;
        u=id[tmp];
        tmp.fs=x[i];
        tmp.sd=y[i];
        tmp.sd.adx();
        tmp.fs.a*=tmp.sd.b;
        tmp.fs.b*=tmp.sd.a;
        tmp.sd.a=tmp.sd.b=0;
        tmp.fs.upd();
        if(id.find(tmp)==id.end())
            id[tmp]=++cnt;
        v=id[tmp];
        // printf("%lld %lld\n",u,v);
        // if(i==1||i==6)
        // {
        //     printf("%lld %lld\n",tmp.fs.a,tmp.fs.b);
        //     printf("%lld %lld\n",tmp.sd.a,tmp.sd.b);
        // }
        g[u].push_back(v);
        idx[u].push_back(i);
        g[v].push_back(u);
        idx[v].push_back(i);
    }
    for(int i=1;i<=cnt;i++)
        if(!dfn[i])
            dfs(i,0);
    printf("%d\n",ans.size());
    for(auto [x,y]:ans)
        printf("%lld %lld\n",x,y);
}