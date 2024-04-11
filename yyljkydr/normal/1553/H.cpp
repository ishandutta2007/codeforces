#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,INF=1e9;

int cnt;

struct T{
    int l,r;
    int ls,rs;
    int ld,rd;
    int dis;
    int sz;
}t[N*2+1];

void update(int x)
{
    t[x].ld=min({t[t[x].ls].ld,t[t[x].rs].ld+t[t[x].ls].sz,INF});
    t[x].rd=min({t[t[x].rs].rd,t[t[x].ls].rd+t[t[x].rs].sz,INF});
    t[x].sz=t[t[x].ls].sz+t[t[x].rs].sz;
    t[x].dis=min({t[t[x].ls].dis,t[t[x].rs].dis,t[t[x].rs].ld+t[t[x].ls].rd});
}

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    if(l==r)
    {
        t[x].sz=1;
        t[x].ld=t[x].rd=1e9;
        t[x].dis=1e9;
        return x;
    }
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    update(x);
    return x;
}

void ins(int x,int v)
{
    if(t[x].sz==1)
    {
        t[x].ld=t[x].rd=1;
        return;
    }
    int mid=(t[x].l+t[x].r)>>1;
    if(v<=mid)
        ins(t[x].ls,v);
    else
        ins(t[x].rs,v);
    update(x);
}

// int vs=0;

void change(int x,int b,int v)
{
    // ++vs;
    // if(vs%1000000==0)
    //     cout<<vs<<endl;
    if((1<<b)&v)
    {
        swap(t[x].ls,t[x].rs);
        update(x);
        return;
    }
    change(t[x].ls,b-1,v);
    change(t[x].rs,b-1,v);
    update(x);
}

vector<int>v;

int ans[N],n,k;

void gen()
{
    v.push_back(0);
    for(int i=1;i<=k;i++)
    {
        for(auto &x:v)
            x<<=1;
        int sz=v.size();
        for(int j=sz-1;j>=0;j--)
            v.push_back(v[j]^1);
    }
    // for(auto x:v)
    //     for(int j=k-1;j>=0;j--)
    //         printf("%d%c",(x>>j)&1," \n"[j==0]);
}


map<int,int>bts;

int main()
{
    scanf("%d%d",&n,&k);
    gen();
    build(0,(1<<k)-1);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ins(1,x);
    }
    // for(int i=0;i+1<v.size();i++)
    //     bts[(v[i]^v[i+1])]++;
    // for(auto [x,y]:bts)
    //     printf("%d %d\n",x,y);
    ans[0]=t[1].dis;
    for(int i=1;i<v.size();i++)
    {
        change(1,k-1,v[i]^v[i-1]),ans[v[i]]=t[1].dis;
        // assert(__builtin_popcount(v[i]^v[i-1])== 1);
    }
    for(int i=0;i<(1<<k);i++)
        printf("%d%c",ans[i]-1," \n"[i+1==1<<k]);
}