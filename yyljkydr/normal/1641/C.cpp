#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,q;

struct Data{
    int tm,pz,cz;
};

struct T{
    int ls,rs,l,r;
    Data v;
    int tag;
}t[N*2+1];

void update(int x)
{
    t[x].v.tm=max(t[t[x].ls].v.tm,t[t[x].rs].v.tm);  
    t[x].v.pz=max(t[t[x].ls].v.pz,t[t[x].rs].v.pz);
    t[x].v.cz=t[t[x].ls].v.cz+t[t[x].rs].v.cz;
}

void add(int x,int c)
{
    if(!t[x].v.cz)
        return;
    t[x].v.tm=c;
    t[x].v.pz=0;
    t[x].v.cz=0;
    t[x].tag=c;
}

void pushdown(int x)
{
    if(t[x].tag)
    {
        add(t[x].ls,t[x].tag);
        add(t[x].rs,t[x].tag);
        t[x].tag=0;
    }
}

int cnt;

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    if(l==r)
    {
        t[x].v.cz=1;
        t[x].v.pz=l;
        t[x].v.tm=0;
        return x;
    }
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    update(x);
    return x;
}

void change(int x,int l,int r,int c)
{
    if(l<=t[x].l&&t[x].r<=r)
    {
        add(x,c);
        return;
    }
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    if(l<=mid)
        change(t[x].ls,l,r,c);
    if(r>mid)
        change(t[x].rs,l,r,c);
    update(x);
}

Data query(int x,int l,int r)
{
    if(l<=t[x].l&&t[x].r<=r)
        return t[x].v;
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    if(r<=mid)
        return query(t[x].ls,l,r);
    else if(l>mid)
        return query(t[x].rs,l,r);
    else
    {
        Data ql=query(t[x].ls,l,r);
        Data qr=query(t[x].rs,l,r);
        return {max(ql.tm,qr.tm),max(ql.pz,qr.pz),ql.cz+qr.cz};
    }
}

int ans[N],gtm[N];

vector<pair<int,int> >qr;

int ct[N];

int main()
{
    scanf("%d%d",&n,&q);
    build(1,n);
    for(int i=1;i<=q;i++)
    {
        int op;
        scanf("%d",&op);
        if(!op)
        {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            if(x==1)
                qr.push_back({l,r}),ct[++ct[0]]=i;
            else
                change(1,l,r,i);
        }
        else
        {
            int p;
            scanf("%d",&p);
            ct[++ct[0]]=i;
            qr.push_back({p,-i});
        }
    }
    fill(gtm+1,gtm+n+1,q+1);
    for(int i=1;i<=n;i++)
    {
        Data tmp=query(1,i,i);
        if(tmp.cz==0)
            ans[i]=1,gtm[i]=tmp.tm;
    }
    int dd=0;
    int cq=0;
    for(auto [x,y]:qr)
    {
        ++dd;
        if(y<0)
        {
            ++cq;
            // if(cq==12)
            //     puts("HERE");
            y=-y;
            if(!ans[x]||gtm[x]>ct[dd])
                puts("N/A");
            else
                puts(ans[x]==2?"YES":"NO");
        }
        else
        {
            Data tmp=query(1,x,y);
            if(tmp.cz>1)
                continue;
            // assert(tmp.cz==1);
            ans[tmp.pz]=2;
            gtm[tmp.pz]=min(gtm[tmp.pz],max(tmp.tm,ct[dd]));
        }
    }
}