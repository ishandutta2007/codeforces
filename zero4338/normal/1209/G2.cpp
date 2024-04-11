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
int n,q;
int a[maxn];
set<int>pos[maxn];
struct segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	struct node{int miv,vsum,pval,sval,tag,mx;}t[maxn<<2];
	void pushdown(int u)
	{
		if(t[u].tag)
		{
			t[L(u)].miv+=t[u].tag;t[L(u)].tag+=t[u].tag;
			t[R(u)].miv+=t[u].tag;t[R(u)].tag+=t[u].tag;
			t[u].tag=0;
		}
	}
	void update(int u)
	{
		t[u].miv=min(t[L(u)].miv,t[R(u)].miv);
		t[u].mx=max(t[L(u)].mx,t[R(u)].mx);
		if(t[L(u)].miv<t[R(u)].miv)
		{
			t[u].vsum=t[L(u)].vsum;
			t[u].pval=t[L(u)].pval;
			t[u].sval=max(t[L(u)].sval,t[R(u)].mx);
		}
		else if(t[L(u)].miv>t[R(u)].miv)
		{
			t[u].pval=max(t[L(u)].mx,t[R(u)].pval);
			t[u].vsum=t[R(u)].vsum-t[R(u)].pval+t[u].pval;
			t[u].sval=t[R(u)].sval;
		}
		else
		{
			t[u].vsum=t[L(u)].vsum+t[R(u)].vsum+max(t[L(u)].sval,t[R(u)].pval)-t[R(u)].pval;
			t[u].pval=t[L(u)].pval;
			t[u].sval=t[R(u)].sval;
		}
	}
	void add(int nl,int nr,int x,int u=1,int l=1,int r=n)
	{
		if(l>=nl&&r<=nr){t[u].miv+=x;t[u].tag+=x;return;}
		pushdown(u);
		int mid=(l+r)>>1;
		if(mid>=nl)add(nl,nr,x,L(u),l,mid);
		if(mid+1<=nr)add(nl,nr,x,R(u),mid+1,r);
		update(u);
	}
	void set(int p,int x,int u=1,int l=1,int r=n)
	{
		if(l==r){t[u].pval=t[u].mx=x;t[u].sval=0;t[u].vsum=x;return;}
		pushdown(u);
		int mid=(l+r)>>1;
		if(mid>=p)set(p,x,L(u),l,mid);
		else set(p,x,R(u),mid+1,r);
		update(u);
	}
	#undef L
	#undef R
}tr;
void addp(int x)
{
	if(!pos[x].empty())
	{
		if(pos[x].size()>1)tr.add(*pos[x].begin(),*pos[x].rbegin()-1,1);
		tr.set(*pos[x].begin(),pos[x].size());
	}
}
void delp(int x)
{
	if(!pos[x].empty())
	{
		if(pos[x].size()>1)tr.add(*pos[x].begin(),*pos[x].rbegin()-1,-1);
		tr.set(*pos[x].begin(),0);
	}
}
int main()
{
	n=read();q=read();
	generate_n(a+1,n,read);
	for(int i=1;i<=n;i++)pos[a[i]].insert(i);
	for(int i=1;i<maxn;i++)addp(i);
	printf("%d\n",n-(tr.t[1].miv==0?tr.t[1].vsum:0));
	while(q--)
	{
		int p=read(),x=read();
		delp(a[p]);pos[a[p]].erase(p);addp(a[p]);
		a[p]=x;
		delp(a[p]);pos[a[p]].insert(p);addp(a[p]);
		printf("%d\n",n-(tr.t[1].miv==0?tr.t[1].vsum:0));
	}
}