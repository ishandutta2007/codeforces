#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e6+5;
int n,q,a[maxn];
struct segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	struct node{int mv,mn,tag;}t[maxn<<2];
	void update(int u)
	{
		t[u].mv=min(t[L(u)].mv,t[R(u)].mv);
		t[u].mn=0;
		if(t[u].mv==t[L(u)].mv)t[u].mn+=t[L(u)].mn;
		if(t[u].mv==t[R(u)].mv)t[u].mn+=t[R(u)].mn;
	}
	void pushdown(int u)
	{
		if(t[u].tag)
		{
			t[L(u)].mv+=t[u].tag;t[L(u)].tag+=t[u].tag;
			t[R(u)].mv+=t[u].tag;t[R(u)].tag+=t[u].tag;
			t[u].tag=0;
		}
	}
	void add(int nl,int nr,int x,int u=1,int l=1,int r=maxn)
	{
		if(l>=nl&&r<=nr){t[u].mv+=x;t[u].tag+=x;return;}
		pushdown(u);
		int mid=(l+r)>>1;
		if(mid>=nl)add(nl,nr,x,L(u),l,mid);
		if(mid+1<=nr)add(nl,nr,x,R(u),mid+1,r);
		update(u);
	}
	void enable(int p,int u=1,int l=1,int r=maxn)
	{
		if(l==r){t[u].mn=1;return;}
		pushdown(u);
		int mid=(l+r)>>1;
		if(mid>=p)enable(p,L(u),l,mid);
		else enable(p,R(u),mid+1,r);
		update(u);
	}
	void disable(int p,int u=1,int l=1,int r=maxn)
	{
		if(l==r){t[u].mn=0;return;}
		pushdown(u);
		int mid=(l+r)>>1;
		if(mid>=p)disable(p,L(u),l,mid);
		else disable(p,R(u),mid+1,r);
		update(u);
	}	
}tr;
int main()
{
	n=read();q=read();
	generate_n(a+1,n,read);
	a[0]=maxn;a[n+1]=0;
	for(int i=1;i<=n+1;i++)tr.add(min(a[i],a[i-1])+1,max(a[i],a[i-1]),1);
	for(int i=1;i<=n;i++)tr.enable(a[i]);
	while(q--)
	{
		int pos=read(),x=read();
		tr.add(min(a[pos],a[pos-1])+1,max(a[pos],a[pos-1]),-1);
		tr.add(min(a[pos],a[pos+1])+1,max(a[pos],a[pos+1]),-1);
		tr.disable(a[pos]);
		
		a[pos]=x;
		tr.add(min(a[pos],a[pos-1])+1,max(a[pos],a[pos-1]),1);
		tr.add(min(a[pos],a[pos+1])+1,max(a[pos],a[pos+1]),1);
		tr.enable(a[pos]);
		printf("%d\n",tr.t[1].mv==1?tr.t[1].mn:0);
	}
	return 0;
}