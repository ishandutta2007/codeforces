#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
inline LL rin()
{
    LL x=0;
    char c;
    bool tag=false;
    for(c=getchar();c>'9'||c<'0';c=getchar())if(c=='-'){c=getchar();tag=true;break;}
    for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^'0');
    if(tag)x=-x;
    return x;
}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}

const int N=3e5+3;
int n;
int h[N];
int a[N];//h 
int b[N];
int c[N];
set<int>val;

struct gyq
{
    LL v[3];
    int ls,rs;
    inline void init(){ls=rs=0;memset(v,-0x3f,sizeof(v));return;}
    inline void add(LL v_){v[1]=v[0]+(v[2]=v_);return;}
    inline void cover(LL v_){v[0]=v[1]=v_;return;}
}t[N<<1];
int nam;
inline void make_tree(int l,int r,int i)
{
    t[i].init();if(l==r)return;
    int mid=l+r>>1;make_tree(l,mid,t[i].ls=++nam);make_tree(mid+1,r,t[i].rs=++nam);return;
}
inline void up(int i){t[i].v[0]=max(t[t[i].ls].v[0],t[t[i].rs].v[0]);t[i].v[1]=max(t[t[i].ls].v[1],t[t[i].rs].v[1]);return;}
inline void down(int i)
{
    if(t[i].v[2]==-0x3f3f3f3f3f3f3f3f)return;
    t[t[i].ls].add(t[i].v[2]);t[t[i].rs].add(t[i].v[2]);
    t[i].v[2]=-0x3f3f3f3f3f3f3f3f;return;
}
int ql,qr;
inline void add(int l,int r,int i,LL v_)
{
    if(ql<=l&&r<=qr){t[i].add(v_);return;}down(i);
    int mid=l+r>>1;if(mid>=ql)add(l,mid,t[i].ls,v_);if(mid<qr)add(mid+1,r,t[i].rs,v_);up(i);return;
}
inline void check(int l,int r,int i,LL v_)
{
    if(ql<=l&&r<=qr){t[i].cover(v_);return;}down(i);
    int mid=l+r>>1;if(mid>=ql)check(l,mid,t[i].ls,v_);if(mid<qr)check(mid+1,r,t[i].rs,v_);up(i);return;
    return;
}

LL sk[N];
inline void work()
{
    n=rin();
    for(int i=1;i<=n;i++)h[i]=rin();
    for(int i=1;i<=n;i++)b[i]=rin();
    for(int i=1;i<=n;i++)a[h[i]]=i;
    for(int i=0;i<=n;i++)
    {
        if(!h[i]){val.insert(h[i]);continue;}
        set<int>::iterator now=val.upper_bound(a[i]);
        if(now!=val.begin())c[a[i]]=(*(--now)),val.insert(a[i]);
    }
    int st=n+1;
    LL maxl=-0x3f3f3f3f3f3f3f3f;
    make_tree(1,n,++nam);
    for(int i=1;i<=n;i++)
    {
        sk[i]=max(t[1].v[1],maxl);qr=i;
        if(st>h[i])st=h[i],maxl=b[i];
        ql=i;check(1,n,1,sk[i]);
        ql=c[i]+1;add(1,n,1,b[i]);
    }
    maxl=max(maxl,t[1].v[1]);
    printf("%lld\n",maxl);
    return;
}
int main()
{
    work();
    return 0;
}

//vjudge 