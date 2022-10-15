#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n;
struct segment
{
	#define L(u) t[u].ls
	#define R(u) t[u].rs
	struct node{int mx,mi,ls,rs,tag;}t[maxn*60];int cnt,rt;
	void init(){cnt=rt=1;t[1].mx=1e9;t[1].mi=0;}
	void update(int u)
	{
		t[u].mx=max(t[L(u)].mx,t[R(u)].mx);
		t[u].mi=min(t[L(u)].mi,t[R(u)].mi);
	}
	void pushdown(int u,int l,int r)
	{
		int mid=(l+r)>>1;
		if(!L(u))
		{
			L(u)=++cnt;
			t[L(u)].mx=mid;t[L(u)].mi=l;
		}
		if(!R(u))
		{
			R(u)=++cnt;
			t[R(u)].mx=r;t[R(u)].mi=mid+1;
		}
		if(t[u].tag)
		{
			t[L(u)].tag+=t[u].tag;t[L(u)].mi+=t[u].tag;t[L(u)].mx+=t[u].tag;
			t[R(u)].tag+=t[u].tag;t[R(u)].mi+=t[u].tag;t[R(u)].mx+=t[u].tag;
			t[u].tag=0;
		}
	}
	void change(int &u,int x,int l=0,int r=1e9)
	{
		if(t[u].mx<x){t[u].tag++;t[u].mx++;t[u].mi++;return;}
		if(t[u].mi>x){t[u].tag--;t[u].mx--;t[u].mi--;return;}
		if(t[u].mi==t[u].mx)return;
		int mid=(l+r)>>1;pushdown(u,l,r);
		change(L(u),x,l,mid);change(R(u),x,mid+1,r);
		update(u);
	}
	int query(int p,int &u,int l=0,int r=1e9)
	{
		if(l==r)return t[u].mi;
		int mid=(l+r)>>1;pushdown(u,l,r);
		if(mid>=p)return query(p,L(u),l,mid);
		else return query(p,R(u),mid+1,r);
	}
}tr;
int main()
{
	n=read();tr.init();
	int lans=0;
	for(int i=1;i<=n;i++)
	{
		tr.change(tr.rt,read());
		int k=read();
		for(int j=1;j<=k;j++)printf("%d\n",lans=tr.query((read()+lans)%1000000001,tr.rt));
	}
	return 0;
}