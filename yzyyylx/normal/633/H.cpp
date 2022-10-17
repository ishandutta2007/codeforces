#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define N 30010
using namespace std;

int n,m,s,M,tt,bb,num[N],b[N],ans[N],cnt[N],fb[2][N];
struct Que
{
    int l,r,id;
    bool operator < (const Que &u) const
    {
	if(l/s!=u.l/s) return l<u.l;
	return r<u.r;
    }
}que[N];
struct Node
{
    int ls,rs,s1,s2,dwn,cnt;
}node[N<<1];
map<int,int>mm;

inline int af(int u){return u>0?fb[0][u]:fb[1][-u];}
inline void chg(int now,int u)
{
    int p,q;
    q=(node[now].s2*af(u-1)%M+node[now].s1*af(u))%M;
    p=(node[now].s2*af(u)%M+node[now].s1*af(u+1))%M;
    node[now].s1=p,node[now].s2=q;
}

inline void up(int now)
{
    int L=node[now].ls,R=node[now].rs;
    node[now].s1=(node[L].s1+node[R].s1)%M;
    node[now].s2=(node[L].s2+node[R].s2)%M;
    node[now].cnt=node[L].cnt+node[R].cnt;
}

inline void down(int now)
{
    int L=node[now].ls,R=node[now].rs;
    if(node[now].dwn)
    {
	node[L].dwn+=node[now].dwn;
	chg(L,node[now].dwn);
	node[R].dwn+=node[now].dwn;
	chg(R,node[now].dwn);
	node[now].dwn=0;
    }
}

void build(int now,int l,int r)
{
    if(l==r) return;
    int mid=((l+r)>>1);
    node[now].ls=++tt;
    build(tt,l,mid);
    node[now].rs=++tt;
    build(tt,mid+1,r);
}

void add(int now,int l,int r,int u,int rk)
{
    if(l==r)
    {
	node[now].cnt=1;
	node[now].s1=b[l]%M*af(rk)%M;
	node[now].s2=b[l]%M*af(rk-1)%M;
	return;
    }
    down(now);
    int L=node[now].ls,R=node[now].rs,mid=((l+r)>>1);
    if(u<=mid)
    {
	node[R].dwn++;
	chg(R,1);
	add(L,l,mid,u,rk);
    }
    else
    {
	add(R,mid+1,r,u,rk+node[L].cnt);
    }
    up(now);
}

void del(int now,int l,int r,int u)
{
    if(l==r)
    {
	node[now].cnt=node[now].s1=node[now].s2=0;
	return;
    }
    down(now);
    int L=node[now].ls,R=node[now].rs,mid=((l+r)>>1);
    if(u<=mid)
    {
	node[R].dwn--;
	chg(R,-1);
	del(L,l,mid,u);
    }
    else
    {
	del(R,mid+1,r,u);
    }
    up(now);
}

inline void in(int u)
{
    if(!cnt[u]) add(1,1,bb,u,1);
    cnt[u]++;
}

inline void out(int u)
{
    cnt[u]--;
    if(!cnt[u]) del(1,1,bb,u);
}

int main()
{
    int i,j,l,r;
    cin>>n>>M;
    s=sqrt(n);
    for(i=1;i<=n;i++)
    {
	scanf("%d",&num[i]);
	b[i]=num[i];
    }
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++)
    {
	if(i==1 || b[i]!=b[i-1])
	{
	    b[++bb]=b[i];
	    mm[b[i]]=bb;
	}
    }
    for(i=1;i<=n;i++) num[i]=mm[num[i]];
    fb[0][1]=fb[1][1]=1;
    for(i=2;i<=bb+1;i++) fb[0][i]=(fb[0][i-1]+fb[0][i-2])%M;
    for(i=2;i<=bb+1;i++) fb[1][i]=(fb[1][i-2]-fb[1][i-1]+M)%M;
    build(tt=1,1,bb);
    
    cin>>m;
    for(i=1;i<=m;i++)
    {
	scanf("%d%d",&que[i].l,&que[i].r);
	que[i].id=i;
    }
    sort(que+1,que+m+1);
    for(l=i=1,r=0;i<=m;i++)
    {
	for(;r<que[i].r;r++) in(num[r+1]);
	for(;l>que[i].l;l--) in(num[l-1]);
	for(;r>que[i].r;r--) out(num[r]);
	for(;l<que[i].l;l++) out(num[l]);
	ans[que[i].id]=node[1].s1;
    }
    for(i=1;i<=m;i++) printf("%d\n",ans[i]);
}