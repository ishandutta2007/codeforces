#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e3+1e2+7,P=1e9+7;

int n,X[N],Y[N],k,L;

struct Pt{
    int x,y,c;
}p[N];

int cnt;

struct T{
    int l,r,ls,rs;
    int sum,mn,mx,tag;
}t[N*2+1];

void add(int x,int v)
{
    t[x].mn=v;
    t[x].mx=v;
    t[x].tag=v;
    if(v==0)
        t[x].sum=0;
    else
        t[x].sum=(Y[t[x].r+1]-Y[t[x].l])*Y[v]%P;
}

void pushdown(int x)
{
    if(t[x].tag!=-1)
    {
        add(t[x].ls,t[x].tag);
        add(t[x].rs,t[x].tag);
        t[x].tag=-1;
    }
}

void update(int x)
{
    t[x].mx=max(t[t[x].ls].mx,t[t[x].rs].mx);
    t[x].mn=min(t[t[x].ls].mn,t[t[x].rs].mn);
    t[x].sum=(t[t[x].ls].sum+t[t[x].rs].sum)%P;
}

int val[N];

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    t[x].tag=-1;
    if(l==r)
    {
        add(x,val[l]);
        return x;
    }
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    update(x);
    return x;
}

void change(int x,int l,int r,int v)
{
    if(t[x].mx<=v)
        return;
    if(t[x].mn>=v&&l<=t[x].l&&t[x].r<=r)
    {
        add(x,v);
        return;
    }
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    if(l<=mid)
        change(t[x].ls,l,r,v);
    if(r>mid)
        change(t[x].rs,l,r,v);
    update(x);
}

vector<Pt>v[N];

vector<Pt>tv[N];

bool cmpy(Pt a,Pt b)
{
    return a.y<b.y;
}

int vis[N],tot;

multiset<int>ms[N];

signed main()
{
    scanf("%lld%lld%lld",&n,&k,&L);
    L++;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].c);
        p[i].x++,p[i].y++;
        X[i]=p[i].x,Y[i]=p[i].y;
    }
    sort(X+1,X+n+1);
    sort(Y+1,Y+n+1);
    X[0]=unique(X+1,X+n+1)-X-1;
    Y[0]=unique(Y+1,Y+n+1)-Y-1;
    X[X[0]+1]=L;
    Y[Y[0]+1]=L;
    for(int i=1;i<=n;i++)
        p[i].x=lower_bound(X+1,X+X[0]+1,p[i].x)-X,p[i].y=lower_bound(Y+1,Y+Y[0]+1,p[i].y)-Y,v[p[i].x].push_back(p[i]);
    for(int i=1;i<=X[0];i++)
        sort(v[i].begin(),v[i].end(),cmpy);
    int ans=0;
    for(int i=1;i<=X[0];i++)
    {
        for(int j=1;j<=Y[0];j++)
            tv[j].clear();
        for(int j=i;j<=X[0];j++)
            for(auto x:v[j])
                tv[x.y].push_back(x);
        for(int i=Y[0],j=Y[0]+1;i>=1;i--)
        {
            while(j>0&&tot<k)
            {
                j--;
                for(auto x:tv[j])
                {
                    if(!vis[x.c])
                        tot++;
                    vis[x.c]++;
                }
            }
            val[i]=j;
            for(auto x:tv[i])
            {
                vis[x.c]--;
                if(!vis[x.c])
                    tot--;
            }
        }
        cnt=0;
        build(1,Y[0]);
        ans+=t[1].sum*(L-X[X[0]])%P*(X[i]-(i-1==0?0:X[i-1]))%P;
        for(int i=1;i<=k;i++)
            ms[i].clear();
        for(int j=i;j<=X[0];j++)
            for(auto x:v[j])
                ms[x.c].insert(x.y);
        for(int j=X[0];j>=i;j--)
        {
            for(auto x:v[j])
            {
                auto it=ms[x.c].find(x.y);
                int suf=Y[0]+1;
                it++;
                if(it!=ms[x.c].end())
                    suf=*it;
                int pre=0;
                it=ms[x.c].find(x.y);
                if(it!=ms[x.c].begin())
                    it--,pre=*it;
                if(x.y<suf)
                    change(1,x.y,suf-1,pre);
                ms[x.c].erase(ms[x.c].find(x.y));
            }
            ans+=t[1].sum*(X[j]-(j-1==0?0:X[j-1]))%P*(X[i]-(i-1==0?0:X[i-1]))%P;
        }
    }
    printf("%lld\n",ans%P);
}