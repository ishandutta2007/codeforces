#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e6+1e3+7;

signed m,k,n;

int S,T;

int cnt=1,head[20001],a[N];

struct Edge{
    signed ne,to,f;
    int w;
}edg[40001];

void build(int u,int v,int w,int f)
{
    ++cnt;
    edg[cnt].to=v;
    edg[cnt].ne=head[u];
    edg[cnt].f=f;
    edg[cnt].w=w;
    head[u]=cnt;
    ++cnt;
    edg[cnt].to=u;
    edg[cnt].ne=head[v];
    edg[cnt].f=-f;
    edg[cnt].w=0;
    head[v]=cnt;
}

queue<int>q;

int d[20001],pre[20001];

bool inq[20001];

bool spfa()
{
    fill(d+S,d+T+1,-1e18);
    d[S]=0;
    q.push(S);
    inq[S]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        inq[x]=0;
        for(int tmp=head[x];tmp;tmp=edg[tmp].ne)
        {
            int v=edg[tmp].to;
            if(edg[tmp].w&&d[v]<d[x]+edg[tmp].f)
            {
                d[v]=d[x]+edg[tmp].f;
                pre[v]=tmp;
                if(!inq[v])
                    q.push(v),inq[v]=1;
            }
        }
    }
    return d[T]!=-1e18;
}

int cost,flow;

void mcmf()
{
    int mn=1e18;
    for(int x=T;x!=S;x=edg[pre[x]^1].to)
        mn=min(mn,edg[pre[x]].w);
    flow+=mn;
    for(int x=T;x!=S;x=edg[pre[x]^1].to)
        edg[pre[x]^1].w+=mn,edg[pre[x]].w-=mn,cost+=mn*edg[pre[x]].f;
}

struct Cand{
    signed x,y;
    int w;
};

bool operator <(const Cand &a,const Cand &b)
{
    if(a.w!=b.w)
        return a.w<b.w;
    return pair<int,int>{a.x,a.y}<pair<int,int>{b.x,b.y};
}

vector<Cand>can;

int lid[N],rid[N],cl,cr;

signed main()
{
    scanf("%d%d",&m,&k);
    n=(1<<m);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    int lim=(2*m-1)*k+1;
    for(signed i=0;i<n;i++)
        if(__builtin_popcount(i)%2==0)
            for(signed j=0;j<m;j++)
                can.push_back({i,i^(1<<j),a[i]+a[i^(1<<j)]});
    lim=min(lim,(int)can.size());
    S=0,T=lim*2+2;
    build(S,1,k,0);
    nth_element(can.begin(),can.begin()+can.size()-lim,can.end());
    for(int i=1;i<=lim;i++)
    {
        auto c=can[can.size()-i];
        if(!lid[c.x])
        {
            lid[c.x]=++cl;
            build(1,cl+1,1,0);
        }
        if(!rid[c.y])
        {
            rid[c.y]=++cr;
            build(cr+lim+1,T,1,0);
        }
        build(lid[c.x]+1,rid[c.y]+lim+1,1,c.w);
    }
    while(spfa())
        mcmf();
    printf("%lld\n",cost);
}