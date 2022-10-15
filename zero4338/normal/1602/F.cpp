#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=5e5+5;
int n,d;
struct point
{
	int a,b,w;
	const bool operator <(const point &x)const{return a+b<x.a+x.b;}
}p[maxn];
int num[maxn<<1],cnt;
void discrete()
{
	num[++cnt]=d;
	for(int i=1;i<=n;i++)num[++cnt]=p[i].a,num[++cnt]=p[i].b;
	sort(num+1,num+cnt+1);cnt=unique(num+1,num+cnt+1)-(num+1);
	for(int i=1;i<=n;i++)p[i].a=lower_bound(num+1,num+cnt+1,p[i].a)-num,p[i].b=lower_bound(num+1,num+cnt+1,p[i].b)-num;
	d=lower_bound(num+1,num+cnt+1,d)-num;
}
struct segmemt
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	struct node{ll mx,tag;}t[maxn<<3];
	void update(int u){t[u].mx=max(t[L(u)].mx,t[R(u)].mx);}
	void pushdown(int u)
	{
		if(t[u].tag)
		{
			t[L(u)].tag+=t[u].tag;t[L(u)].mx+=t[u].tag;
			t[R(u)].tag+=t[u].tag;t[R(u)].mx+=t[u].tag;
			t[u].tag=0;
		}
	}
	void change(int u,int l,int r,int nl,int nr,ll x)
	{
		if(l>=nl&&r<=nr){t[u].mx+=x;t[u].tag+=x;return;}
		pushdown(u);int mid=(l+r)>>1;
		if(mid>=nl)change(L(u),l,mid,nl,nr,x);
		if(mid+1<=nr)change(R(u),mid+1,r,nl,nr,x);
		update(u);
	}
	ll query(int u,int l,int r,int nl,int nr)
	{
		if(nl>nr)return 0;
		if(l>=nl&&r<=nr)return t[u].mx;
		pushdown(u);int mid=(l+r)>>1;ll ret=0;
		if(mid>=nl)ret=max(ret,query(L(u),l,mid,nl,nr));
		if(mid+1<=nr)ret=max(ret,query(R(u),mid+1,r,nl,nr));
		return ret;
	}
}tr;
int main()
{
	n=read();d=read();
	for(int i=1;i<=n;i++)p[i].b=read(),p[i].a=max(d,read()),p[i].w=1;
	discrete();
	sort(p+1,p+n+1);
	for(int i=n;i>=1;i--)
	{
		if(p[i].b<d)continue;
		if(p[i].a<=p[i].b)tr.change(1,1,cnt,p[i].a,p[i].b,p[i].w);
		ll mx=tr.query(1,1,cnt,max(p[i].a,p[i].b+1),cnt);
		ll bv=tr.query(1,1,cnt,p[i].b,p[i].b);
		if(mx+p[i].w>bv)tr.change(1,1,cnt,p[i].b,p[i].b,mx+p[i].w-bv);
	}
	printf("%lld",tr.t[1].mx);
	return 0;
}