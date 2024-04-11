#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=4e5+1e3+7;

int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int cnt;

struct T{
    int l,r,ls,rs;
    int sz;
    int sum,sumi;
}t[N*2];

void update(int x)
{
    t[x].sz=t[t[x].ls].sz+t[t[x].rs].sz;
    t[x].sum=t[t[x].ls].sum+t[t[x].rs].sum;
    t[x].sumi=t[t[x].ls].sumi+t[t[x].rs].sumi+t[t[x].ls].sz*t[t[x].rs].sum;
}

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    if(l==r)
        return x;
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    update(x);
    return x;
}

int tot;

void change(int x,int p,int v)
{
    if(t[x].l==t[x].r)
    {
        tot-=t[x].sz;
        t[x].sz^=1;
        t[x].sum^=v;
        t[x].sumi^=v;
        tot+=t[x].sz;
        return;
    }
    int mid=(t[x].l+t[x].r)>>1;
    if(p<=mid)
        change(t[x].ls,p,v);
    else
        change(t[x].rs,p,v);
    update(x);
}

int sumpre(int x,int k)
{
    if(t[x].l==t[x].r)
        return t[x].sum*k;
    if(t[t[x].ls].sz>=k)
        return sumpre(t[x].ls,k);
    return sumpre(t[x].rs,k-t[t[x].ls].sz)+t[t[x].ls].sum;
}

int sumsuf(int x,int k)
{
    if(t[x].l==t[x].r)
        return t[x].sum*k;
    if(t[t[x].rs].sz>=k)
        return sumsuf(t[x].rs,k);
    return sumsuf(t[x].ls,k-t[t[x].rs].sz)+t[t[x].rs].sum;
}

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii sumipre(int x,int k)
{
    if(t[x].l==t[x].r)
        return mp(t[x].sum*k,t[x].sumi*k);
    if(t[t[x].ls].sz>=k)
        return sumipre(t[x].ls,k);
    pii ret=sumipre(t[x].rs,k-t[t[x].ls].sz);
    return mp(t[t[x].ls].sum+ret.fs,ret.sd+ret.fs*t[t[x].ls].sz+t[t[x].ls].sumi);
}

int n,q,s[N],a[N];

vector<int>v;

void upd(int val)
{
    int p=lower_bound(v.begin(),v.end(),val)-v.begin()+1;
    change(1,p,val);
}

long long solve()
{
    int l=0,r=(tot-1)/2+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(sumpre(1,mid+1)-sumsuf(1,mid)>=0)
            l=mid;
        else
            r=mid;
    }
    int p=l;
    int suml=sumpre(1,p+1);
    int sumil=sumipre(1,p+1).sd;
    int sumr=sumsuf(1,p);
    int sumir=sumipre(1,tot).sd-sumipre(1,tot-p).sd;
    int ret=-sumil-sumir+(p+2)*suml-(p-tot)*sumr;
    ret*=2;
    if(tot%2==1&&p==(tot-1)/2)
        ret-=sumpre(1,p+1)-sumsuf(1,p);
    return sumpre(1,tot)-ret;
}

signed main()
{
    n=read(),q=read();
    for(int i=1;i<=n;i++)
        s[i]=read(),v.push_back(s[i]);
    for(int i=1;i<=q;i++)
        read(),a[i]=read(),v.push_back(a[i]);
    sort(v.begin(),v.end());
    build(1,n+q);
    for(int i=1;i<=n;i++)
        upd(s[i]);
    printf("%lld\n",solve());
    for(int i=1;i<=q;i++)
    {
        upd(a[i]);
        printf("%lld\n",solve());
    }
}